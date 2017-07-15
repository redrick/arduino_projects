#include <DS1302RTC.h>
#include <Time.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define RS 0x3F
#define TSP 0
#define PR_LIGHT 200

LiquidCrystal_I2C lcd(RS,16,2);  
 
void setup()
{
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}
 
void loop()
{
  int reading = analogRead(TSP);
  
  float mv = ( reading/1024.0) * 5000; 
  float temperature = mv / 10;

  lcd.setCursor(4,0);
  lcd.print("Teplota");
  lcd.setCursor(5,1);
  lcd.print(temperature); lcd.print(" C");
  
  Serial.println(rtc.getMonth());

  delay(500);
}
