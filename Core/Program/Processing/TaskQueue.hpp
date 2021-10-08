#pragma once

#include <queue>
#include <any>
//#include "Task.hpp"
#include <functional>

namespace Program
{

class TaskQueue
{
private:
	std::queue<std::function<void()>> tasks_;
public:
	TaskQueue();
	virtual ~TaskQueue() = default;
	void addTask(Task&& task);
	Task getTask();
	bool isEmpty() const;
};

}
