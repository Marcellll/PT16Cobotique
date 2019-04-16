#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def sendingInformation():
    publisher = rospy.Publisher('LED', String, queue_size = 10)
    rospy.init_node('sendingInformationToArduino', anonymous = True)
    state = rospy.get_param('~state')
    #rospy.loginfo('Got parameter %s', state)
    publisher.publish(str(state))

if __name__ == '__main__':
    sendingInformation()
