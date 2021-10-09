#pragma once

#include "../../Inc/usart.h"

#include <vector>

namespace Program
{

//do device to jakoś trzeba powiązać bezpośrednio hala
//np. będzie uart1 , uart2
//to będzie takie direct IO ,
//urządzenia zrób jako singletony
//tutaj będzie bezpośredni bajtowy IO
//uobiektowienie urządzenia
class UartDevice
{
private:
	std::vector<uint8_t> buffer_;
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
	void transmitData(std::vector<uint8_t> bytes);
	std::vector<uint8_t> getBufferedData();

	void resizeBuffer(uint16_t size);

	static UartDevice& getInstance();
};

//ta klasa będzie pewną konkretyzacją i ukształtowaniem urzadzenia
//deskryptor roli urządzenia
class UartDriver
{

};



}

