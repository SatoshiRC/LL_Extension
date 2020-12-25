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
	enum class TransferDirection:uint32_t{
		Write = 0,
		Read = 1,
	};
	enum class AddressSize{
		BIT7 = LL_I2C_OWNADDRESS1_7BIT,
		BIT10 = LL_I2C_OWNADDRESS1_10BIT
	};
	enum class AcknowledgeType{
		ACK = LL_I2C_ACK,
		NACK = LL_I2C_NACK,
	};

	I2C_base(I2C_TypeDef *I2Cx):I2Cx(I2Cx){};

	void enable();
	void disable();
	bool isEnable();

	void enableDMARequestsTX();
	void disableDMARequestsTX();
	bool isEnableDMARequestsTX();
	void enableDMARequestsRX();
	void disableDMARequestsRX();
	bool isEnableDMARequestsRX();
	uint32_t getDMADataGeristerAddress();
	void enableLastDMA();
	void disableLastDMA();
	bool isEnableLastDMA();

	void enableInterrupTransmit();
	void disableInterrupTransmit();
	bool isEnableInterrupTransmit();
	void enableInterrupReceive();
	void disableInterrupReceive();
	bool isEnableInterrupReceive();
	void enableInterrupEvent();
	void disableInterrupEvent();
	bool isEnableInterrupEvent();
	void enableInterrupBuffer();
	void disableInterrupBuffer();
	bool isEnableInterrupBuffer();
	void enableInterrupError();
	void disableInterrupError();
	bool isEnableInterrupError();

	bool isActiveFlagTransmitdataEmpty();
	bool isActiveFlagByteTransferFinished();
	bool isActiveFlagReceiveDataNotEmpty();
	bool isActiveFlagStartBit();
	bool isActiveFlagAddress();//address sent(master) or address matched(slave mode)
	bool isActiveFlagADD10();
	bool isActiveFlagAcknowledgeFailure();
	bool isActiveFlagStopDetection();
	bool isActiveFlagBussError();
	bool isActiveFlagAribitrationLost();
	bool isActiveFlagOverrunUnderrun();
	bool isActiveFlagBusBusy();
	//RESET: Received address matched with OAR1.
	//SET: Received address matched with OAR2.
	bool isActiveFlagDual();
	bool isActiveFlagGeneralCallAddressReception();
	bool isActiveFlagMasterMode();

	void clearFlagAddress();
	void clearFlagAcknowledgeFailure();
	void clearFlagStopDetection();
	void clearFlagBussError();
	void clearFlagAribitrationLost();
	void clearFlagOverrunUnderrun();

	void enablePOS();
	void disablePOS();
	bool isEnabledPOS();

	void enableReset();
	void disableeReset();
	bool isEnableReset();

	void enableGeneralCall();
	void disableGeneralCall();
	bool isEnableGeneralCall();

	void setOwnAddrerss1(uint16_t address, AddressSize OwnAddressSize);
	uint16_t getOwnAddress1();
	void setOwnAddrerss2(uint8_t address);
	void enableOwnAddress2();
	void disableOwnAddress2();
	bool isEnableOwnAddress2();

	void acknowledgeNextData(AcknowledgeType acknowledgeType);

	void generateStartCondition();
	void generateStopCondition();

	uint8_t receive8bit();
	void transmit8bit(uint8_t data);

	TransferDirection getTransferDirection();

};
}



#endif /*#ifndef CONFIG_DISABLE_MODULE_I2C*/

#endif /* I2C_LL_EXTENSION_I2C_BASE_HPP_ */
