// CONNECTIONS:
// 	DS1302:
//  	-CLK/SCLK --> 6
//  	-DAT/IO --> 7
//  	-RST/CE --> 8
//  	-VCC --> 3.3v
//  	-GND --> GND
//	LCD:
//		-GND --> GND
//		-VCC --> 5v
//		-SDA --> A4
//		-SCL --> A5
//BUTTONS
//

#include <ThreeWire.h>  
#include <RtcDS1302.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

// Create an LCD object. Parameters: (RS, E, D4, D5, D6, D7):
LiquidCrystal_I2C lcd (0x27, 2, 1, 0, 4, 5, 6, 7);

// Create an RTC object. Parameters: (DAT, CLK, RST):
ThreeWire myWire(7,6,8);
RtcDS1302<ThreeWire> Rtc(myWire);

//chrono variables
int mili = 0;
int sec = 0;
int m = 0;
int hr = 0;
void setup () 
{   
	setupRtc();
}

boolean crono = false;
boolean stop = false;
void loop () 
{ 
  if(digitalRead(2) == LOW)
    loopRtc();
  if(digitalRead(2) == HIGH){
    digitalWrite(13, HIGH);
    //if(crono = false){
      stop = false;
      setupSW();
      if(digitalRead(9) == HIGH && digitalRead(2) == HIGH)
        loopSW();
    //}else{
      //crono = false;
    //}
  }
}
