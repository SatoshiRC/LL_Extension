/*
 * LL_Extension_GPIO.cpp
 *
 *  Created on: Dec 4, 2020
 *      Author: conat
 */
#include "LL_Extension_GPIO.hpp"

#ifndef CONFIG_DISABLE_MODULE_GPIO

namespace llex{

uint32_t GPIO::read(){
	return LL_GPIO_IsInputPinSet(GPIOx, PinMask);
}

void GPIO::write(bool PinState){
	if(PinState){
		set();
	}else{
		reset();
	}
}

void GPIO::set(){
	LL_GPIO_SetOutputPin(GPIOx, PinMask);
}

void GPIO::reset(){
	LL_GPIO_ResetOutputPin(GPIOx, PinMask);
}

void GPIO::toggle(){
	LL_GPIO_TogglePin(GPIOx, PinMask);
}

}
#endif //CONFIG_DISABLE_MODULE_GPIO
