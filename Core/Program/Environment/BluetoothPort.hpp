#pragma once

#include "../../Inc/usart.h"

namespace Program
{

class BluetoothPort
{
public:
	BluetoothPort();
	BluetoothPort(const BluetoothPort &other) = delete;
	BluetoothPort(BluetoothPort &&other) = delete;
	BluetoothPort& operator=(const BluetoothPort &other) = delete;
	BluetoothPort& operator=(BluetoothPort &&other) = delete;
	virtual ~BluetoothPort() = default;
};

}
