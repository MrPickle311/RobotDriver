#pragma once
#include "Event.hpp"

namespace Program
{

class EventObserver
{
public:
	virtual ~EventObserver() = default;
	void handle(const IEvent& event);
};

}

