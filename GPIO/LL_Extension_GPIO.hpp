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
	enum class PinState{
		Reset,
		Set,
	};
	GPIO(GPIO_TypeDef *GPIOx, uint32_t PinMask)
	:GPIOx(GPIOx),PinMask(PinMask){};
	bool isSet();
	void write(PinState state);
	void set();
	void reset();
	void toggle();
};
}


#endif //LL_EXTENSION_GPIO_HPP
#endif //CONFIG_DISABLE_MODULE_GPIO
