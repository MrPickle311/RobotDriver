#include "UartDevice.hpp"
#include "../Processing/TaskQueue.hpp"

namespace Program
{

UartDevice::UartDevice():
		current_buffer_{first_buffer_}
{
}

void UartDevice::changeBuffer()
{
	if(&current_buffer_ == &first_buffer_)
	{
		current_buffer_ = second_buffer_;
		return;
	}

	current_buffer_ = first_buffer_;
}

void UartDevice::startReceivingData()
{
	HAL_UART_Receive_DMA(&huart1, current_buffer_.data() , current_buffer_.size());
}

void UartDevice::dataArrived()
{
	auto& temp_buf = current_buffer_;

//	changeBuffer();
//	startReceivingData();

	if(on_data_arrived_action)
	{
		on_data_arrived_action(temp_buf);
	}
}

void UartDevice::dataTransmitted()
{
	if(on_data_transmitted_action)
	{
		on_data_transmitted_action(current_buffer_);
	}
}

void UartDevice::waitForData(uint16_t bytes_count)
{
	if(bytes_count != current_buffer_.size())
	{
		resizeBuffer(bytes_count);
	}

	startReceivingData();
}

void UartDevice::transmitData(UartDevice::StorageType<DataType> bytes)
{
	HAL_UART_Transmit_DMA(&huart1, bytes.data(), bytes.size());
}

 UartDevice::StorageType<UartDevice::DataType> UartDevice::getBufferedData()
{
	return first_buffer_;
}

void UartDevice::resizeBuffer(uint16_t size)
{
	first_buffer_.resize(size);
	second_buffer_.resize(size);
}


UartDevice& UartDevice::getInstance()
{
	static UartDevice uart;

	return uart;
}

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart)
{
	Program::UartDevice::getInstance().dataArrived();
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef* huart)
{
	Program::UartDevice::getInstance().dataTransmitted();
}
