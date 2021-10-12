#include "Engines.hpp"

#include "../Devices/Timer.hpp"
#include "../Devices/PwmGenerator.hpp"

namespace Program
{


Engines::Engines() {
	Timer::getInstance().on_timeout_handler_ = [this]{
			stopEngines();
	};
//	Timer::getInstance().setTimeout(990);
}

void Engines::setLeftEngineDriveForward()
{
	GpioDevice<PORT::B , GPIO_PIN_0>::setHigh();
	GpioDevice<PORT::B , GPIO_PIN_1>::setLow();
}

void Engines::setLeftEngineDriveBackwards()
{
	GpioDevice<PORT::B , GPIO_PIN_0>::setLow();
	GpioDevice<PORT::B , GPIO_PIN_1>::setHigh();
}

void Engines::setRightEngineDriveForward()
{
	GpioDevice<PORT::C , GPIO_PIN_0>::setHigh();
	GpioDevice<PORT::C , GPIO_PIN_1>::setLow();
}

void Engines::setRightEngineDriveBackwards()
{
	GpioDevice<PORT::C , GPIO_PIN_0>::setLow();
	GpioDevice<PORT::C , GPIO_PIN_1>::setHigh();
}

void Engines::runEngines()
{
	PwmGenerator::getInstance().setPwmSignalFilling(999);
	Timer::getInstance().startTimer();
}

void Engines::stopEngines()
{
	PwmGenerator::getInstance().setPwmSignalFilling(0);
}

void Engines::driveForward()
{
	setLeftEngineDriveForward();
	setRightEngineDriveForward();
	runEngines();
}

void Engines::driveBackwards()
{
	setLeftEngineDriveBackwards();
	setRightEngineDriveBackwards();
	runEngines();
}

void Engines::turnLeft()
{
	setLeftEngineDriveForward();
	setRightEngineDriveBackwards();
	runEngines();
}

void Engines::turnRight()
{
	setRightEngineDriveBackwards();
	setLeftEngineDriveForward();
	runEngines();
}

}
