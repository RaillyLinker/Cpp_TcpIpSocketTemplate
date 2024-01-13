#pragma once

// !!!ifndef 이름 수정 - 파일명 대문자!!!
#ifndef WIN_SOCKET_SERVER
#define WIN_SOCKET_SERVER

// !!![라이브러리 include]!!!
#include <winsock2.h>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

// !!!using namespace 설정!!!

// !!!namespace 선언 - ns_{파일명}과 동일!!!
namespace ns_win_socket_server
{
	// !!!클래스명 선언(파일명을 파스칼 표기법으로)!!!
	/**
	 * @brief 윈도우 소켓 서버 클래스
	 * @details 윈도우 소켓 서버입니다.
	 * @author RaillyLinker
	 * @date 2023-12-26
	 * @version 1.0.0
	 */
	class WinSocketServer
	{
		// !!![생성/소멸자 선언]!!!
	public:
		WinSocketServer();
		~WinSocketServer();

		// !!![변수 선언]!!!
	public:
		bool isRunning; // 서버 실행 여부

	private:
		WSADATA wsaData;	 // Windows 소켓 초기화 정보
		SOCKET serverSocket; // 서버 소켓
		SOCKADDR_IN serverAddr; // 서버 주소

		SOCKET clientSocket; // 클라이언트 소켓
		SOCKADDR_IN clientAddr; // 클라이언트 주소

		// !!![함수 선언]!!!
	public:
		// 서버 시작 함수
		int startSocketServer(int port);

		// 서버 종료 함수
		void closeSocketServer();
	};
}

#endif