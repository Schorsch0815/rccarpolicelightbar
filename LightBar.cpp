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
        mPinArray(pPinArray), mNumberOfSegments(pNumberOfSegments), mPatternRepArray(NULL), mMaxFlashPattern(
                pMaxFlashPattern), mNumberOfFlashPattern(0), mCurrentPattern(0), mCurrentRepetition(0), mStatus(OFF)
{
    mPatternRepArray = new FlashPatternRep_t[pMaxFlashPattern];
}

LightBar::~LightBar()
{
    delete[] mPatternRepArray;
}

void LightBar::setup(void)
{
    for (unsigned int i = 0; i < mNumberOfSegments; ++i)
    {
        pinMode(mPinArray[i], OUTPUT);
    }
}

void LightBar::addPattern(FlashPattern &pPattern, unsigned int pNumberOfRepetitions)
{
    if (mNumberOfFlashPattern < mMaxFlashPattern)
    {
        mPatternRepArray[mNumberOfFlashPattern].pattern = &pPattern;
        mPatternRepArray[mNumberOfFlashPattern].numberOfRepetitions = pNumberOfRepetitions;
        ++mNumberOfFlashPattern;
    }
}

void LightBar::setStatus(LightBarStatus_t pStatus)
{
    if (mStatus != pStatus && ON == pStatus)
    {
        unsigned int lPattern;
        mCurrentPattern = 0;
        mCurrentRepetition = 0;
        mPatternRepArray[mCurrentPattern].pattern->getCurrentPattern(true, lPattern);
    }
    mStatus = pStatus;
}

void LightBar::repeatPattern()
{
    ++mCurrentRepetition;
    mPatternRepArray[mCurrentPattern].pattern->restartFlashPattern();
}

void LightBar::determineNextPattern()
{
    ++mCurrentPattern;
    mCurrentRepetition = 0;
    if (mCurrentPattern >= mMaxFlashPattern)
    {
        mCurrentPattern = 0;
        mCurrentRepetition = 0;
        mPatternRepArray[mCurrentPattern].pattern->restartFlashPattern();
    }
}

void LightBar::getCurrentPattern(unsigned int &pattern)
{
    while (!mPatternRepArray[mCurrentPattern].pattern->getCurrentPattern(false, pattern))
    {
        if (mCurrentRepetition < mPatternRepArray[mCurrentPattern].numberOfRepetitions
                || 0 == mPatternRepArray[mCurrentPattern].numberOfRepetitions)
        {
//            Serial.print("Repeat pattern\n");
            repeatPattern();
        }
        else
        {
//            Serial.print("Determine Next Pattern\n");
            determineNextPattern();
        }
    }
}

void LightBar::switchToPattern(unsigned int pPatternIdx)
{
    if (0 <= pPatternIdx && pPatternIdx <mMaxFlashPattern)
    {
        mCurrentPattern = pPatternIdx;
        mCurrentRepetition = 0;
        mPatternRepArray[mCurrentPattern].pattern->restartFlashPattern();
    }
    else
    {
        setStatus(OFF);
    }
}


void LightBar::loop(void)
{
    unsigned int pattern = 0;

    if (ON == mStatus)
    {
        getCurrentPattern(pattern);
    }
//    Serial.print("\nPattern:");
//    Serial.print(pattern);

    for (unsigned int i = 0; i < mNumberOfSegments; ++i)
    {
//        Serial.print( " i: ");
//        Serial.print(i);
//        Serial.print( " Pin: ");
//        Serial.print(mPinArray[i]);
//        Serial.print( " : patter >> i ");
//        Serial.print((pattern >> i));
//        Serial.print( " : HIGH or LOW ");
//        Serial.print(((pattern >> i) & 0x1) ? HIGH : LOW);
//        Serial.print( " : ");
        digitalWrite(mPinArray[i], ((pattern >> i) & 0x1) ? HIGH : LOW);
    }
}

