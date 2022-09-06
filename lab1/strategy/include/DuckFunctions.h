#ifndef DUCKFUNCTIONS_H
#define DUCKFUNCTIONS_H

#include "pch.h"

#include "Duck.h"

void DrawDuck(Duck const& duck)
{
	duck.Display();
}

void PlayWithDuck(Duck& duck)
{
	DrawDuck(duck);
	duck.PerformQuack();
	duck.PerfromFly();
	duck.PerformDance();
	std::cout << std::endl;
}

#endif // !DUCKFUNCTIONS_H
