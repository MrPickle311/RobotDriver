#pragma once

#include <functional>

namespace Program
{

class Timer
{
public:
	using ActionHandlerType = std::function<void()>;
public:
	Timer();
	virtual ~Timer() = default;
	Timer(const Timer &other) = delete;
	Timer(Timer &&other) = delete;
	Timer& operator=(const Timer &other) = delete;
	Timer& operator=(Timer &&other) = delete;
public:
	ActionHandlerType on_timeout_handler_;
public:
	void timeout(bool is_single_shot = false);

	void startTimer();
	void stopTimer();

	void setTimeout(uint16_t milliseconds);

	static Timer& getInstance();
};

}
