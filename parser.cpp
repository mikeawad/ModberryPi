
#include "headers.h"


/*+-----------------------------------------------------------------+

This will serve as the parser for incoming modbus requests.


+-------------------------------------------------------------------+*/

void parseRequest(const uint8_t * mBuffer)
{

uint16_t transactionId =  mBuffer[0] | mBuffer[1] << 8;
uint16_t dataLength =  mBuffer[5] | mBuffer[4] << 8;

    if(DEBUG_MODE)
    {
	printf("Transaction ID: %04x\n",transactionId);
	printf("DataL: %04x\n",dataLength);
        printf("Transaction ID: %02x%02x\n",mBuffer[0], mBuffer[1]);
    	printf("Protocol ID: %02x%02x\n",mBuffer[2], mBuffer[3]);
    	printf("Length: %02x%02x\n",mBuffer[4], mBuffer[5]);
    	printf("Unit ID: %02x\n",mBuffer[6]);
    	printf("FC: %02x\n\n",mBuffer[7]);
    }
}


