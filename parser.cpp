
#include "headers.h"


/*+-----------------------------------------------------------------+

This will serve as the parser for incoming modbus requests.


+-------------------------------------------------------------------+*/

void parseRequest(const uint8_t * mBuffer, int mBufferBytes, uint8_t * nBuffer)
{

uint16_t *startingAddressPtr,
	*endingAddressPtr;
uint16_t transactionId =  mBuffer[0] << 8 | mBuffer[1];
uint16_t protocolId = mBuffer[2] << 8 | mBuffer[3];
uint16_t dataLength = mBuffer[4] << 8 | mBuffer[5];
uint16_t startingLocation = mBuffer[8] << 8 | mBuffer[9];
uint16_t numberRegisters = mBuffer[10] << 8| mBuffer[11];
uint8_t calclatedLength;

#ifdef DEBUG_MODE
    {
	printf("\n============== MBAP Header Information ==============\n");
	printf("Transaction ID: %04x\n",transactionId);   // bytes 0,1
	printf("Protocol ID: %04x\n",protocolId);	  // bytes 2,3
	printf("Data Length: %04x\n",dataLength);	  // bytes 4,5
    	printf("Unit ID: %02x\n",mBuffer[6]);		  // bytes 6
    	printf("FC: %02x\n",mBuffer[7]);		  // bytes 7
	printf("======================================================\n");	

	printf("\n============== Requested Data ========================\n");
	printf("First requested register: %02x%02x\n",mBuffer[8], mBuffer[9]);
	printf("Total number of registers requested: %02x%02x\n",mBuffer[10], mBuffer[11]);
	printf("======================================================\n\n"); 

    }
#endif
	bzero(nBuffer, BUFFER_SIZE);			// zero out response buffer
	memcpy(nBuffer,mBuffer, 4); 			// copy first 4 bytes into new buffer
	memcpy( (nBuffer + 6), (mBuffer + 6), 2);	// copy unit ID into new buffer, also FC but this will need to be  through error checking
	nBuffer[4] = mBuffer[4];			// length  - temporary
	nBuffer[5] = mBuffer[5];			// length - temporary
/*
	startingAddressPtr = analogInputHoldingRegisters + startingLocation;


	for (uint16_t count = 0; count <= numberRegisters; count++)
	{
		printf("\nCount = %d\n",count);	
	}
*/
	// print buffer - this should be turned into generic callable print buffer function
	printf("============== Buffers ===============================\n");
       	std:: cout << "Modubus message in: ";
        for (int i = 0; i < mBufferBytes; i++)
        {
            printf("%02x ", mBuffer[i]);
        }

        std::cout << "\nFrom copied buffer: ";
        for (int i = 0; i < 12 ; i++)
        {
            printf("%02x ", nBuffer[i]);
        }
	printf("\n======================================================\n\n...\n\n"); 
     		//-------- end print buffer code segment ---------

}



// temporary function
void buildresponse(uint8_t * rBuffer)
{
    rBuffer[8] = 0xCD;
    rBuffer[9] = 0x6B;
    rBuffer[10] = 0xB2;
    rBuffer[11] = 0x0E;
    rBuffer[12] =0x1B;
    rBuffer[5] = 0x5;

}



