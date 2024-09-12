#include "LandingTransport.h"

namespace RacingTransport
{
	LandingTransport::LandingTransport(double racingDistance, std::string transportName, double transportSpeed, double newMoveTime, unsigned int size) :
		Transport{ racingDistance, transportName, transportSpeed, TransportType::landing }, moveTime{ newMoveTime }, relaxArraySize{ size }
	{
		//racingCalculate();
	}



	double LandingTransport::getMoveTime() const
	{
		return moveTime;
	}

	double LandingTransport::getRelaxTime() const
	{
		return relaxTime;
	}



	double LandingTransport::distanceCalculate()
	{
		return speed * moveTime;
	}

	void LandingTransport::racingCalculate()
	{
		for (unsigned int i = 0; i < relaxArraySize; ++i)
		{
			double calculatingDistans{ distanceCalculate() };
			if (distance > calculatingDistans)
			{
				distance -= calculatingDistans;
				relaxTime = relaxArray[i];
				//std::cout << relaxTime << std::endl;
				racingTime += (moveTime + relaxTime);
			}
			else
			{
				racingTime += (distance / speed);
			}
		}
		double calculatingDistans{ distanceCalculate() };
		while (distance > calculatingDistans)
		{
			distance -= calculatingDistans;
			racingTime += (moveTime + relaxTime);
		}
		racingTime += (distance / speed);
	}
}