#include <Adafruit_LiquidCrystal.h>
#include <Servo.h>
//#include "rgb_lcd.h"

// Variáveis do switch
bool flag_array[5] = {0, 0, 0, 0, 0};
int switch_array[5] = {2, 3, 4, 5, 6};

// Permutação de pinos
int permut[5] = {-1, -1, -1, -1, -1};
int value;
int pos = 0;
int aux = 0;

// Potenciometro
int potpin = A0;
int potval = 0;

// Servo motor
int servopin = 7;
Servo servo_motor;
int servo_pos = 0;

// Variáveis de jogo
int dist = 5;
int num_lock_pick = 5;

// Variáveis de tempo
int time_pressed = 0;
int current_time = 0;

// Variáveis de estado
bool is_pressed = false;
bool retry = false;

// LCD
int seconds = 0;
// LCD rgb_lcd.h
// rgb_lcd lcd_1;
// LCD Adafruit_LiquidCrystal.h
Adafruit_LiquidCrystal lcd_1(0);

void setup(){
  Serial.begin(9600);
  servo_motor.write(servo_pos);
  
  for(int i = 0; i < 5; i++){
  	pinMode(switch_array[i], INPUT_PULLUP);
  }
  pinMode(potpin, INPUT);
  
  randomSeed(analogRead(A1));
  for(int i = 0; i < 5; i++){
  	value = random(5);
    
    int j = 0;
    while(j < 5){
      if(value == permut[j]){
      	j = 0;
        value = random(5);
      } else {
      	j++;
      }
    }
    
    permut[i] = value;
  }

  servo_motor.attach(servopin);
  lcd_1.begin(16, 2);
}

void loop(){
  lcd_1.setCursor(0, 0);
  lcd_1.print("G: " + String(num_lock_pick) + " P: " + String(pos));
  
  for(int i = 0; i < 5; i++){
  	if(digitalRead(switch_array[i]) == 1 && !flag_array[i]){
   	  aux = i;
      flag_array[i] = true;
    }
  }
  
  for(int i = 0; i < 5; i++){	
    if(digitalRead(switch_array[i]) != 1){
      flag_array[i] = false;
    }
  }
  
  dist = abs(permut[pos] - aux);
  
  potval = analogRead(potpin) / 100;
  
  if(pos >= 5){
  	servo_pos = 90;
  }
  
  servo_motor.write(servo_pos);

  if(num_lock_pick >= 0){
    if(potval >= 1 && dist <= 4){
      if(!is_pressed){
        time_pressed = millis();
        is_pressed = true;
      }
      current_time = millis() - time_pressed;
      lcd_1.setCursor(0, 1);
      lcd_1.print("###");
      
      if(current_time > 5000 && !retry && dist != 0){
        num_lock_pick--;
        pos = 0;
        retry = true;
      }
    }else{
      time_pressed = 0;
      current_time = 0;
      
      retry = false;
      is_pressed = false;
      
      lcd_1.setCursor(0, 1);
      lcd_1.print("   ");
    }
    
    if(potval >= 3 && dist <= 3){
      lcd_1.setCursor(3, 1);
      lcd_1.print("###");
      
      if(current_time > 4000 && !retry && dist != 0){
        num_lock_pick--;
        pos = 0;
        retry = true;
      }
    } else {
      lcd_1.setCursor(3, 1);
      lcd_1.print("   ");
    }
    
    if(potval >= 6 && dist <= 2){
      lcd_1.setCursor(6, 1);
      lcd_1.print("###");
      
      if(current_time > 3000 && !retry && dist != 0){
        num_lock_pick--;
        pos = 0;
        retry = true;
      }
    } else {
      lcd_1.setCursor(6, 1);
      lcd_1.print("   ");
    }
    
    if(potval >= 9 && dist <= 1){
      lcd_1.setCursor(9, 1);
      lcd_1.print("###");
      
      if(current_time > 2000 && !retry && dist != 0){
        num_lock_pick--;
        pos = 0;
        retry = true;
      }
    } else {
      lcd_1.setCursor(9, 1);
      lcd_1.print("   ");
    }
    
    if(potval >= 10 && dist == 0){
      lcd_1.setCursor(12, 1);
      lcd_1.print("####");
      pos++;
      retry = true;
    } else {
      lcd_1.setCursor(12, 1);
      lcd_1.print("    ");
    }
  }
  
  /*Serial.print(digitalRead(switch_array[0]));
  Serial.print(digitalRead(switch_array[1]));
  Serial.print(digitalRead(switch_array[2]));
  Serial.print(digitalRead(switch_array[3]));
  Serial.print(digitalRead(switch_array[4]));
  
  Serial.print(" ");
  
  Serial.print(flag_array[0]);
  Serial.print(flag_array[1]);
  Serial.print(flag_array[2]);
  Serial.print(flag_array[3]);
  Serial.print(flag_array[4]);
  
  Serial.print(" ");
  
  Serial.print(permut[0]);
  Serial.print(permut[1]);
  Serial.print(permut[2]);
  Serial.print(permut[3]);
  Serial.print(permut[4]);
  
  Serial.print(" aux: ");
  
  Serial.print(aux);
  
  Serial.print(" dist: ");
  
  Serial.print(dist);
  
  Serial.print(" pos: ");
  
  Serial.print(pos);
  
  Serial.print(" nlp: ");
  
  Serial.print(num_lock_pick);
  
  Serial.println();*/
  
}
