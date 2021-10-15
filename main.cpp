#include <Arduino.h>

const int mF  = 27;
const int mB  = 26;
const int stp1 = 4;
const int stp2 = 18;
const int ldr = 12;
const int relay = 14;
const unsigned long eventInterval = 600000;
unsigned long previousTime = 0;

void setup()
{
  Serial.begin(112500);

  pinMode(mF, OUTPUT);
  pinMode(mB, OUTPUT);
  pinMode(stp1, OUTPUT);
  pinMode(stp2, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(ldr, INPUT);
}

void loop()
{ 
  unsigned long currentTime = millis();
  int stop1 = digitalRead(stp1);
  int stop2 = digitalRead(stp2); 
  int ldrVal = analogRead(ldr);
      
  if(stop1 == 1)
    {  
      digitalWrite(mF, HIGH);  
    }
  else
    {      
      digitalWrite(mF, LOW);
    } 

  if(stop2 == 1)
    {
      digitalWrite(mB, HIGH);
    }
  else
    {      
      digitalWrite(mB, LOW);   
    }

  if(currentTime - previousTime >= eventInterval)
    { if(ldrVal > 1000)
      {
        digitalWrite(relay, LOW);
        Serial.print("\n It's day time");
      }
      else
      {
        digitalWrite(relay, HIGH);
        Serial.print("\nIt's night time");
      }
      previousTime = currentTime;
    }
}



