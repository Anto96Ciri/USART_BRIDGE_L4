/*
 * extFunc.h
 *
 *  Created on: Jul 17, 2025
 *      Author: CirincioneA
 */

#ifndef INC_EXTFUNC_H_
#define INC_EXTFUNC_H_

//Buffer Ricezione e Trasmissione
extern CCHAR 				Rx_Byte[1];							//Byte ricevuto corrente
extern CCHAR 				Rx_data[MAX_LEN_RX];				//messaggio ricevuto
extern CCHAR				Tx_buffer[MAX_LEN_TX];

//Indici UART
extern SHORT				i_rx;								//indice del BYTE correntemente ricevuto
extern SHORT				i_tx;								//indice del BYTE trasmesso
extern SHORT 				i_buf;								//indice del buffer di trasmissione salvato
extern UCHAR 				tx_busy;
extern SHORT 				tx_count;
extern CCHAR 				attesa[];
extern uint8_t 				index_atteso;  					//posizione del carattere atteso
//Flag
extern FlagStatus			UartReady;
extern HAL_StatusTypeDef 	UARTSTATUS;							//check lettura UART

//UART Handle
extern UART_HandleTypeDef   huart2;
extern UART_HandleTypeDef 	huart1;

#endif /* INC_EXTFUNC_H_ */
