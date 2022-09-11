#include "include/pch.h"

#include "include/DuckFunctions.h"

#include "include/DecoyDuck.h"
#include "include/Duck.h"
#include "include/MallardDuck.h"
#include "include/ModelDuck.h"
#include "include/RedheadDuck.h"
#include "include/RubberDuck.h"

#include "include/CountedFly.h"
#include "include/DanceNoWay.h"

int main()
{
	MallardDuck mallardDuck;
	PlayWithDuck(mallardDuck);
	mallardDuck.SetDanceBehavior(std::make_unique<DanceNoWay>());
	PlayWithDuck(mallardDuck);

	RedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);

	RubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);

	DecoyDuck decoyDuck;
	PlayWithDuck(decoyDuck);

	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);
	modelDuck.SetFlyBehavior(std::make_unique<CountedFly>());
	PlayWithDuck(modelDuck);
}
