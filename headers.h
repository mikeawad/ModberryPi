#pragma once

/// #includes - all header files
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>		 // needed to use socklent_t (32 bit)
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>        	 //needed for memset
#include <iostream>		 //cout and  cin,  will not be needed if resorting to printf()
#include <fstream>		 // file I/O



//// #DEFINES
#define BUFFER_SIZE 260
#define PORT_502 502
#define HOLDING_OFFSET 40001




/// PROTOTYPES
void  backUpRegister();
void regCounter();
///void parseRequest(const uint8_t * mBuffer, uint8_t * nBuffer);
void buildresponse(uint8_t * rBuffer);
void parseRequest(const uint8_t * mBuffer, int mBufferBytes, uint8_t * nBuffer);


typedef struct mb_msg
{
	uint16_t trans_id;
	uint16_t protocol_id;
	uint16_t msg_size;
	uint8_t  unit_id;
	uint8_t  fc_code;

}mb_msg_t;

typedef struct holding_reg
{
	mb_msg_t header;
	uint16_t address;
	uint16_t num_reg;
	uint16_t crc;

}holding_reg_t;
