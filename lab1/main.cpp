#include "include/pch.h"

#include "include/FlyWithWings.h"
#include "include/FlyNoWay.h"

#include "include/MuteQuackBehavior.h"
#include "include/QuackBehavior.h"
#include "include/SqueakBehavior.h"

#include "include/Duck.h"
#include "include/MallardDuck.h"
#include "include/RedheadDuck.h"
#include "include/DecoyDuck.h"
#include "include/RubberDuck.h"
#include "include/ModelDuck.h"

void DrawDuck(Duck const& duck)
{
	duck.Display();
}

void PlayWithDuck(Duck& duck)
{
	DrawDuck(duck);
	duck.Quack();
	duck.Fly();
	duck.Dance();
	std::cout << std::endl;
}

int main()
{
	MallardDuck mallardDuck;
	PlayWithDuck(mallardDuck);

	RedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);

	RubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);

	DecoyDuck decoyDuck;
	PlayWithDuck(decoyDuck);

	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);
	modelDuck.SetFlyBehavior(std::make_unique<FlyWithWings>());
	PlayWithDuck(modelDuck);
}