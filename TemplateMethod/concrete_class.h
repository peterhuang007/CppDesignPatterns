#ifndef CONCRETE_CLASS_H
#define CONCRETE_CLASS_H

#include "abstract_class.h"
#include <iostream>

// 阿里
class Alibaba : public Company
{
public:
	virtual void Interview() override {
		std::cout << "First interview -> Second interview -> Third interview" << std::endl;
	}

	virtual void Offer() override {
		std::cout << "30W" << std::endl;
	}
};

// 腾讯
class Tencent : public Company
{
public:
	virtual void Interview() override {
		std::cout << "First interview -> Second interview" << std::endl;
	}

	virtual void Offer() override {
		std::cout << "25W" << std::endl;
	}
};

#endif // CONCRETE_CLASS_H
