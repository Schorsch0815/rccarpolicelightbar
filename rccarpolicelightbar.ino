#include "Arduino.h"

#include "FlashPattern.h"
#include "FlashRow.h"
#include "LightBar.h"
#include "rccarswitches/PinSwitch.h"
#include "rccarswitches/SteppingSwitch.h"

/*
 * traffic lightbar setup
 */
unsigned int g_trafficLightBarPins[] =
    { 14, 15, 16, 17, 18, 19 };

LightBar g_trafficLightBar( 6, g_trafficLightBarPins, 4);

FlashPattern g_trafficToLeftPattern(6,24);
FlashPattern g_trafficToRightPattern(6,24);
FlashPattern g_trafficSplitPattern(6,12);
FlashPattern g_trafficAttentionPattern(6,2);


/*
 * Emergency light bar setup
 */
unsigned int g_emergencyLightBarPins[] =
    { 10, 9, 7, 6, 5, 4, 3, 2, 1, 0 };

LightBar g_emergencyLightBar(10, g_emergencyLightBarPins, 4);

FlashPattern g_simplePattern(10, 2);
FlashPattern g_wierdPattern1(10, 8);
FlashPattern g_fastSimplePattern(10, 2);
FlashPattern g_wierdPattern2(10, 8);


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
const unsigned int g_TrafficLightSwitchPin = 12;

/*
 * pin for sirene switch
 */
const unsigned int g_SirenSwitchPin = 13;


PinSwitch g_EmergencyLightSwitch(g_EmergencyLightSwitchPin);

PinSwitch g_SirenSwitch(g_SirenSwitchPin);

SteppingSwitch g_TrafficLightSwitch(5, g_TrafficLightSwitchPin, 300, 10);

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

    g_TrafficLightSwitch.setup();
}

void setupTrafficToLeftPattern()
{
    /*
     * setup pattern "to left lane"
     */
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 1), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 1), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 1, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 1, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 1, 0, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 1, 0, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 1, 0, 0, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 1, 0, 0, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 1, 0, 0, 0, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 1, 0, 0, 0, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(1, 0, 0, 0, 0, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(1, 0, 0, 0, 0, 0), 50);
    g_trafficToLeftPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 150);
    g_trafficLightBar.addPattern(g_trafficToLeftPattern, 0);
}

void setupTrafficToRightPattern()
{
    /*
     * setup pattern "to right lane"
     */
    g_trafficToRightPattern.addRow(FLASH_ROW_6(1, 0, 0, 0, 0, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(1, 0, 0, 0, 0, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 1, 0, 0, 0, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 1, 0, 0, 0, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 1, 0, 0, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 1, 0, 0, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 1, 0, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 1, 0, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 1, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 1, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 1), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 1), 50);
    g_trafficToRightPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 150);
    g_trafficLightBar.addPattern(g_trafficToRightPattern, 0);
}

void setupTrafficSplitPattern()
{
    /*
     * setup pattern "split lanes"
     */
    g_trafficSplitPattern.addRow(FLASH_ROW_6(0, 0, 1, 1, 0, 0), 70);
    g_trafficSplitPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 70);
    g_trafficSplitPattern.addRow(FLASH_ROW_6(0, 0, 1, 1, 0, 0), 70);
    g_trafficSplitPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 70);
    g_trafficSplitPattern.addRow(FLASH_ROW_6(0, 1, 0, 0, 1, 0), 70);
    g_trafficSplitPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 70);
    g_trafficSplitPattern.addRow(FLASH_ROW_6(0, 1, 0, 0, 1, 0), 70);
    g_trafficSplitPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 70);
    g_trafficSplitPattern.addRow(FLASH_ROW_6(1, 0, 0, 0, 0, 1), 70);
    g_trafficSplitPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 70);
    g_trafficSplitPattern.addRow(FLASH_ROW_6(1, 0, 0, 0, 0, 1), 70);
    g_trafficSplitPattern.addRow(FLASH_ROW_6(0, 0, 0, 0, 0, 0), 200);
    g_trafficLightBar.addPattern(g_trafficSplitPattern, 0);
}

void setupAttentionPattern()
{
    /*
     * setup pattern "attention"
     */
    g_trafficAttentionPattern.addRow(FLASH_ROW_6(1, 0, 1, 0, 1, 0), 300);
    g_trafficAttentionPattern.addRow(FLASH_ROW_6(0, 1, 0, 1, 0, 1), 300);
    g_trafficLightBar.addPattern(g_trafficAttentionPattern, 0);
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
    g_trafficLightBar.setup();
}


