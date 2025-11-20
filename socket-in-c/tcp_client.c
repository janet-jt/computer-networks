#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main(void)
{
	
	// create a socket
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	// specify an adress for the socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET; //AF_INET means using IPv4
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY; //server_address holding the information of that addr & sin_addr is a structure, in this structure has s_addr field & INADDR_ANY = (0.0.0.0)

	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	// check for error with the connection
	if (connection_status == -1){
		fprintf(stderr, "There was an error making a connection to the remote socket \n\n");
	}
	// recieve data from the server
	char server_response[256];
	recv(network_socket, &server_response, sizeof(server_response), 0); //recv:receive message from a socket
	
	// print out the server's response
	printf("The server sent the data: %s\n", server_response);

	// and then close the socket
	close(network_socket);

	return 0;
}
