#include "Centaur.h"

// Кентавр

namespace RacingTransport
{
	Centaur::Centaur(double racingDistance) :
		Centaur{ racingDistance, "ЉҐ­в ўа", 15, 8, 1 }
	{}
	
	Centaur::Centaur(double racingDistance, std::string transportName, double transportSpeed, double newMoveTime, unsigned int size) :
		LandingTransport{ racingDistance, transportName, transportSpeed,  newMoveTime, size }
	{
		double newArray[]{ 2 };	// Время отдыха
		relaxArray = newArray;
		racingCalculate();		// Вычисление времени гонки
	}
}