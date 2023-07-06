#include <LiquidCrystal.h>

int yesil=6,kirmizi=7,buzzer=10;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int analogPin = A0; // Analog giriş pini A0
const int analogPin1 = A1; // Analog giriş pini A1

void setup() {
  Serial.begin(9600);
  pinMode(yesil,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(kirmizi,OUTPUT);
  lcd.begin(16, 2);
}

void loop() {

  for(int i=60;i>0;i--){
    //surekş, okunmaları gerektigi icin burda
    int analogValue = analogRead(analogPin); // Analog değeri oku
    int analogValue1 = analogRead(analogPin1); // Analog değeri oku


    Serial.print("analogValue :");
    Serial.println(analogValue);

    Serial.print("analogValue1 :");
    Serial.println(analogValue1);


    digitalWrite(kirmizi,1);
    lcd.clear();
    lcd.setCursor(0,0);   //lcd.home() aynı
    lcd.print("patlamaya : ");
    lcd.setCursor(12,0);
    lcd.print(i);
    if(i>=10) lcd.setCursor(14,0);
    if(i<10) lcd.setCursor(13,0);
    lcd.print("sn");
    lcd.setCursor(0,1);
    digitalWrite(buzzer,1);
    lcd.print("----------------");
    delay(500);
    digitalWrite(buzzer,0);
    digitalWrite(kirmizi,0);
    delay(500);   //buzzer icin
    //ilk kontrol ustteki kablo cekilirse
    if (analogValue != 0){
      Serial.println("boom");
      lcd.clear();
      lcd.setCursor(0,0);   //lcd.home() aynı
      lcd.print("      Boom");
      lcd.setCursor(0,1);
      lcd.print("----------------");
      digitalWrite(buzzer,1);
      digitalWrite(kirmizi,1);
      delay(10000);
      exit(1);
    }
    if (analogValue1 != 0){
      Serial.println("bomba durdu");
      lcd.clear();
      lcd.setCursor(0,0);   //lcd.home() aynı
      lcd.print("  bomba durdu");
      lcd.setCursor(0,1);
      lcd.print("----------------");
      digitalWrite(buzzer,0);
      digitalWrite(kirmizi,0);
      digitalWrite(yesil,1);
      delay(10000);
      exit(1);
    }

    if(i==1){
      Serial.println("boom");
      lcd.clear();
      lcd.setCursor(0,0);   //lcd.home() aynı
      lcd.print("      Boom");
      lcd.setCursor(0,1);
      lcd.print("----------------");
      digitalWrite(buzzer,1);
      digitalWrite(kirmizi,1);
      delay(10000);
      exit(1);
    }
  }
}
