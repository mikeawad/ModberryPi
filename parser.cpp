
#include "headers.h"


/*+-----------------------------------------------------------------+

This will serve as the parser for incoming modbus requests.


+-------------------------------------------------------------------+*/

void parseRequest(const uint8_t * mBuffer)
{

uint16_t transactionId =  mBuffer[0] << 8 | mBuffer[1];
uint16_t protocolId = mBuffer[2] << 8 | mBuffer[3];
uint16_t dataLength = mBuffer[4] << 8 | mBuffer[5];

    if(DEBUG_MODE)
    {
	printf("Transaction ID: %04x\n",transactionId);
	printf("Protocol ID: %04x\n",protocolId);
	printf("Data Length: %04x\n",dataLength);

    	printf("Unit ID: %02x\n",mBuffer[6]);
    	printf("FC: %02x\n\n",mBuffer[7]);
    }
}


// temporary function
void buildresponse(uint8_t * mBuffer)
{
    mBuffer[8] = 0xCD;
    mBuffer[9] = 0x6B;
    mBuffer[10] = 0xB2;
    mBuffer[11] = 0x0E;
    mBuffer[12] =0x1B;
    mBuffer[5] = 0x5;

}



