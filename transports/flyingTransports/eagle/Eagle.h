#pragma once

// Îð¸ë

#include "../FlyingTransport.h"

namespace RacingTransport
{
	class Eagle : public FlyingTransport
	{
	private:
		Eagle(double racingDistance, std::string transportName, double transportSpeed);

		//double setKoef(double dist);

	public:
		Eagle(double racingDistance);
	};
}