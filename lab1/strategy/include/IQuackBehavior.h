#ifndef IQUACKBEHAVIOR_H
#define IQUACKBEHAVIOR_H

class IQuackBehavior
{
public:
	virtual void Quack() = 0;
	virtual ~IQuackBehavior() = default;
};

#endif // !IQUACKBEHAVIOR_H
