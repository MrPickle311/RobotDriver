#pragma once

#include <string_view>

namespace Program
{

class IEvent
{
public:
	virtual ~IEvent() = default;
public:
	using DescriptorType = std::string_view ;
	virtual DescriptorType type() const = 0;
};

class DemoEvent : public IEvent
{
public:
	DemoEvent() = default;

	static constexpr auto descriptor{"DemoEvent"};

	virtual DescriptorType type() const;
};



}
