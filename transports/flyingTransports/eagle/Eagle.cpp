#include "Eagle.h"

// Îð¸ë

namespace RacingTransport
{
	Eagle::Eagle(double racingDistance) : Eagle(racingDistance, "Žàñ«", 8)
	{}

	Eagle::Eagle(double racingDistance, std::string transportName, double transportSpeed) : FlyingTransport{ racingDistance, transportName, transportSpeed }
	{
		racingCalculate(setDistance(racingDistance, 6));
	}

}