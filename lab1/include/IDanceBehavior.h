#ifndef IDANCEBEHAVIOR_H
#define IDANCEBEHAVIOR_H

class IDanceBehavior
{
public:
	virtual void Dance() = 0;
	virtual ~IDanceBehavior() = default;
};

#endif // !IDANCEBEHAVIOR_H
