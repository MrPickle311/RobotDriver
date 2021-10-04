/*
 * EventObserver.cpp
 *
 *  Created on: Oct 3, 2021
 *      Author: Damian
 */

#include "EventObserver.hpp"
#include "../../Inc/main.h"
#include "../../Inc/usart.h"

namespace Program
{

EventObserver::EventObserver()
{
	// TODO Auto-generated constructor stub

}

EventObserver::~EventObserver()
{
	// TODO Auto-generated destructor stub
}

volatile uint8_t nm[2] = {'n' , 'm'};

void EventObserver::handle(const IEvent& event)
{

	if( event.type() == DemoEvent::descriptor )
	{

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
		// This demonstrates how to obtain the underlying event type in case a
		// slot is set up to handle multiple events of different types.

		const DemoEvent& demoEvent{static_cast<const DemoEvent&>(event)};

		const  uint8_t* t = reinterpret_cast<const uint8_t*>( demoEvent.type().data() );

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
		HAL_UART_Transmit(&huart2, const_cast<uint8_t*>(nm) , 2 , 200);
		HAL_UART_Transmit(&huart2, const_cast<uint8_t*>(t) , 8 , 200);
	}
}

} /* namespace Program */
