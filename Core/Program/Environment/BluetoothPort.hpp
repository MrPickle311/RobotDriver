#pragma once

#include "../Devices/UartDevice.hpp"
#include "../Processing/Event.hpp"
#include "../Processing/TaskQueue.hpp"

namespace Program
{

class BluetoothPort
{
private:
	BluetoothPort();
public:
	BluetoothPort(const BluetoothPort &other) = delete;
	BluetoothPort(BluetoothPort &&other) = delete;
	BluetoothPort& operator=(const BluetoothPort &other) = delete;
	BluetoothPort& operator=(BluetoothPort &&other) = delete;
	virtual ~BluetoothPort() = default;
public:
	void waitForCommands();
	void parseIncomingData(const std::vector<uint8_t>& data);
	void postTaskToTaskQueue(BluetoothEvent&& event);

	static BluetoothPort& getInstance();
};

}
