#include "Eagle.h"

// ���

namespace RacingTransport
{
	Eagle::Eagle(double racingDistance) : Eagle(racingDistance, "���", 8)
	{}

	Eagle::Eagle(double racingDistance, std::string transportName, double transportSpeed) : FlyingTransport{ racingDistance, transportName, transportSpeed }
	{
		racingCalculate(setDistance(racingDistance, 6));
	}

}