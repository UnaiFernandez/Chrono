#include <ThreeWire.h>  
#include <RtcDS1302.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

// Create an LCD object. Parameters: (RS, E, D4, D5, D6, D7):
//LiquidCrystal_I2C lcd (0x27, 2, 1, 0, 4, 5, 6, 7);

// Create an RTC object. Parameters: (DAT, CLK, RST):
//ThreeWire myWire(7,6,8);
//RtcDS1302<ThreeWire> Rtc(myWire);

void setupRtc () 
{   
  //Initialize the lcd
    lcd.begin(16,2);
    lcd.setBacklightPin(3, POSITIVE); 
    lcd.setBacklight(HIGH);
    
  //begin serial to print the output of the rtc
    Serial.begin(57600);
  Serial.print("compiled: ");
    Serial.print(__DATE__);
    Serial.println(__TIME__);

  //Begin the rtc
    Rtc.Begin();
  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
    printDateTime(compiled);
    Serial.println();

    if (!Rtc.IsDateTimeValid()) {
        // Common Causes:
        //    1) first time you ran and the device wasn't running yet
        //    2) the battery on the device is low or even missing
        Serial.println("RTC lost confidence in the DateTime!");
        Rtc.SetDateTime(compiled);
    }

    if (Rtc.GetIsWriteProtected()){
        Serial.println("RTC was write protected, enabling writing now");
        Rtc.SetIsWriteProtected(false);
    }

    if (!Rtc.GetIsRunning()){
        Serial.println("RTC was not actively running, starting now");
        Rtc.SetIsRunning(true);
    }



    RtcDateTime now = Rtc.GetDateTime();
    if (now < compiled) {
        Serial.println("Updating DateTime");
        Rtc.SetDateTime(compiled);
    } else if (now > compiled) {
        Serial.println("RTC is newer than compile time. (this is expected)");
    } else if (now == compiled) {
        Serial.println("RTC is the same as compile time! (not expected but all is fine)");
    }
}

void loopRtc () 
{ 
    RtcDateTime now = Rtc.GetDateTime();

    printDateTime(now);
    lcd.setCursor(0,0);
    printDate(now);
    lcd.setCursor(0,1);
    printTime(now);
    lcd.setCursor(12,1);
    printDayOfWeek(now);
    Serial.println();
   

    if (!now.IsValid()){
        // Common Causes:
        //    1) the battery on the device is low or even missing and the power line was disconnected
        Serial.println("RTC lost confidence in the DateTime!");
    }

    delay(1000); // one second
}

#define countof(a) (sizeof(a) / sizeof(a[0]))

void printDateTime(const RtcDateTime& dt)
{
    char datestring[20];

    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            dt.Month(),
            dt.Day(),
            dt.Year(),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );
    Serial.print(datestring);
}
void printDate(const RtcDateTime& d)
{
    char datestring[16];

    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u"),
            d.Month(),
            d.Day(),
            d.Year() );
    lcd.print(datestring);
    Serial.print(datestring);
}
void printTime(const RtcDateTime& t)
{
    char timestring[16];

    snprintf_P(timestring, 
            countof(timestring),
            PSTR("%02u:%02u:%02u"),
            t.Hour(),
            t.Minute(),
            t.Second() );
    lcd.print(timestring);
    Serial.print(timestring);
}
void printDayOfWeek(const RtcDateTime& d)
{
    char daystring[16];

    snprintf_P(daystring, 
            countof(daystring),
            PSTR("%01u"),
            d.DayOfWeek() );
            switch (d.DayOfWeek()){
          case 0:
          lcd.print("Dom");
          Serial.print("Dom");
          break;
          case 1:
          lcd.print("Lun");
          Serial.print("Lun");
          break;
          case 2:
          lcd.print("Mar");
          Serial.print("Mar");
          break;
          case 3:
          lcd.print("Mier");
          Serial.print("Mier");
          break;
          case 4:
          lcd.print("Jue");
          Serial.print("Jue");
          break;
          case 5:
          lcd.print("Vi");
          Serial.print("Vi");
          break;
          case 6:
          lcd.print("Sab");
          Serial.print("Sab");
          break;
        }
}
