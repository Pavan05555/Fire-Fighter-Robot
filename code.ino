#include <Servo.h>

#define servo1 8
Servo motor;

int Br=A1;//Straight
int Bl=A0;//Right
int G=A2;//Left

int ena=2;
int motor1pin1 = 3;
int motor1pin2 = 4;
int motor2pin1 = 5;
int motor2pin2 = 6;
int enb=7;

int water=10;

void setup()
{
  Serial.begin(9600);
  
  motor.attach(servo1); 

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(Br,INPUT);
  pinMode(Bl,INPUT);
  pinMode(G,INPUT);
  pinMode(water,OUTPUT);
}

void loop(){
analogWrite(ena, 200);
analogWrite(enb, 200);

int brvalue=analogRead(Br);
int blvalue;
int Gvalue=analogRead(G);
blvalue=analogRead(Bl);
int i;
int j;

Serial.print("Bl");
Serial.println(blvalue);
Serial.print("Br");
Serial.println(brvalue);
Serial.print("G");
Serial.println(Gvalue);
delay(1000);

if(brvalue<150)
{
    moveforward();
    delay(2000);
    stop();
    digitalWrite(water,HIGH);
    for(i=1;i<180;i++)
    {
      motor.write(i);
      delay(10);
    }
        for(i=180;i>=0;i--)
    {
      motor.write(i);
      delay(10);
    }
}

else if(blvalue<150)
{
  turnleft();
  delay(3000);
  stop();
  digitalWrite(water,HIGH);
      for(i=1;i<180;i++)
    {
      motor.write(i);
      delay(10);
    }
        for(i=180;i>=0;i--)
    {
      motor.write(i);
      delay(10);
    }
}
else if(Gvalue<150)
{ 
  turnright();
  delay(3000);
  stop();
  digitalWrite(water,HIGH);
      for(i=1;i<180;i++)
    {
      motor.write(i);
      delay(10);
    }
        for(i=180;i>=0;i--)
    {
      motor.write(i);
      delay(10);
    }
}
else
{
  stop();
}
}

void turnleft(){
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}

void turnright(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}

void movebackward(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}

void moveforward(){
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}

void stop(){
  analogWrite(ena, 0);
  analogWrite(ena, 0);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}
