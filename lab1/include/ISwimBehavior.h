#pragma once

class ISwimBehavior
{
public:
	virtual void Swim() = 0;
	virtual ~ISwimBehavior() = default;
};
