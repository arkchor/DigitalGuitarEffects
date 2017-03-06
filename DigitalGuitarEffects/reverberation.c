/*****************************************************************************/
/*                                                                           */
/* FILENAME                                                                  */
/*  reverberation.c                                                          */
/*                                                                           */
/* DESCRIPTION                                                               */
/*   TMS320C5505 USB Stick. Reverberation based on 200 ms delay.             */
/*                                                                           */
/* REVISION                                                                  */
/*   Revision: 1.00                                                          */
/*   Author  : Richard Sikora                                                */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/* HISTORY                                                                   */
/*   Revision 1.00                                                           */
/*   27th January 2010. Created by Richard Sikora from C5510 code.           */
/*                                                                           */
/*****************************************************************************/

//#define N 8000
//#define DEPTH 12000

#define N 12000
#define DEPTH 20000

//#define N2 12000
//#define DEPTH2 32767

signed int reverberation_array[N]; /* Buffer for maximum of 200 ms delay */
//signed int reverberation_array2[N2];

/*****************************************************************************/
/* reverberation_array_clear()                                               */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/* Fill reverberation_array[] used for reverberation with zeroes to prevent  */
/* noise and clicks.                                                         */
/*                                                                           */
/*****************************************************************************/

void reverberation_array_clear(void)
{
 int i;
 
 for ( i = 0 ; i < N ; i++)
  {
   reverberation_array[i] = 0;
  }
}

/*****************************************************************************/
/* reverberation()                                                           */
/*****************************************************************************/

signed int reverberation( signed int latest_input)
{
 static signed int index = 0; /* Retain value between calls */
 signed long temp;
 signed long oldest_input;
 

 oldest_input =  ((long) reverberation_array[index] * DEPTH); /* Scale oldest sample */
 
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
 
 reverberation_array[index] = temp; /* Overwrite buffer with new value */
 
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
/*
void reverberation_array_clear2(void)
{
 int i;
 
 for ( i = 0 ; i < N ; i++)
  {
   reverberation_array2[i] = 0;
  }
}
*/
/*****************************************************************************/
/* reverberation()                                                           */
/*****************************************************************************/
/*
signed int reverberation2( signed int latest_input)
{
 static signed int index = 0; Retain value between calls
 signed long temp;
 signed long oldest_input;
 

 oldest_input =  ((long) reverberation_array2[index] * DEPTH2);// Scale oldest sample
 
 oldest_input >>= 15; //Remove fractional part 
 
 temp = (long) latest_input + oldest_input; // Newest + oldest

 temp >>= 1;  // Divide by two 
 
 if ( temp > 32767) // Limit positive to maximum in case of overload
   {
    temp = 32767;
   } 
 else if ( temp < -32767) // Limit negative to minimum 
   { 
    temp = -32767;
   }
 
 reverberation_array2[index] = temp; // Overwrite buffer with new value 
 
 if ( index < N2 - 1)  // Increment index if not at end of buffer 
   {
    index++;
   }  
 else
   {
    index = 0;  // Otherwise go back to beginning of buffer 
   }
   
 return( (signed int) temp); // Return new output 

}
*/
/*****************************************************************************/
/* End of reverberation.c                                                    */
/*****************************************************************************/
