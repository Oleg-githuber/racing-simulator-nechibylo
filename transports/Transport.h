#pragma once

// Базовый класс

#include <iostream>

enum class TransportType	// Тип транспортного средства
{
	landing = 1, flying
};

namespace RacingTransport
{
	class Transport
	{
	protected:

		const TransportType tType{};	// Тип транспортного средства

		const std::string name{};	// Наименование ТС

		const double speed{};		// Скорость ТС

		double distance{};		// Расстояние

		double racingTime{};	// Время гонки

		Transport(double distance, std::string transportName, double transportSpeed, TransportType transType);

	public:

		std::string getName() const;

		double getRacingTime();

		TransportType getType();
	};
}

