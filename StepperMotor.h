/******************************************************************************

FILE
    MODULE.h  -  exported declarations for MODULE.h

*******************************************************************************/


#ifndef STEPPER_MOTOR_H               /* include this file only once         */
#define STEPPER_MOTOR_H

class StepperMotor{
private:
	byte DIR;
	byte STEP;
	byte SLEEP;
	byte RESET;
	byte MS3;
	byte MS2;
	byte MS1;
	byte ENABLE;

public:
    StepperMotor(int MotorNumber, int nMicroSteps); // Constructor
    ~StepperMotor(); // Destructor
    void setPinMode();
    void step(bool direct, int nSteps, int delayTime);
    void step(int nSteps, int delayTime);
    void sleep(bool slp);
    void reset(bool rst);
    void enable(bool enb);
    void setMicroStep(int nMicroSteps);
};

 
#endif 