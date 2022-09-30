#include "include/pch.h"

#include "include/CoconutFlakes.h"
#include "include/DecoratorHelpers.hpp"
#include "include/Milkshake.h"
#include "include/Syrup.h"

int main(int, char*)
{
	{
		auto beverage = std::make_unique<Milkshake>()
			<< MakeCondiment<Syrup>(SyrupType::Chocolate)
			<< MakeCondiment<CoconutFlakes>(50);

		std::cout << beverage->GetDescription() << " costs " << beverage->GetCost() << '\n';
	}

	return 0;
}
