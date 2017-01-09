#include "headers.h"
/*+-----------------------------------------------------------------+

This will serve as the anlaog input holding registers array.
Address range from 0000h to 270Eh (40001-49999)
Access type: Read/Write

+-------------------------------------------------------------------+*/

uint16_t analogInputHoldingRegisters[9998];

/// using this temporarily as a means of assigning the value of the location to the location itself for debugging. 
void  backUpRegister()
{
	//std::ofstream writeToRegister;
	//writeToRegister.open("HoldingRegisters.txt");
	for (uint16_t i = 0; i <= 9998; i++)
	{
	 analogInputHoldingRegisters[i] = i;
	// printf("Analog register %i = %02x --> data address = %i\n", i, analogInputHoldingRegisters[i], i + HOLDING_OFFSET);
	// writeToRegister << i << "\n";
	}
	//writeToRegister.close();
}

void regCounter()
{
	int numOfElements = sizeof(analogInputHoldingRegisters) / sizeof(analogInputHoldingRegisters[0]);
	//printf("** analogInputHoldingRegisters[] has %i number of elements in it\and has %i bytes\n", numOfElements, sizeof(analogInputHoldingRegisters[0]));
}
