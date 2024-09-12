#ifndef FUNCTIONS_FOR_RACING_SIMULATOR
#define FUNCTIONS_FOR_RACING_SIMULATOR

#include <iostream>
#include <cstdlib>
#include "transports/TransportCollection.h"
#include "RacingType.h"
#include "TransportList.h"

int enterRacingType();	// Выбор типа гонки

int enterDistance();	// Ввод дистанции гонки

void createTransportArray(TransportList* tList, RacingType& racingType, double distance);	// Создание списка ТС

void transportRegister(RacingType& rType, TransportType& tType, TransportList* tList, int sizeArray, int& count);	// Регистрация ТС на гонку


void addTransport(RacingType& rType, TransportType& tType, TransportList* tList, int sizeArray, int& count, std::string& str);	// Добавление ТС в список участников

void Racing(TransportList* tList, int sizeArray, RacingType& rType, double dist, int& count);		// Гонка

void sortRacers(TransportList* tList, int sizeArray);	// Сортировка участников по скорости.

void swapRacers(TransportList* tList, int index);	// Обмен двух ТС в рейтинге

void printAllTransport();		// Вывод в консоль всех ТС

void printResult(TransportList* tList, int arraySize);	// Вывод в консоль рейтинга гонки

bool oneMoreGame();		// Сыграть ещё?

#endif // !FUNCTIONS_FOR_RACING_SIMULATOR