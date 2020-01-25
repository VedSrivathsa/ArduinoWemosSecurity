#include <ESP8266WiFi.h>

#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>

int pirPin = D3;
int ledPin = D4;

char auth[] = "Auth ID";
char ssid[] = "Network Name";
char pass[] = "Network Password";

BlynkTimer timer;

void setup()
{  
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  Blynk.run();
  int motion = digitalRead(pirPin);

  if(motion == HIGH)
  {
    digitalWrite(ledPin, HIGH);
    Blynk.notify("Motion detected! Keep your belongings safe");
    delay(1000);
  }

  else if(motion == LOW)
  {
    digitalWrite(ledPin, LOW);
    delay(1000);
  }

  Blynk.virtualWrite(V5, motion);
}
