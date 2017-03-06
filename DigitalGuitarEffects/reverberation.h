/*****************************************************************************/
/*                                                                           */
/* FILENAME                                                                  */
/*  reverberation.h                                                          */
/*                                                                           */
/* DESCRIPTION                                                               */
/*   Header file to generate reverberation effect using an infinite impulse  */
/*   response (IIR) configuration.                                           */                                               
/*                                                                           */
/* REVISION                                                                  */
/*   Revision: 1.00                                                          */
/*   Author  : Richard Sikora                                                */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/* HISTORY                                                                   */
/*   Revision 1.00                                                           */
/*   9th October 2002. Created by Richard Sikora from C6711 code.            */
/*                                                                           */
/*****************************************************************************/

#ifndef REVERBERATION_H
#define REVERBERATION_H
 
 void reverberation_array_clear(void);              
 
 signed int reverberation( signed int latest_input);
 
 //void reverberation_array_clear2(void);              
 
 //signed int reverberation2( signed int latest_input);
 
#endif

/*****************************************************************************/
/* End of reverberation.c                                                    */
/*****************************************************************************/



  
