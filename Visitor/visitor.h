#ifndef VISITOR_H
#define VISITOR_H

class BellTower;
class TerracottaWarriors;

// 访问者
class IVisitor
{
public:
	virtual ~IVisitor() {}
	virtual void Visit(BellTower *) = 0;
	virtual void Visit(TerracottaWarriors *) = 0;
};

#endif // VISITOR_H
