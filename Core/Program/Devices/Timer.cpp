#include "Timer.hpp"

#include "../Inc/tim.h"

namespace Program
{

Timer::Timer()
{
	htim4.Instance->SR = 0;
}

void Timer::timeout(bool is_single_shot)
{
	if(is_single_shot)
	{
		stopTimer();
	}

	if(on_timeout_handler_)
	{
		on_timeout_handler_();
	}
}

void Timer::startTimer()
{
	HAL_TIM_Base_Start_IT(&htim4);
}

void Timer::stopTimer()
{
	HAL_TIM_Base_Stop(&htim4);
}

void Timer::setTimeout(uint16_t milliseconds)
{
	__HAL_TIM_SET_COUNTER(&htim4 , milliseconds);
}

Timer& Timer::getInstance()
{
	static Timer timer;

	return timer;
}

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
	if(htim->Instance == TIM4)
	{
		Program::Timer::getInstance().timeout();
//		HAL_TIM_Base_Stop(&htim4);
//		stopEngines();
	}
}
