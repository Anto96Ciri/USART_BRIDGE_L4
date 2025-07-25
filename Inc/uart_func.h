/*
 * uart_func.h
 *
 *  Created on: Feb 19, 2025
 *      Author: CirincioneA
 */

#ifndef INC_UART_FUNC_H_
#define INC_UART_FUNC_H_

//Riavvio modalità ricezione interrupt
void readUserInput(void);
//chiamata una volta ricevuti tutti i BYTE
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle);
//Calcolo del checksum
UCHAR CheckSum(CCHAR *msg, USHORT len);
#endif /* INC_UART_FUNC_H_ */
