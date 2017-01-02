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

