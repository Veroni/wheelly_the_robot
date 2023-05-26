#!/usr/bin/env python

import RPi.GPIO as GPIO
import time
from pygame import display, joystick, event
from pygame import QUIT, JOYAXISMOTION, JOYBALLMOTION, JOYHATMOTION, JOYBUTTONUP, JOYBUTTONDOWN

# for 1st Motor on ENA
ENA_LEFT = 33
IN1_LEFT = 35
IN2_LEFT = 37
ENA_RIGHT = 31
IN1_RIGHT = 40
IN2_RIGHT = 38

# set pin numbers to the board's
GPIO.setmode(GPIO.BOARD)

# initialize EnA, In1 and In2
GPIO.setup(ENA_LEFT, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(IN1_LEFT, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(IN2_LEFT, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(ENA_RIGHT, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(IN1_RIGHT, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(IN2_RIGHT, GPIO.OUT, initial=GPIO.LOW)


h = {
	(0,0):  'c',
	(1,0):  'E', (1,1):   'NE', (0,1):  'N', (-1,1): 'NW',
	(-1,0): 'W', (-1,-1): 'SW', (0,-1): 'S', (1,-1): 'SE'
}

P = 2 # precision

 # Stop
GPIO.output(ENA_LEFT, GPIO.HIGH)
GPIO.output(IN1_LEFT, GPIO.LOW)
GPIO.output(IN2_LEFT, GPIO.LOW)
GPIO.output(ENA_RIGHT, GPIO.HIGH)
GPIO.output(IN1_RIGHT, GPIO.LOW)
GPIO.output(IN2_RIGHT, GPIO.LOW)


def main(argv=[]):
	display.init()
	joystick.init()

	if len(argv) > 1:
		for sz in argv[1:]:
			try:    joystick.Joystick(int(sz)).init()
			except: pass
	else:
		for i in range(joystick.get_count()):
			joystick.Joystick(i).init()

	e = event.wait()
	while e.type != QUIT:

		if e.type == JOYBUTTONUP:  
                    print('js', e.joy, 'button', e.button, 'up')
                    GPIO.output(IN1_LEFT, GPIO.LOW)
                    GPIO.output(IN2_LEFT, GPIO.LOW)
                    GPIO.output(IN1_RIGHT, GPIO.LOW)
                    GPIO.output(IN2_RIGHT, GPIO.LOW)
		elif e.type == JOYBUTTONDOWN:
                    print('js', e.joy, 'button', e.button, 'down')
                    if e.button==8:
                        print("left Forward")
                        GPIO.output(IN1_LEFT, GPIO.HIGH)
                        GPIO.output(IN2_LEFT, GPIO.LOW)
                    elif e.button==9:
                        print("Right Forward")
                        GPIO.output(IN1_RIGHT, GPIO.HIGH)
                        GPIO.output(IN2_RIGHT, GPIO.LOW)
                    elif e.button==6:
                        print("Left Backward")
                        GPIO.output(IN1_LEFT, GPIO.LOW)
                        GPIO.output(IN2_LEFT, GPIO.HIGH)
                    elif e.button==7:
                        print("Right Backward")
                        GPIO.output(IN1_RIGHT, GPIO.LOW)
                        GPIO.output(IN2_RIGHT, GPIO.HIGH)
		e = event.wait()
    
if __name__ == "__main__":
	from sys import argv
	main(argv)
