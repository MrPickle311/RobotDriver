#include "Event.hpp"

namespace Program
{

IEvent::DescriptorType DemoEvent::type() const
{
	return descriptor;
}

}
