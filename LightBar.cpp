/*--------------------------------------------------------------------
 * This file is part of the RcPoliceLightBar arduino application.
 *
 * RcPoliceLightBar is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * RcPoliceLightBar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RcCarLights.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright: Jochen Schales 2014
 *
 * --------------------------------------------------------------------*/

#include "Arduino.h"

#include "LightBar.h"
#include "FlashPattern.h"

LightBar::LightBar(unsigned int pNumberOfSegments, unsigned int pPinArray[], unsigned int pMaxFlashPattern) :
        m_PinArray(pPinArray), m_NumberOfSegments(pNumberOfSegments), m_PatternRepArray(NULL), m_MaxFlashPattern(
                pMaxFlashPattern), m_NumberOfFlashPattern(0), m_CurrentPattern(0), m_CurrentRepetition(0), m_Status(OFF)
{
    m_PatternRepArray = new FlashPatternRep_t[pMaxFlashPattern];
}

LightBar::~LightBar()
{
    delete[] m_PatternRepArray;
}

void LightBar::setup(void)
{
    for (unsigned int i = 0; i < m_NumberOfSegments; ++i)
    {
        pinMode(m_PinArray[i], OUTPUT);
    }
}

void LightBar::addPattern(FlashPattern &pPattern, unsigned int pNumberOfRepetitions)
{
    if (m_NumberOfFlashPattern < m_MaxFlashPattern)
    {
        m_PatternRepArray[m_NumberOfFlashPattern].pattern = &pPattern;
        m_PatternRepArray[m_NumberOfFlashPattern].numberOfRepetitions = pNumberOfRepetitions;
        ++m_NumberOfFlashPattern;
    }
}

void LightBar::setStatus(LightBarStatus_t pStatus)
{
    if (m_Status != pStatus && ON == pStatus)
    {
        unsigned int lPattern;
        m_CurrentPattern = 0;
        m_CurrentRepetition = 0;
        m_PatternRepArray[m_CurrentPattern].pattern->getCurrentPattern(true, lPattern);
    }
    m_Status = pStatus;
}

void LightBar::repeatPattern()
{
    ++m_CurrentRepetition;
    m_PatternRepArray[m_CurrentPattern].pattern->restartFlashPattern();
}

void LightBar::determineNextPattern()
{
    ++m_CurrentPattern;
    m_CurrentRepetition = 0;
    if (m_CurrentPattern >= m_MaxFlashPattern)
    {
        m_CurrentPattern = 0;
        m_CurrentRepetition = 0;
        m_PatternRepArray[m_CurrentPattern].pattern->restartFlashPattern();
    }
}

void LightBar::getCurrentPattern(unsigned int &pattern)
{
    while (!m_PatternRepArray[m_CurrentPattern].pattern->getCurrentPattern(false, pattern))
    {
        if (m_CurrentRepetition < m_PatternRepArray[m_CurrentPattern].numberOfRepetitions
                || 0 == m_PatternRepArray[m_CurrentPattern].numberOfRepetitions)
        {
//            Serial.print("Repeat pattern\n");
            repeatPattern();
        }
        else
        {
//            Serial.print("Determine next pattern\n");
            determineNextPattern();
        }
    }
}

void LightBar::loop(void)
{
    unsigned int pattern = 0;

    if (ON == m_Status)
    {
        getCurrentPattern(pattern);
    }

//    Serial.print("\nPattern:");
//    Serial.print(pattern);

    for (unsigned int i = 0; i < m_NumberOfSegments; ++i)
    {
/*        Serial.print( " i: ");
        Serial.print(i);
        Serial.print( " Pin: ");
        Serial.print(m_PinArray[i]);
        Serial.print( " : patter >> i ");
        Serial.print((pattern >> i));
        Serial.print( " : HIGH or LOW ");
        Serial.print(((pattern >> i) & 0x1) ? HIGH : LOW);
        Serial.print( " : ");
*/        digitalWrite(m_PinArray[i], ((pattern >> i) & 0x1) ? HIGH : LOW);
    }
}

