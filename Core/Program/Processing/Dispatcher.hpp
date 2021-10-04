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
	bool containsObserver(std::string_view str)
	{

	}
public:

	using SlotType = std::function< void( const IEvent& ) >;

	Dispatcher();

	void subscribe( std::string_view descriptor, SlotType&& slot );

	void post( const IEvent& event ) const;

private:

	std::map< std::string_view , std::vector<SlotType> > observers_;
};

}
