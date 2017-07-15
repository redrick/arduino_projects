#include <virtuabotixRTC.h>
#include <Wire.h>

virtuabotixRTC myRTC(6, 7, 8);

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  myRTC.setDS1302Time(00, 58, 23, 2, 17, 11, 2014);
}
 
void loop()
{ 
  myRTC.updateTime();
  Serial.print("Data : ");
  Serial.print(", ");
  Serial.print(myRTC.dayofmonth);
  Serial.print("/");
  Serial.print(myRTC.month);
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print("  ");
  Serial.print("Hora : ");
  if (myRTC.hours < 10)
  {
    Serial.print("0");
  }
  Serial.print(myRTC.hours);
  Serial.print(":");
  if (myRTC.minutes < 10)
  {
    Serial.print("0");
  }
  Serial.print(myRTC.minutes);
  Serial.print(":");
  if (myRTC.seconds < 10)
  {
    Serial.print("0");
  }
  Serial.println(myRTC.seconds);

  delay(1000);
}
