#include "win_socket_server.h"

namespace ns_win_socket_server
{
    // [클래스 변수 할당]

    // [클래스 함수 구현]
    // (클래스 생성 콜백)
    WinSocketServer::WinSocketServer() : isRunning(false)
    {
    }

    // (클래스 소멸 콜백)
    WinSocketServer::~WinSocketServer()
    {
    }

    // (소켓 서버 실행)
    int WinSocketServer::startSocketServer(int port)
    {
        if (isRunning)
        {
            return 1;
        }

        isRunning = true;

        // Step1 : Windows 소켓 라이브러리 초기화
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        {
            isRunning = false;
            return 2;
        }

        // Step2 : 서버 소켓 생성
        serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (serverSocket == INVALID_SOCKET)
        {
            isRunning = false;
            return 3;
        }

        // 서버 주소 설정
        memset(&serverAddr, 0, sizeof(serverAddr)); // 데이터를 0 으로 변경
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(port); // 빅 엔디안으로 변경
        serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); // 빅 엔디안으로 변경

        // Step3 : 소켓에 주소 / 포트번호 바인딩
        if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
        {
            closesocket(serverSocket);
            isRunning = false;
            return 4;
        }

        // Step4 : 리스닝 시작 (할당된 주소 / 포트번호 Open 후 클라이언트의 connect 요청 대기)
        if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
        {
            closesocket(serverSocket);
            isRunning = false;
            return 5;
        }

        std::cout << "Server is listening on port " << port << std::endl;

        // 클라이언트 연결을 대기하고 처리
        while (isRunning)
        {
            // Step5 : 요청을 보낸 클라이언트의 주소 / 포트번호 정보를 가져오고 client 의 소켓 가져오기
            int clientAddrSize = sizeof(clientAddr);
            clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrSize);
            if (clientSocket == INVALID_SOCKET)
            {
                continue;
            }

            const char *message = "Hello, Client!";
            send(clientSocket, message, strlen(message), 0);

            // 클라이언트 소켓 닫기
            closesocket(clientSocket);  // 클라이언트 소켓을 닫지 않아야 서버가 계속 통신 가능
        }

        return 0;
    }

    void WinSocketServer::closeSocketServer()
    {
        if (isRunning)
        {
            std::cout << "Closing the server." << std::endl;
            // 서버 소켓 닫기
            closesocket(serverSocket);

            // Windows 소켓 라이브러리 정리
            WSACleanup();

            isRunning = false;
        }
    }
}