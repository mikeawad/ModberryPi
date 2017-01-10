#include "headers.h"


int main(int argc, char *argv[])
{
    int sockfd,                                   // socket file descriptor for binding to port for connections
        commsSocket,                              // socket file descriptor for communication on bound socket
        byteCount;				  // variable for catching the return and byte count from recv()
    socklen_t clilen;                             // get size of client ip address, needed for accept()
    uint8_t incomingBuffer[BUFFER_SIZE];          // data buffer of size BUFFER_SIZE bytes
    uint8_t outgoingBuffer[BUFFER_SIZE];	  // return request buffe
    struct sockaddr_in serv_addr, cli_addr;       // structs to hold connection information

    backUpRegister();
    regCounter();

/*+---------------------------------------------------------------------------------------------------------------------------+
				Socket connection
+----------------------------------------------------------------------------------------------------------------------------+*/


    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
	 error("Error opening socket");
    }

    memset(&serv_addr, 0, sizeof serv_addr);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(502);


    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        error("Binding error");
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    commsSocket = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (commsSocket < 0)
    {
        error("Error on accept");
    }

    printf("\n*** Server: got connection from %s on port %d *** \n\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

//==============================================================================================================================

    bzero(incomingBuffer, BUFFER_SIZE); // zero out the incoming buffer to remove any potential garbage

    for(;;)
    {
        byteCount = recv(commsSocket,incomingBuffer, BUFFER_SIZE, 0);
        if (byteCount < 0)
        {
            error("error reading from socket");
        }

	parseRequest(incomingBuffer,byteCount, outgoingBuffer);

        int sentVale = send(commsSocket, incomingBuffer, BUFFER_SIZE, 0);
    }

    close(sockfd);
    close(commsSocket);

    return 0;
}
