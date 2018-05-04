#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>

int main(){
	struct sockaddr_in serverAddress;
	int serverSocket;
	int clientSocket;
	char clientMsg[1000];
	char *hello = "Hello World";

	serverSocket = socket(PF_INET, SOCK_STREAM, 0);

	memset(&serverAddress, '0', sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.sin_addr = htonl(INADOR_ANY);
	serverAddress.sin_port = htons(5000);
	bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
	listen(serverSocket, 10);
	while(1){
		clientSocket = accept(serverSocket, (struct sockaddr *) NULL, NULL );
		write(clientSocket, hello, strlen(hello));
		close(clientSocket, clientMsg, 10000);
		//close(clientSocket);
	}
	return 0;
}