#include "refined_abstraction.h"
#include "concrete_implementor.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif
//桥接（Bridge）是用于把抽象化与实现化解耦，使得二者可以独立变化。
//这种类型的设计模式属于结构型模式，它通过提供抽象化和实现化之间的桥接结构，来实现二者的解耦。
//这种模式涉及到一个作为桥接的接口，使得实体类的功能独立于接口实现类。这两种类型的类可被结构化改变而互不影响。
int main()
{
	// 创建电器 - 电灯、风扇
	IElectricalEquipment *light = new Light();
	IElectricalEquipment *fan = new Fan();

	/**
	* 创建开关 - 拉链式开关、两位开关
	* 将拉链式开关和电灯关联起来，将两位开关和风扇关联起来
	**/
	ISwitch *pullChain = new PullChainSwitch(light);
	ISwitch *twoPosition = new TwoPositionSwitch(fan);

	// 开灯、关灯
	pullChain->On();
	pullChain->Off();

	// 打开风扇、关闭风扇
	twoPosition->On();
	twoPosition->Off();

	SAFE_DELETE(twoPosition);
	SAFE_DELETE(pullChain);
	SAFE_DELETE(fan);
	SAFE_DELETE(light);

	//getchar();

	return 0;
}
