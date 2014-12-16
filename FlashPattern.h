/*
 * FlashPattern.h
 *
 *  Created on: 09.12.2014
 *      Author: Jochen
 */

#ifndef FLASHPATTERN_H_
#define FLASHPATTERN_H_

class FlashPattern
{
public:
    FlashPattern(unsigned int pNumberOfSegments, unsigned int pMaxRows);
    virtual ~FlashPattern();

    void addRow(unsigned int pPattern, unsigned int pDuration);

    void restartFlashPattern();

    bool getCurrentPattern(bool pStart, unsigned int &pCurrentPattern);

private:
    void determineFlashPattern();

    typedef struct
    {
        unsigned int pattern;
        unsigned int duration;
    } PatternRow_t;

    PatternRow_t *m_Rows;

    unsigned int m_NumberOfSegments;
    unsigned int m_MaxRows;
    unsigned int m_NumberOfRows;

    unsigned int m_CurrentRow;
    unsigned long m_LastStartTimestamp;

};

#endif /* FLASHPATTERN_H_ */
