#pragma once

// !!!ifndef 이름 수정 - 파일명 대문자!!!
#ifndef TEMPLATE
#define TEMPLATE

// !!![라이브러리 include]!!!
#include <string>
#include <iostream>

// !!!namespace 선언 - ns_{파일명}과 동일!!!
namespace ns_template
{
	// !!!클래스명 선언(파일명을 파스칼 표기법으로)!!!
	/**
	 * @brief 템플릿 클래스
	 * @details 템플릿 클래스입니다.
	 * @author RaillyLinker
	 * @date 2023-12-26
	 * @version 1.0.0
	 */
	class Template
	{
		// !!![변수 선언]!!!
	public:
		/**
		 * @brief 샘플 정수값
		 * @details 테스트를 위한 샘플 정수입니다.
		 * @author RaillyLinker
		 * @date 2023-12-26
		 * @version 1.0.0
		 */
		static int sampleInt;

		// !!![함수 선언]!!!
	public:
		/**
		 * @brief 샘플 함수
		 * @details 테스트를 위한 샘플 함수입니다.
		 * @pa
		 * @author RaillyLinker
		 * @date 2023-12-26
		 * @version 1.0.0
		 */
		static bool sampleFunc(const std::string &sampleParam1, const std::string &sampleParam2);
	};
}

// !!!using namespace 설정!!!
using namespace ns_template;

#endif