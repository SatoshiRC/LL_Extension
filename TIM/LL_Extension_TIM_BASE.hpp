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
protected:
	TIM_TypeDef *TIMx;
public:
	TIM_base(TIM_TypeDef *TIMx)
	:TIMx(TIMx){};

	void start();
	void stop();
	bool isStarted();
	uint32_t getAutoReload();
	void enableCaputurCompare(uint8_t channel);
	void enableUpdateInterrupt();
	void enableTriggerInterrupt();
	void enableCaputurCompare1Interrupt();
	void enableCaputurCompare2Interrupt();
	void enableCaputurCompare3Interrupt();
	void enableCaputurCompare4Interrupt();
	void disableCaputurCompare(uint8_t channel);
	void disableUpdateInterrupt();
	void disableTriggerInterrupt();
	void disableCaputurCompare1Interrupt();
	void disableCaputurCompare2Interrupt();
	void disableCaputurCompare3Interrupt();
	void disableCaputurCompare4Interrupt();
	bool isenableUpdateInterrupt();
	bool isenableTriggerInterrupt();
	bool isenableCaputurCompare1Interrupt();
	bool isenableCaputurCompare2Interrupt();
	bool isenableCaputurCompare3Interrupt();
	bool isenableCaputurCompare4Interrupt();
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
	void setCompareCH1(uint32_t CompareValue);
	void setCompareCH2(uint32_t CompareValue);
	void setCompareCH3(uint32_t CompareValue);
	void setCompareCH4(uint32_t CompareValue);
	uint32_t getCompareCH1();
	uint32_t getCompareCH2();
	uint32_t getCompareCH3();
	uint32_t getCompareCH4();
};
}
#endif /* CONFIG_DISABLE_MODULE_TIM */

#endif /* TIM_LL_EXTENSION_TIM_BASE_HPP_ */
