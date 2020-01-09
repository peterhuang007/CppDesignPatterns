#include "concrete_visitor.h"
#include "object_structure.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif
///在访问者模式（Visitor Pattern）中，我们使用了一个访问者类，
//它改变了元素类的执行算法。通过这种方式，元素的执行算法可以随着访问者改变而改变。
//这种类型的设计模式属于行为型模式。根据模式，元素对象已接受访问者对象，
//这样访问者对象就可以处理元素对象上的操作。
int main()
{
	City *city = new City();

	// 景点 - 钟楼、兵马俑
	IPlace *bellTower = new BellTower();
	IPlace *warriors = new TerracottaWarriors();

	// 访问者 - 游客、清洁工
	IVisitor *tourist = new Tourist();
	IVisitor *cleaner = new Cleaner();

	// 添加景点
	city->Attach(bellTower);
	city->Attach(warriors);

	// 接受访问
	city->Accept(tourist);
	city->Accept(cleaner);

	SAFE_DELETE(cleaner);
	SAFE_DELETE(tourist);
	SAFE_DELETE(warriors);
	SAFE_DELETE(bellTower);
	SAFE_DELETE(city);

	//getchar();

	return 0;
}
