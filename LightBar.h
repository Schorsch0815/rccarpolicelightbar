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

#ifndef LIGHTBAR_H_
#define LIGHTBAR_H_

class FlashPattern;

class LightBar
{
public:
    typedef enum
    {
        OFF, ON
    } LightBarStatus_t;

    LightBar(unsigned int pNumberOfSegments, unsigned int pPinArray[], unsigned int pMaxFlashPattern);

    virtual ~LightBar();

    void setup(void);

    void loop(void);

    void setStatus( LightBarStatus_t pStatus );

    LightBarStatus_t getStatus(void)
    {
        return m_Status;
    }

    void addPattern( FlashPattern &pPattern, unsigned int pNumberOfRepetitions);

private:
    void repeatPattern();
    void determineNextPattern();
    void getCurrentPattern(unsigned int &pattern);

    typedef struct
    {
        FlashPattern *pattern;
        unsigned int numberOfRepetitions;
    } FlashPatternRep_t;

    unsigned int *m_PinArray;
    unsigned int m_NumberOfSegments;

    FlashPatternRep_t *m_PatternRepArray;
    unsigned int m_MaxFlashPattern;
    unsigned int m_NumberOfFlashPattern;

    unsigned int m_CurrentPattern;
    unsigned int m_CurrentRepetition;

    LightBarStatus_t m_Status;

};

#endif /* LIGHTBAR_H_ */
