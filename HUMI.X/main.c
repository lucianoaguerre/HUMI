/*******************************************************************************
* Title                 :   Funciones principales   
* Filename              :   main.c
* Author                :   Luciano Aguerre
* Origin Date           :   08/03/2021
* Version               :   1.0.0
* Compiler              :   MPLAB XC8 v2.30
* Target                :   PIC16F18854
* Notes                 :   None
*
* THIS SOFTWARE IS PROVIDED BY BENINGO ENGINEERING "AS IS" AND ANY EXPRESSED
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL BENINGO ENGINEERING OR ITS CONTRIBUTORS BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
*******************************************************************************/

/*************** SOURCE REVISION LOG *******************************************
*
*    Date    Version   Author         Description 
*  04/01/15   1.0.0   Jacob Beningo   Initial Release.
*
*******************************************************************************/

/** @file main.c
 *  @brief Estas son las funciones principales del sistema 
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <xc.h>
#include <pic16f18854.h>   

#include "user.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/
/**
 * Doxygen tag for documenting variables and constants
 */
#define SYS_FREQ            32000000
#define FCY                 SYS_FREQ/4
#define _XTAL_FREQ          32000000

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/


/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
void reg_confs(void) 
{
    //-------------- OSCILLATOR CONFIG DEFINITIONS -----------------------------
    OSCCON1 = 0b00000000;
    OSCCON3 = 0b00000000;
    OSCEN   = 0b01000000;
    OSCFRQ  = 0b00000110;   //32MHz
    //--------------------------------------------------------------------------
    PCON0bits.nBOR = 1;
    PCON0bits.nPOR = 1;
    //---- PERIPHERAL MODULES SHUTDOWN -----------------------------------------
    PMD0 = 0b01111111;
    PMD1 = 0b11111111;
    PMD2 = 0b11111111;
    PMD3 = 0b11111111;
    PMD4 = 0b11111111;
    PMD5 = 0b11111111;
 
    //---- PORTS CONFIG DEFINITIONS --------------------------------------------
    // PORTA
    TRISA   = 0b00000011;
    LATA    = 0b00000000;
    PORTA   = 0b00000000;
    ANSELA  = 0b00000000;
    WPUA    = 0b00000000;
    ODCONA  = 0b00000000;
    SLRCONA = 0b00000000;
    INLVLA  = 0b00000000;
    // PORTB        
    TRISB   = 0b00000000;
    LATB    = 0b00000000;
    PORTB   = 0b00000000;
    ANSELB  = 0b00000000;
    WPUB    = 0b00000000;
    ODCONB  = 0b00000000;
    SLRCONB = 0b00000000;
    INLVLB  = 0b00000000;
    // PORTC
    TRISC   = 0b00000000;
    LATC    = 0b00000000;
    PORTC   = 0b00000000;
    ANSELC  = 0b00000000;
    WPUC    = 0b00000000;
    ODCONC  = 0b00000000;
    SLRCONC = 0b00000000;
    INLVLC  = 0b00000000;       
    //-------------- INTERRUPT CONFIG DEFINITIONS ------------------------------
    INTCON = 0b00000000;  // GIE & PI
    PIE0 = 0b00000000;    // TMR0 & IOC & EXT_INT
    PIE1 = 0b00000000;    // OSFIE & CSWIE & ADC 
    PIE2 = 0b00000000;    // ZERO CROSS & COMPARATORS
    PIE3 = 0b00000000;    // USART & SERIAL COM
    PIE4 = 0b00000000;    // TIMERS OVERFLOW
    PIE5 = 0b00000000;    // CLC & TIMERS GATES
    PIE6 = 0b00000000;    // CCP 
    PIE7 = 0b00000000;    // SCAN & WAVEFOR GENERATOR 
    PIE8 = 0b00000000;    // SMT ADQUISITIONS
    PIR0 = 0x00;
    PIR1 = 0x00;
    PIR2 = 0x00;
    PIR3 = 0x00;
    PIR4 = 0x00;
    PIR5 = 0x00;
    PIR6 = 0x00;
    PIR7 = 0x00;
    PIR8 = 0x00;
    return;
}

/*************** END OF FUNCTIONS ***************************************************************************/

//------------------------------------------------------------------------------
void timer_minuto (uint16_t retardo)
{
    for (minutos = 0; minutos < retardo; minutos++)
    {
        for (segundos = 0; segundos < 60; segundos++)
        {
            for (milisegundos = 0; milisegundos < 10; milisegundos++)
            {
                __delay_ms(100);
            }
        }
    }
    return;
}

//------------------------------------------------------------------------------
void main(void) 
{
    NOP();
    reg_confs();
    system_state = 0;
    RELE1 = 0;
    RELE2 = 0;
    RELE3 = 0;
    RELE4 = 0;
                   
    LED_GRN = 0;
    LED_RED = 1;

    //-----------------------------------------------------------
    while (1)
    {
        switch(system_state)
        {
            case 0:
                if (!BOTON_A)   
                {
                    __delay_ms(10);
                    if (!BOTON_A)
                    {
                        system_state = 1;
                        RELE1 = 1;
                        RELE2 = 1;
                        RELE3 = 0;
                        RELE4 = 1;
                    
                        LED_GRN = 1;
                        LED_RED = 0;
                    }        
                }
                
                if (!BOTON_B)   
                {
                    __delay_ms(10);
                    if (!BOTON_B)
                    {
                        system_state = 2;
                        RELE1 = 1;
                        RELE2 = 1;
                        RELE3 = 0;
                        RELE4 = 1;
                    
                        LED_GRN = 1;
                        LED_RED = 0;
                    }        
                }   
                break;
                
            case 1:
                // dispara timer de 5 minutos
                timer_minuto (5);
                system_state = 3;
                break;
                
            case 2:
                timer_minuto (15);
                system_state = 3;
                //dispara timer de 15 minuts
                break;
                
            case 3:
                // apaga los leds y vuelva  
                system_state = 0;
                RELE1 = 0;
                RELE2 = 0;
                RELE3 = 1;
                RELE4 = 0;
                
                for (segundos = 0; segundos < 3; segundos++)
                {
                    for (milisegundos = 0; milisegundos < 10; milisegundos++)
                    {
                        __delay_ms(100);
                    }
                }
                
                RELE3 = 0;    
                LED_GRN = 0;
                LED_RED = 1;
                break;
                
            default:
                break;
        }
    }
}

/*************** END OF FILE ***************************************************************************/