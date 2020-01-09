#include "context.h"
#include "concrete_strategy.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif
//在策略模式（Strategy Pattern）中，一个类的行为或其算法可以在运行时更改。
//这种类型的设计模式属于行为型模式。
//在策略模式中，我们创建表示各种策略的对象和一个行为随着策略对象改变而改变的 context 对象。
//策略对象改变 context 对象的执行算法。
int main()
{
	// 策略之间可以相互替换
	IStrategy *bike = new BikeStrategy();
	IStrategy *car = new CarStrategy();
	IStrategy *train = new TrainStrategy();

	Context *bikeContext = new Context(bike);
	Context *carContext = new Context(car);
	Context *trainContext = new Context(train);

	bikeContext->Travel();
	carContext->Travel();
	trainContext->Travel();

	SAFE_DELETE(bike);
	SAFE_DELETE(car);
	SAFE_DELETE(train);

	SAFE_DELETE(bikeContext);
	SAFE_DELETE(carContext);
	SAFE_DELETE(trainContext);

	//getchar();

	return 0;
}