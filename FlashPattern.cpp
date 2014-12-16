/*
 * FlashPattern.cpp
 *
 *  Created on: 09.12.2014
 *      Author: Jochen
 */

#include "FlashPattern.h"

#include <stdio.h>
#include <stdlib.h>

#include "Arduino.h"

FlashPattern::FlashPattern(unsigned int pNumberOfSegments, unsigned int pMaxRows) :
m_Rows(NULL), m_NumberOfSegments(pNumberOfSegments), m_MaxRows(pMaxRows), m_NumberOfRows(0), m_CurrentRow(0), m_LastStartTimestamp(0)
{
m_Rows = new PatternRow_t[m_MaxRows];
}

FlashPattern::~FlashPattern()
{
    delete[] m_Rows;
}

void FlashPattern::addRow(unsigned int pPattern, unsigned int pDuration)
{
    if (m_NumberOfRows < m_MaxRows)
    {
        m_Rows[m_NumberOfRows].pattern = pPattern;
        m_Rows[m_NumberOfRows].duration = pDuration;
        ++m_NumberOfRows;
    }
    Serial.print( "Add pattern:");
    Serial.print(pPattern);
    Serial.print(", Duration:");
    Serial.print(pDuration);
    Serial.print(", Number of Rows:");
    Serial.print(m_NumberOfRows);
    Serial.print("\n");
}

void FlashPattern::restartFlashPattern()
{
//    Serial.print("Restart pattern");
    m_CurrentRow = 0;
    m_LastStartTimestamp = millis();
}

void FlashPattern::determineFlashPattern()
{
    unsigned long lCurrentTimestamp = millis();

    while (lCurrentTimestamp - m_LastStartTimestamp > m_Rows[m_CurrentRow].duration)
    {
        m_LastStartTimestamp += m_Rows[m_CurrentRow].duration;
        ++m_CurrentRow;

        if (m_CurrentRow >= m_NumberOfRows)
            break;
    }
}

bool FlashPattern::getCurrentPattern(bool pStart, unsigned int &pCurrentPattern)
{
    if (m_CurrentRow < m_NumberOfRows)
    {
        determineFlashPattern();
    }

    if (m_CurrentRow >= m_NumberOfRows)
    {
//        Serial.print( "return false and pattern 0");
        pCurrentPattern = 0;
        return false;
    }


//    Serial.print( "Current pattern:");
//    Serial.print(m_Rows[m_CurrentRow].pattern);
    pCurrentPattern = m_Rows[m_CurrentRow].pattern;
    return true;
}
