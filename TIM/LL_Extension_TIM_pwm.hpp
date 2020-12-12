/*
 * LL_Extension_TIM_all.hpp
 *
 *  Created on: Dec 4, 2020
 *      Author: conat
 */

#ifndef TIM_LL_EXTENSION_TIM_PWM_HPP_
#define TIM_LL_EXTENSION_TIM_PWM_HPP_

#ifndef CONFIG_DISABLE_MODULE_TIM

#include "tim.h"
#include "functional"

namespace llex{

class TIM_pwm{
private:
	TIM_TypeDef *TIMx;
	uint32_t Channels;
	std::function<void(TIM_TypeDef *TIMx, uint32_t CompareValue)> TIM_OC_SetCompare;
	std::function<uint16_t(TIM_TypeDef *TIMx)> TIM_OC_GetCompare;
public:
	TIM_pwm(TIM_TypeDef *TIMx, uint32_t Channels)
	:TIMx(TIMx), Channels(Channels){
		switch(Channels){
		case LL_TIM_CHANNEL_CH1:
			TIM_OC_SetCompare = LL_TIM_OC_SetCompareCH1;
			TIM_OC_GetCompare = LL_TIM_OC_GetCompareCH1;
			break;
		case LL_TIM_CHANNEL_CH2:
			TIM_OC_SetCompare = LL_TIM_OC_SetCompareCH2;
			TIM_OC_GetCompare = LL_TIM_OC_GetCompareCH2;
			break;
		case LL_TIM_CHANNEL_CH3:
			TIM_OC_SetCompare = LL_TIM_OC_SetCompareCH3;
			TIM_OC_GetCompare = LL_TIM_OC_GetCompareCH3;
			break;
		case LL_TIM_CHANNEL_CH4:
			TIM_OC_SetCompare = LL_TIM_OC_SetCompareCH4;
			TIM_OC_GetCompare = LL_TIM_OC_GetCompareCH4;
			break;
		}
	};
	void start();
	void stop();
	void setCompare(uint16_t CompareValue);
	uint16_t getCompare();
	uint32_t getCounterPeriod();

};

}

#endif /* CONFIG_DISABLE_MODULE_TIM */

#endif /* TIM_LL_EXTENSION_TIM_PWM_HPP_ */
