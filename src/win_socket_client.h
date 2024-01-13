#pragma once

// !!!ifndef �̸� ���� - ���ϸ� �빮��!!!
#ifndef WIN_SOCKET_CLIENT
#define WIN_SOCKET_CLIENT

// !!![���̺귯�� include]!!!
#include <winsock2.h>
#include <iostream>
#include <stdexcept>

// !!!using namespace ����!!!

// !!!namespace ���� - ns_{���ϸ�}�� ����!!!
namespace ns_win_socket_client
{
	// !!!Ŭ������ ����(���ϸ��� �Ľ�Į ǥ�������)!!!
	class WinSocketClient
	{
		// !!![����/�Ҹ��� ����]!!!
	public:
		WinSocketClient();
		~WinSocketClient();

		// !!![���� ����]!!!
	private:
        WSADATA wsaData;
        SOCKET clientSocket;
        SOCKADDR_IN serverAddr;

		// !!![�Լ� ����]!!!
	public:
        int connectToSocketServer(const char *serverAddress, int port);
        void disconnectFromSocketServer();
	};
}

#endif