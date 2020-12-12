/*
 * LL_Extension_TIM_interrupt.hpp
 *
 *  Created on: Dec 4, 2020
 *      Author: satoshi ohya
 */

#ifndef TIM_LL_EXTENSION_TIM_INTERRUPT_HPP_
#define TIM_LL_EXTENSION_TIM_INTERRUPT_HPP_

#ifndef CONFIG_DISABLE_MODULE_TIM

#include "tim.h"
#include "functional"

#include "LL_Extension_TIM_BASE.hpp"

namespace llex{

class TIM_interrupt: public TIM_base{
private:
	std::function<void(void)> updateCallback;
	std::function<void(void)> triggerCallback;
	std::function<void(void)> captureCompare1Callback;
	std::function<void(void)> captureCompare2Callback;
	std::function<void(void)> captureCompare3Callback;
	std::function<void(void)> captureCompare4Callback;

public:
	using TIM_base::TIM_base;

	void setUpdateCallback(std::function<void(void)>function);
	void setTriggerCallback(std::function<void(void)>function);
	void setCaputureCompare1Callback(std::function<void(void)>function);
	void setCaputureCompare2Callback(std::function<void(void)>function);
	void setCaputureCompare3Callback(std::function<void(void)>function);
	void setCaputureCompare4Callback(std::function<void(void)>function);
	void intrruptCallback();
};

}

#endif /* CONFIG_DISABLE_MODULE_TIM */

#endif /* TIM_LL_EXTENSION_TIM_INTERRUPT_HPP_ */
