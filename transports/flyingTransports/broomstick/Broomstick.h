#pragma once

// �����

#include "../FlyingTransport.h"

namespace RacingTransport
{
	class Broomstick : public FlyingTransport
	{
	private:
		Broomstick(double racingDistance, std::string transportName, double transportSpeed);

		double setKoef(double dist);	// ������ ����������� ���������� ���������

	public:
		Broomstick(double racingDistance);
	};
}