#include "FastCamel.h"

// �������-���������

namespace RacingTransport
{
	FastCamel::FastCamel(double racingDistance) :
		FastCamel{ racingDistance, "��࡫�-�����室", 40, 10, 3 }
	{}

	FastCamel::FastCamel(double racingDistance, std::string transportName, double transportSpeed, double newMoveTime, unsigned int size) :
		LandingTransport{ racingDistance, transportName, transportSpeed,  newMoveTime, size }
	{
		double newArray[]{ 5, 6.5, 8 };		// ����� ������
		relaxArray = newArray;			// ����� ������
		racingCalculate();			// ���������� ������� �����
	}
}