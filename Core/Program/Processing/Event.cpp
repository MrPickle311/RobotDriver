#include "Event.hpp"

namespace Program
{

IEvent::EventGroupType BluetoothEvent::group() const
{
	return BluetoothEvent::event_group;
}

IEvent::EventDescriptorType BluetoothDataArrivedEvent::what() const
{
	return BluetoothDataArrivedEvent::event_descriptor;
}

}
