/*
 * LL_Extension_TIM_all.cpp
 *
 *  Created on: Dec 4, 2020
 *      Author: conat
 */
#include "LL_Extension_TIM_pwm.hpp"
namespace llex{
void TIM_pwm::start(){
	if(not LL_TIM_IsEnabledCounter(TIMx)){
		LL_TIM_EnableCounter(TIMx);
	}
	LL_TIM_CC_EnableChannel(TIMx, Channels);
}

void TIM_pwm::stop(){
	LL_TIM_CC_DisableChannel(TIMx, Channels);
}

void TIM_pwm::setCompare(uint16_t CompareValue){
	TIM_OC_SetCompare(TIMx, CompareValue);
}

uint16_t TIM_pwm::getCompare(){
	return TIM_OC_GetCompare(TIMx);
}

uint32_t TIM_pwm::getCounterPeriod(){
	return LL_TIM_GetAutoReload(TIMx);
}
}
