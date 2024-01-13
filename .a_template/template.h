#pragma once

// !!!ifndef �̸� ���� - ���ϸ� �빮��!!!
#ifndef TEMPLATE
#define TEMPLATE

// !!![���̺귯�� include]!!!
#include <string>
#include <iostream>

// !!!using namespace ����!!!

// !!!namespace ���� - ns_{���ϸ�}�� ����!!!
namespace ns_template
{
	// !!!Ŭ������ ����(���ϸ��� �Ľ�Į ǥ�������)!!!
	/**
	 * @brief ���ø� Ŭ����
	 * @details ���ø� Ŭ�����Դϴ�.
	 * @author RaillyLinker
	 * @date 2023-12-26
	 * @version 1.0.0
	 */
	class Template
	{
		// !!![����/�Ҹ��� ����]!!!
	public:
		Template();
		~Template();

		// !!![���� ����]!!!
	public:
		/**
		 * @brief ���� ������
		 * @details �׽�Ʈ�� ���� ���� �����Դϴ�.
		 * @author RaillyLinker
		 * @date 2023-12-26
		 * @version 1.0.0
		 */
		static int sampleInt;

		// !!![�Լ� ����]!!!
	public:
		/**
		 * @brief ���� �Լ�
		 * @details �׽�Ʈ�� ���� ���� �Լ��Դϴ�.
		 * @pa
		 * @author RaillyLinker
		 * @date 2023-12-26
		 * @version 1.0.0
		 */
		bool sampleFunc(const std::string &sampleParam1, const std::string &sampleParam2);
	};
}

#endif