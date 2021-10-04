#pragma once

#include <stdint-gcc.h>
#include <functional>

namespace Program
{

class Task
{
public:
	using PriorityType = uint8_t;
	using TaskType 	    =  std::function<void()>;
private:
	TaskType  task_;
	PriorityType priority_;
public:
	Task( TaskType   fn , PriorityType priority );
	virtual ~Task() = default;
public:
	void operator() ();
	friend bool operator< (const Task& lhs ,const Task& rhs );
};

}
