#include "template.h"

namespace ns_template
{
	// [Ŭ���� ���� �Ҵ�]
	// (���� static ����)
	int Template::sampleInt = 1;

	// [Ŭ���� �Լ� ����]
	// (Ŭ���� ���� �ݹ�)
	Template::Template()
	{
	}

	// (Ŭ���� �Ҹ� �ݹ�)
	Template::~Template()
	{
	}

	// (���� �Լ�)
	bool Template::sampleFunc(const std::string &sampleParam1, const std::string &sampleParam2)
	{
		std::cout << "sampleParam1: " << sampleParam1 << ", sampleParam2: " << sampleParam2 << std::endl;
		return true;
	}
}