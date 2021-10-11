#include "Engines.hpp"

#include "../Devices/Timer.hpp"
#include "../Devices/PwmGenerator.hpp"

namespace Program
{


Engines::Engines() {
	Timer::getInstance().on_timeout_handler_ = [this]{
			stopEngines();
	};
	Timer::getInstance().setTimeout(20);
}

void Engines::setLeftEngineDriveForward()
{
	GpioDevice<GPIO::B , 0>::setHigh();
	GpioDevice<GPIO::B , 1>::setLow();
}

void Engines::setLeftEngineDriveBackwards()
{
	GpioDevice<GPIO::B , 0>::setLow();
	GpioDevice<GPIO::B , 1>::setHigh();
}

void Engines::setRightEngineDriveForward()
{
	GpioDevice<GPIO::C , 0>::setHigh();
	GpioDevice<GPIO::C , 1>::setLow();
}

void Engines::setRightEngineDriveBackwards()
{
	GpioDevice<GPIO::C , 0>::setLow();
	GpioDevice<GPIO::C , 1>::setHigh();
}

void Engines::runEngines()
{
	PwmGenerator::getInstance().setPwmSignalFilling(999);
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
