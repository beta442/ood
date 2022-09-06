#ifndef IFLYBEHAVIOR_H
#define IFLYBEHAVIOR_H

class IFlyBehavior
{
public:
	virtual void Fly() = 0;
	virtual ~IFlyBehavior() = default;
};

#endif // !IFLYBEHAVIOR_H
