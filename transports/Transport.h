#pragma once

// ������� �����

#include <iostream>

enum class TransportType	// ��� ������������� ��������
{
	landing = 1, flying
};

namespace RacingTransport
{
	class Transport
	{
	protected:

		const TransportType tType{};	// ��� ������������� ��������

		const std::string name{};	// ������������ ��

		const double speed{};		// �������� ��

		double distance{};		// ����������

		double racingTime{};	// ����� �����

		Transport(double distance, std::string transportName, double transportSpeed, TransportType transType);

	public:

		std::string getName() const;

		double getRacingTime();

		TransportType getType();
	};
}

