#ifndef TRANSPORT_LOST_STRUCTURE
#define TRANSPORT_LOST_STRUCTURE

#include <iostream>
#include "transports/TransportCollection.h"

struct TransportList
{
	std::string name{};
	TransportType tType{};
	double racingTime{};
	bool isUsing{};
};

#endif // !TRANSPORT_LOST_STRUCTURE


