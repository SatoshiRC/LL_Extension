/*
 * LL_Extension_GPIO.cpp
 *
 *  Created on: Dec 4, 2020
 *      Author: conat
 */
#include "LL_Extension_GPIO.hpp"

#ifndef CONFIG_DISABLE_MODULE_GPIO

namespace llex{

bool GPIO::isSet(){
	return LL_GPIO_IsInputPinSet(GPIOx, PinMask);
}

void GPIO::write(PinState state){
	if(state == PinState::Set){
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
