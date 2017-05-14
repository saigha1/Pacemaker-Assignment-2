/*Module Includes----------------------------------------------------------------------*/
#include "serial.h"
#include "parameters.h"
//#include "egram.h"

/*Library Includes---------------------------------------------------------------------*/
#include <string>

/*Std----------------------------------------------------------------------------------*/
using std::string;

//Getters and Setters------------------------------------------------------------------*/
string get_function_code(void);

//Private Functions--------------------------------------------------------------------*/
void read_function_code(void);
