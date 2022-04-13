#include <Wire.h> 
#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);   /* Задаем адрес и размерность дисплея. 
При использовании LCD I2C модуля с дисплеем 20х04 ничего в коде изменять не требуется, cледует только задать правильную размерность */

byte PhotoDiod_An_pin = A2;
byte ButtonDig_pin = 3;
int value;     // переменная для хранения считываемого значения c фотодиода
int coins;


void setup()
{
  
  lcd.init();                            // Инициализация lcd             
  // Курсор находится в начале 1 строки
  //pinMode (analogPin1, INPUT);  //настройка порта на вход для фотодиода
  pinMode (4, OUTPUT);     //настройка еще одного пина для фотодиода
  pinMode (digPin2, INPUT);  //настройка порта на вход для кнопки
  pinMode (5, OUTPUT);  //настройка порта на выход для светодиода
  lcd.setCursor(4,0);
  EEPROM.get(0, coins)
  lcd.print("Piggy Bank");
  lcd.backlight();
  
}         

void loop(){
 
//----------------------------------------------Проверка на антидребезг-------------------------------- 
 analogWrite(5, 255);
 delay (10);
 val = analogRead(analogPin1);  //считать показания с фотодиода
 digitalWrite(4, HIGH); //Отключить фотодиод
 analogWrite(5, 00);   //Отключить светодиод
 lcd.setCursor(1, 0);
  
 if(val>=160) {coins++;
 analogWrite(5, 255);
 delay(20); 
 val = analogRead(analogPin1);  //считать показания с фотодиода
 digitalWrite(4, HIGH); //Отключить фотодиод
 analogWrite(5, 00);   //Отключить светодиод
 EEPROM.put(0, coins)
 }

 lcd.setCursor(0, 1);
 lcd.print("Coins:");
 lcd.setCursor(6, 1);
 lcd.print(b);
 if (digitalRead(digPin2)){
  	coins=0; lcd.setCursor(6, 1); 
    EEPROM.put(0, 0)
  	lcd.print("       ");
 }
}