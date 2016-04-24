#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "allvars.h"
#include "proto.h"

/*! \darkenergy.c 
 *  \Multiplicative factors for H(a).
 *  
 *  Refer to darkenergy.pdf in the Documentation
 *  for an explanation of the parameterizations.  
 */

double de_factor(double a,int choice)
{
	switch (choice)
	{

                case 0: 
		return 1;
		break;

		case 1: 
		return pow(a,-3*(1 + All.CurDEParam + All.DEParamCoeff)) * exp(-3*All.DEParamCoeff*(1-a));
		break;
	
		case 2:
		return pow(a,-3*(1 + All.CurDEParam)) * exp(1.5*All.DEParamCoeff*(1-a)*(1-a));
		break;

		case 3:
		return pow(a,-3*(1 + All.CurDEParam)) * pow((a*a + (1-a)*(1-a))/(a*a),1.5*All.DEParamCoeff);
		break;

		case 4:
		return pow(a,-3*(1 + All.CurDEParam / ( 1 - All.DEParamCoeff*log(a) ) ) );
		break;
	}
}



