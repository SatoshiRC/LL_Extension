/*
 * LL_Extension_USART.hpp
 *
 *  Created on: Dec 5, 2020
 *      Author: conat
 */

#ifndef USART_LL_EXTENSION_USART_BASE_HPP_
#define USART_LL_EXTENSION_USART_BASE_HPP_

#ifndef CONFIG_DISABLE_MODULE_USART

#include "usart.h"

namespace llex{
class USART_Base{
public:
	enum class Parity{
		  None = LL_USART_PARITY_NONE,
		  Even = LL_USART_PARITY_EVEN,
		  Odd = LL_USART_PARITY_ODD,
	};
	enum class WakeUpMethod{
		IdleLine = LL_USART_WAKEUP_IDLELINE,
		AddressMark = LL_USART_WAKEUP_ADDRESSMARK,
	};
	enum class DataWidth{
		DataWidth_8Bits = LL_USART_DATAWIDTH_8B,
		DataWidth_9Bits = LL_USART_DATAWIDTH_9B,
	};
	enum class StopBitsLength{
		StopBits05 = LL_USART_STOPBITS_0_5,
		StopBits1 = LL_USART_STOPBITS_1,
		StopBits15 = LL_USART_STOPBITS_1_5,
		StopBits2 = LL_USART_STOPBITS_2,
	};
	enum class Mode{
		none,
		receive,
		transmit,
	};

	USART_Base(USART_TypeDef *USARTx = nullptr)
	:USARTx(USARTx){
		mode = Mode::none;
	};
	void enable();
	void disable();
	bool isEnable();
	void enableDirectionTx();
	void disableDirectionTx();
	void enableDirectionRx();
	void disableDirectionRx();
	void setParity(Parity parity);
	Parity getParity();
	void SetWakeUpMethod(WakeUpMethod wakeUpMethod);
	WakeUpMethod GetWakeUpMethod();
	void setDataWidth(DataWidth dataWidth);
	DataWidth getDataWidth();
	void SetStopBitsLength(StopBitsLength stopBitsLength);
	StopBitsLength getStopBitsLength();
	void SetNodeAddress(uint8_t nodeAddress);
	uint8_t GetNodeAddress();
	bool isActiveFlag_PE();
	bool isActiveFlag_FE();
	bool isActiveFlag_NE();
	bool isActiveFlag_ORE();
	bool isActiveFlag_IDLE();
	bool isActiveFlag_RXNE();
	bool isActiveFlag_TC();
	bool isActiveFlag_TXE();
	bool isActiveFlag_LBD();
	bool isActiveFlag_nCTS();
	bool isActiveFlag_SBK();
	bool isActiveFlag_RWU();
	void clearFlag_PE();
	void clearFlag_FE();
	void clearFlag_NE();
	void clearFlag_ORE();
	void clearFlag_IDLE();
	void clearFlag_RXNE();
	void clearFlag_TC();
	void clearFlag_LBD();
	void clearFlag_nCTS();

	void enableReceiveIT();
	bool isEnableReceiveIT();
	void disableReceiveIT();

	void enableIdleIT();
	bool isEnableIdleIT();
	void disableIdleIT();

	void enableBreakDetectionIT();
	bool isEnableBreakDetectionIT();
	void disableBreakDetectionIT();

	void transmitData8Bits(uint8_t value);
	void transmitData9Bits(uint16_t value);
	void transmitData(uint16_t value);
	uint8_t receiveData8Bits();
	uint16_t receiveData9Bits();
	uint16_t receiveData();

protected:
	USART_TypeDef *USARTx;
	Mode mode;

};
}



#endif /* CONFIG_DISABLE_MODULE_USART */

#endif /* USART_LL_EXTENSION_USART_BASE_HPP_ */
