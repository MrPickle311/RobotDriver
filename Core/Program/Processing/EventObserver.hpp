#pragma once

#include "Event.hpp"
#include "TaskQueue.hpp"
#include <map>

namespace Program
{


class IEventObserver
{
public:
	virtual void handle(const IEvent& event) = 0;
};

class EventCallbacksStorage
{
public:
	using EventDescriptorType = std::string_view;
	using EventCallbackType = std::function<void()>;
protected:
	std::map<EventDescriptorType , EventCallbackType > events_group_;
public:
	void subscribeEvent(EventDescriptorType event_type , EventCallbackType&& callback );
};

class BluetoothEventObserver : public IEventObserver
{
public:
	virtual void handle(const IEvent& event);
};

}

