#pragma once

// �����-�������

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