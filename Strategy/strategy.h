#ifndef STRATEGY_H
#define STRATEGY_H

// 出行策略
class IStrategy
{
public:
	virtual void Travel() = 0;
};

#endif // STRATEGY_H