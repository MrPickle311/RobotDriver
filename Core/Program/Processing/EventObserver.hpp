#pragma once
#include "Event.hpp"

namespace Program
{

class EventObserver
{
public:
	EventObserver();
	virtual ~EventObserver();

	void handle(const IEvent& event);

};

}

