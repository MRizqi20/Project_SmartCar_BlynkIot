#define BLYNK_TEMPLATE_ID "TMPL6u2K-g_oP"
#define BLYNK_TEMPLATE_NAME "Smart Monitoring"
#define BLYNK_AUTH_TOKEN "DoiQ3RBVE7Nws0BCnbDJOVs3h54Z33fL"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth [] = "Token_Auth_Blynk";
char ssid [] = "Nama Wifi";
char pass [] = "Password";

//Motor L298N pin
#define ENA D0
#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4
#define ENB D6

BlynkTimer timer;

void setup() {
  Serial.begin(9600);
  Blynk.begin (auth,ssid,pass);
  pinMode (ENA,OUTPUT);
  pinMode (IN1,OUTPUT);
  pinMode (IN2,OUTPUT);
  pinMode (IN3,OUTPUT);
  pinMode (IN4,OUTPUT);
  pinMode (ENB,OUTPUT);

  timer.setInterval(1000, sendSensor);
}

void loop () {
  Blynk.run();
  timer.run();
}

void sendSensor() {

}

BLYNK_WRITE(V1) {
  int x = param[0].asInt();
  int y = param[1].asInt();

  if (y>50) {
    digitalWrite (IN1, HIGH);
    digitalWrite (IN2,LOW);
    analogWrite (ENA, map(y, 0, 255, 0, 1023));
  }
  else if (y<-50) {
   digitalWrite (IN1, LOW);
   digitalWrite (IN2,HIGH);
   analogWrite (ENA, map(-y, 0, 255, 0, 1023));
  }
  else {
   digitalWrite (IN1, LOW);
   digitalWrite (IN2,LOW);
   analogWrite (ENA,0);
  }
if (x>50) {
    digitalWrite (IN3, HIGH);
    digitalWrite (IN4,LOW);
    analogWrite (ENB, map(x, 0, 255, 0, 1023));
  }
  else if (y<-50) {
   digitalWrite (IN3, LOW);
   digitalWrite (IN4,HIGH);
   analogWrite (ENB, map(-x, 0, 255, 0, 1023));
  }
  else {
   digitalWrite (IN3, LOW);
   digitalWrite (IN4,LOW);
   analogWrite (ENB,0);
  }
  }