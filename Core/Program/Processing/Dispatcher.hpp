#pragma once

#include <functional>
#include <map>
#include "Event.hpp"

namespace Program
{


class Dispatcher
{
public:
	using SlotType = std::function< void( const IEvent& ) >;
	using DescriptorType = EventGroup;
private:
	bool containsObserver(DescriptorType descriptor) const;
public:
	void subscribeEventGroup(DescriptorType descriptor, SlotType&& slot );

	void post( const IEvent& event ) const;

private:

	std::map< DescriptorType , SlotType > observers_;
};


}
