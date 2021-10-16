****** SMART AGRICULTURE MONITORING WITH NOTIFICATION TO FARMER ****** 
/////////****SOURCE CODE*****/////////

#include<LiquidCrystal.h>
#include<SoftwareSerial.h>
#include <DHT.h>
#define echo 9
#define trigger 10
#define tank_pump 4
#define watering_pump 13
#define moisture_sensor A0
#define rain_pin A1
#define motion_pin A2
#define DHTPIN A3    
#define DHTTYPE DHT11 
#define buzzer_pin A4 
DHT dht(DHTPIN, DHTTYPE); 
float hum;  
float temp; 
long duration;
int distance;
int moisture_value;
int distance_percent;
int moist_percent;

SoftwareSerial SIM900(2, 3);
LiquidCrystal lcd(12,11,8,7,6,5);

void setup () {
lcd.begin(20,4);
SIM900.begin(9600);
Serial.begin(9600);
dht.begin();
pinMode(rain_pin,INPUT);
pinMode(motion_pin,INPUT);
pinMode(DHTPIN,INPUT);
pinMode(buzzer_pin,OUTPUT);
pinMode(echo,INPUT);
pinMode(moisture_sensor,INPUT);
pinMode(trigger,OUTPUT);
digitalWrite(trigger,LOW);
pinMode(watering_pump,OUTPUT);
pinMode(tank_pump,OUTPUT);
digitalWrite(watering_pump,LOW);
digitalWrite(tank_pump,LOW);
lcd.setCursor(0,0);
lcd.print("SMART AGRO MONITOR"    );
lcd.setCursor(0,1);
lcd.print(" TEAM SMART FARMER");
lcd.setCursor(0,2);
lcd.print("   WELCOME");
delay(500);
lcd.clear(); 
}


void loop(){

 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigger,LOW);
 duration=pulseIn(echo,HIGH);
 distance=duration*0.017; 
 distance_percent=map( distance,0,1023,0,100);
 moisture_value= analogRead(moisture_sensor);
 moist_percent=map(moisture_value,0,1023,0,100);
 condition();
}

void condition(){
if(digitalRead(rain_pin)==0)
{
if (distance_percent>65 &&moist_percent<85)
{
LCD_3();
digitalWrite(tank_pump,LOW);
digitalWrite(watering_pump,HIGH);
 sms1();
 sms2();
delay(500);
}
else if (distance_percent<65 &&moist_percent>85)
{
LCD_2();
digitalWrite(tank_pump,HIGH);
digitalWrite(watering_pump,LOW);
sms3();
sms();
delay(500);
}
else if (distance_percent>65 &&moist_percent>85)
{

LCD_4();
digitalWrite(tank_pump,LOW);
digitalWrite(watering_pump,LOW);

sms1();
sms();
delay(500);

}

else if (distance_percent<65 &&moist_percent<85)
{
LCD_1();
digitalWrite(tank_pump,HIGH);
digitalWrite(watering_pump,HIGH);
sms3();
sms2();
delay(500);

}
}
if(digitalRead(rain_pin)==1)
{
  digitalWrite(watering_pump,LOW);
  digitalWrite(tank_pump,LOW);
  LCD_5();
  sms4();
  sms();
  sms1();
  delay(500); 
  }
if(digitalRead(motion_pin)==1)
{
    tone(buzzer_pin,1000,500);
    sms6();
    delay(500);
  }
delay(1000);
temp_h();

}
