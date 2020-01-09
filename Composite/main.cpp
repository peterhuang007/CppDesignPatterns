#include "composite.h"
#include "leaf.h"
//组合模式（Composite Pattern），又叫部分整体模式，是用于把一组相似的对象当作一个单一的对象。
//组合模式依据树形结构来组合对象，用来表示部分以及整体层次。这种类型的设计模式属于结构型模式，
//它创建了对象组的树形结构。
//这种模式创建了一个包含自己对象组的类。该类提供了修改相同对象组的方式。
int main()
{
	// 创建一个树形结构
	// 创建根节点
	Component *pRoot = new Composite("江湖公司（任我行）");

	// 创建分支
	Component *pDepart1 = new Composite("日月神教（东方不败）");
	pDepart1->Add(new Leaf("光明左使（向问天）"));
	pDepart1->Add(new Leaf("光明右使（曲洋）"));
	pRoot->Add(pDepart1);

	Component *pDepart2 = new Composite("五岳剑派（左冷蝉）");
	pDepart2->Add(new Leaf("嵩山（左冷蝉）"));
	pDepart2->Add(new Leaf("衡山（莫大）"));
	pDepart2->Add(new Leaf("华山（岳不群）"));
	pDepart2->Add(new Leaf("泰山（天门道长）"));
	pDepart2->Add(new Leaf("恒山（定闲师太）"));
	pRoot->Add(pDepart2);

	// 添加和删除叶子
	pRoot->Add(new Leaf("少林（方证大师）"));
	pRoot->Add(new Leaf("武当（冲虚道长）"));
	Component *pLeaf = new Leaf("青城（余沧海）");
	pRoot->Add(pLeaf);

	// 小丑，直接裁掉
	pRoot->Remove(pLeaf);

	// 递归地显示组织架构
	pRoot->Operation(1);

	// 删除分配的内存
	SAFE_DELETE(pRoot);

	//getchar();

	return 0;
}