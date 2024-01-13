#pragma once

// !!!ifndef 이름 수정 - 파일명 대문자!!!
#ifndef WIN_SOCKET_CLIENT
#define WIN_SOCKET_CLIENT

// !!![라이브러리 include]!!!
#include <winsock2.h>
#include <iostream>
#include <stdexcept>

// !!!using namespace 설정!!!

// !!!namespace 선언 - ns_{파일명}과 동일!!!
namespace ns_win_socket_client
{
	// !!!클래스명 선언(파일명을 파스칼 표기법으로)!!!
	class WinSocketClient
	{
		// !!![생성/소멸자 선언]!!!
	public:
		WinSocketClient();
		~WinSocketClient();

		// !!![변수 선언]!!!
	private:
        WSADATA wsaData;
        SOCKET clientSocket;
        SOCKADDR_IN serverAddr;

		// !!![함수 선언]!!!
	public:
        int connectToSocketServer(const char *serverAddress, int port);
        void disconnectFromSocketServer();
	};
}

#endif