#pragma once

// Кентавр

#include "../LandingTransport.h"

namespace RacingTransport
{
	class Centaur : public LandingTransport
	{
	private:
		Centaur(double racingDistance, std::string transportName, double transportSpeed, double newMoveTime, unsigned int size);
	public:
		Centaur(double racingDistance);
	};
}