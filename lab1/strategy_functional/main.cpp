#include "include/pch.h"

#include "include/DuckFunctions.h"

#include "include/MallardDuck.h"
#include "include/ModelDuck.h"
#include "include/RedheadDuck.h"
#include "include/RubberDuck.h"

int main()
{
	MallardDuck mallardDuck;
	PlayWithDuck(mallardDuck);
	mallardDuck.SetFlyBehavior([](std::size_t) { std::cout << "I'm too tired to fly today" << std::endl; });
	PlayWithDuck(mallardDuck);

	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);
	modelDuck.SetDanceBehavior([]() { std::cout << "I'm dancing so hard without any reason!" << std::endl; });
	PlayWithDuck(modelDuck);

	RedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);
	redheadDuck.SetQuackBehavior([]() { std::cout << "My throat is aching, qua-a, ouch!" << std::endl; });
	PlayWithDuck(redheadDuck);

	RubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);
	rubberDuck.SetSwimBehavior([]() { std::cout << "Whoa! Now I can swim!!!" << std::endl; });
	PlayWithDuck(rubberDuck);

	return 0;
}
