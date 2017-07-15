#include <virtuabotixRTC.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define RS 0x3F
#define TSP 0

LiquidCrystal_I2C lcd(RS,16,2);  

virtuabotixRTC myRTC(6, 7, 8);

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  myRTC.setDS1302Time(00, 58, 23, 2, 17, 11, 2014);
  
  lcd.init();
  lcd.backlight();
}
 
void loop()
{ 
  myRTC.updateTime();
  int reading = analogRead(TSP);
  
  float mv = ( reading/1024.0) * 5000; 
  float temperature = mv / 10;

  lcd.setCursor(0,1);
  lcd.print("Teplota: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0,0);

  // Imprime as informacoes no serial monitor
  Serial.print("Data : ");
  Serial.print(", ");
  Serial.print(myRTC.dayofmonth);
  Serial.print("/");
  Serial.print(myRTC.month);
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print("  ");
  Serial.print("Hora : ");
  // Adiciona um 0 caso o valor da hora seja <10
  if (myRTC.hours < 10)
  {
    Serial.print("0");
  }
  Serial.print(myRTC.hours);
  Serial.print(":");
  // Adiciona um 0 caso o valor dos minutos seja <10
  if (myRTC.minutes < 10)
  {
    Serial.print("0");
  }
  Serial.print(myRTC.minutes);
  Serial.print(":");
  // Adiciona um 0 caso o valor dos segundos seja <10
  if (myRTC.seconds < 10)
  {
    Serial.print("0");
  }
  Serial.println(myRTC.seconds);

  delay(1000);
}
