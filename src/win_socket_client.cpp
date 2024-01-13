#include "win_socket_client.h"

namespace ns_win_socket_client
{
	// [Ŭ���� �Լ� ����]
	// (Ŭ���� ���� �ݹ�)
	WinSocketClient::WinSocketClient() : clientSocket(INVALID_SOCKET)
	{
	}

	// (Ŭ���� �Ҹ� �ݹ�)
	WinSocketClient::~WinSocketClient()
	{
	}

    int WinSocketClient::connectToSocketServer(const char *serverAddress, int port)
    {
        if (clientSocket != INVALID_SOCKET)
        {
            return 1; // �̹� ����� ���
        }

        clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (clientSocket == INVALID_SOCKET)
        {
            return 2;
        }

        memset(&serverAddr, 0, sizeof(serverAddr));
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = inet_addr(serverAddress);
        serverAddr.sin_port = htons(port);

        if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
        {
            closesocket(clientSocket);
            clientSocket = INVALID_SOCKET;
            return 4;
        }

        std::cout << "Connected to the server." << std::endl;

        return 0;
    }

    void WinSocketClient::disconnectFromSocketServer()
    {
        if (clientSocket != INVALID_SOCKET)
        {
            std::cout << "Disconnecting from the server." << std::endl;
            closesocket(clientSocket);
            clientSocket = INVALID_SOCKET;
        }
    }
}