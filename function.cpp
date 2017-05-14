/*Header File--------------------------------------------------------------------------*/
#include "function.h"

/*Private Variables--------------------------------------------------------------------*/

//String that holds the function code

string const K_PPARAMS = "01010101";

/*Getters and Setters------------------------------------------------------------------*/

//Returns function_code
//string get_function_code(void)
//{
//	return function_code;
//}

/*Private Functions--------------------------------------------------------------------*/

//Reads the next byte, stores in function_code
void read_function_code(void)
{
	string function_code = "";
	if (find_sync_byte() == 1)
	{
		reset_serialtime();
		function_code = read_byte();
		if (function_code == K_PPARAMS) // Setting Parameters
		{
			build_struct();
			assign_values();
		}
		else
		{
			flush_serial();
		}
		// Egrams
	}
	
}
