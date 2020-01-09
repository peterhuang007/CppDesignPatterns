#include "concrete_class.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif
//在模板模式（Template Pattern）中，一个抽象类公开定义了执行它的方法的方式/模板。
//它的子类可以按需要重写方法实现，但调用将以抽象类中定义的方式进行。这种类型的设计模式属于行为型模式
int main()
{
	// 阿里校招
	Company *alibaba = new Alibaba();
	alibaba->Recruit();

	// 腾讯校招
	Company *tencent = new Tencent();
	tencent->Recruit();

	SAFE_DELETE(tencent);
	SAFE_DELETE(alibaba);

	//getchar();

	return 0;
}
