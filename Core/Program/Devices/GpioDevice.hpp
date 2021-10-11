/*
 * GpioDevice.hpp
 *
 *  Created on: 11 paź 2021
 *      Author: macma
 */

#ifndef PROGRAM_DEVICES_GPIODEVICE_HPP_
#define PROGRAM_DEVICES_GPIODEVICE_HPP_

namespace Program {

class GpioDevice {
public:
	GpioDevice();
	virtual ~GpioDevice() = default;
	GpioDevice(const GpioDevice &other) = delete;
	GpioDevice(GpioDevice &&other) = delete;
	GpioDevice& operator=(const GpioDevice &other) = delete;
	GpioDevice& operator=(GpioDevice &&other) = delete;
};

} /* namespace Program */

#endif /* PROGRAM_DEVICES_GPIODEVICE_HPP_ */
