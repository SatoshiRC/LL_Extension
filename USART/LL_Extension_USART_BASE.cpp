/*
 * LL_Extension_USART.cpp
 *
 *  Created on: Dec 5, 2020
 *      Author: conat
 */
#include "LL_Extension_USART_BASE.hpp"

namespace llex{
void USART_Base::enable(){
	LL_USART_Enable(USARTx);
}

void USART_Base::disable(){
	LL_USART_Disable(USARTx);
}

bool USART_Base::isEnable(){
	return (bool)LL_USART_IsEnabled(USARTx);
}

void USART_Base::enableDirectionTx(){
	LL_USART_EnableDirectionTx(USARTx);
}

void USART_Base::disableDirectionTx(){
	LL_USART_DisableDirectionTx(USARTx);
}

void USART_Base::enableDirectionRx(){
	LL_USART_EnableDirectionRx(USARTx);
}

void USART_Base::disableDirectionRx(){
	LL_USART_DisableDirectionRx(USARTx);
}

void USART_Base::setParity(Parity parity){
	LL_USART_SetParity(USARTx, (uint32_t)parity);
}

USART_Base::Parity USART_Base::getParity(){
	return (Parity)LL_USART_GetParity(USARTx);
}

void USART_Base::SetWakeUpMethod(WakeUpMethod wakeUpMethod){
	LL_USART_SetWakeUpMethod(USARTx, (uint32_t)wakeUpMethod);
}

USART_Base::WakeUpMethod USART_Base::GetWakeUpMethod(){
	return (WakeUpMethod)LL_USART_GetWakeUpMethod(USARTx);
}

void USART_Base::setDataWidth(DataWidth dataWidth){
	LL_USART_SetDataWidth(USARTx, (uint32_t)dataWidth);
}

USART_Base::DataWidth USART_Base::getDataWidth(){
	return (DataWidth)LL_USART_GetDataWidth(USARTx);
}

void USART_Base::SetStopBitsLength(StopBitsLength stopBitsLength){
	LL_USART_SetStopBitsLength(USARTx, (uint32_t)stopBitsLength);
}

USART_Base::StopBitsLength USART_Base::getStopBitsLength(){
	return (StopBitsLength)LL_USART_GetStopBitsLength(USARTx);
}

void USART_Base::SetNodeAddress(uint8_t nodeAddress){
	if(nodeAddress > 0xf) return;
	LL_USART_SetNodeAddress(USARTx, nodeAddress);
}

uint8_t USART_Base::GetNodeAddress(){
	return LL_USART_GetNodeAddress(USARTx);
}

bool USART_Base::isActiveFlag_PE(){
	return (bool)LL_USART_IsActiveFlag_PE(USARTx);
}

bool USART_Base::isActiveFlag_FE(){
	return (bool)LL_USART_IsActiveFlag_FE(USARTx);
}

bool USART_Base::isActiveFlag_NE(){
	return (bool)LL_USART_IsActiveFlag_NE(USARTx);
}

bool USART_Base::isActiveFlag_ORE(){
	return (bool)LL_USART_IsActiveFlag_ORE(USARTx);
}

bool USART_Base::isActiveFlag_IDLE(){
	return (bool)LL_USART_IsActiveFlag_IDLE(USARTx);
}

bool USART_Base::isActiveFlag_RXNE(){
	return (bool)LL_USART_IsActiveFlag_RXNE(USARTx);
}

bool USART_Base::isActiveFlag_TC(){
	return (bool)LL_USART_IsActiveFlag_TC(USARTx);
}

bool USART_Base::isActiveFlag_TXE(){
	return (bool)LL_USART_IsActiveFlag_TXE(USARTx);
}

bool USART_Base::isActiveFlag_LBD(){
	return (bool)LL_USART_IsActiveFlag_LBD(USARTx);
}

bool USART_Base::isActiveFlag_nCTS(){
	return (bool)LL_USART_IsActiveFlag_nCTS(USARTx);
}

bool USART_Base::isActiveFlag_SBK(){
	return (bool)LL_USART_IsActiveFlag_SBK(USARTx);
}

bool USART_Base::isActiveFlag_RWU(){
	return (bool)LL_USART_IsActiveFlag_RWU(USARTx);
}

void USART_Base::clearFlag_PE(){
	LL_USART_ClearFlag_PE(USARTx);
}

void USART_Base::clearFlag_FE(){
	LL_USART_ClearFlag_FE(USARTx);
}

void USART_Base::clearFlag_NE(){
	LL_USART_ClearFlag_NE(USARTx);
}

void USART_Base::clearFlag_ORE(){
	LL_USART_ClearFlag_ORE(USARTx);
}

void USART_Base::clearFlag_IDLE(){
	LL_USART_ClearFlag_IDLE(USARTx);
}

void USART_Base::clearFlag_RXNE(){
	LL_USART_ClearFlag_RXNE(USARTx);
}

void USART_Base::clearFlag_TC(){
	LL_USART_ClearFlag_TC(USARTx);
}

void USART_Base::clearFlag_LBD(){
	LL_USART_ClearFlag_LBD(USARTx);
}

void USART_Base::clearFlag_nCTS(){
	LL_USART_ClearFlag_nCTS(USARTx);
}

void USART_Base::enableReceiveIT(){
	LL_USART_EnableIT_RXNE(USARTx);
}

void USART_Base::disableReceiveIT(){
	LL_USART_DisableIT_RXNE(USARTx);
}

bool USART_Base::isEnableReceiveIT(){
	return LL_USART_IsEnabledIT_RXNE(USARTx);
}

void USART_Base::enableIdleIT(){
	LL_USART_EnableIT_IDLE(USARTx);
}

void USART_Base::disableIdleIT(){
	LL_USART_DisableIT_IDLE(USARTx);
}

bool USART_Base::isEnableIdleIT(){
	return LL_USART_IsEnabledIT_IDLE(USARTx);
}

void USART_Base::enableBreakDetectionIT(){
	LL_USART_EnableIT_LBD(USARTx);
}

void USART_Base::disableBreakDetectionIT(){
	LL_USART_DisableIT_LBD(USARTx);
}

bool USART_Base::isEnableBreakDetectionIT(){
	return LL_USART_IsEnabledIT_LBD(USARTx);
}

void USART_Base::transmitData8Bits(uint8_t value){
	LL_USART_TransmitData8(USARTx, value);
}

void USART_Base::transmitData9Bits(uint16_t value){
	if(value > 0x1ff) return;
	LL_USART_TransmitData9(USARTx, value);
}

void USART_Base::transmitData(uint16_t value){
	if(getParity() == Parity::None){
		transmitData8Bits(value);
	}else{
		transmitData9Bits(value);
	}
}

uint8_t USART_Base::receiveData8Bits(){
	return LL_USART_ReceiveData8(USARTx);
}

uint16_t USART_Base::receiveData9Bits(){
	return LL_USART_ReceiveData9(USARTx);
}

uint16_t USART_Base::receiveData(){
	if(getParity() == Parity::None){
		return receiveData8Bits();
	}else{
		return receiveData9Bits();
	}
}

}
