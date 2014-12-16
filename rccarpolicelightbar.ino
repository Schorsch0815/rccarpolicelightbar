#include "Arduino.h"

#include "FlashPattern.h"
#include "FlashRow.h"
#include "LightBar.h"

FlashPattern g_simplePattern(6, 2);
FlashPattern g_wierdPattern(6, 8);

unsigned int g_SimpleLightBarPins[] =
    { 8, 2, 3, 6, 7, 9  };

LightBar g_simpleLightBar(6, g_SimpleLightBarPins, 2);


//The setup function is called once at startup of the sketch
void setup()
{
 //   Serial.begin(9600);
 //   Serial.print("\nSetup.");

    g_simplePattern.addRow(FLASH_ROW_6(0, 1, 0, 1, 0, 1), 300);
    g_simplePattern.addRow(FLASH_ROW_6(1, 0, 1, 0, 1, 0), 300);

    g_simpleLightBar.addPattern(g_simplePattern, 5);

    g_wierdPattern.addRow(FLASH_ROW_6(0, 1, 1, 0, 0, 0), 80);
    g_wierdPattern.addRow(FLASH_ROW_6(0, 1, 0, 1, 1, 0), 80);
    g_wierdPattern.addRow(FLASH_ROW_6(1, 0, 0, 1, 0, 0), 80);
    g_wierdPattern.addRow(FLASH_ROW_6(1, 0, 0, 0, 0, 1), 80);
    g_wierdPattern.addRow(FLASH_ROW_6(0, 1, 0, 0, 1, 0), 80);
    g_wierdPattern.addRow(FLASH_ROW_6(0, 0, 1, 1, 0, 1), 80);
    g_wierdPattern.addRow(FLASH_ROW_6(1, 0, 1, 0, 0, 1), 80);
    g_wierdPattern.addRow(FLASH_ROW_6(0, 1, 0, 0, 1, 1), 80);
    g_simpleLightBar.addPattern(g_wierdPattern, 8);

    g_simpleLightBar.setup();
    g_simpleLightBar.setStatus(LightBar::ON);
}

// The loop function is called in an endless loop
void loop()
{
//    Serial.print("\nLoop.");

    g_simpleLightBar.loop();
}


