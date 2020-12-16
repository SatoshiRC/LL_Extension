/*
 * LL_Extension_TIM_interrupt.cpp
 *
 *  Created on: Dec 4, 2020
 *      Author: satoshi ohya
 */
#ifndef CONFIG_DISABLE_MODULE_TIM

#include "LL_Extension_TIM_interrupt.hpp"
namespace llex{
void TIM_interrupt::setUpdateCallback(std::function<void(void)>function){
	updateCallback = function;
}

void TIM_interrupt::setTriggerCallback(std::function<void(void)>function){
	triggerCallback = function;
}

void TIM_interrupt::setCaputureCompare1Callback(std::function<void(void)>function){
	captureCompare1Callback = function;
}

void TIM_interrupt::setCaputureCompare2Callback(std::function<void(void)>function){
	captureCompare2Callback = function;
}

void TIM_interrupt::setCaputureCompare3Callback(std::function<void(void)>function){
	captureCompare3Callback = function;
}

void TIM_interrupt::setCaputureCompare4Callback(std::function<void(void)>function){
	captureCompare4Callback = function;
}

void TIM_interrupt::intrruptCallback(){
	if(isActiveFlagUpdate()){
		clearFlagUpdate();
		updateCallback();
	}else if(isActiveFlagTrigger()){
		clearFlagTrigger();
		triggerCallback();
	}else if(isActiveFlagCaputurCompare1()){
		clearFlagCaputurCompare1();
		captureCompare1Callback();
	}else if(isActiveFlagCaputurCompare2()){
		clearFlagCaputurCompare2();
		captureCompare2Callback();
	}else if(isActiveFlagCaputurCompare3()){
		clearFlagCaputurCompare3();
		captureCompare3Callback();
	}else if(isActiveFlagCaputurCompare4()){
		clearFlagCaputurCompare4();
		captureCompare4Callback();
	}
}
}

#endif /* CONFIG_DISABLE_MODULE_TIM */
