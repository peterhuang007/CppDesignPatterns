#include "singleton.h"
#include <iostream>

using namespace std;

Singleton::GC Singleton::GC::gc; // 重要
//单例模式（Singleton Pattern）是 Java 中最简单的设计模式之一。
//这种类型的设计模式属于创建型模式，它提供了一种创建对象的最佳方式。
//这种模式涉及到一个单一的类，该类负责创建自己的对象，
//同时确保只有单个对象被创建。这个类提供了一种访问其唯一的对象的方式，可以直接访问，不需要实例化该类的对象
int main()
{
    //Singleton single = Singleton::GetInstance();

	//Singleton *pSingleton1 = Singleton::GetInstance();
	//Singleton *pSingleton2 = Singleton::GetInstance();

	//cout << (pSingleton1 == pSingleton2) << endl;

	//Singleton::GetInstance().doSomething();  // OK
	//Singleton single = Singleton::GetInstance();  // Error 不能编译通过

    Singleton::GetInstance();
    //Singleton::GetInstance()->DestoryInstance();  // 手动释放

    return 0;
}
