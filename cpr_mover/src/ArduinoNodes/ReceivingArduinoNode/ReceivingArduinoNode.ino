/*
 * rosserial
 * Receiving arduino which sends out 6 distance values
 */

#include <ros.h>
#include <std_msgs/Float64.h>

ros::NodeHandle  nh;

std_msgs::Float64 distanceUltrasound1;
std_msgs::Float64 distanceUltrasound2;
std_msgs::Float64 distanceUltrasound3;
std_msgs::Float64 distanceUltrasound4;
std_msgs::Float64 distanceUltrasound5;
std_msgs::Float64 distanceUltrasound6;
std_msgs::Float64 distanceUltrasound7;

ros::Publisher ultrasoundOne("ultrasound1", &distanceUltrasound1);
ros::Publisher ultrasoundTwo("ultrasound2", &distanceUltrasound2);
ros::Publisher ultrasoundThree("ultrasound3", &distanceUltrasound3);
ros::Publisher ultrasoundFour("ultrasound4", &distanceUltrasound4);
ros::Publisher ultrasoundFive("ultrasound5", &distanceUltrasound5);
ros::Publisher ultrasoundSix("ultrasound6", &distanceUltrasound6);
ros::Publisher ultrasoundSeven("ultrasound7", &distanceUltrasound7);

const int TrigPin1 = 30;
const int EchoPin1 = 31;
const int TrigPin2 = 34;
const int EchoPin2 = 35;
const int TrigPin3 = 38;
const int EchoPin3 = 39;
const int TrigPin4 = 42;
const int EchoPin4 = 43;
const int TrigPin5 = 46;
const int EchoPin5 = 47;
const int TrigPin6 = 50;
const int EchoPin6 = 51;
const int TrigPin7 = 22;
const int EchoPin7 = 23;

long duration;
int distance;

void setup()
{
  nh.initNode();
  nh.advertise(ultrasoundOne);
  nh.advertise(ultrasoundTwo);
  nh.advertise(ultrasoundThree);
  nh.advertise(ultrasoundFour);
  nh.advertise(ultrasoundFive);
  nh.advertise(ultrasoundSix);
  nh.advertise(ultrasoundSeven);

  pinMode(TrigPin1, OUTPUT);
  pinMode(EchoPin1, INPUT);
  pinMode(TrigPin2, OUTPUT);
  pinMode(EchoPin2, INPUT);
  pinMode(TrigPin3, OUTPUT);
  pinMode(EchoPin3, INPUT);
  pinMode(TrigPin4, OUTPUT);
  pinMode(EchoPin4, INPUT);
  pinMode(TrigPin5, OUTPUT);
  pinMode(EchoPin5, INPUT);
  pinMode(TrigPin6, OUTPUT);
  pinMode(EchoPin6, INPUT);
  pinMode(TrigPin7, OUTPUT);
  pinMode(EchoPin7, INPUT);
}

void loop(){
  distanceUltrasound1.data = distanceCapteurUltraSon(TrigPin1, EchoPin1);
  distanceUltrasound2.data = distanceCapteurUltraSon(TrigPin2, EchoPin2);
  distanceUltrasound3.data = distanceCapteurUltraSon(TrigPin3, EchoPin3);
  distanceUltrasound4.data = distanceCapteurUltraSon(TrigPin4, EchoPin4);
  distanceUltrasound5.data = distanceCapteurUltraSon(TrigPin5, EchoPin5);
  distanceUltrasound6.data = distanceCapteurUltraSon(TrigPin6, EchoPin6);
  distanceUltrasound7.data = distanceCapteurUltraSon(TrigPin7, EchoPin7);
  
  ultrasoundOne.publish( &distanceUltrasound1 );
  ultrasoundTwo.publish( &distanceUltrasound2 );
  ultrasoundThree.publish( &distanceUltrasound3 );
  ultrasoundFour.publish( &distanceUltrasound4 );
  ultrasoundFive.publish( &distanceUltrasound5 );
  ultrasoundSix.publish( &distanceUltrasound6 );
  ultrasoundSeven.publish( &distanceUltrasound7 );
  nh.spinOnce();
  delay(2);
}

int distanceCapteurUltraSon(int TrigPin, int EchoPin){
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  duration = pulseIn(EchoPin, HIGH);
  distance = duration * 0.034/2;

  return distance;
}
