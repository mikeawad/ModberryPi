
#include "headers.h"


using namespace std;


// reusable error function, just pass in message
void error(const char *msg)
{
    perror(msg);
    exit(1);
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

int main(int argc, char *argv[])
{
    int sockfd,                                   // socket file descriptor for binding to port for connections
        commsSocket,                              // socket file descriptor for communication on bound socket
        byteCount;
    socklen_t clilen;                             // get size of client ip address, needed for accept()
    uint8_t buffer[BUFFER_SIZE];                  // data buffer of size BUFFER_SIZE bytes
    struct sockaddr_in serv_addr, cli_addr;       // structs to hold connection information
    
    backUpRegister();
    regCounter();
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
    bzero(buffer, BUFFER_SIZE);

    for(;;)
    {
        byteCount = recv(commsSocket, buffer, BUFFER_SIZE, 0);

        if (byteCount < 0)
        {
            error("error reading from socket");
        }

        cout << "Modubus message in: ";
        for (int i = 0; i < byteCount; i++)
        {
            printf("%02x ", buffer[i]);
        }
        printf("\n");

        parseRequest(buffer);
        buildresponse(buffer);
/*
        cout << "Modbus message out: ";
        for (int i = 0; i < byteCount; i++)
        {
            printf("%02x ", buffer[i]);
        }
*/
        printf("\n");

        int sentVale = send(commsSocket, buffer, BUFFER_SIZE, 0);
    }
    close(sockfd);
    close(commsSocket);

    return 0;
}
