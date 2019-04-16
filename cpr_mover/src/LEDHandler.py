#!/usr/bin/env python

import rospy
from std_msgs.msg import Float64
from std_msgs.msg import String
LEDState = [0, 0, 0, 0]

def securityBreach(data):
    rospy.loginfo(data.data)
        if(data.data < 75 ):
            LEDState[3] = 1
        else:
            LEDState[3] = 0

    rospy.loginfo("Published: " + "".join(str(x) for x in LEDState))
    publisher.publish("".join(str(x) for x in LEDState))

def receivingInformation():
    global publisher

    rospy.init_node('LEDHandler')
    publisher = rospy.Publisher('LED', String, queue_size = 10)
    rospy.Subscriber('/ultrasound1', Float64, securityBreach)
    rospy.Subscriber('/ultrasound2', Float64, securityBreach)
    rospy.Subscriber('/ultrasound3', Float64, securityBreach)
    rospy.Subscriber('/ultrasound4', Float64, securityBreach)
    rospy.Subscriber('/ultrasound5', Float64, securityBreach)
    rospy.Subscriber('/ultrasound6', Float64, securityBreach)
    rospy.Subscriber('/ultrasound7', Float64, securityBreach)
    rospy.spin()

if __name__ == '__main__':
    receivingInformation()
