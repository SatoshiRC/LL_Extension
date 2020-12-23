/*
 * LL_Extension_I2C_BASE.cpp
 *
 *  Created on: Dec 18, 2020
 *      Author: satohi ohya
 */
#ifndef CONFIG_DISABLE_MODULE_I2C

#include "LL_Extension_I2C_BASE.hpp"

namespace llex{

void I2C_base::enable(){
	LL_I2C_Enable(I2Cx);
}

void I2C_base::disable(){
	LL_I2C_Disable(I2Cx);
}

bool I2C_base::isEnable(){
	return LL_I2C_IsEnabled(I2Cx);
}


void I2C_base::enableDMARequestsTX(){
	LL_I2C_EnableDMAReq_TX(I2Cx);
}

void I2C_base::disableDMARequestsTX(){
	LL_I2C_DisableDMAReq_TX(I2Cx);
}

bool I2C_base::isEnableDMARequestsTX(){
	return LL_I2C_IsEnabledDMAReq_TX(I2Cx);
}

void I2C_base::enableDMARequestsRX(){
	LL_I2C_EnableDMAReq_RX(I2Cx);
}

void I2C_base::disableDMARequestsRX(){
	LL_I2C_DisableDMAReq_RX(I2Cx);
}

bool I2C_base::isEnableDMARequestsRX(){
	return LL_I2C_IsEnabledDMAReq_RX(I2Cx);
}

uint32_t I2C_base::getDMADataGeristerAddress(){
	return LL_I2C_DMA_GetRegAddr(I2Cx);
}

void I2C_base::enableLastDMA(){
	LL_I2C_EnableLastDMA(I2Cx);
}

void I2C_base::disableLastDMA(){
	LL_I2C_DisableLastDMA(I2Cx);
}

bool I2C_base::isEnableLastDMA(){
	return LL_I2C_IsEnabledLastDMA(I2Cx);
}

void I2C_base::enableInterrupTransmit(){
	LL_I2C_EnableIT_TX(I2Cx);
}

void I2C_base::disableInterrupTransmit(){
	LL_I2C_DisableIT_TX(I2Cx);
}

bool I2C_base::isEnableInterrupTransmit(){
	return LL_I2C_IsEnabledIT_TX(I2Cx);
}

void I2C_base::enableInterrupReceive(){
	LL_I2C_EnableIT_RX(I2Cx);
}

void I2C_base::disableInterrupReceive(){
	LL_I2C_DisableIT_RX(I2Cx);
}

bool I2C_base::isEnableInterrupReceive(){
	return LL_I2C_IsEnabledIT_RX(I2Cx);
}

void I2C_base::enableInterrupEvent(){
	LL_I2C_EnableIT_EVT(I2Cx);
}

void I2C_base::disableInterrupEvent(){
	LL_I2C_DisableIT_EVT(I2Cx);
}

bool I2C_base::isEnableInterrupEvent(){
	return LL_I2C_IsEnabledIT_EVT(I2Cx);
}

void I2C_base::enableInterrupBuffer(){
	LL_I2C_EnableIT_BUF(I2Cx);
}

void I2C_base::disableInterrupBuffer(){
	LL_I2C_DisableIT_BUF(I2Cx);
}

bool I2C_base::isEnableInterrupBuffer(){
	return LL_I2C_IsEnabledIT_BUF(I2Cx);
}

void I2C_base::enableInterrupError(){
	LL_I2C_EnableIT_ERR(I2Cx);
}

void I2C_base::disableInterrupError(){
	LL_I2C_DisableIT_ERR(I2Cx);
}

bool I2C_base::isEnableInterrupError(){
	return LL_I2C_IsEnabledIT_ERR(I2Cx);
}


bool I2C_base::isActiveFlagTransmitdataNotEmpty(){
	return LL_I2C_IsActiveFlag_TXE(I2Cx);
}

bool I2C_base::isActiveFlagByteTransferFinished(){
	return LL_I2C_IsActiveFlag_BTF(I2Cx);
}

bool I2C_base::isActiveFlagReceiveDataNotEmpty(){
	return LL_I2C_IsActiveFlag_RXNE(I2Cx);
}

bool I2C_base::isActiveFlagStartBit(){
	return LL_I2C_IsActiveFlag_SB(I2Cx);
}

bool I2C_base::isActiveFlagAddress(){
	return LL_I2C_IsActiveFlag_ADDR(I2Cx);
}

bool I2C_base::isActiveFlagADD10(){
	return LL_I2C_IsActiveFlag_ADD10(I2Cx);
}

bool I2C_base::isActiveFlagAcknowledgeFailure(){
	return LL_I2C_IsActiveFlag_AF(I2Cx);
}

bool I2C_base::isActiveFlagStopDetection(){
	return LL_I2C_IsActiveFlag_STOP(I2Cx);
}

bool I2C_base::isActiveFlagBussError(){
	return LL_I2C_IsActiveFlag_BERR(I2Cx);
}

bool I2C_base::isActiveFlagAribitrationLost(){
	return LL_I2C_IsActiveFlag_ARLO(I2Cx);
}

bool I2C_base::isActiveFlagOverrunUnderrun(){
	return LL_I2C_IsActiveFlag_OVR(I2Cx);
}

bool I2C_base::isActiveFlagBusBusy(){
	return LL_I2C_IsActiveFlag_BUSY(I2Cx);
}

bool I2C_base::isActiveFlagDual(){
	return LL_I2C_IsActiveFlag_DUAL(I2Cx);
}

bool I2C_base::isActiveFlagGeneralCallAddressReception(){
	return LL_I2C_IsActiveFlag_GENCALL(I2Cx);
}

bool I2C_base::isActiveFlagMasterMode(){
	return LL_I2C_IsActiveFlag_MSL(I2Cx);
}


void I2C_base::clearFlagAddress(){
	LL_I2C_ClearFlag_ADDR(I2Cx);
}

void I2C_base::clearFlagAcknowledgeFailure(){
	LL_I2C_ClearFlag_AF(I2Cx);
}

void I2C_base::clearFlagStopDetection(){
	LL_I2C_ClearFlag_STOP(I2Cx);
}

void I2C_base::clearFlagBussError(){
	LL_I2C_ClearFlag_BERR(I2Cx);
}

void I2C_base::clearFlagAribitrationLost(){
	LL_I2C_ClearFlag_ARLO(I2Cx);
}

void I2C_base::clearFlagOverrunUnderrun(){
	LL_I2C_ClearFlag_OVR(I2Cx);
}


void I2C_base::enableReset(){
	LL_I2C_EnableReset(I2Cx);
}

void I2C_base::disableeReset(){
	LL_I2C_DisableReset(I2Cx);
}

bool I2C_base::isEnableReset(){
	return LL_I2C_IsResetEnabled(I2Cx);
}


void I2C_base::enableGeneralCall(){
	LL_I2C_EnableGeneralCall(I2Cx);
}

void I2C_base::disableGeneralCall(){
	LL_I2C_DisableGeneralCall(I2Cx);
}

bool I2C_base::isEnableGeneralCall(){
	return LL_I2C_IsEnabledGeneralCall(I2Cx);
}


void I2C_base::setOwnAddrerss1(uint16_t address, AddressSize OwnAddressSize){
	if(OwnAddressSize == I2C_base::AddressSize::BIT7){
		address <<= 1;
	}
	LL_I2C_SetOwnAddress1(I2Cx, address, (uint32_t)OwnAddressSize);
}

uint16_t I2C_base::getOwnAddress1(){
	uint16_t oar1 = READ_REG(I2Cx->OAR1);
	if(oar1 & 0b1<<15){
		return oar1 & 0b1111111111;
	}else{
		return (oar1 >> 1) & 0b1111111;
	}
}

void I2C_base::setOwnAddrerss2(uint8_t address){
	LL_I2C_SetOwnAddress2(I2Cx, address);
}

void I2C_base::enableOwnAddress2(){
	LL_I2C_EnableOwnAddress2(I2Cx);
}

void I2C_base::disableOwnAddress2(){
	LL_I2C_DisableOwnAddress2(I2Cx);
}

bool I2C_base::isEnableOwnAddress2(){
	return LL_I2C_IsEnabledOwnAddress2(I2Cx);
}

void I2C_base::generateStartCondition(){
	LL_I2C_GenerateStartCondition(I2Cx);
}

void I2C_base::generateStopCondition(){
	LL_I2C_GenerateStopCondition(I2Cx);
}

uint8_t I2C_base::receive8bit(){
	return LL_I2C_ReceiveData8(I2Cx);
}

void I2C_base::transmit8bit(uint8_t data){
	LL_I2C_TransmitData8(I2Cx, data);
}


I2C_base::TransferDirection I2C_base::getTransferDirection(){
	uint32_t tmp = LL_I2C_GetTransferDirection(I2Cx);
	if(tmp == LL_I2C_DIRECTION_WRITE){
		return I2C_base::TransferDirection::Write;
	}else{
		return I2C_base::TransferDirection::Read;
	}
}
}
#endif /*#ifndef CONFIG_DISABLE_MODULE_I2C*/
