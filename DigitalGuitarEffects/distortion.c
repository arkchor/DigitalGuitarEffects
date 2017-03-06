#include "distortion.h"

signed long int distortion(signed long int xin, int obciecie, int wzmocnienie)
{
	signed long int yout;
	if ( xin > obciecie )
	{
		yout = obciecie;
	}
	else if( xin < -obciecie )
	{
		yout = -obciecie;
	}
	else
	{
		yout = xin;
	}
	if ( wzmocnienie*yout > 32767 )
	{
		return 32767;
	}
	else
	{
		return wzmocnienie*yout;
	}
}
