#include "TaskQueue.hpp"

namespace Program
{

TaskQueue::TaskQueue() {
	// TODO Auto-generated constructor stub

}

Task TaskQueue::getTask()
{
	auto task{std::move(tasks_.top())};
//	return tasks_.pop();
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
