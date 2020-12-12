/*
 * LL_Extension_TIM_BASE.cpp
 *
 *  Created on: Dec 12, 2020
 *      Author: satoshi ohya
 */
#include "LL_Extension_TIM_BASE.hpp"

namespace llex{
void TIM_base::start(){
	LL_TIM_EnableCounter(TIMx);
}

void TIM_base::stop(){
	LL_TIM_DisableCounter(TIMx);
}

bool TIM_base::isStarted(){
	return LL_TIM_IsEnabledCounter(TIMx);
}

uint32_t TIM_base::getAutoRelode(){
	return LL_TIM_GetAutoReload(TIMx);
}

void TIM_base::enebleUpdateInterrupt(){
	LL_TIM_EnableIT_UPDATE(TIMx);
}

void TIM_base::enebleTriggerInterrupt(){
	LL_TIM_EnableIT_TRIG(TIMx);
}

void TIM_base::enebleCaputurCompare1Interrupt(){
	LL_TIM_EnableIT_CC1(TIMx);
}

void TIM_base::enebleCaputurCompare2Interrupt(){
	LL_TIM_EnableIT_CC2(TIMx);
}

void TIM_base::enebleCaputurCompare3Interrupt(){
	LL_TIM_EnableIT_CC3(TIMx);
}

void TIM_base::enebleCaputurCompare4Interrupt(){
	LL_TIM_EnableIT_CC4(TIMx);
}

void TIM_base::disableUpdateInterrupt(){
	LL_TIM_DisableIT_UPDATE(TIMx);
}

void TIM_base::disableTriggerInterrupt(){
	LL_TIM_DisableIT_TRIG(TIMx);
}

void TIM_base::disableCaputurCompare1Interrupt(){
	LL_TIM_DisableIT_CC1(TIMx);
}

void TIM_base::disableCaputurCompare2Interrupt(){
	LL_TIM_DisableIT_CC2(TIMx);
}

void TIM_base::disableCaputurCompare3Interrupt(){
	LL_TIM_DisableIT_CC3(TIMx);
}

void TIM_base::disableCaputurCompare4Interrupt(){
	LL_TIM_DisableIT_CC4(TIMx);
}

bool TIM_base::isEnebleUpdateInterrupt(){
	return LL_TIM_IsEnabledIT_UPDATE(TIMx);
}

bool TIM_base::isEnebleTriggerInterrupt(){
	return LL_TIM_IsEnabledIT_TRIG(TIMx);
}

bool TIM_base::isEnebleCaputurCompare1Interrupt(){
	return LL_TIM_IsEnabledIT_CC1(TIMx);
}

bool TIM_base::isEnebleCaputurCompare2Interrupt(){
	return LL_TIM_IsEnabledIT_CC2(TIMx);
}

bool TIM_base::isEnebleCaputurCompare3Interrupt(){
	return LL_TIM_IsEnabledIT_CC3(TIMx);
}

bool TIM_base::isEnebleCaputurCompare4Interrupt(){
	return LL_TIM_IsEnabledIT_CC4(TIMx);
}

bool TIM_base::isActiveFlagUpdate(){
	return LL_TIM_IsActiveFlag_UPDATE(TIMx);
}

bool TIM_base::isActiveFlagTrigger(){
	return LL_TIM_IsActiveFlag_TRIG(TIMx);
}

bool TIM_base::isActiveFlagCaputurCompare1(){
	return LL_TIM_IsActiveFlag_CC1(TIMx);
}

bool TIM_base::isActiveFlagCaputurCompare2(){
	return LL_TIM_IsActiveFlag_CC2(TIMx);
}

bool TIM_base::isActiveFlagCaputurCompare3(){
	return LL_TIM_IsActiveFlag_CC3(TIMx);
}

bool TIM_base::isActiveFlagCaputurCompare4(){
	return LL_TIM_IsActiveFlag_CC4(TIMx);
}

void TIM_base::clearFlagUpdate(){
	LL_TIM_ClearFlag_UPDATE(TIMx);
}
void TIM_base::clearFlagTrigger(){
	LL_TIM_ClearFlag_TRIG(TIMx);
}

void TIM_base::clearFlagCaputurCompare1(){
	LL_TIM_ClearFlag_CC1(TIMx);
}

void TIM_base::clearFlagCaputurCompare2(){
	LL_TIM_ClearFlag_CC2(TIMx);
}

void TIM_base::clearFlagCaputurCompare3(){
	LL_TIM_ClearFlag_CC3(TIMx);
}

void TIM_base::clearFlagCaputurCompare4(){
	LL_TIM_ClearFlag_CC4(TIMx);
}
}
