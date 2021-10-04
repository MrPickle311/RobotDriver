
#include "TaskProcessor.hpp"

namespace Program
{

TaskProcessor::TaskProcessor(TaskQueue& task_queue):
		task_queue_{task_queue}
{
	// TODO Auto-generated constructor stub

}

TaskProcessor::~TaskProcessor()
{
	// TODO Auto-generated destructor stub
}

void TaskProcessor::tryProccessTask()
{
	if(!task_queue_.isEmpty())
	{
		auto task {task_queue_.getTask()};
		task();
	}
}

}
