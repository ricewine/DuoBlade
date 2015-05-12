#define CW true
#define CC false

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

//constructor
StepperMotor::StepperMotor(int MotorNumber, int nMicroSteps){
	switch (MotorNumber){
		case 1 : 
		DIR   = 53;
		STEP  = 51;
		SLEEP = 49;
		RESET = 47;
		MS3   = 45;
		MS2   = 43;
		MS1   = 41;
		ENABLE= 39;
		break;

		case 2 : 
		DIR   = 36;
		STEP  = 34;
		SLEEP = 32;
		RESET = 30;
		MS3   = 28;
		MS2   = 26;
		MS1   = 24;
		ENABLE= 22;
		break; 

		default : 
		DIR   = 53;
		STEP  = 51;
		SLEEP = 49;
		RESET = 47;
		MS3   = 45;
		MS2   = 43;
		MS1   = 41;
		ENABLE= 39;
	}
	setPinMode();
	setMicroStep(nMicroSteps);
	sleep(false);
	reset(false);
	enable(true);
}

//destructor
StepperMotor::~StepperMotor(){
	enable(false);
}

//set pins to OUTPUT
void StepperMotor::setPinMode(){
	pinMode(DIR, OUTPUT);
	pinMode(STEP, OUTPUT);
	pinMode(SLEEP, OUTPUT);
	pinMode(RESET, OUTPUT);
	pinMode(MS3, OUTPUT);
	pinMode(MS2, OUTPUT);
	pinMode(MS1, OUTPUT);
	pinMode(ENABLE, OUTPUT);
}

 /**************  stepping with or without direction indicated ***********/
void StepperMotor::step(bool direct, int nSteps, int delayTime){
	if (direct){
		digitalWrite(DIR, LOW);
	}else{
		digitalWrite(DIR, HIGH);
	}  
	for(int i=0; i< nSteps; i++){
		digitalWrite(STEP, HIGH);
		delayMicroseconds(1);
		digitalWrite(STEP, LOW);
		delayMicroseconds(delayTime);
	}
}

void StepperMotor::step(int nSteps, int delayTime){
	for(int i=0; i< nSteps; i++){
		digitalWrite(STEP, HIGH);
		delayMicroseconds(1);
		digitalWrite(STEP, LOW);
		delayMicroseconds(delayTime);
	}
}

/******* sleep function of motor *******/
//SLEEP is on when low 
void StepperMotor::sleep(bool slp){ 
	if (slp){
		digitalWrite(SLEEP, LOW);
	}else{
		digitalWrite(SLEEP, HIGH);
	}  
}

/*************** reset motor ************/
//RESET is on when low
void StepperMotor::reset(bool rst){
	if (rst){
		digitalWrite(RESET, LOW);
	}else{
		digitalWrite(RESET, HIGH);
	}  
}

void StepperMotor::enable(bool enb)
{
	if (enb){
		digitalWrite(ENABLE, LOW);
	}else{
		digitalWrite(ENABLE, HIGH);
	}  
}

/******** set microstep size ************/
void StepperMotor::setMicroStep(int nMicroSteps){
	switch(nMicroSteps){
		case 1:
		digitalWrite(MS1, LOW);
		digitalWrite(MS2, LOW);
		digitalWrite(MS3, LOW);
		break;
		
		case 2:
		digitalWrite(MS1, HIGH);
		digitalWrite(MS2, LOW);
		digitalWrite(MS3, LOW);
		break;
		
		case 4:
		digitalWrite(MS1, LOW);
		digitalWrite(MS2, HIGH);
		digitalWrite(MS3, LOW);
		break;
		
		case 8:
		digitalWrite(MS1, HIGH);
		digitalWrite(MS2, HIGH);
		digitalWrite(MS3, LOW);
		break;
		
		case 16:
		digitalWrite(MS1, HIGH);
		digitalWrite(MS2, HIGH);
		digitalWrite(MS3, HIGH);
		break;
		
		default:
		digitalWrite(MS1, LOW);
		digitalWrite(MS2, LOW);
		digitalWrite(MS3, LOW);
	}
}

/***************** constructing ****************/
StepperMotor Motor1(1,2); //construct motor #1, half stepsize 
StepperMotor Motor2(2,2); //construct motor #2, half stepsize

/******** set up ******/
void setup() {
	Serial.begin(9600);

}

void loop() {
	Serial.println("motor 1 CC");
  Motor1.step(CC, 200, 1000); //direction, num of step, delay microsecond
  delay(500);
  Motor2.step(CW, 200, 1000);
  delay(3000);
}