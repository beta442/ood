#ifndef TEA_H
#define TEA_H

#include "BeverageImpl.h"

constexpr auto TEA_DESCRIPTION = "Tea";

class Tea : public BeverageImpl
{
public:
	Tea(const std::string& description = TEA_DESCRIPTION);

	double GetCost() const override;
};

#endif // !TEA_H
