#include "MagicCarpet.h"

// Ковер самолет

namespace RacingTransport
{
	MagicCarpet::MagicCarpet(double racingDistance) : MagicCarpet(racingDistance, "Љ®ўса-б ¬®«св", 10)
	{}

	MagicCarpet::MagicCarpet(double racingDistance, std::string transportName, double transportSpeed) : FlyingTransport{ racingDistance, transportName, transportSpeed }
	{
		racingCalculate(setDistance(racingDistance, setKoef(racingDistance)));
	}

	double MagicCarpet::setKoef(double dist)
	{
		if (dist < 1000)
		{
			return 0;
		}
		else if (dist < 5000)
		{
			return 3;
		}
		else if (dist < 10000)
		{
			return 10;
		}
		else
		{
			return 5;
		}
	}
}