#pragma once

#include <functional>
#include <map>
#include "Event.hpp"
#include <string_view>

namespace Program
{

class Dispatcher
{
private:
	bool containsObserver(std::string_view str) const;
public:

	using SlotType = std::function< void( const IEvent& ) >;

	void subscribe( std::string_view descriptor, SlotType&& slot );

	void post( const IEvent& event ) const;

private:

	std::map< IEvent::DescriptorType , std::vector<SlotType> > observers_;
};


}
