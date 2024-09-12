#include "CrossoverShoes.h"

// ������-���������

namespace RacingTransport
{
	CrossoverShoes::CrossoverShoes(double racingDistance) :
		CrossoverShoes{ racingDistance, "������-�����室�", 6, 60, 2 }
	{}

	CrossoverShoes::CrossoverShoes(double racingDistance, std::string transportName, double transportSpeed, double newMoveTime, unsigned int size) :
		LandingTransport{ racingDistance, transportName, transportSpeed,  newMoveTime, size }
	{
		double newArray[]{ 10, 5 };		// ����� ������
		relaxArray = newArray;			// ����� ������
		racingCalculate();				// ���������� ������� �����
	}
}