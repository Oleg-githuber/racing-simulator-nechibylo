#include "Transport.h"

namespace RacingTransport
{
	Transport::Transport(double racingDistance, std::string transportName, double transportSpeed, TransportType transType) :
		distance{ racingDistance }, name{ transportName }, speed{ transportSpeed }, racingTime{}, tType{ transType }
	{}

	std::string Transport::getName() const
	{
		return name;
	}

	double Transport::getRacingTime()
	{
		return racingTime;
	}

	TransportType Transport::getType()
	{
		return tType;
	}
}