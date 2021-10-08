#include "Dispatcher.hpp"

namespace Program
{

bool Dispatcher::containsObserver(Dispatcher::DescriptorType type) const
{
	return ! (observers_.find(type) == observers_.end());
}

void Dispatcher::subscribe(Dispatcher::DescriptorType descriptor , SlotType&& slot )
{
	observers_[descriptor].push_back(slot);
}

uint8_t* toBytes(const char* str)
{
	return const_cast<uint8_t*>(reinterpret_cast<const uint8_t*>(str));
}

void Dispatcher::post( const IEvent& event ) const
{
	auto group{event.group()};

	if(!containsObserver(group))
	{
		return;
	}

	for(auto&& observer : observers_.at(group))
	{
		observer(event);
	}
}

}
