#include <iostream>
#include <WS2tcpip.h>
#include <string>
#include <thread>

#define UNCALLED 0
#define FAILED -1
#define IP_INPUT 1
#define CONNECTING 2
#define CONNECTED 3

#pragma comment (lib, "ws2_32.lib")

void Server(SOCKET* sock, int* serverStatus, std::string* receive)
{
	// winsock �ʱ� ����
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	int wsOk = WSAStartup(ver, &wsData);
	if (wsOk != 0)
	{
		*serverStatus = FAILED;
		return;
	}

	// ���� ����
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET)
	{
		*serverStatus = FAILED;
		return;
	}

	// ���Ͽ� ip�� ��Ʈ ����
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(727);
	hint.sin_addr.S_un.S_addr = INADDR_ANY;

	bind(listening, (sockaddr*)&hint, sizeof(hint));

	// ���� listening ����
	listen(listening, SOMAXCONN);

	// Ŭ���̾�Ʈ ����

	sockaddr_in client;
	int clientSize = sizeof(client);

	*serverStatus = CONNECTING;
	*sock = accept(listening, (sockaddr*)&client, &clientSize);

	// Ŭ���̾�Ʈ ���� �Ϸ�

	*serverStatus = CONNECTED;

	char host[NI_MAXHOST];		// Ŭ���̾�Ʈ �̸�
	char service[NI_MAXSERV];	// Ŭ���̾�Ʈ ���� ����

	memset(host, 0, NI_MAXHOST);
	memset(service, 0, NI_MAXSERV);

	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) != 0)
	{
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		ntohs(client.sin_port);
	}

	// ���� listening ����
	closesocket(listening);

	char buf[4096];

	while (true)
	{
		memset(buf, 0, 4096);

		// Ŭ���̾�Ʈ���Լ� ������ ���� ���
		int bytesReceived = recv(*sock, buf, 4096, 0);
		
		if (bytesReceived == SOCKET_ERROR || bytesReceived == 0)
		{
			system("cls");
			std::cout << "Ŭ���̾�Ʈ���� ������ ������ϴ�." << std::endl;
			exit(1);
		}
		
		*receive = std::string(buf, 0, bytesReceived);
	}

	// ���� �ݱ�
	closesocket(*sock);

	// winsock �ݱ�
	WSACleanup();
	system("pause");
}

void Client(SOCKET* sock, int* clientStatus, std::string* receive)
{
	int port = 727;
	std::string ipAddress;

	*clientStatus = IP_INPUT;

	while (ipAddress.length() <= 0)
	{
		std::cin >> ipAddress;
	}

	*clientStatus = CONNECTING;

	// winsock �ʱ� ����
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		*clientStatus = FAILED;
		return;
	}

	// ���� ����
	*sock = socket(AF_INET, SOCK_STREAM, 0);
	if (*sock == INVALID_SOCKET)
	{
		WSACleanup();

		*clientStatus = FAILED;
		return;
	}

	// hint ����ü �ʱ�ȭ
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	// ���� ����
	int connResult = connect(*sock, (sockaddr*)&hint, sizeof(hint));
	
	// ���� ����
	if (connResult == SOCKET_ERROR)
	{
		closesocket(*sock);
		WSACleanup();

		*clientStatus = FAILED;
		return;
	}

	*clientStatus = CONNECTED;

	char buf[4096];
	std::string userInput;

	while (true)
	{
		memset(buf, 0, 4096);

		// �������Լ� ������ ���� ���
		int bytesReceived = recv(*sock, buf, 4096, 0);
		
		if (bytesReceived == SOCKET_ERROR || bytesReceived == 0)
		{
			system("cls");
			std::cout << "�������� ������ ������ϴ�." << std::endl;
			exit(1);
		}

		*receive = std::string(buf, 0, bytesReceived);
	}

	closesocket(*sock);
	WSACleanup();
}

void Send(SOCKET sock, std::string request)
{
	send(sock, request.c_str(), request.size() + 1, 0);
	return;
}