/*
 * LL_Extension_I2C_BASE.hpp
 *
 *  Created on: Dec 12, 2020
 *      Author: satohi ohya
 */

#ifndef I2C_LL_EXTENSION_I2C_BASE_HPP_
#define I2C_LL_EXTENSION_I2C_BASE_HPP_

#ifndef CONFIG_DISABLE_MODULE_I2C

#include "i2c.h"

namespace llex{

class I2C_base{
private:
	I2C_TypeDef *I2Cx;
public:
	I2C_base(I2C_TypeDef *I2Cx):I2Cx(I2Cx){};
};
}



#endif /*#ifndef CONFIG_DISABLE_MODULE_I2C*/

#endif /* I2C_LL_EXTENSION_I2C_BASE_HPP_ */
