#pragma once

#include "Event.hpp"
#include "TaskQueue.hpp"
#include <map>

namespace Program
{

enum class EventGroupType
{
	BluetoothEvents
};

class IEventObserver
{
public:
	virtual void handle(const IEvent& event) = 0;
};

class EventObserver
{
public:
	virtual ~EventObserver() = default;
	void handle(const IEvent& event);
};

class EventTypeStorage
{
protected:
	std::map<std::string_view , std::function<void()>> events_group_;
public:
	void appendEvent()
};


class BluetoothEventObserver : public IEventObserver
{
public:
	virtual void handle(const IEvent& event);
};

}

