#include "Arduino.h"

#include "FlashPattern.h"
#include "FlashRow.h"
#include "LightBar.h"
#include "rccarswitches/PinSwitch.h"
#include "rccarswitches/SteppingSwitch.h"

/*
 * traffic lightbar setup
 */
unsigned int gTrafficLightBarPins[] =
    { 14, 15, 16, 17, 18, 19 };

LightBar gTrafficLightBar( 6, gTrafficLightBarPins, 4);

FlashPattern gTrafficToLeftPattern(6,24);
FlashPattern gTrafficToRightPattern(6,24);
FlashPattern gTrafficSplitPattern(6,12);
FlashPattern gTrafficAttentionPattern(6,2);


/*
 * Emergency light bar setup
 */
unsigned int gEmergencyLightBarPins[] =
    { 10, 9, 7, 6, 5, 4, 3, 2, 1, 0 };

LightBar gEmergencyLightBar(10, gEmergencyLightBarPins, 4);

FlashPattern g_simplePattern(10, 2);
FlashPattern gWierdPattern1(10, 8);
FlashPattern gFastSimplePattern(10, 2);
FlashPattern gWierdPattern2(10, 8);


/*
 * pin used for siren
 */
const unsigned int g_SirenPin = 8;


/*
 * pin for police blue light switch
 */
const unsigned int g_EmergencyLightSwitchPin = 11;

/*
 * pin for traffic pattern switch
 */
const unsigned int gTrafficLightSwitchPin = 12;

/*
 * pin for sirene switch
 */
const unsigned int g_SirenSwitchPin = 13;


PinSwitch g_EmergencyLightSwitch(g_EmergencyLightSwitchPin);

PinSwitch g_SirenSwitch(g_SirenSwitchPin);

SteppingSwitch gTrafficLightSwitch(5, gTrafficLightSwitchPin, 300, 10);

//The setup function is called once at startup of the sketch
void setup()
{
//    Serial.begin(9600);
//    Serial.print("\nSetup.");

    /*
     * traffic pattern setup
     */
    setupTrafficLightBar();

    /*
     * emergency pattern setup
     */
    setupEmergencyLightBar();

    g_EmergencyLightSwitch.setup();

    g_SirenSwitch.setup();

    gTrafficLightSwitch.setup();
}

void setupTrafficToLeftPattern()
{
    /*
     * setup pattern "to left lane"
     */
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 1), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 1), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 1, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 1, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 1, 0, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 1, 0, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 1, 0, 0, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 1, 0, 0, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 1, 0, 0, 0, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 1, 0, 0, 0, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(1, 0, 0, 0, 0, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(1, 0, 0, 0, 0, 0), 50);
    gTrafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 150);
    gTrafficLightBar.addPattern(gTrafficToLeftPattern, 0);
}

void setupTrafficToRightPattern()
{
    /*
     * setup pattern "to right lane"
     */
    gTrafficToRightPattern.addRow(FLASH_ROW_6(1, 0, 0, 0, 0, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(1, 0, 0, 0, 0, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 1, 0, 0, 0, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 1, 0, 0, 0, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 1, 0, 0, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 1, 0, 0, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 1, 0, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 1, 0, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 1, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 1, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 1), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 1), 50);
    gTrafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 150);
    gTrafficLightBar.addPattern(gTrafficToRightPattern, 0);
}

void setupTrafficSplitPattern()
{
    /*
     * setup pattern "split lanes"
     */
    gTrafficSplitPattern.addRow(FLASH_ROW_6(0, 0, 1, 1, 0, 0), 70);
    gTrafficSplitPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 70);
    gTrafficSplitPattern.addRow(FLASH_ROW_6(0, 0, 1, 1, 0, 0), 70);
    gTrafficSplitPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 70);
    gTrafficSplitPattern.addRow(FLASH_ROW_6(0, 1, 0, 0, 1, 0), 70);
    gTrafficSplitPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 70);
    gTrafficSplitPattern.addRow(FLASH_ROW_6(0, 1, 0, 0, 1, 0), 70);
    gTrafficSplitPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 70);
    gTrafficSplitPattern.addRow(FLASH_ROW_6(1, 0, 0, 0, 0, 1), 70);
    gTrafficSplitPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 70);
    gTrafficSplitPattern.addRow(FLASH_ROW_6(1, 0, 0, 0, 0, 1), 70);
    gTrafficSplitPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 200);
    gTrafficLightBar.addPattern(gTrafficSplitPattern, 0);
}

void setupAttentionPattern()
{
    /*
     * setup pattern "attention"
     */
    gTrafficAttentionPattern.addRow(FLASH_ROW_6(1, 0, 1, 0, 1, 0), 300);
    gTrafficAttentionPattern.addRow(FLASH_ROW_6(0, 1, 0, 1, 0, 1), 300);
    gTrafficLightBar.addPattern(gTrafficAttentionPattern, 0);
}

