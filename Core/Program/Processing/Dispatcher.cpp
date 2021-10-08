#include "Dispatcher.hpp"

#include "../../Inc/main.h"
#include "../../Inc/usart.h"

namespace Program
{

bool Dispatcher::containsObserver(std::string_view type) const
{
	return ! (observers_.find(type) == observers_.end());
}

void Dispatcher::subscribe( std::string_view descriptor, SlotType&& slot )
{
	observers_[descriptor].push_back(slot);
}

uint8_t* toBytes(const char* str)
{
	return const_cast<uint8_t*>(reinterpret_cast<const uint8_t*>(str));
}

void Dispatcher::post( const IEvent& event ) const
{
	auto type{event.type()};

	if(containsObserver(type))
	{
		return;
	}

	for(auto&& observer : observers_.at(type))
	{
		observer(event);
	}
}

}
