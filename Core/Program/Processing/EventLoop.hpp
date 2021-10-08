#include "TaskQueue.hpp"

namespace Program
{


class EventLoop
{
private:
	TaskQueue& queue_;
	std::function<void()> current_task_handler_;
	bool 	   			   is_task_present_to_invoke_;
private:
	bool queueHasTask();
	void tryAcquireHandler();
	void tryInvokeHandler();
public:
	EventLoop(TaskQueue& queue);
	virtual ~EventLoop() = default;
	EventLoop(const EventLoop &other) = delete;
	EventLoop(EventLoop &&other) = delete;
	EventLoop& operator=(const EventLoop &other) = delete;
	EventLoop& operator=(EventLoop &&other) = delete;
public:
	void start();
};

}

