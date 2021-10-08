#pragma once

#include <queue>
#include <any>
#include <functional>

namespace Program
{

class TaskQueue
{
private:
	std::queue<std::function<void()>> tasks_;
public:

	using TaskType = std::function<void()>;

	virtual ~TaskQueue() = default;
public:
	void addTask(TaskType&& task);
	TaskType getTask();
	bool isEmpty() const;

	static TaskQueue& getInstance();
};

}
