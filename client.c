
#include <stdio.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h> 
#include <stdlib.h> 
#include <unistd.h>

int main(){
	int clientSocket;
	char message[1024];
	struct sockaddr_in serverAddr;
	socklen_t addr_size;
	
	clientSocket = socket(PF_INET, SOCK_STREAM, 0);

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(5356);
	serverAddr.sin_addr.s_addr = 
inet_addr("192.168.184.137");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
	addr_size = sizeof serverAddr;
	connect(clientSocket, (struct sockaddr *) &serverAddr, 
addr_size);
	
	while(1){
	
	printf("Enter a text : " , message );
	scanf("%s",message);
	
	char a[] = "quit";
	
	send(clientSocket, message, 50, 0);
	recv(clientSocket, message, 50, 0);
	
	

	if(strcasecmp(message,a)==0)
	{ break; }
	else;
	
	printf("Server Reply: %s\n", message);

	
	}
	close(clientSocket);
	return 0;
}

