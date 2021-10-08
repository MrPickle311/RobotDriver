#include "TaskQueue.hpp"

namespace Program
{

TaskQueue::TaskType TaskQueue::getTask()
{
	auto task{std::move(tasks_.front())};
	tasks_.pop();
	return task;
}

bool TaskQueue::isEmpty() const
{
	return tasks_.empty();
}

void TaskQueue::addTask(TaskType&& task)
{
	tasks_.push(task);
}

TaskQueue& TaskQueue::getInstance()
{
	static TaskQueue task_queue{};
	return task_queue;
}

}
