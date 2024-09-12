#pragma once

// Верблюд

#include "../LandingTransport.h"

namespace RacingTransport
{
	class Camel : public LandingTransport
	{
	private:
		Camel(double racingDistance, std::string transportName, double transportSpeed, double newMoveTime, unsigned int size);
	public:
		Camel(double racingDistance);
	};
}