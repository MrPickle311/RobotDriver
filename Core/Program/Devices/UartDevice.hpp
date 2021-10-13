#pragma once

#include "../../Inc/usart.h"

#include <vector>
#include <functional>
namespace Program
{

class UartDevice
{
public:
	using DataType = uint8_t;
	template<typename T>
	using StorageType = std::vector<T>;
	using ActionHandlerType = std::function<void(std::vector<uint8_t>)>;
private:
	 StorageType<DataType> first_buffer_;
	 StorageType<DataType> second_buffer_;
	 StorageType<DataType>& current_buffer_;
private:
	 void changeBuffer();
	 void startReceivingData();
public:
	ActionHandlerType on_data_arrived_action;
	ActionHandlerType on_data_transmitted_action;
public:
	UartDevice();
	virtual ~UartDevice() = default;
	UartDevice(const UartDevice &other) = delete;
	UartDevice(UartDevice &&other) = delete;
	UartDevice& operator=(const UartDevice &other) = delete;
	UartDevice& operator=(UartDevice &&other) = delete;
public:
	void dataArrived();//creates event
	void dataTransmitted();//creates event
	void waitForData(uint16_t bytes_count);
	void transmitData(StorageType<DataType> bytes);
	StorageType<DataType> getBufferedData();

	void resizeBuffer(uint16_t size);

	static UartDevice& getInstance();
};

//Driver splittes incoming/outgoing data into several parts
//multiton or normal object
//it stores rules for data splitting
class UartDriver
{

};



}

