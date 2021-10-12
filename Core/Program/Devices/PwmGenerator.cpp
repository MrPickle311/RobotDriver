#include "PwmGenerator.hpp"

#include "../Inc/tim.h"

namespace Program
{

PwmGenerator::PwmGenerator()
{
	// TODO Auto-generated constructor stub

}


void PwmGenerator::startGenerating()
{
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}

void PwmGenerator::stopGenerating()
{
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
}


void PwmGenerator::setPwmSignalFilling(uint16_t filling)
{
	__HAL_TIM_SET_COMPARE(&htim3 , TIM_CHANNEL_1 , filling);
}

PwmGenerator& PwmGenerator::getInstance()
{
	static PwmGenerator generator;

	return generator;
}

}
