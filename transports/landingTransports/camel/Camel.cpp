#include "Camel.h"

// Верблюд

namespace RacingTransport
{
	Camel::Camel(double racingDistance) :
		Camel{ racingDistance, "‚ҐаЎ«о¤", 10, 30, 2 }
	{}

	Camel::Camel(double racingDistance, std::string transportName, double transportSpeed, double newMoveTime, unsigned int size) :
		LandingTransport{ racingDistance, transportName, transportSpeed,  newMoveTime, size }
	{
		double newArray[]{ 5, 8 };	// Время отдыха
		relaxArray = newArray;		// Время отдыха
		racingCalculate();			// Вычисление времени гонки
	}
}