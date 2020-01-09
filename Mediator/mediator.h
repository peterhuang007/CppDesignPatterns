#pragma once

#include "colleague.h"
#include <list>
#include <string>

class IColleague;

// 抽象中介者
class IMediator
{
public:
	// 注册参与者  push_back emplace_back
	virtual void registerColleague(IColleague* colleague) { m_colleagues.push_back(colleague); }
	const std::list<IColleague*>& getColleagues() const { return m_colleagues; }

	// 将发送者的消息发送给所有参与者
	virtual void distributeMessage(const IColleague* sender, const std::string& message) const = 0;

private:
	std::list<IColleague*> m_colleagues;
};