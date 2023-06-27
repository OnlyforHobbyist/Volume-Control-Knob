#include "HID-Project.h"

#define sw1 2
#define sw2 3
#define sw3 4
#define sw4 5
#define sw5 8
#define A1 7
#define B1 6
#define A2 10
#define B2 9

#define switch1 digitalRead(sw1)
#define switch2 digitalRead(sw2)
#define switch3 digitalRead(sw3)
#define switch4 digitalRead(sw4)
#define switch5 digitalRead(sw5)
#define pinA1 digitalRead(A1)
#define pinB1 digitalRead(B1)
#define pinA2 digitalRead(A2)
#define pinB2 digitalRead(B2)

int currentstateclk1, previousstateclk1;
int currentstateclk2, previousstateclk2;

void setup() {
  // put your setup code here, to run once:
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);
  pinMode(sw4, INPUT_PULLUP);
  pinMode(sw5, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(B1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(B2, INPUT_PULLUP);

  Consumer.begin();

  previousstateclk1 = pinA1;
  previousstateclk2 = pinA2;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(switch1 == LOW && switch2 == HIGH && switch3 == HIGH && switch4 == HIGH && switch5 == HIGH)
  {//previous
    Consumer.write(MEDIA_PREV);
    delay(300);
  }
  else if(switch1 == HIGH && switch2 == LOW && switch3 == HIGH && switch4 == HIGH && switch5 == HIGH)
  {//play/pause
    Consumer.write(MEDIA_PLAY_PAUSE);
    delay(300);
  }
  else if(switch1 == HIGH && switch2 == HIGH && switch3 == LOW && switch4 == HIGH && switch5 == HIGH)
  {//next
    Consumer.write(MEDIA_NEXT);
    delay(300);
  }
  else if(switch1 == HIGH && switch2 == HIGH && switch3 == HIGH && switch4 == LOW && switch5 == HIGH)
  {//mute
    Consumer.write(MEDIA_VOLUME_MUTE);
    delay(300);
  }
  else if(switch1 == HIGH && switch2 == HIGH && switch3 == HIGH && switch4 == HIGH && switch5 == LOW)
  {//stop
    Consumer.write(MEDIA_STOP);
    delay(300);
  }

  currentstateclk1 = pinA1;
  if(currentstateclk1 != previousstateclk1)
  {
    if(pinB1 != currentstateclk1)
    {
      Consumer.write(MEDIA_VOLUME_UP);
    }
    else
    {
      Consumer.write(MEDIA_VOLUME_DOWN);
    }
  }
  previousstateclk1 = currentstateclk1;
  
  currentstateclk2 = pinA2;
  if(currentstateclk2 != previousstateclk2)
  {
    if(pinB2 != currentstateclk2)
    {
      Consumer.write(CONSUMER_BRIGHTNESS_UP);
    }
    else
    {
      Consumer.write(CONSUMER_BRIGHTNESS_DOWN);
    }
  }
  previousstateclk2 = currentstateclk2;
}
