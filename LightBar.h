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
        return mStatus;
    }

    void addPattern( FlashPattern &pPattern, unsigned int pNumberOfRepetitions);

    void switchToPattern(unsigned int);

private:
    void repeatPattern();
    void determineNextPattern();
    void getCurrentPattern(unsigned int &pattern);

    typedef struct
    {
        FlashPattern *pattern;
        unsigned int numberOfRepetitions;
    } FlashPatternRep_t;

    unsigned int *mPinArray;
    unsigned int mNumberOfSegments;

    FlashPatternRep_t *mPatternRepArray;
    unsigned int mMaxFlashPattern;
    unsigned int mNumberOfFlashPattern;

    unsigned int mCurrentPattern;
    unsigned int mCurrentRepetition;

    LightBarStatus_t mStatus;

};

#endif /* LIGHTBAR_H_ */
