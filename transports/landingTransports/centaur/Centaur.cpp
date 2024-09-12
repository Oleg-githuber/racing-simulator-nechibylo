#include "Centaur.h"

// �������

namespace RacingTransport
{
	Centaur::Centaur(double racingDistance) :
		Centaur{ racingDistance, "���⠢�", 15, 8, 1 }
	{}
	
	Centaur::Centaur(double racingDistance, std::string transportName, double transportSpeed, double newMoveTime, unsigned int size) :
		LandingTransport{ racingDistance, transportName, transportSpeed,  newMoveTime, size }
	{
		double newArray[]{ 2 };	// ����� ������
		relaxArray = newArray;
		racingCalculate();		// ���������� ������� �����
	}
}