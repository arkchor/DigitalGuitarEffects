/*****************************************************************************/
/*                                                                           */
/* FILENAME                                                                  */
/*  echo.c                                                                   */
/*                                                                           */
/* DESCRIPTION                                                               */
/*   TMS320C5505 USB Stick. Echo based on delay up to 0.5 seconds.           */
/*                                                                           */
/* REVISION                                                                  */
/*   Revision: 1.00                                                          */
/*   Author  : Richard Sikora                                                */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/* HISTORY                                                                   */
/*   Revision 1.00                                                           */
/*   27th January 2010. Created by Richard Sikora from echo.c                */
/*                                                                           */
/*****************************************************************************/

#define N 32000

signed int echo_array[N]; /* Buffer for maximum of 0.5s delay */

/*****************************************************************************/
/* echo_array_clear()                                                        */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/* Fill echo_array[] used for echo with zeroes to prevent                    */
/* noise and clicks. Call this function when changing buffer length.         */
/*                                                                           */
/*****************************************************************************/

void echo_array_clear(void)
{
 int i;
 
 for ( i = 0 ; i < N ; i++)
  {
   echo_array[i] = 0;
  }
}

/*****************************************************************************/
/* echo()                                                                    */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/* Simple echo. Uses full buffer length and depth of effect is fixed.        */
/*                                                                           */
/*****************************************************************************/

signed int echo( signed int latest_input)
{
 static signed int index = 0; /* Retain value between calls */
 signed long temp;
 signed long oldest_input;
 

 oldest_input =  ((long) echo_array[index] * 30000); /* Scale oldest sample */
 
 oldest_input >>= 15; /* Remove fractional part */
 
 temp = (long) latest_input + oldest_input; /* Newest + oldest */

 temp >>= 1;  /* Divide by two */
 
 if ( temp > 32767) /* Limit positive to maximum in case of overload */
   {
    temp = 32767;
   } 
 else if ( temp < -32767) /* Limit negative to minimum */
   { 
    temp = -32767;
   }
 
 echo_array[index] = latest_input; /* Overwrite buffer with new value */
 
 if ( index < N - 1)  /* Increment index if not at end of buffer */
   {
    index++;
   }  
 else
   {
    index = 0;  /* Otherwise go back to beginning of buffer */
   }
   
 return( (signed int) temp); /* Return new output */

}

/*****************************************************************************/
/* variable_echo()                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/* Variable echo. Takes 3 input parameters:                                  */
/*                                                                           */
/* Parameter 1: Input from ADC.                                              */
/* Parameter 2: Number of delay elements to be used between 1 and N.         */ 
/* Parameter 3: Depth. 0 = No echo. 32767 = 100% of input used for echo.     */
/*                                                                           */
/*****************************************************************************/


signed int variable_echo(signed int latest_input, unsigned int length, unsigned int depth)
{
 static signed int index = 0; /* Retain value between calls */
 signed long temp;
 signed long oldest_input;
 unsigned int local_depth;
 unsigned int buffer_length;

 if ( depth > 32767)
   {
     local_depth = 32767; /* Limit to range 0 to 32767 */
   }
 else
  {
     local_depth = depth;
  }
  

 if ( length > N)
  {
     buffer_length = N; /* Length specified is greater than size of buffer. Limit. */
  }
 else
  {
     buffer_length = length; 
  }
 

 oldest_input =  ((long) echo_array[index] * local_depth); /* Scale oldest sample */
 
 oldest_input >>= 15; /* Remove fractional part */
 
 temp = (long) latest_input + oldest_input; /* Newest + oldest */

 temp >>= 1;  /* Divide by two */
 

 if ( temp > 32767) /* Limit positive to maximum in case of overload */
   {
    temp = 32767;
   } 
 else if ( temp < -32767) /* Limit negative to minimum */
   { 
    temp = -32767;
   }
 
 echo_array[index] = latest_input; /* Overwrite buffer with new value */
 
 if ( index < buffer_length - 1)  /* Increment index if not at end of buffer */
   {
    index++;
   }  
 else
   {
    index = 0;  /* Otherwise go back to beginning of buffer */
   }
   
 return( (signed int) temp); /* Return new output */

}


/*****************************************************************************/
/* End of echo.c                                                             */
/*****************************************************************************/
