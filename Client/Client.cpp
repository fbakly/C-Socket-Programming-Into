#include "Client.h"

using namespace std;

void main()
{
	//locals
	long SUCCESSFUL;
	WSAData WinSockData;
	WORD DLLVersion;
	DLLVersion = MAKEWORD(2, 1);
	SUCCESSFUL = WSAStartup(DLLVersion, &WinSockData);

	string RESPONSE;
	string CONVERTER;
	char MESSAGE[200];

	SOCKADDR_IN ADDRESS;

	SOCKET sock;
	sock = socket(AF_INET, SOCK_STREAM, NULL);

	ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");
	ADDRESS.sin_family = AF_INET;
	ADDRESS.sin_port = htons(444);

	do {
		cout << "\n\tCLIENT: Do you want to connect to this server? (Y/N) ";
		cin >> RESPONSE;
		RESPONSE[0] = tolower(RESPONSE[0]);
	} while (RESPONSE[0] != 'y' && RESPONSE[0] != 'n');

	if (RESPONSE == "n")
		cout << "\nOK. Quitting now.";
	else
	{
		connect(sock, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
		SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
		CONVERTER = MESSAGE;
		cout << "\n\tMessage from SERVER:\n\n\t" << CONVERTER << endl;
	}

	cout << "\n\n\t";
	system("PAUSE");
	exit(1);
}