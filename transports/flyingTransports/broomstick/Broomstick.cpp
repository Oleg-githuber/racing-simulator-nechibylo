#include "Broomstick.h"

// ╠хЄыр

namespace RacingTransport
{
	Broomstick::Broomstick(double racingDistance) : Broomstick(racingDistance, "Метла", 20)
	{}

	Broomstick::Broomstick(double racingDistance, std::string transportName, double transportSpeed) : FlyingTransport{ racingDistance, transportName, transportSpeed }
	{
		racingCalculate(setDistance(racingDistance, setKoef(racingDistance)));
	}

	double Broomstick::setKoef(double dist)
	{
		int intDist{ static_cast<int>(dist) };
		if (intDist < 100000)
		{
			return intDist / 1000;
		}
		else
		{
			return 100;
		}
	}
}