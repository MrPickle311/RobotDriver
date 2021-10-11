#pragma once

namespace Program
{

enum class Engine
{
	LeftEngine ,
	RightEngine
};

class Engines {
public:
	Engines();
	virtual ~Engines() = default;
	Engines& operator=(Engines &&other) = delete;
	Engines& operator=(const Engines &other) = delete;
	Engines(Engines &&other) = delete;
	Engines(const Engines &other) = delete;
private:
	void setEngineRunning(Engine engine);
	void setEngineStopped(Engine engine);
public:
	void driveForward();
	void driveBackwards();
	void turnLeft();
	void turnRight();

	static Engines& getInstance();
};

}