void setupEmergencyLightBar()
{
    g_simplePattern.addRow(FLASH_ROW_10(0, 1, 0, 1, 0, 1, 0, 1, 0, 1), 300);
    g_simplePattern.addRow(FLASH_ROW_10(1, 0, 1, 0, 1, 0, 1, 0, 1, 0), 300);
    g_emergencyLightBar.addPattern(g_simplePattern, 5);

    g_wierdPattern1.addRow(FLASH_ROW_10(1, 0, 1, 0, 0, 0, 1, 0, 0, 1), 80);
    g_wierdPattern1.addRow(FLASH_ROW_10(0, 1, 0, 0, 0, 1, 0, 1, 1, 0), 80);
    g_wierdPattern1.addRow(FLASH_ROW_10(0, 0, 1, 0, 1, 1, 0, 1, 0, 0), 80);
    g_wierdPattern1.addRow(FLASH_ROW_10(1, 0, 0, 1, 1, 0, 0, 0, 0, 1), 80);
    g_wierdPattern1.addRow(FLASH_ROW_10(0, 1, 0, 1, 0, 1, 0, 0, 1, 0), 80);
    g_wierdPattern1.addRow(FLASH_ROW_10(1, 0, 1, 0, 0, 0, 1, 1, 0, 1), 80);
    g_wierdPattern1.addRow(FLASH_ROW_10(0, 1, 1, 0, 1, 0, 1, 0, 0, 1), 80);
    g_wierdPattern1.addRow(FLASH_ROW_10(1, 0, 0, 1, 0, 1, 0, 0, 1, 0), 80);
    g_emergencyLightBar.addPattern(g_wierdPattern1, 8);

    g_fastSimplePattern.addRow(FLASH_ROW_10(0, 1, 0, 1, 0, 1, 0, 1, 0, 1), 100);
    g_fastSimplePattern.addRow(FLASH_ROW_10(1, 0, 1, 0, 1, 0, 1, 0, 1, 0), 100);
    g_emergencyLightBar.addPattern(g_simplePattern, 5);

    g_wierdPattern2.addRow(FLASH_ROW_10(0, 1, 0, 1, 0, 1, 0, 1, 0, 0 ), 80);
    g_wierdPattern2.addRow(FLASH_ROW_10(0, 0, 0, 0, 1, 0, 1, 0, 0, 1 ), 80);
    g_wierdPattern2.addRow(FLASH_ROW_10(1, 1, 0, 0, 1, 0, 0, 1, 0, 0 ), 80);
    g_wierdPattern2.addRow(FLASH_ROW_10(1, 0, 1, 0, 0, 1, 0, 0, 1, 0 ), 80);
    g_wierdPattern2.addRow(FLASH_ROW_10(0, 1, 0, 0, 0, 0, 1, 0, 1, 1 ), 80);
    g_wierdPattern2.addRow(FLASH_ROW_10(0, 0, 1, 1, 1, 1, 0, 1, 0, 0 ), 80);
    g_wierdPattern2.addRow(FLASH_ROW_10(1, 0, 0, 1, 0, 0, 1, 1, 0, 0 ), 80);
    g_wierdPattern2.addRow(FLASH_ROW_10(0, 1, 1, 0, 0, 1, 0, 0, 1, 1 ), 80);
    g_emergencyLightBar.addPattern(g_wierdPattern2, 12);

    g_emergencyLightBar.setup();
}


// The loop function is called in an endless loop
void loop()
{
    g_EmergencyLightSwitch.refresh();

    g_emergencyLightBar.setStatus((Switch::OFF == g_EmergencyLightSwitch.getState()) ? LightBar::OFF : LightBar::ON );

    g_emergencyLightBar.loop();

    g_TrafficLightSwitch.refresh();

    unsigned int lCurrentTrafficStep = g_TrafficLightSwitch.getCurrentStep();

    if (0 == lCurrentTrafficStep)
    {
        g_trafficLightBar.setStatus(LightBar::OFF);
    }
    else
    {
        g_trafficLightBar.setStatus(LightBar::ON);
        g_trafficLightBar.switchToPattern(lCurrentTrafficStep-1);
    }

    g_trafficLightBar.loop();
}

