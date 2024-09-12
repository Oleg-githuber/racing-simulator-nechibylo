#pragma once

#include "../Transport.h"

namespace RacingTransport
{
	class LandingTransport : public Transport
	{
	protected:
		const double moveTime{};	// ����� ������������ ��������

		double relaxTime{};		// ����� ������

		const unsigned int relaxArraySize{};	// ������ ������� ��� ������� ������

		double* relaxArray{ nullptr };		// ������ ��� ������� ������

		LandingTransport(double racingDistance, std::string transportName, double transportSpeed, double newMoveTime, unsigned int size);

		double distanceCalculate();		// ������ ������� ���� ����� ������

		void racingCalculate();		// ������� ������� �����

	public:

		double getMoveTime() const;

		double getRelaxTime() const;
	};
}

