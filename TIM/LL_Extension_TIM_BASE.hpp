/*
 * LL_Extension_TIM_BASE.hpp
 *
 *  Created on: Dec 12, 2020
 *      Author: conat
 */

#ifndef TIM_LL_EXTENSION_TIM_BASE_HPP_
#define TIM_LL_EXTENSION_TIM_BASE_HPP_

#ifndef CONFIG_DISABLE_MODULE_TIM

#include "tim.h"

namespace llex{
class TIM_base{
private:
	TIM_TypeDef *TIMx;
public:
	TIM_base(TIM_TypeDef *TIMx)
	:TIMx(TIMx){};

	void start();
	void stop();
	bool isStarted();
	uint32_t getAutoRelode();
	void enebleUpdateInterrupt();
	void enebleTriggerInterrupt();
	void enebleCaputurCompare1Interrupt();
	void enebleCaputurCompare2Interrupt();
	void enebleCaputurCompare3Interrupt();
	void enebleCaputurCompare4Interrupt();
	void disableUpdateInterrupt();
	void disableTriggerInterrupt();
	void disableCaputurCompare1Interrupt();
	void disableCaputurCompare2Interrupt();
	void disableCaputurCompare3Interrupt();
	void disableCaputurCompare4Interrupt();
	bool isEnebleUpdateInterrupt();
	bool isEnebleTriggerInterrupt();
	bool isEnebleCaputurCompare1Interrupt();
	bool isEnebleCaputurCompare2Interrupt();
	bool isEnebleCaputurCompare3Interrupt();
	bool isEnebleCaputurCompare4Interrupt();
	bool isActiveFlagUpdate();
	bool isActiveFlagTrigger();
	bool isActiveFlagCaputurCompare1();
	bool isActiveFlagCaputurCompare2();
	bool isActiveFlagCaputurCompare3();
	bool isActiveFlagCaputurCompare4();
	void clearFlagUpdate();
	void clearFlagTrigger();
	void clearFlagCaputurCompare1();
	void clearFlagCaputurCompare2();
	void clearFlagCaputurCompare3();
	void clearFlagCaputurCompare4();
};
}
#endif /* CONFIG_DISABLE_MODULE_TIM */

#endif /* TIM_LL_EXTENSION_TIM_BASE_HPP_ */
