#pragma once

// !!!ifndef �̸� ���� - ���ϸ� �빮��!!!
#ifndef WIN_SOCKET_SERVER
#define WIN_SOCKET_SERVER

// !!![���̺귯�� include]!!!
#include <winsock2.h>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

// !!!using namespace ����!!!

// !!!namespace ���� - ns_{���ϸ�}�� ����!!!
namespace ns_win_socket_server
{
	// !!!Ŭ������ ����(���ϸ��� �Ľ�Į ǥ�������)!!!
	/**
	 * @brief ������ ���� ���� Ŭ����
	 * @details ������ ���� �����Դϴ�.
	 * @author RaillyLinker
	 * @date 2023-12-26
	 * @version 1.0.0
	 */
	class WinSocketServer
	{
		// !!![����/�Ҹ��� ����]!!!
	public:
		WinSocketServer();
		~WinSocketServer();

		// !!![���� ����]!!!
	public:
		bool isRunning; // ���� ���� ����

	private:
		WSADATA wsaData;	 // Windows ���� �ʱ�ȭ ����
		SOCKET serverSocket; // ���� ����
		SOCKADDR_IN serverAddr; // ���� �ּ�

		SOCKET clientSocket; // Ŭ���̾�Ʈ ����
		SOCKADDR_IN clientAddr; // Ŭ���̾�Ʈ �ּ�

		// !!![�Լ� ����]!!!
	public:
		// ���� ���� �Լ�
		int startSocketServer(int port);

		// ���� ���� �Լ�
		void closeSocketServer();
	};
}

#endif