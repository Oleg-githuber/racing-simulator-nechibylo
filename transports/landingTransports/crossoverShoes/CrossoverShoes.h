#pragma once

// ������-���������

#include "../LandingTransport.h"

namespace RacingTransport
{
	class CrossoverShoes : public LandingTransport
	{
	private:
		CrossoverShoes(double racingDistance, std::string transportName, double transportSpeed, double newMoveTime, unsigned int size);
	public:
		CrossoverShoes(double racingDistance);
	};
}