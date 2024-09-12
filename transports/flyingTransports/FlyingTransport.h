#pragma once

#include "../Transport.h"

namespace RacingTransport
{
	class FlyingTransport : public Transport
	{
	protected:

		double koefDist{};	// Коэфициент сокращения дистанции

		FlyingTransport(double racingDistance, std::string transportName, double transportSpeed);

		double setDistance(double dist, double koef);	// Сокращение дистанции

		void racingCalculate(double dist);	// Вычисление времени гонки
	};
}