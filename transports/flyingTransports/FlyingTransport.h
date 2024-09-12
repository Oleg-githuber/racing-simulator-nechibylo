#pragma once

#include "../Transport.h"

namespace RacingTransport
{
	class FlyingTransport : public Transport
	{
	protected:

		double koefDist{};	// ���������� ���������� ���������

		FlyingTransport(double racingDistance, std::string transportName, double transportSpeed);

		double setDistance(double dist, double koef);	// ���������� ���������

		void racingCalculate(double dist);	// ���������� ������� �����
	};
}