#include "concrete_flyweight.h"
#include "flyweight_factory.h"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

std::map<std::string, IPlayer*> PlayerFactory::m_map = std::map<std::string, IPlayer*>();

// 玩家类型和武器
static std::string s_playerType[2] = { "T", "CT" };
static std::string s_weapons[4] = { "AK-47", "Maverick", "Gut Knife", "Desert Eagle" };

#define GET_ARRAY_LEN(array, len) {len = (sizeof(array) / sizeof(array[0]));}
//享元模式
//主要用于减少创建对象的数量，以减少内存占用和提高性能。
//这种类型的设计模式属于结构型模式，它提供了减少对象数量从而改善应用所需的对象结构的方式。
//用 HashMap 存储这些对象。
int main()
{
	srand((unsigned)time(NULL));/*播种子*/

	int playerLen;
	int weaponsLen;
	GET_ARRAY_LEN(s_playerType, playerLen);
	GET_ARRAY_LEN(s_weapons, weaponsLen);

	// 假设，游戏中有十位玩家
	for (int i = 0; i < 10; i++) {
		// 获取随机玩家和武器
		int typeIndex = rand() % playerLen;/*产生playerLen以内的随机整数*/
		int weaponIndex = rand() % weaponsLen;
		std::string type = s_playerType[typeIndex];
		std::string weapon = s_weapons[weaponIndex];

		// 获取玩家
		IPlayer *p = PlayerFactory::getPlayer(type);

		// 从武器库中随机分配武器
		p->assignWeapon(weapon);

		// 派玩家去执行任务
		p->mission();
	}

	//getchar();

	return 0;
}