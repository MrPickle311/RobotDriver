#pragma once

#include "TaskQueue.hpp"

namespace Program
{

class TaskProcessor
{
private:
	TaskQueue& task_queue_;
public:
	TaskProcessor(TaskQueue& task_queue);
	virtual ~TaskProcessor();

	void tryProccessTask();
};

}
