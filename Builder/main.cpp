#include "concrete_bulider.h"
#include "director.h"
#include <string>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif
//建造者模式（Builder Pattern）使用多个简单的对象一步一步构建成一个复杂的对象。
//这种类型的设计模式属于创建型模式，它提供了一种创建对象的最佳方式。
//一个 Builder 类会一步一步构造最终的对象。该 Builder 类是独立于其他对象的。
int main()
{
    Direcror *pDirecror = new Direcror();
    ThinkPadBuilder *pTPBuilder = new ThinkPadBuilder();
    YogaBuilder *pYogaBuilder = new YogaBuilder();

    // 组装 ThinkPad、Yoga
    pDirecror->Create(pTPBuilder);
    pDirecror->Create(pYogaBuilder);

    // 获取组装后的电脑
    Computer *pThinkPadComputer = pTPBuilder->GetResult();
    Computer *pYogaComputer = pYogaBuilder->GetResult();

    // 测试输出
    cout << "-----ThinkPad-----" << endl;
    cout << "CPU: " << pThinkPadComputer->GetCPU() << endl;
    cout << "Mainboard: " << pThinkPadComputer->GetMainboard() << endl;
    cout << "Ram: " << pThinkPadComputer->GetRam() << endl;
    cout << "VideoCard: " << pThinkPadComputer->GetVideoCard() << endl;

    cout << "-----Yoga-----" << endl;
    cout << "CPU: " << pYogaComputer->GetCPU() << endl;
    cout << "Mainboard: " << pYogaComputer->GetMainboard() << endl;
    cout << "Ram: " << pYogaComputer->GetRam() << endl;
    cout << "VideoCard: " << pYogaComputer->GetVideoCard() << endl;

	SAFE_DELETE(pThinkPadComputer);
	SAFE_DELETE(pYogaComputer);
	SAFE_DELETE(pTPBuilder);
	SAFE_DELETE(pYogaBuilder);
	SAFE_DELETE(pDirecror);

	//getchar();

    return 0;
}
