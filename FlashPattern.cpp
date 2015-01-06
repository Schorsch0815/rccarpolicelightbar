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
mRows(NULL), mNumberOfSegments(pNumberOfSegments), mMaxRows(pMaxRows), mNumberOfRows(0), mCurrentRow(0), mLastStartTimestamp(0)
{
mRows = new PatternRow_t[mMaxRows];
}

FlashPattern::~FlashPattern()
{
    delete[] mRows;
}

void FlashPattern::addRow(unsigned int pPattern, unsigned int pDuration)
{
    if (mNumberOfRows < mMaxRows)
    {
        mRows[mNumberOfRows].pattern = pPattern;
        mRows[mNumberOfRows].duration = pDuration;
        ++mNumberOfRows;
    }

    Serial.print( "Add pattern:");
    Serial.print(pPattern);
    Serial.print(", Duration:");
    Serial.print(pDuration);
    Serial.print(", Number of Rows:");
    Serial.print(mNumberOfRows);
    Serial.print("\n");

}

void FlashPattern::restartFlashPattern()
{
//    Serial.print("Restart pattern");
    mCurrentRow = 0;
    mLastStartTimestamp = millis();
}


void FlashPattern::determineFlashPattern()
{
    unsigned long lCurrentTimestamp = millis();

    while (lCurrentTimestamp - mLastStartTimestamp > mRows[mCurrentRow].duration)
    {
        mLastStartTimestamp += mRows[mCurrentRow].duration;
        ++mCurrentRow;

        if (mCurrentRow >= mNumberOfRows)
            break;
    }
}

bool FlashPattern::getCurrentPattern(bool pStart, unsigned int &pCurrentPattern)
{
    if (mCurrentRow < mNumberOfRows)
    {
        determineFlashPattern();
    }

    if (mCurrentRow >= mNumberOfRows)
    {
//        Serial.print( "return false and pattern 0");
        pCurrentPattern = 0;
        return false;
    }


//    Serial.print( "Current pattern:");
//    Serial.print(mRows[mCurrentRow].pattern);
    pCurrentPattern = mRows[mCurrentRow].pattern;
    return true;
}
