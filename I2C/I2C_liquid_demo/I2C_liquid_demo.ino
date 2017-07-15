#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
// LCD pin definitions
#define RS 0x3F

// vytvoří objekt lcd a nastaví jeho adresu
// 0x20 a 16 zanků na 2 řádcích
LiquidCrystal_I2C lcd(RS,16,2);  
 
void setup()
{
  lcd.init();// inicializuje displej
  lcd.backlight(); // zapne podsvětlení
 
}
 
void loop()
{
  for (int i = 0; i < 500; i++) // smyčka pro počítání
  {
    lcd.setCursor(7,1);
    lcd.print(i);
    delay(100);
  }
 
  lcd.setCursor(7,1);
  lcd.print("   ");
}
