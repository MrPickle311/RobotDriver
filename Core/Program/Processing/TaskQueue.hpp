#pragma once

#include <queue>
#include <any>
#include "Task.hpp"

namespace Program
{

class TaskQueue
{
private:
	std::priority_queue<Task> tasks_;
public:
	TaskQueue();
	virtual ~TaskQueue() = default;
	void addTask(Task&& task);
	Task getTask();
	bool isEmpty() const;
};

}
