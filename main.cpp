
#include <Arduino.h>

const int mF  = 0;
const int mB  = 1;
const int stp1 = 3;
const int stp2 = 4;


void setup()
{
  pinMode(mF, OUTPUT);
  pinMode(mB, OUTPUT);
  pinMode(stp1, OUTPUT);
  pinMode(stp2, OUTPUT);
}

void loop()
{ 
  
  int stop1 = digitalRead(stp1);
  int stop2 = digitalRead(stp2); 
      
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
}
