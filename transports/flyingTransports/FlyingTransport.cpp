#include "FlyingTransport.h"

namespace RacingTransport
{
	FlyingTransport::FlyingTransport(double racingDistance, std::string transportName, double transportSpeed) :
		Transport{ racingDistance, transportName, transportSpeed, TransportType::flying }
	{
		//racingCalculate();
	}

	double FlyingTransport::setDistance(double dist, double koef)
	{
		return dist * (100 - koef) / 100;
	}

	void FlyingTransport::racingCalculate(double dist)
	{
		racingTime = dist / speed;
	}
}