void setupTrafficLightBar(void)
{
    /*
     * setup pattern "to left lane"
     */
    setupTrafficToLeftPattern();
    /*
     * setup pattern "to right lane"
     */
    setupTrafficToRightPattern();

    /*
     * setup pattern "split lanes"
     */
    setupTrafficSplitPattern();
    /*
     * setup pattern "attention"
     */
    setupAttentionPattern();

    /*
     * setup the lightbar
     */
    gTrafficLightBar.setup();
}


void setupEmergencyLightBar()
{
    g_simplePattern.addRow(FLASH_ROW_10(0, 1, 0, 1, 0, 1, 0, 1, 0, 1), 300);
    g_simplePattern.addRow(FLASH_ROW_10(1, 0, 1, 0, 1, 0, 1, 0, 1, 0), 300);
    gEmergencyLightBar.addPattern(g_simplePattern, 5);

    gWierdPattern1.addRow(FLASH_ROW_10(1, 0, 1, 0, 0, 0, 1, 0, 0, 1), 80);
    gWierdPattern1.addRow(FLASH_ROW_10(0, 1, 0, 0, 0, 1, 0, 1, 1, 0), 80);
    gWierdPattern1.addRow(FLASH_ROW_10(0, 0, 1, 0, 1, 1, 0, 1, 0, 0), 80);
    gWierdPattern1.addRow(FLASH_ROW_10(1, 0, 0, 1, 1, 0, 0, 0, 0, 1), 80);
    gWierdPattern1.addRow(FLASH_ROW_10(0, 1, 0, 1, 0, 1, 0, 0, 1, 0), 80);
    gWierdPattern1.addRow(FLASH_ROW_10(1, 0, 1, 0, 0, 0, 1, 1, 0, 1), 80);
    gWierdPattern1.addRow(FLASH_ROW_10(0, 1, 1, 0, 1, 0, 1, 0, 0, 1), 80);
    gWierdPattern1.addRow(FLASH_ROW_10(1, 0, 0, 1, 0, 1, 0, 0, 1, 0), 80);
    gEmergencyLightBar.addPattern(gWierdPattern1, 8);

    gFastSimplePattern.addRow(FLASH_ROW_10(0, 1, 0, 1, 0, 1, 0, 1, 0, 1), 100);
    gFastSimplePattern.addRow(FLASH_ROW_10(1, 0, 1, 0, 1, 0, 1, 0, 1, 0), 100);
    gEmergencyLightBar.addPattern(g_simplePattern, 5);

    gWierdPattern2.addRow(FLASH_ROW_10(0, 1, 0, 1, 0, 1, 0, 1, 0, 0 ), 80);
    gWierdPattern2.addRow(FLASH_ROW_10(0, 0, 0, 0, 1, 0, 1, 0, 0, 1 ), 80);
    gWierdPattern2.addRow(FLASH_ROW_10(1, 1, 0, 0, 1, 0, 0, 1, 0, 0 ), 80);
    gWierdPattern2.addRow(FLASH_ROW_10(1, 0, 1, 0, 0, 1, 0, 0, 1, 0 ), 80);
    gWierdPattern2.addRow(FLASH_ROW_10(0, 1, 0, 0, 0, 0, 1, 0, 1, 1 ), 80);
    gWierdPattern2.addRow(FLASH_ROW_10(0, 0, 1, 1, 1, 1, 0, 1, 0, 0 ), 80);
    gWierdPattern2.addRow(FLASH_ROW_10(1, 0, 0, 1, 0, 0, 1, 1, 0, 0 ), 80);
    gWierdPattern2.addRow(FLASH_ROW_10(0, 1, 1, 0, 0, 1, 0, 0, 1, 1 ), 80);
    gEmergencyLightBar.addPattern(gWierdPattern2, 12);

    gEmergencyLightBar.setup();
}


// The loop function is called in an endless loop
void loop()
{
    g_EmergencyLightSwitch.refresh();

    gEmergencyLightBar.setStatus((Switch::OFF == g_EmergencyLightSwitch.getState()) ? LightBar::OFF : LightBar::ON );

    gEmergencyLightBar.loop();

    gTrafficLightSwitch.refresh();

    unsigned int lCurrentTrafficStep = gTrafficLightSwitch.getCurrentStep();

    if (0 == lCurrentTrafficStep)
    {
        gTrafficLightBar.setStatus(LightBar::OFF);
    }
    else
    {
        gTrafficLightBar.setStatus(LightBar::ON);
        gTrafficLightBar.switchToPattern(lCurrentTrafficStep-1);
    }

    gTrafficLightBar.loop();
}

