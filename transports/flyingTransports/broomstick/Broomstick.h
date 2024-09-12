#pragma once

// Метла

#include "../FlyingTransport.h"

namespace RacingTransport
{
	class Broomstick : public FlyingTransport
	{
	private:
		Broomstick(double racingDistance, std::string transportName, double transportSpeed);

		double setKoef(double dist);	// Расчёт коэфициента сокращения дистанции

	public:
		Broomstick(double racingDistance);
	};
}