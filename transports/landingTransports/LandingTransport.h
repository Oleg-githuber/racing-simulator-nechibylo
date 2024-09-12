#pragma once

#include "../Transport.h"

namespace RacingTransport
{
	class LandingTransport : public Transport
	{
	protected:
		const double moveTime{};	// Время непрерывного движения

		double relaxTime{};		// Время отдыха

		const unsigned int relaxArraySize{};	// Размер массива для времени отдыха

		double* relaxArray{ nullptr };		// Массив для времени отдыха

		LandingTransport(double racingDistance, std::string transportName, double transportSpeed, double newMoveTime, unsigned int size);

		double distanceCalculate();		// Расчёт остатка пути после отдыха

		void racingCalculate();		// Рассчет времени гонки

	public:

		double getMoveTime() const;

		double getRelaxTime() const;
	};
}

