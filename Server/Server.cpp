#include "Server.h"

using namespace std;

int main()
{
	// main locals
	long SUCCESSFUL;
	WSAData WinSockData;
	WORD DLLVERSION;

	// WORDS = objects of a data size that a processor naturally handles such as 16 bit or 32 bit
	DLLVERSION = MAKEWORD(2, 1);

	// Start WinSock DLL
	SUCCESSFUL = WSAStartup(DLLVERSION, &WinSockData);

	// Create Socket Structure
	SOCKADDR_IN ADDRESS;
	int AddressSize = sizeof(ADDRESS);

	// Create Sockets
	SOCKET sock_LISTEN;	// Listens for an incoming connection
	SOCKET sock_CONNECTION; // Activates if a connection is found

	// socket Arguments: AF_INET = internet domian (not unix domain)
	// SOCK_STREAM = connection oriented TCP (not SOCK_DGRAM)
	sock_CONNECTION = socket(AF_INET, SOCK_STREAM, NULL);
	ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");	// SET IP ADDRESS
	ADDRESS.sin_family = AF_INET;
	ADDRESS.sin_port = htons(444); // Port

	sock_LISTEN = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sock_LISTEN, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
	listen(sock_LISTEN, SOMAXCONN);

	// if connection is found
	for (;;)
	{
		cout << "\n\tSERVER: Waiting for incoming connection...";

		if (sock_CONNECTION = accept(sock_LISTEN, (SOCKADDR*)&ADDRESS, &AddressSize))
		{
			cout << "\n\tA connection was found!" << endl;
			
			SUCCESSFUL = send(sock_CONNECTION,  "Welcome! You have connceted to the server!", 46, NULL);
		}
	}
	return (0);
}