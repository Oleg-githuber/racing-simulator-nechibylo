#ifndef FUNCTIONS_FOR_RACING_SIMULATOR
#define FUNCTIONS_FOR_RACING_SIMULATOR

#include <iostream>
#include <cstdlib>
#include "transports/TransportCollection.h"
#include "RacingType.h"
#include "TransportList.h"

int enterRacingType();	// ����� ���� �����

int enterDistance();	// ���� ��������� �����

void createTransportArray(TransportList* tList, RacingType& racingType, double distance);	// �������� ������ ��

void transportRegister(RacingType& rType, TransportType& tType, TransportList* tList, int sizeArray, int& count);	// ����������� �� �� �����


void addTransport(RacingType& rType, TransportType& tType, TransportList* tList, int sizeArray, int& count, std::string& str);	// ���������� �� � ������ ����������

void Racing(TransportList* tList, int sizeArray, RacingType& rType, double dist, int& count);		// �����

void sortRacers(TransportList* tList, int sizeArray);	// ���������� ���������� �� ��������.

void swapRacers(TransportList* tList, int index);	// ����� ���� �� � ��������

void printAllTransport();		// ����� � ������� ���� ��

void printResult(TransportList* tList, int arraySize);	// ����� � ������� �������� �����

bool oneMoreGame();		// ������� ���?

#endif // !FUNCTIONS_FOR_RACING_SIMULATOR