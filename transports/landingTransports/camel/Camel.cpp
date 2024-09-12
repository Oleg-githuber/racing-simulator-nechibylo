#include "Camel.h"

// �������

namespace RacingTransport
{
	Camel::Camel(double racingDistance) :
		Camel{ racingDistance, "��࡫�", 10, 30, 2 }
	{}

	Camel::Camel(double racingDistance, std::string transportName, double transportSpeed, double newMoveTime, unsigned int size) :
		LandingTransport{ racingDistance, transportName, transportSpeed,  newMoveTime, size }
	{
		double newArray[]{ 5, 8 };	// ����� ������
		relaxArray = newArray;		// ����� ������
		racingCalculate();			// ���������� ������� �����
	}
}