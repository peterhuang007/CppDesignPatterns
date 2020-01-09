#include "concrete_handler.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif
//责任链模式（Chain of Responsibility Pattern）为请求创建了一个接收者对象的链。
//这种模式给予请求的类型，对请求的发送者和接收者进行解耦。这种类型的设计模式属于行为型模式。
//在这种模式中，通常每个接收者都包含对另一个接收者的引用。如果一个对象不能处理该请求，
//那么它会把相同的请求传给下一个接收者，依此类推。
int main()
{
	IHandler *manager = new Manager();
	IHandler *director = new Director();
	IHandler *ceo = new CEO();

	// 职责链：经理 -> 总监 -> 总裁
	manager->SetSuccessor(director);
	director->SetSuccessor(ceo);

	manager->HandleRequest(1);
	manager->HandleRequest(2);
	manager->HandleRequest(5);
	manager->HandleRequest(10);

	SAFE_DELETE(manager);
	SAFE_DELETE(director);
	SAFE_DELETE(ceo);

	//getchar();

	return 0;
}