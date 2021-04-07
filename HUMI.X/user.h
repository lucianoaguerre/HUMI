/****************************************************************************
* Title                 :   user defined functions   
* Filename              :   user.h
* Author                :   Luciano Aguerre
* Origin Date           :   08/03/2021
* Version               :   1.0.0
* Compiler              :   MPLAB XC8 v2.30
* Target                :   PIC16F18854
* Notes                 :   None
*
*
*****************************************************************************/
/** @file  user.h
 *  @brief Este archivo contiene las definiciones y las declaraciones
 * 
 *  
 */

/******************************************************************************
* Includes
*******************************************************************************/
#include <xc.h> // include processor files - each processor file is guarded.

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
// PORT A
#define BOTON_B   PORTAbits.RA0
#define BOTON_A   PORTAbits.RA1   
#define LED_GRN   LATAbits.LATA2   
#define LED_RED   LATAbits.LATA3   

// PORT B
//#define ICSPCLK LATBbits.LATB6  //SALIDA	0   
//#define ICSPDAT LATBbits.LATB7  //SALIDA  0

// PORT C
#define RELE4     LATCbits.LATC0  
#define RELE3     LATCbits.LATC1  
#define RELE2     LATCbits.LATC2  
#define RELE1     LATCbits.LATC3  

#define SYS_FREQ            32000000
#define FCY                 SYS_FREQ/4
#define _XTAL_FREQ          32000000

/******************************************************************************
* Configuration Constants
*******************************************************************************/


/******************************************************************************
* Macros
*******************************************************************************/

	
/******************************************************************************
* Typedefs
*******************************************************************************/


/******************************************************************************
* Variables
*******************************************************************************/
uint16_t        system_state = 0;
uint16_t        segundos = 0;
uint16_t        milisegundos = 0;
uint16_t        minutos = 0;

/******************************************************************************
* Function Prototypes
*******************************************************************************/
void reg_confs(void);
void timer_minuto (uint16_t retardo);
/*** End of File **************************************************************/
