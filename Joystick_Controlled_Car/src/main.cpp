#include <Arduino.h>

#define enA 10
#define enB 9

//motors 1 & 2
#define in1 7
#define in2 6
//motors 2 & 3
#define in3 5
#define in4 4


// joystick
#define joyX A0
#define joyY A1
//joystick value
int JvalX = 512;
int JvalY = 512;


void setup()
{
  for (int i=enA; i<=in4; i++)
  {
    pinMode (i, OUTPUT);
  }
}

void loop()
{
  JvalX = analogRead(joyX);
  JvalY = analogRead(joyY);

   Drive();
   Steer();
}

//drive and reverse modes
void Drive()
{
  //forwards
  if (JvalY < 400 )
  {
    digitalWrite (enA, HIGH);
    digitalWrite (enB, HIGH);

    digitalWrite (in1, HIGH );
    digitalWrite (in2, LOW);

    digitalWrite (in3, HIGH);
    digitalWrite (in4, LOW);
  }

  //backwards
  else if (JvalY > 600)
  {
    digitalWrite (enA, HIGH);
    digitalWrite (enB, HIGH);

    digitalWrite (in1, LOW);
    digitalWrite (in2, HIGH);

    digitalWrite (in3, LOW);
    digitalWrite (in4, HIGH);
  }

  else
  {
    digitalWrite (enA, LOW);
    digitalWrite (enB, LOW);
  }
}

//steering
void Steer()
{
  
  //right
  if (JvalX < 350)
  {
    digitalWrite (enA, HIGH);

    digitalWrite (in1, HIGH );
    digitalWrite (in2, LOW);
  }

  //left
  else if (JvalX > 700)
  {
    digitalWrite (enB, HIGH);

    digitalWrite (in3, HIGH );
    digitalWrite (in4, LOW);
  }

  //stopped
  else
  {
    digitalWrite (enA, LOW);
    digitalWrite (enB, LOW);
  }
 
}