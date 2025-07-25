/*
 * app.c
 *
 *  Created on: Jul 17, 2025
 *      Author: CirincioneA
 */

#include "main.h"
#include "definizioni.h"
#include "extFunc.h"
#include "uart_func.h"
#include "string.h"
#include "stdio.h"
/*
 * Funzione per l'inizializzazione
*/

void App_Init(void)
{
	memset(Rx_data, 0, sizeof(Rx_data));
	memset(Tx_buffer, 0, sizeof(Tx_buffer));
	//attesa[MAX_LENGTH_BUFFER] = "ABCDEFGHILMNOPQRSTUVZ"; 						//buffer di controllo per test.
}

/*
 * Ciclo while
 */
void App_RunCycle(void)
{
	readUserInput();															//Riavvio della ricezione

	//char *msg = "HELLO PC\r\n";
	//HAL_UART_Transmit_IT(&huart2, (uint8_t*)msg, strlen(msg));				//Trasmetti un byte
	//HAL_UART_Transmit(&hlpuart1, (uint8_t*)msg, sizeof(msg), HAL_MAX_DELAY);
	//HAL_Delay(1000);

	if (CAN_TRANSMIT) 															//Non stiamo già trasmettendo e ci sono nuovi byte da trasmettere
	{
		//HAL_UART_Transmit_IT(&huart2, (uint8_t*)&Tx_buffer[i_tx], 1);			//Trasmetti un byte
		//tx_busy = 1;

//		if(Tx_buffer[i_tx] == attesa[index_atteso]){index_atteso += 1;}
//		else
//		{
//			printf("errato");
//		}
	}
}
