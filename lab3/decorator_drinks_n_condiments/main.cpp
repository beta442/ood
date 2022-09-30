#include "include/pch.h"

#include "include/DecoratorHelpers.hpp"

#include "include/Cappuccino.h"
#include "include/Latte.h"
#include "include/Milkshake.h"
#include "include/Tea.h"

#include "include/CoconutFlakes.h"
#include "include/Syrup.h"

int main(int, char*)
{
	{
		auto beverage = std::make_unique<Latte>(LattePortionSize::DOUBLE)
			<< MakeCondiment<Syrup>(SyrupType::Chocolate)
			<< MakeCondiment<CoconutFlakes>(1);

		std::cout << beverage->GetDescription() << " costs " << beverage->GetCost() << '\n';
	}

	{
		auto beverage = std::make_unique<Cappuccino>(CappuccinoPortionSize::DOUBLE);

		std::cout << beverage->GetDescription() << " costs " << beverage->GetCost() << '\n';
	}

	{
		auto beverage = std::make_unique<Cappuccino>(CappuccinoPortionSize::DOUBLE);

		std::cout << beverage->GetDescription() << " costs " << beverage->GetCost() << '\n';
	}

	{
		auto beverage = std::make_unique<Tea>(TeaType::OOLONG);

		std::cout << beverage->GetDescription() << " costs " << beverage->GetCost() << '\n';
	}

	{
		auto beverage = std::make_unique<Milkshake>(MilkshakePortionSize::MEDIUM);

		std::cout << beverage->GetDescription() << " costs " << beverage->GetCost() << '\n';
	}

	return 0;
}
