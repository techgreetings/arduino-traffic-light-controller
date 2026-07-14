
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd_1(32,16,2);

int greenLights = 10;
int yellowLights= 2;

// downward signals
int d_green = 2;
int d_yellow = 3;
int d_red = 4;
// upward signals
int u_green = 5;
int u_yellow = 6;
int u_red = 7;
// leftward signals
int l_red = 8;
int l_yellow = 9;
int l_green = 10;
// wrightward signals
int w_red = 11;
int w_yellow = 12;
int w_green = 13;

void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(50); //by default it is taking around 1second but now it will takes 50 milliseconds
  //lcd implementation
  lcd_1.init();
  lcd_1.setCursor(0,0);
  lcd_1.backlight();
  lcd_1.display();
  
  //led pins implementation
  // downward pins
  pinMode(d_green, OUTPUT);
  pinMode(d_yellow, OUTPUT);
  pinMode(d_red, OUTPUT);
  // upward pins
  pinMode(u_green, OUTPUT);
  pinMode(u_yellow, OUTPUT);
  pinMode(u_red, OUTPUT);
  //leftward signals
  pinMode(l_green, OUTPUT);
  pinMode(l_yellow, OUTPUT);
  pinMode(l_red, OUTPUT);
  //wrightward signals
  pinMode(w_green, OUTPUT);
  pinMode(w_yellow, OUTPUT);
  pinMode(w_red, OUTPUT);
}

