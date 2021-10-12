#pragma once

#include "../Inc/gpio.h"
#include "main.h"

namespace Program
{

enum class PORT
{
	A = GPIOA_BASE ,
	B = GPIOB_BASE ,
	C = GPIOC_BASE ,
	D = GPIOD_BASE ,
	E = GPIOE_BASE ,
};

template<auto Port , auto Pin>
class GpioDevice
{
public:
	virtual ~GpioDevice() = default;
	GpioDevice(const GpioDevice &other) = delete;
	GpioDevice(GpioDevice &&other) = delete;
	GpioDevice& operator=(const GpioDevice &other) = delete;
	GpioDevice& operator=(GpioDevice &&other) = delete;

	static void setHigh()
	{
		HAL_GPIO_WritePin( reinterpret_cast<GPIO_TypeDef*>(Port) , Pin , GPIO_PIN_SET);
	}

	static void setLow()
	{
		HAL_GPIO_WritePin( reinterpret_cast<GPIO_TypeDef*>(Port) , Pin , GPIO_PIN_RESET);
	}
};



}
