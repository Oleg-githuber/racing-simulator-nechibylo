#pragma once

// Ковер-самолет

#include "../FlyingTransport.h"

namespace RacingTransport
{
	class MagicCarpet : public FlyingTransport
	{
	private:
		MagicCarpet(double racingDistance, std::string transportName, double transportSpeed);

		double setKoef(double dist);

	public:
		MagicCarpet(double racingDistance);
	};
}