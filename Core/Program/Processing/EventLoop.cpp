#include "EventLoop.hpp"

#include "../../Inc/main.h"

namespace Program
{

EventLoop::EventLoop(TaskQueue& queue):
		queue_{queue} ,
		current_task_handler_{} ,
		is_task_present_to_invoke_{false}
{}

bool EventLoop::queueHasTask()
{
	return ! queue_.isEmpty();
}

void EventLoop::tryAcquireHandler()
{
	if(queueHasTask())
	{
		current_task_handler_ = std::move(queue_.getTask());
		is_task_present_to_invoke_ = true;
	}
}

void EventLoop::tryInvokeHandler()
{
	if(is_task_present_to_invoke_)
	{
		current_task_handler_();
		is_task_present_to_invoke_ = false;
	}
}

void EventLoop::start()
{
	__disable_irq();

	tryAcquireHandler();

	__enable_irq();

	tryInvokeHandler();
}

EventLoop& EventLoop::getInstance(TaskQueue& queue)
{
	static EventLoop event_loop{queue};
	return event_loop;
}

}
