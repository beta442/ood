#ifndef TEA_H
#define TEA_H

#include "BeverageImpl.h"

enum class TeaType
{
	BLACK = 0,
	GREEN,
	OOLONG,
	WHITE,
};

class Tea : public BeverageImpl
{
public:
	Tea(TeaType type);

	double GetCost() const override;

private:
	double m_cost;
};

#endif // !TEA_H
