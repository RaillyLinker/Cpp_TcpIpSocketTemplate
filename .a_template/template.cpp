#include "template.h"

namespace ns_template
{
	// [클래스 변수 할당]
	// (샘플 static 변수)
	int Template::sampleInt = 1;

	// [클래스 함수 구현]
	// (클래스 생성 콜백)
	Template::Template()
	{
	}

	// (클래스 소멸 콜백)
	Template::~Template()
	{
	}

	// (샘플 함수)
	bool Template::sampleFunc(const std::string &sampleParam1, const std::string &sampleParam2)
	{
		std::cout << "sampleParam1: " << sampleParam1 << ", sampleParam2: " << sampleParam2 << std::endl;
		return true;
	}
}