#include "EventObserver.hpp"
#include "../../Inc/main.h"
#include "../../Inc/usart.h"

#include "TaskQueue.hpp"

namespace Program
{

void EventCallbacksStorage::subscribeEvent(EventDescriptorType event_type , EventCallbackType&& callback )
{
	events_group_[event_type] = std::move(callback);
}

volatile uint8_t nm[2] = {'n' , 'm'};

void BluetoothEventObserver::handle(const IEvent& event)
{
	TaskQueue::getInstance().addTask([]
									  {
											HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
											HAL_UART_Transmit(&huart2, const_cast<uint8_t*>(nm) , 2 , 200);
									  });
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
//	HAL_UART_Transmit(&huart2, const_cast<uint8_t*>(nm) , 2 , 200);
}

}
