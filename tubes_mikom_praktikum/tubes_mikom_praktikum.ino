#include "LiquidCrystal_I2C.h"
#include  "Wire.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

int merah = LOW;
int kuning = LOW;
int hijau = LOW;
int buzzer = LOW;

void setup(){

  Serial.begin(9600);
  pinMode(2, OUTPUT); //Buzzer
  pinMode(3, OUTPUT); //LED1
  pinMode(4, OUTPUT); //LED2
  pinMode(5, OUTPUT); //LED3
  pinMode(11, OUTPUT); //trigpin
  pinMode(12, INPUT); //Echo

  lcd.init();
  lcd.backlight();

}


void loop(){

  digitalWrite(3, hijau);
  digitalWrite(4, kuning);
  digitalWrite(5, merah);
  digitalWrite(2, buzzer);

digitalWrite(11, LOW);
delayMicroseconds(2);
digitalWrite(11, HIGH);
delayMicroseconds(10);
digitalWrite(11, LOW);

long timer = pulseIn(12, HIGH);
int jarak = timer/58;
// delay(1000);

if (jarak > 30){
  hijau = LOW;
  merah = LOW;
  kuning = LOW;
  buzzer = LOW;
  Serial.println("halo");
  delay(1000);

}

if (jarak >=20 && jarak <= 30 ){

  hijau = HIGH;
  merah = LOW;
  kuning = LOW;
  buzzer = HIGH;
  Serial.println("halo");
  delay(1000);
  
}if(jarak < 20 && jarak >=10){
  hijau = LOW;
  merah = LOW;
  kuning = HIGH;
  buzzer = HIGH;
  Serial.println("halo2");
  delay(500);
}if (jarak < 10){
  hijau = LOW;
  merah = HIGH;
  kuning = LOW;
  buzzer = HIGH;
  Serial.println("halo3");
  delay(100);
}

Serial.print("jarak : ");
Serial.print(jarak);
Serial.print(" cm");
Serial.println();

// LCD
  lcd.setCursor(0,0);
  lcd.print(jarak);
  lcd.print(" cm");

  // delay(2000);
  // lcd.clear();


}