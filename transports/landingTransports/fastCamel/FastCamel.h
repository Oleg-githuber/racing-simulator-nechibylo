#pragma once

// Верблюд-быстроход

#include "../LandingTransport.h"

namespace RacingTransport
{
	class FastCamel : public LandingTransport
	{
	private:
		FastCamel(double racingDistance, std::string transportName, double transportSpeed, double newMoveTime, unsigned int size);
	public:
		FastCamel(double racingDistance);
	};
}