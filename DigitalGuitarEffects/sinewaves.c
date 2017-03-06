/*****************************************************************************/
/*                                                                           */
/* FILENAME                                                                  */
/*   sinewaves.c                                                             */
/*                                                                           */
/* DESCRIPTION                                                               */
/*   Sinewave generation for the TMS320C5505 USB Stick.                      */
/*                                                                           */
/*   Generates two sinewaves of adjustable frequency using sine() function   */
/*   in 55xdsph.lib                                                          */
/*                                                                           */
/*   The frequency of range of the sine wave is 10 Hz to 8000 Hz.            */
/*                                                                           */
/* REVISION                                                                  */
/*   Revision: 1.00                                                          */
/*   Author  : Richard Sikora                                                */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/* HISTORY                                                                   */
/*                                                                           */
/*   Revision 1.00                                                           */
/*   20th December 2009. Created by Richard Sikora from TMS320C5510 code.    */
/*                                                                           */
/*****************************************************************************/
/*
 *
 * Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/ 
 * 
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/

#include "tms320.h"
#include "dsplib.h"

/*****************************************************************************/
/* generate_sinewave_1()                                                     */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/* Generate a sinewave. Based on sampling rate of 48000 Hz.                  */
/*                                                                           */
/*                                                                           */
/* PARAMETER 1: The frequency of the sinewave between 10 Hz and 16000 Hz.    */ 
/* PARAMETER 2: The maximum amplitude of the sinewave between 1 to 32767.    */
/*                                                                           */
/*****************************************************************************/

signed int generate_sinewave_1( signed short int frequency, 
                                signed short int amplitude)
{
 short int sinusoid;
 signed long result;
 static short int count = 0;
 
 /* Multiply frequency by scaling factor of 32767 / 48000 */
 
 result = ( (long)frequency * 22368 ) >> 14 ;
 
 if ( result > 32767)
   {
     result = 32767; /* Maximum value for highest frequency */
   }
 else if ( 0 == result)  
   {
     result = 1;     /* Minimum value for lowest fequency */
   }
 else if ( result < -32767)
   {
     result = -32767;
   }  
 
 count += (short int) result; 
 
 /* Obtain sine of input */

 sine ( &count, &sinusoid, 1);

 if ( amplitude > 32767 )
   {
     amplitude = 32767; /* Range limit amplitude */
   } 

 /* Scale sine wave to have maximum value set by amplitude */

 result =  ( (long) sinusoid * amplitude ) >> 15;
 
 return ( (signed int ) result );
}

/*****************************************************************************/
/* generate_sinewave_2()                                                     */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/* Generate a second sinewave.                                               */
/*                                                                           */
/*                                                                           */
/* PARAMETER 1: The frequency of the sinewave between 10 Hz and 16000 Hz.    */ 
/* PARAMETER 2: The maximum amplitude of the sinewave between 1 to 32767.    */
/*                                                                           */
/*****************************************************************************/

signed int generate_sinewave_2( signed short int frequency, 
                                signed short int amplitude)
{
 short int sinusoid;
 signed long result;
 static short int count = 0;
 
 /* Multiply frequency by scaling factor of ratio 32767 / 48000 */
 
 result = ( (long) frequency * 22368 ) >> 14 ;
 
 if ( result > 32767)
   {
     result = 32767; /* Maximum value for highest frequency */
   }
 else if ( 0 == result)  
   {
     result = 1;     /* Minimum value for lowest fequency */
   }
 else if ( result < -32767)
   {
     result = -32767;
   }  
 
 count += (signed int) result; 
 
 /* Obtain sine of input */

 sine ( &count, &sinusoid, 1);

 if ( amplitude > 32767 )
   {
     amplitude = 32767; /* Range limit amplitude */
   } 

 /* Scale sine wave to have maximum value set by amplitude */

 result =  ( (long) sinusoid * amplitude ) >> 15;
 
 return ( (signed int ) result );
}

/******************************************************************************/
/* End of sinewaves.c                                                         */
/******************************************************************************/

