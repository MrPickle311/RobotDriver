#include "TaskQueue.hpp"

namespace Program
{

TaskQueue::TaskQueue() {
	// TODO Auto-generated constructor stub

}

Task TaskQueue::getTask()
{
	auto task{std::move(tasks_.front())};
	tasks_.pop();
	return task;
}

bool TaskQueue::isEmpty() const
{
	return tasks_.empty();
}

void TaskQueue::addTask(Task&& task)
{
	tasks_.push(task);
}

}
