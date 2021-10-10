#pragma once

#include <string_view>

namespace Program
{

enum class BluetoothEventType
{
	DataArrived
};

enum class EventGroup
{
	BluetoothEvents
};

class IEvent
{
public:
	virtual ~IEvent() = default;
public:
	using EventGroupType  =  EventGroup;
	using EventDescriptorType = std::string_view;

	virtual EventGroupType group() const = 0;
	virtual EventDescriptorType what() const = 0;
};

class BluetoothEvent : public IEvent
{
private:
	static constexpr auto event_group{EventGroupType::BluetoothEvents};
public:
	virtual EventGroupType group() const override;
};

class BluetoothDataArrivedEvent : public BluetoothEvent
{
public:
	static constexpr auto event_descriptor{"DataArrived"};
public:
	virtual EventDescriptorType what() const override;
};

}
