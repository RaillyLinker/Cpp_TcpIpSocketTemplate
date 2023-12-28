#include "template.h"

// [헤더 변수 할당]
int Template::sampleInt = 1;

// [헤더 함수 구현]
bool Template::sampleFunc(const std::string &sampleParam1, const std::string &sampleParam2)
{
	std::cout << "sampleParam1: " << sampleParam1 << ", sampleParam2: " << sampleParam2 << std::endl;
	return true;
}