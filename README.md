# TIVA-C-control-systems-working-with-LCD-Keypad-sensor-and-motor

------------------

Research and Design:
-The TIVA C port pins
-Determine best port pins for interfacing to a sensor and the motor.
-Rewrite the C program for the control system as per the requirements below.
-Research your given sensor and SET UP A TEST EXPERIMENT TO TEST THE SENSOR ALONE.  Record all information about the testing of the sensor in your lab book and include how this information will be used in the program on the TIVA C EVB in your write ups.
-Research the MOTOR DRIVER IC you chose for the MOTOR CONTROL and DESIGN A CIRCUIT (draw this in your lab book).  Record all the information of the research in your lab book.
-  You MUST use the test template for the final testing of your control system.
Your control systems must have a working LCD, a key pad, the TIVA C EVB, a working interface to the sensor, a motor drive circuit and stepper motor along with a specific menu which have the following requirements:
-Must be a 2-line display
-Must have an introductory screen that says: 
o“<your name>’s solar control”
o“May 23, 2018”
-The introductory screen described above, is shown for no less than 2 seconds then the following screen appears over the two lines:
o“Main Menu”
o“Select: 1) Light state   2) Panel Pos. 3) End”
If user presses ‘1’, show the information from the sensor in the following format:  “ There is <sensor output>%of light: ”; wait for 2 seconds then return to the Main Menu display
If user presses ‘2’ output the sub-menu:
“1) 40 degrees   2) 90 degrees 3) 180 degrees”
oMove motor to the position on the printed protractor as per user selection and then return to Main Menu display 
If user presses ’3’ terminate the program and re-display the opening screen
oAll displays on the LCD must be neat and LEFT JUSTIFIED
 
