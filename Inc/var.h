/*
 * var.h
 *
 *  Created on: Jul 17, 2025
 *  Author: Antonio Cirincione
 */

#ifndef INC_VAR_H_
#define INC_VAR_H_

/*
 * @AC: UART Variables
 */

//Buffer Ricezione e Trasmissione
CCHAR 				Rx_Byte[1] = {0};									//Singolo Byte ricevuto
CCHAR 				Rx_data[MAX_LEN_RX];								//Messaggio ricevuto
CCHAR				Tx_buffer[MAX_LENGTH_BUFFER];								//Buffer di trasmissione, salviamo i byte ricevuti per trasmetterli

CCHAR 				attesa[MAX_LENGTH_BUFFER]="ABCDEFGHILMNOPQRSTUVZ";	//attesa[MAX_LENGTH_BUFFER] = "ABCDEFGHILMNOPQRSTUVZ";
uint8_t 			index_atteso = 0;  									//posizione del carattere atteso

//Indici UART
SHORT				i_rx = 0;											//Indice del BYTE correntemente ricevuto
SHORT				i_tx = 0;											//Indice del BYTE correntemente ricevuto e che verrùà trasmesso
SHORT 				i_buf = 0;											//Indice del
UCHAR 				tx_busy = 0; 										//Trasmissione in corso
UCHAR				STATE = ENDLINE;

//Flag
FlagStatus			UartReady  = SET;									//Flag per riabilitare la ricezione UART PCCOM-Micro
HAL_StatusTypeDef 	UARTSTATUS = HAL_ERROR;								//Check lettura UART

#endif /* INC_VAR_H_ */
