#include "Dispatcher.hpp"

#include "../../Inc/main.h"

#include "../../Inc/usart.h"
namespace Program
{

Dispatcher::Dispatcher()
{
	// TODO Auto-generated constructor stub

}

void Dispatcher::subscribe( std::string_view descriptor, SlotType&& slot )
{
	observers_[descriptor].push_back(slot);
}

uint8_t* toBytes(const char* str)
{
	return  const_cast<uint8_t*>(reinterpret_cast<const uint8_t*>(str));
}

void Dispatcher::post( const IEvent& event ) const
{
	auto type{event.type()};

//		HAL_UART_Transmit(&huart2, toBytes(type)  , 9 , 200);

//	for(auto&& el : observers_)
//	{
//		HAL_UART_Transmit(&huart2, toBytes(el.first.data())  , 9 , 200);
//	}

	if(observers_.find(type) == observers_.end())
	{
		return;
	}

	for(auto&& observer : observers_.at(type))
	{
		observer(event);
	}
}

}
