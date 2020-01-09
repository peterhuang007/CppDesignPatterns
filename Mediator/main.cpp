#include "concrete_colleague.h"
#include "concrete_mediator.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif
//中介者模式（Mediator Pattern）是用来降低多个对象和类之间的通信复杂性。
//这种模式提供了一个中介类，该类通常处理不同类之间的通信，并支持松耦合，
//使代码易于维护。中介者模式属于行为型模式。
int main()
{
	// 房东
	IColleague *landlord = new ConcreteColleague("Tom");

	// 租客
	IColleague *jerry = new ConcreteColleague("Jerry");
	IColleague *tuffy = new ConcreteColleague("Tuffy");

	// 中介者 - 添加租客
	ConcreteMediator mediator;
	mediator.registerColleague(jerry);
	mediator.registerColleague(tuffy);

	// 房东通过中介将消息发送出去
	landlord->sendMessage(mediator, "Xi'erqi, two bedroom house, 6000/month.");

	SAFE_DELETE(jerry);
	SAFE_DELETE(tuffy);

	//getchar();

	return 0;
}