/* DEFINIZIONI */

//#define USB_USE_LSE_MSI_CLOCK

//----------------- ADC DEFINE

typedef char                UCHAR;      /* 1byte senza segno  */
typedef signed char         SCHAR;      /* 1 byte con segno */
typedef signed char         I8;         /* 1 byte con segno */
typedef char                CCHAR;      /* 1 byte senza segno */
typedef unsigned char       BOOLEAN;    /* logico */
typedef unsigned short      USHORT;     /* 2byte senza segno */
typedef signed short        SHORT;      /* 2 byte con segno */
typedef unsigned long int   UINT;       /* 4byte senza segno */
typedef signed long int     INT;        /* 4byte con segno */
typedef float               FLOAT;      /* 4byte in singola precisione */
typedef float               F32;       	/* 4byte in singola precisione */
typedef double              DOUBLE;     /* 4byte in singola precisione */
typedef void *              PVOID;      /*   */
typedef char                UINT8;      /* 1byte senza segno  */
typedef unsigned int        UINT16;     /* 2byte senza segno */
typedef unsigned long int   UINT32;     /* 4byte senza segno */
typedef unsigned long long  ULONG64;    /* 8byte senza segno */
typedef signed long int     INT32;      /* 4byte senza segno */
typedef signed long long    LONG64;     /* 8byte senza segno */
typedef unsigned short      U16;        /* 2byte senza segno */

#define TIPO_UCHAR	        0
#define TIPO_USHORT         1
#define TIPO_LONG	        2
#define TIPO_FLOAT	        3

//UI-PROTCOL Variables
#define S_SOH	  			0x01	//Record beginning identifier
#define S_EOT				0x04	//Communication session end identifier
#define S_LF				0x0A	//Record end identifier
#define MAX_LEN_RX 			1		//Numero massimo di caratteri del messaggio msgRx
#define MAX_LEN_TX			21
#define MAX_LENGTH_BUFFER	21

#define ENDLINE				0		//FINE STRINGA DI TEST
#define NEWLINE				1		//AGGIORNAMENTO PER TRASMISSIONE "\n"


//UART
#define TX_IS_READY 		(!tx_busy)							/*Si può trasmettere un dato*/
#define TX_BUFFER_HAS_DATA 	(i_tx != i_buf)						/*Buffer di trasmissione ha nuovi dati da trasmettere*/
#define CAN_TRANSMIT		(TX_IS_READY && TX_BUFFER_HAS_DATA) /*Si può trasmettere un byte all'altro micro */

//Grandezza Buffer di trasmissione verso micro

//VEFF ESTIMATION DEFINE
#define ZERO_CAB			0
#define VEFF				1
#define IDLE				2
#define PIGRECO        		3.1415926
#define RADICE2        		sqrt(2)

/* EOF */
