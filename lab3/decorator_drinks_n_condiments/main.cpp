#include "include/pch.h"

#include "include/DecoratorHelpers.hpp"

#include "include/Cappuccino.h"
#include "include/Latte.h"
#include "include/Milkshake.h"
#include "include/Tea.h"

#include "include/Chocolate.h"
#include "include/CoconutFlakes.h"
#include "include/Cream.h"
#include "include/Liquor.h"
#include "include/Syrup.h"

int main(int, char*)
{
	{
		auto beverage = std::make_unique<Latte>(LattePortionSize::DOUBLE)
			<< MakeCondiment<Cream>()
			<< MakeCondiment<Chocolate>(4)
			<< MakeCondiment<Liquor>(LiquorType::CHOCOLATE);

		std::cout << beverage->GetDescription() << " costs " << beverage->GetCost() << '\n';
	}

	return 0;
}
