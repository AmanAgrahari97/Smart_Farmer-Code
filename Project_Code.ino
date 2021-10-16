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
