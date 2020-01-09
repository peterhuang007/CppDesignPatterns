﻿#ifndef ELEMENT_H
#define ELEMENT_H

class IVisitor;

// хпий
class IPlace
{
public:
	virtual ~IPlace() {}
	virtual void Accept(IVisitor *visitor) = 0;
};

#endif // ELEMENT_H
