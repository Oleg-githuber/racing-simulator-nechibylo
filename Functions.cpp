#include "Functions.h"

// ����� ���� �����
int enterRacingType()
{
	int racingType{};
	while (true)
	{
		std::cout << "\n���� ���������� � ������ ᨬ����!\n"
			<< "1. ����� ��� ��������� �࠭ᯮ��\n"
			<< "2. ����� ��� �����譮�� �࠭ᯮ��\n"
			<< "3. ����� ��� ��������� � �����譮�� �࠭ᯮ��\n"
			<< "�롥�� ⨯ �����: ";
		if (std::cin >> racingType) {
			if (racingType < 1 || racingType > 3)
			{
				std::cout << "\n�� ����� ����୮� ���祭��\n" << std::endl;
				continue;
			}
			break;
		}
		std::cout << "\n�� ����� �����४�� ᨬ���\n" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
	return racingType;
}

// ���� ��������� �����
int enterDistance()
{
	int distance{};
	while (true)
	{
		std::cout << "������ ����� ���⠭樨 (������ ���� ������⥫쭠): ";
		if (std::cin >> distance) {
			if (distance <= 0)
			{
				std::cout << "\n����� ������ ���� ������⥫쭠\n" << std::endl;
				continue;
			}
			break;
		}
		std::cout << "\n�� ����� �����४�� ᨬ���\n" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
	return distance;
}

// �������� ������ ���� ��
void createTransportArray(TransportList* tList, RacingType& racingType, double distance)
{
	constexpr int arraySize{ 7 };

	RacingTransport::CrossoverShoes shoes(distance);
	RacingTransport::Broomstick boomstick(distance);
	RacingTransport::Camel camel(distance);
	RacingTransport::Centaur centaur(distance);
	RacingTransport::Eagle eagle(distance);
	RacingTransport::FastCamel fastCamel(distance);
	RacingTransport::MagicCarpet carpet(distance);

	TransportList tList1[arraySize]
	{
		{shoes.getName(), shoes.getType(), shoes.getRacingTime(), false},
		{boomstick.getName(), boomstick.getType(), boomstick.getRacingTime(), false},
		{camel.getName(), camel.getType(), camel.getRacingTime(), false},
		{centaur.getName(), centaur.getType(), centaur.getRacingTime(), false},
		{eagle.getName(), eagle.getType(), eagle.getRacingTime(), false},
		{fastCamel.getName(), fastCamel.getType(), fastCamel.getRacingTime(), false},
		{carpet.getName(), carpet.getType(), carpet.getRacingTime(), false}
	};

	for (int i = 0; i < arraySize; i++)
	{
		tList[i] = tList1[i];
	}
}

// ����������� �� �� �����
void transportRegister(RacingType& rType, TransportType& tType, TransportList* tList, int sizeArray, int& count)
{
	int number{};
	std::string registeredTransports{ "\n��ॣ����஢���� �࠭ᯮ��� �।�⢠: " };
	while (true)
	{
		if (count > 0)
		{
			std::cout << registeredTransports << std::endl;
		}
		if (count < 2) {
			std::cout << "\n������ ���� ��ॣ����஢��� ��� �� 2 �࠭ᯮ���� �।�⢠\n";
		}
		std::cout << "1. ��ॣ����஢��� �࠭ᯮ��\n";
		if (count >= 2)
		{
			std::cout << "2. ����� �����\n";
		}
		std::cout << "�롥�� ����⢨�: ";
		if (std::cin >> number)
		{
			switch (number)
			{
			case 1:
				addTransport(rType, tType, tList, sizeArray, count, registeredTransports);
				break;
			case 2:
				if (count < 2)
				{
					std::cout << "\n�� ����� ����୮� ���祭��\n" << std::endl;
					continue;
				}
				sortRacers(tList, sizeArray);
				break;
			default:
				std::cout << "\n�� ����� ����୮� ���祭��\n" << std::endl;
				continue;
			}
			if (number == 2)
			{
				break;
			}
		}
		else
		{
			std::cout << "\n�� ����� �����४�� ᨬ���\n" << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
	}
}

// ���������� ���������
void addTransport(RacingType& rType, TransportType& tType, TransportList* tList, int sizeArray, int& count, std::string& str)
{

	int number{};
	while (true)
	{
		printAllTransport();
		//std::cout << "������ ����� ���⠭樨 (������ ���� ������⥫쭠): ";
		if (std::cin >> number) {
			if (number < 0 || number > sizeArray)
			{
				std::cout << "\n�� ����� ����୮� ���祭��\n" << std::endl;
				continue;
			}
			if (!number)
			{
				break;
			}
			if (tList[number - 1].isUsing)
			{
				std::cout << '\n' << tList[number - 1].name << " 㦥 ��ॣ����஢��\n" << std::endl;
				continue;
			}
			if ((rType != RacingType::allTransportRacing) && (tList[number - 1].tType != tType))
			{
				std::cout << "\n����⪠ ��ॣ����஢��� ���ࠢ���� ⨯ �࠭ᯮ�⭮�� �।�⢠!\n" << std::endl;
				continue;
			}
			tList[number - 1].isUsing = true;
			if (count > 0)
			{
				str = str + ",";
			}
			str = str + " " + tList[number - 1].name;
			++count;
			//break;
			continue;
		}
		std::cout << "\n�� ����� �����४�� ᨬ���\n" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
}

// �����
void Racing(TransportList* tList, int sizeArray, RacingType& rType, double dist, int& count)
{
	TransportType tType{};
	switch (rType)
	{
	case RacingType::landingRacing:
		std::cout << "����� ��� ��������� �࠭ᯮ��. �����ﭨ�: " << dist << std::endl;
		tType = TransportType::landing;
		break;
	case RacingType::flyingRacing:
		std::cout << "����� ��� �����譮�� �࠭ᯮ��. �����ﭨ�: " << dist << std::endl;
		tType = TransportType::flying;
		break;
	case RacingType::allTransportRacing:
		std::cout << "����� ��� ��������� � �����譮�� �࠭ᯮ��. �����ﭨ�: " << dist << std::endl;
		break;
	default:
		break;
	}

	transportRegister(rType, tType, tList, sizeArray, count);
}

// ���������� �� �� ��������
void sortRacers(TransportList* tList, int sizeArray)
{
	bool isDone{};
	while (!isDone)
	{
		isDone = true;
		for (int i{}; i < sizeArray - 1; ++i) {

			if (tList[i].racingTime > tList[i + 1].racingTime)
			{
				swapRacers(tList, i);
				isDone = false;
			}
		}
	}
}

// ������ ���� �� � ��������
void swapRacers(TransportList* tList, int index)
{
	TransportList temp{ tList[index] };
	tList[index] = tList[index + 1];
	tList[index + 1] = temp;
}

// ����� � ������� ���� ��
void printAllTransport()
{
	std::cout << "\n1. ��⨭��-�����室�\n2. ��⫠\n3 .����\n4. ���⠢�\n5. ���\n6. ��࡫�-�����室\n7. �����-ᠬ����\n0. �������� ॣ������\n"
		<< "�롥�� �࠭ᯮ�� ��� 0 ��� ����砭�� ����� ॣ����樨: ";
}

// ����� � ������� ����������� �����
void printResult(TransportList* tList, int arraySize)
{
	std::cout << "\n������� �����:\n";
	int j{ 1 };
	for (int i = 0; i < arraySize; i++)
	{
		if (tList[i].isUsing) {
			std::cout << j++ << ". " << tList[i].name << ". �६�: " << tList[i].racingTime << std::endl;
		}
	}
}

// ������� ���?
bool oneMoreGame()
{
	int number{};
	while (true)
	{
		std::cout << "\n1. �஢��� ��� ���� �����\n2. ���\n�롥�� ����⢨�: ";
		if (std::cin >> number) {
			if (number < 1 || number > 2)
			{
				std::cout << "\n�� ����� ���ࠢ��쭮� �᫮\n" << std::endl;
				continue;
			}
			break;
		}
		std::cout << "\n�� ����� �����४�� ᨬ���\n" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
	return (number == 1);
}