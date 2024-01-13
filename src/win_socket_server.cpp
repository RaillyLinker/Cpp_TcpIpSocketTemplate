#include "win_socket_server.h"

namespace ns_win_socket_server
{
    // [Ŭ���� ���� �Ҵ�]

    // [Ŭ���� �Լ� ����]
    // (Ŭ���� ���� �ݹ�)
    WinSocketServer::WinSocketServer() : isRunning(false)
    {
    }

    // (Ŭ���� �Ҹ� �ݹ�)
    WinSocketServer::~WinSocketServer()
    {
    }

    // (���� ���� ����)
    int WinSocketServer::startSocketServer(int port)
    {
        if (isRunning)
        {
            return 1;
        }

        isRunning = true;

        // Step1 : Windows ���� ���̺귯�� �ʱ�ȭ
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        {
            isRunning = false;
            return 2;
        }

        // Step2 : ���� ���� ����
        serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (serverSocket == INVALID_SOCKET)
        {
            isRunning = false;
            return 3;
        }

        // ���� �ּ� ����
        memset(&serverAddr, 0, sizeof(serverAddr)); // �����͸� 0 ���� ����
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(port); // �� ��������� ����
        serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); // �� ��������� ����

        // Step3 : ���Ͽ� �ּ� / ��Ʈ��ȣ ���ε�
        if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
        {
            closesocket(serverSocket);
            isRunning = false;
            return 4;
        }

        // Step4 : ������ ���� (�Ҵ�� �ּ� / ��Ʈ��ȣ Open �� Ŭ���̾�Ʈ�� connect ��û ���)
        if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
        {
            closesocket(serverSocket);
            isRunning = false;
            return 5;
        }

        std::cout << "Server is listening on port " << port << std::endl;

        // Ŭ���̾�Ʈ ������ ����ϰ� ó��
        while (isRunning)
        {
            // Step5 : ��û�� ���� Ŭ���̾�Ʈ�� �ּ� / ��Ʈ��ȣ ������ �������� client �� ���� ��������
            int clientAddrSize = sizeof(clientAddr);
            clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrSize);
            if (clientSocket == INVALID_SOCKET)
            {
                continue;
            }

            const char *message = "Hello, Client!";
            send(clientSocket, message, strlen(message), 0);

            // Ŭ���̾�Ʈ ���� �ݱ�
            closesocket(clientSocket);  // Ŭ���̾�Ʈ ������ ���� �ʾƾ� ������ ��� ��� ����
        }

        return 0;
    }

    void WinSocketServer::closeSocketServer()
    {
        if (isRunning)
        {
            std::cout << "Closing the server." << std::endl;
            // ���� ���� �ݱ�
            closesocket(serverSocket);

            // Windows ���� ���̺귯�� ����
            WSACleanup();

            isRunning = false;
        }
    }
}