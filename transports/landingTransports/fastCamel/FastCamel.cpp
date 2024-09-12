#include "FastCamel.h"

// Верблюд-быстроход

namespace RacingTransport
{
	FastCamel::FastCamel(double racingDistance) :
		FastCamel{ racingDistance, "‚ҐаЎ«о¤-Ўлбва®е®¤", 40, 10, 3 }
	{}

	FastCamel::FastCamel(double racingDistance, std::string transportName, double transportSpeed, double newMoveTime, unsigned int size) :
		LandingTransport{ racingDistance, transportName, transportSpeed,  newMoveTime, size }
	{
		double newArray[]{ 5, 6.5, 8 };		// Время отдыха
		relaxArray = newArray;			// Время отдыха
		racingCalculate();			// Вычисление времени гонки
	}
}