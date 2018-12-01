#ifndef SUMOCONTROLLER_H
#define SUMOCONTROLLER_H
#include "Arduino.h"
#include "ScrapDefinitions.h"
#include "ScrapController.h"

class ScrapMotorDualPWM: public ScrapMotorInterface {
	protected:
		int PIN_PWM1;
		int PIN_PWM2;
		virtual void initMotor();
	public:
		ScrapMotorDualPWM(int PinPWM1, int PinPWM2, int dirMultip = 1);
		virtual void setMotor(int pwm);
		virtual void setDirection(int pwm);
		virtual void setDirectionMultiplier(int multi);
		virtual void setPower(int pwm);
		virtual void incrementPower(int val = 1) { setPower(currDir+val); };
		virtual void decrementPower(int val = 1) { setPower(currDir-val); };
		virtual int getDirection();
		virtual int getPower();
		virtual void stop();
};


class SumoWedge {
	private:
		int SWITCH_LEFT;
		int SWITCH_RIGHT;
	public:
		SumoWedge(int SwitchL, int SwitchR) { SWITCH_LEFT = SwitchL; SWITCH_RIGHT = SwitchR; initWedge(); };
		void initWedge() { pinMode(SWITCH_LEFT,INPUT); pinMode(SWITCH_RIGHT,INPUT); };
		bool getPressedState() { return digitalRead(SWITCH_LEFT) || digitalRead(SWITCH_RIGHT); }; 
};

#endif