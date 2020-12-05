/*
 * LL_Extension_GPIO.hpp
 *
 *  Created on: Dec 4, 2020
 *      Author: conat
 */
#ifndef LL_EXTENSION_GPIO_HPP
#define LL_EXTENSION_GPIO_HPP
#ifndef CONFIG_DISABLE_MODULE_GPIO

#include "gpio.h"

namespace llex{

class GPIO{
private:
	GPIO_TypeDef *GPIOx;
	uint32_t PinMask;
public:
	enum class pinState{
		reset,
		set,
	};
	GPIO(GPIO_TypeDef *GPIOx, uint32_t PinMask)
	:GPIOx(GPIOx),PinMask(PinMask){};
	uint32_t read();
	void write(pinState PinState);
	void set();
	void reset();
	void toggle();
};
}


#endif //LL_EXTENSION_GPIO_HPP
#endif //CONFIG_DISABLE_MODULE_GPIO
