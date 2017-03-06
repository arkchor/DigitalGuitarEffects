/*****************************************************************************/
/*                                                                           */
/* FILENAME                                                                  */
/*  echo.h                                                                   */
/*                                                                           */
/* DESCRIPTION                                                               */
/*   Header file to generate echo effect using an finite impulse             */
/*   response (FIR) filter configuration.                                    */                                               
/*                                                                           */
/* REVISION                                                                  */
/*   Revision: 1.00                                                          */
/*   Author  : Richard Sikora                                                */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/* HISTORY                                                                   */
/*   Revision 1.00                                                           */
/*   27th January 2010. Created by Richard Sikora from reverberation.h       */
/*                                                                           */
/*****************************************************************************/

#ifndef echo_H
#define echo_H
 
 void echo_array_clear(void);              
 
 signed int echo( signed int latest_input);
 
 signed int variable_echo(signed int latest_input, unsigned int length, unsigned int depth);
 
#endif

/*****************************************************************************/
/* End of echo.c                                                    */
/*****************************************************************************/



  
