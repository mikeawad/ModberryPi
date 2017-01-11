#include "headers.h"

/*+-----------------------------------------------------------------+

This will serve as the parser for incoming modbus requests.

+-------------------------------------------------------------------+*/

void parseRequest(const uint8_t * mBuffer, int mBufferBytes, uint8_t * nBuffer)
{

        bzero(nBuffer, BUFFER_SIZE);                    // zero out response buffer

        mb_msg_t * input_msg = (mb_msg_t *) mBuffer;
        mb_msg_t * output_msg = (mb_msg_t *) nBuffer;

        output_msg->trans_id = htons(input_msg->trans_id);
        output_msg->protocol_id = htons(input_msg->protocol_id);
        output_msg->msg_size = htons(input_msg->msg_size);
        output_msg->unit_id = input_msg->unit_id;
        output_msg->fc_code = input_msg->fc_code;
	output_msg->starting_address = htons(input_msg->starting_address);
	output_msg->num_reg = htons(input_msg->num_reg);


#ifdef DEBUG_MODE
    {
	printf("\n================ MBAP Header Information =================\n");
	printf("Transaction ID: %04x\n",output_msg->trans_id);     // bytes 0,1
	printf("Protocol ID: %04x\n",output_msg->protocol_id);	  // bytes 2,3
	printf("Data Length: %04x\n",output_msg->msg_size);	  // bytes 4,5
    	printf("Unit ID: %02x\n",output_msg->unit_id);		  // bytes 6
    	printf("FC: %02x\n",output_msg->fc_code);		  // bytes 7
	printf("==========================================================\n");

	printf("\n================ Requested Data ==========================\n");
	printf("First requested register: %04x\n", output_msg->starting_address);
	printf("Total number of registers requested: %04x\n", output_msg->num_reg);
	printf("==========================================================\n\n");

    }
#endif

	// print buffer - this should be turned into generic callable print buffer function
	printf("================ Buffers =================================\n");
      	printf("Modubus message in: ");
        for (int i = 0; i < mBufferBytes; i++)
        {
            printf("%02x ", mBuffer[i]);
        }
	printf("\n==========================================================\n... ... ...\n");
     	//-------- end print buffer code segment ---------

}
