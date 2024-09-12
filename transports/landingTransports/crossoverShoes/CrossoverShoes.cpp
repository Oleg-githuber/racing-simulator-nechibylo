#include "CrossoverShoes.h"

// Сапоги-вездеходы

namespace RacingTransport
{
	CrossoverShoes::CrossoverShoes(double racingDistance) :
		CrossoverShoes{ racingDistance, "‘ Ї®ЈЁ-ўҐ§¤Ґе®¤л", 6, 60, 2 }
	{}

	CrossoverShoes::CrossoverShoes(double racingDistance, std::string transportName, double transportSpeed, double newMoveTime, unsigned int size) :
		LandingTransport{ racingDistance, transportName, transportSpeed,  newMoveTime, size }
	{
		double newArray[]{ 10, 5 };		// Время отдыха
		relaxArray = newArray;			// Время отдыха
		racingCalculate();				// Вычисление времени гонки
	}
}