#pragma once

#include "../../Inc/usart.h"

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
public:
	UartDevice();
	virtual ~UartDevice() = default;
	UartDevice(const UartDevice &other) = delete;
	UartDevice(UartDevice &&other) = delete;
	UartDevice& operator=(const UartDevice &other) = delete;
	UartDevice& operator=(UartDevice &&other) = delete;
public:

};

//ta klasa będzie pewną konkretyzacją i ukształtowaniem urzadzenia
//deskryptor roli urządzenia
class UartDriver
{

};



}

