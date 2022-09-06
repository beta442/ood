#ifndef ISWIMBEHAVIOR_H
#define ISWIMBEHAVIOR_H

class ISwimBehavior
{
public:
	virtual void Swim() = 0;
	virtual ~ISwimBehavior() = default;
};

#endif // !ISWIMBEHAVIOR_H
