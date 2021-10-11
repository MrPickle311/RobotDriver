#pragma once

#include "../Utils/DeviceTraits.hpp"
#include "../Devices/GpioDevice.hpp"

#include <functional>

namespace Program
{


class Engines : public Singleton<Engines>
{
public:
	using ActionHandlerType = std::function<void()>;
	ActionHandlerType turn_engines_on_handler_;
	ActionHandlerType turn_engines_off_handler_;
public:
	Engines();
	virtual ~Engines() = default;
	Engines& operator=(Engines &&other) = delete;
	Engines& operator=(const Engines &other) = delete;
	Engines(Engines &&other) = delete;
	Engines(const Engines &other) = delete;
private:
	void setLeftEngineDriveForward();
	void setLeftEngineDriveBackwards();
	void setRightEngineDriveForward();
	void setRightEngineDriveBackwards();

	void runEngines();
	void stopEngines();
public:
	void driveForward();
	void driveBackwards();
	void turnLeft();
	void turnRight();
};

}
