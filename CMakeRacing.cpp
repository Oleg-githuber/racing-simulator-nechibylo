// CMakeRacing.cpp: определяет точку входа для приложения.
//

#include "CMakeRacing.h"

int main()
{
	bool oneMore{ true };
	while (oneMore)
	{
		RacingType racingType{ static_cast<RacingType>(enterRacingType()) };
		int distance{ enterDistance() };
		constexpr int sizeArray{ 7 };
		int count{};
		TransportList tList[7];
		createTransportArray(tList, racingType, distance);
		Racing(tList, sizeArray, racingType, distance, count);
		printResult(tList, sizeArray);
		oneMore = oneMoreGame();
	}

	return 0;
}