void loop()
{
  inputLights();
  changeLights();
}
void inputLights(){
  if(Serial.available()> 0 ){
  Serial.print("Green: ");
  greenLights = Serial.parseInt();
  Serial.println(greenLights);
  Serial.print("Yellow: ");    
  yellowLights= Serial.parseInt(); 
  Serial.println(yellowLights);
  }
}
void changeLights()
{
  //first part of cycle
  //Upper green light ON and others yellow light OFF

  digitalWrite(u_yellow,LOW);
  digitalWrite(u_red, LOW);
  digitalWrite(u_green,HIGH);
  
  digitalWrite(d_red,HIGH);
  digitalWrite(l_red,HIGH);
  digitalWrite(w_red,HIGH);
 
  
  //lcd implementation
  lcd_1.clear();
  lcd_1.setCursor(0,0);
  lcd_1.print("First road: GO");
  
  unsigned long startTime = millis();
  int lastShown = -1;

  while ((millis() - startTime) / 1000 < (unsigned long)greenLights) {
    int secondsLeft = greenLights - (millis() - startTime) / 1000;

    if (secondsLeft != lastShown) {
        char buf[17];
        sprintf(buf, "%2d sec left    ", secondsLeft);
        lcd_1.setCursor(0,1);
        lcd_1.print(buf);
        lastShown = secondsLeft;
    }

    if (secondsLeft <= yellowLights) {
        digitalWrite(w_yellow, HIGH);
        digitalWrite(w_red, HIGH);
    }

    inputLights();
}
  
 
  //-----------------------------------------------------------
  //Wrightward Yellow turns ON.
  digitalWrite(d_yellow,LOW);
  digitalWrite(u_yellow,LOW);
  digitalWrite(l_yellow,LOW);
  
  
  digitalWrite(d_red,HIGH);
  digitalWrite(l_red,HIGH);

  digitalWrite(u_red,LOW);
  
  digitalWrite(u_green,HIGH);  

  //Second part of cycle
  //Rightward green light ON and others light tunrn OFF.
  digitalWrite(d_yellow,LOW);
  digitalWrite(u_yellow,LOW);
  digitalWrite(l_yellow,LOW);
  digitalWrite(w_yellow,LOW);
  
  digitalWrite(w_green,HIGH);
  
  digitalWrite(d_red,HIGH);
  digitalWrite(l_red,HIGH);
  digitalWrite(u_red,HIGH);
  
  digitalWrite(w_red,LOW);
  
  digitalWrite(u_green,LOW);
  
  //lcd implementation
  lcd_1.clear();
  lcd_1.setCursor(0,0);
  lcd_1.print("Second road: GO");
  
  startTime = millis();
  lastShown = -1;

  while ((millis() - startTime) / 1000 < (unsigned long)greenLights) {
    int secondsLeft = greenLights - (millis() - startTime) / 1000;

    if (secondsLeft != lastShown) {
        char buf[17];
        sprintf(buf, "%2d sec left    ", secondsLeft);
        lcd_1.setCursor(0,1);
        lcd_1.print(buf);
        lastShown = secondsLeft;
    }

    if (secondsLeft <= yellowLights) {
    digitalWrite(d_yellow, HIGH);
    digitalWrite(d_red, HIGH);
}

    inputLights();
}
  
 
  //---------------------------------------------------------------
  //downward Yellow light turn ON.

  digitalWrite(u_yellow,LOW);
  digitalWrite(l_yellow,LOW);
  digitalWrite(w_yellow,LOW);
  
  digitalWrite(l_red,HIGH);
  digitalWrite(w_red,LOW);
  digitalWrite(u_red,HIGH);
  
  digitalWrite(u_green,LOW);
  digitalWrite(w_green,HIGH);
  
  //Third part of cycle
  //Downward green light ON and others light tunrn OFF.
  digitalWrite(d_yellow,LOW);
  digitalWrite(u_yellow,LOW);
  digitalWrite(l_yellow,LOW);
  digitalWrite(w_yellow,LOW);
  
  digitalWrite(d_green,HIGH);
  
  digitalWrite(u_red,HIGH);
  digitalWrite(l_red,HIGH);
  digitalWrite(w_red,HIGH);
  
  digitalWrite(d_red,LOW);
  
  digitalWrite(u_green,LOW);
  digitalWrite(w_green,LOW);
  
  //lcd implementation
  lcd_1.clear();
  lcd_1.setCursor(0,0);
  lcd_1.print("Third road: GO");
    
  startTime = millis();
  lastShown = -1;

  while ((millis() - startTime) / 1000 < (unsigned long)greenLights) {
    int secondsLeft = greenLights - (millis() - startTime) / 1000;

    if (secondsLeft != lastShown) {
        char buf[17];
        sprintf(buf, "%2d sec left    ", secondsLeft);
        lcd_1.setCursor(0,1);
        lcd_1.print(buf);
        lastShown = secondsLeft;
    }

    if (secondsLeft <= yellowLights) {
     digitalWrite(l_yellow, HIGH);
     digitalWrite(l_red, HIGH);
     }

    inputLights();
}
  
 
  //---------------------------------------
  //Left yellow light turn ON.
  digitalWrite(d_yellow,LOW);
  digitalWrite(u_yellow,LOW);
  digitalWrite(w_yellow,LOW);
  
  digitalWrite(d_red,LOW);
  digitalWrite(w_red,HIGH);
  digitalWrite(u_red,HIGH);
  
  digitalWrite(u_green,LOW);
  digitalWrite(w_green,LOW);
  digitalWrite(d_green,HIGH);
  
  //Fourth part of cycle
  //Downward green light ON and others light tunrn OFF.
  digitalWrite(d_yellow,LOW);
  digitalWrite(u_yellow,LOW);
  digitalWrite(l_yellow,LOW);
  digitalWrite(w_yellow,LOW);
  
  digitalWrite(l_green,HIGH);
  
  digitalWrite(u_red,HIGH);
  digitalWrite(d_red,HIGH);
  digitalWrite(w_red,HIGH);
  
  digitalWrite(l_red,LOW);
  
  digitalWrite(u_green,LOW);
  digitalWrite(w_green,LOW);
  digitalWrite(d_green,LOW);
  
  //lcd implementation
  lcd_1.clear();
  lcd_1.setCursor(0,0);
  lcd_1.print("Fourth road: GO");
    
  startTime = millis();
  lastShown = -1;

  while ((millis() - startTime) / 1000 < (unsigned long)greenLights) {
    int secondsLeft = greenLights - (millis() - startTime) / 1000;

    if (secondsLeft != lastShown) {
        char buf[17];
        sprintf(buf, "%2d sec left    ", secondsLeft);
        lcd_1.setCursor(0,1);
        lcd_1.print(buf);
        lastShown = secondsLeft;
    }

   if (secondsLeft <= yellowLights) {
     digitalWrite(u_yellow, HIGH);
     digitalWrite(u_red, HIGH);
    }

    inputLights();
}
  
 
  //----------------------------------------
    
  //Left green,yellow and red turned OFF.
  digitalWrite(l_green,LOW);
  digitalWrite(l_yellow,LOW);
  digitalWrite(l_red,LOW);
  
}