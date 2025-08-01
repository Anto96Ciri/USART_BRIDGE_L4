/*
 * uart_func.c
 *
 *  Created on: Feb 19, 2025
 *  Author: CirincioneA
 */

#include "main.h"
#include "definizioni.h"
#include "extFunc.h"

/*
 * readUserInput
 * Description: Questa funzione serve per riavviare la ricezione
 * in modalità interrupt. All'avvio del programma UartReady è sempre
 * vera, in modo tale che la HAL_UART_Receive_IT() serva per configurare
 * la ricezione e UartReady = RESET. Quindi non si entrerà più dentro all'if
 * finché, ricevuti 6 Byte, non si richiami la callback che setta UartReady = SET;
 * e riavvia l'ascolto tramite interrupt. UartReady inizializzata come RESET.
 */

void readUserInput(void)
{
	if(UartReady == SET)
	{
		UartReady = RESET;
		UARTSTATUS = HAL_UART_Receive_IT(&huart1, (uint8_t*)Rx_Byte, 1); 			//ricezione interrupt byte-per-byte
	}
}

//UART - CALLBACK
/*
 * Quando la trasmissione è completata, si entra nella callback
 * e si setta il flag per riavviare la ricezione in modalità interrupt.
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart == &huart1) 															//RICEZIONE DA PC
	{
		//HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin);
		Tx_buffer[i_buf] 	= Rx_Byte[0]; 											//salvo nel buffer di trasmissione nella posizione corrente
		Rx_Byte[0] 			= 0; 													//pulizia del byte letto
		//Aggiornamento
		if( i_buf < (MAX_LENGTH_BUFFER-1) ){i_buf +=1;}
		else {i_buf = 0;}
		UartReady = SET;															//set transmission flag: transfer complete

	}
}

//UART - CALLBACK
/*
 * Quando la trasmissione è completata, si entra nella callback
 * e si setta il flag per riavviare la ricezione in modalità interrupt.
 */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart == &huart2)
	{
		switch (STATE)
		{
			case ENDLINE: // Fine linea di Test
				if (++i_tx >= MAX_LENGTH_BUFFER)
				{
					i_tx = 0;
					STATE = NEWLINE;														// il ciclo dopo non devo incrementare i_tx!
					HAL_UART_Transmit_IT(&huart2, (uint8_t*)"\n", 1);						//trasmetto a capo
				}
			break;

			case NEWLINE: // Aggiornamento NEWLINE "\n"
				STATE = ENDLINE;
				i_tx = 0;
			break;
		}
		tx_busy = 0; 																//trasmissione finita → pronto per prossimo byte
	}
}
