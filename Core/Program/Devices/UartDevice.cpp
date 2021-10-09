#include "UartDevice.hpp"
#include "../Processing/TaskQueue.hpp"

namespace Program
{

UartDevice::UartDevice()
{
}

void UartDevice::dataArrived()
{
	if(on_data_arrived_action)
	{
		on_data_arrived_action(buffer_);
	}
}

void UartDevice::dataTransmitted()
{
	if(on_data_transmitted_action)
	{
		on_data_transmitted_action(buffer_);
	}
}

void UartDevice::waitForData(uint16_t bytes_count)
{
	if(bytes_count != buffer_.size())
	{
		resizeBuffer(bytes_count);
	}

	HAL_UART_Receive_DMA(&huart1, buffer_.data() , bytes_count);
}

void UartDevice::transmitData(UartDevice::StorageType<DataType> bytes)
{
	HAL_UART_Transmit_DMA(&huart1, bytes.data(), bytes.size());
}

 UartDevice::StorageType<UartDevice::DataType> UartDevice::getBufferedData()
{
	return buffer_;
}

void UartDevice::resizeBuffer(uint16_t size)
{
	buffer_.resize(size);
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
