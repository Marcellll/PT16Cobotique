#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;

int pinLEDGV = 13;
int pinLEDGR = 12;
int pinLEDPV = 11;
int pinLEDPR = 10;
int pinStartUltrasound = 2;
String LEDGV;
String LEDGR;
String LEDPV;
String LEDPR;

void changingLEDState(const std_msgs::String& ledOrder){
  LEDGV = ledOrder.data[0];
  LEDGR = ledOrder.data[1];
  LEDPV = ledOrder.data[2];
  LEDPR = ledOrder.data[3];

  if(LEDGV.equals("1")){
    digitalWrite(pinLEDGV, HIGH);
  } else if(LEDGV.equals("0")){
    digitalWrite(pinLEDGV, LOW);
  }

  if(LEDGR.equals("1")){
    digitalWrite(pinLEDGR, HIGH);
  } else if(LEDGR.equals("0")){
    digitalWrite(pinLEDGR, LOW);
  }

  if(LEDPV.equals("1")){
    digitalWrite(pinLEDPV, HIGH);
  } else if(LEDPV.equals("0")){
    digitalWrite(pinLEDPV, LOW);
  }

  if(LEDPR.equals("1")){
    digitalWrite(pinLEDPR, HIGH);
  } else if(LEDPR.equals("0")){
    digitalWrite(pinLEDPR, LOW);
  }
}

ros::Subscriber<std_msgs::String> sub("LED", &changingLEDState );

void setup() {
  nh.initNode();
  nh.subscribe(sub);
  pinMode(pinLEDGV, OUTPUT);
  pinMode(pinLEDGR, OUTPUT);
  pinMode(pinLEDPV, OUTPUT);
  pinMode(pinLEDPR, OUTPUT);
}

void loop() {
  nh.spinOnce();
  delay(100);
}
