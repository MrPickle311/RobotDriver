#pragma once

template<typename ObjectType>
class Singleton
{
public:
	static ObjectType& getInstance()
	{
		static ObjectType object;

		return object;
	}
};
