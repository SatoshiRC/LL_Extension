/*
 * LL_Extension_TIM_all.cpp
 *
 *  Created on: Dec 4, 2020
 *      Author: conat
 */
#ifndef CONFIG_DISABLE_MODULE_TIM

#include "LL_Extension_TIM_pwm.hpp"
namespace llex{
void TIM_pwm::start(){
	if(not isStarted()){
		start();
	}
	enableCaputurCompare(channel);
}

void TIM_pwm::stop(){
	disableCaputurCompare(channel);
}

void TIM_pwm::setCompare(uint16_t CompareValue){
	TIM_OC_SetCompare(TIMx, CompareValue);
}

uint16_t TIM_pwm::getCompare(){
	return TIM_OC_GetCompare(TIMx);
}

uint32_t TIM_pwm::getCounterPeriod(){
	return getAutoReload();
}
}

#endif /* CONFIG_DISABLE_MODULE_TIM */
