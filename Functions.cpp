#include "Functions.h"

// ┬√сюЁ Єшяр уюэъш
int enterRacingType()
{
	int racingType{};
	while (true)
	{
		std::cout << "\nДобро пожаловать в гоночный симулятор!\n"
			<< "1. Гонка для наземного транспорта\n"
			<< "2. Гонка для воздушного транспорта\n"
			<< "3. Гонка для наземного и воздушного транспорта\n"
			<< "Выберите тип гонки: ";
		if (std::cin >> racingType) {
			if (racingType < 1 || racingType > 3)
			{
				std::cout << "\nВы ввели неверное значение\n" << std::endl;
				continue;
			}
			break;
		}
		std::cout << "\nВы ввели некорректный символ\n" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
	return racingType;
}

// ┬тюф фшёЄрэЎшш уюэъш
int enterDistance()
{
	int distance{};
	while (true)
	{
		std::cout << "Укажите длину дистанции (должна быть положительна): ";
		if (std::cin >> distance) {
			if (distance <= 0)
			{
				std::cout << "\nДлина должна быть положительна\n" << std::endl;
				continue;
			}
			break;
		}
		std::cout << "\nВы ввели некорректный символ\n" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
	return distance;
}

// ╤ючфрэшх ёяшёър тёхї ╥╤
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

// ╨хушёЄЁрЎш  ╥╤ эр уюэъє
void transportRegister(RacingType& rType, TransportType& tType, TransportList* tList, int sizeArray, int& count)
{
	int number{};
	std::string registeredTransports{ "\nЗарегистрированные транспортные средства: " };
	while (true)
	{
		if (count > 0)
		{
			std::cout << registeredTransports << std::endl;
		}
		if (count < 2) {
			std::cout << "\nДолжно быть зарегистрировано хотя бы 2 транспортных средства\n";
		}
		std::cout << "1. Зарегистрировать транспорт\n";
		if (count >= 2)
		{
			std::cout << "2. Начать гонку\n";
		}
		std::cout << "Выберите действие: ";
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
					std::cout << "\nВы ввели неверное значение\n" << std::endl;
					continue;
				}
				sortRacers(tList, sizeArray);
				break;
			default:
				std::cout << "\nВы ввели неверное значение\n" << std::endl;
				continue;
			}
			if (number == 2)
			{
				break;
			}
		}
		else
		{
			std::cout << "\nВы ввели некорректный символ\n" << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
	}
}

// ─юсртыхэшх єўрёЄэшър
void addTransport(RacingType& rType, TransportType& tType, TransportList* tList, int sizeArray, int& count, std::string& str)
{

	int number{};
	while (true)
	{
		printAllTransport();
		//std::cout << "Укажите длину дистанции (должна быть положительна): ";
		if (std::cin >> number) {
			if (number < 0 || number > sizeArray)
			{
				std::cout << "\nВы ввели неверное значение\n" << std::endl;
				continue;
			}
			if (!number)
			{
				break;
			}
			if (tList[number - 1].isUsing)
			{
				std::cout << '\n' << tList[number - 1].name << " уже зарегистрирован\n" << std::endl;
				continue;
			}
			if ((rType != RacingType::allTransportRacing) && (tList[number - 1].tType != tType))
			{
				std::cout << "\nПопытка зарегистрировать неправильный тип транспортного средства!\n" << std::endl;
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
		std::cout << "\nВы ввели некорректный символ\n" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
}

// ├юэър
void Racing(TransportList* tList, int sizeArray, RacingType& rType, double dist, int& count)
{
	TransportType tType{};
	switch (rType)
	{
	case RacingType::landingRacing:
		std::cout << "Гонка для наземного транспорта. Расстояние: " << dist << std::endl;
		tType = TransportType::landing;
		break;
	case RacingType::flyingRacing:
		std::cout << "Гонка для воздушного транспорта. Расстояние: " << dist << std::endl;
		tType = TransportType::flying;
		break;
	case RacingType::allTransportRacing:
		std::cout << "Гонка для наземного и воздушного транспорта. Расстояние: " << dist << std::endl;
		break;
	default:
		break;
	}

	transportRegister(rType, tType, tList, sizeArray, count);
}

// ╤юЁЄшЁютър ╥╤ яю ёъюЁюёЄш
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

// ╟рьхэр фтєї ╥╤ т ЁхщЄшэух
void swapRacers(TransportList* tList, int index)
{
	TransportList temp{ tList[index] };
	tList[index] = tList[index + 1];
	tList[index + 1] = temp;
}

// ┬√тюф т ъюэёюы№ тёхї ╥╤
void printAllTransport()
{
	std::cout << "\n1. Ботинки-вездеходы\n2. Метла\n3 .Верлюд\n4. Кентавр\n5. Орёл\n6. Верблюд-быстроход\n7. Ковёр-самолёт\n0. Закончить регистрацию\n"
		<< "Выберите транспорт или 0 для окончания процесса регистрации: ";
}

// ┬√тюф т ъюэёюы№ Ёхчєы№ЄрЄют уюэъш
void printResult(TransportList* tList, int arraySize)
{
	std::cout << "\nРезультат гонки:\n";
	int j{ 1 };
	for (int i = 0; i < arraySize; i++)
	{
		if (tList[i].isUsing) {
			std::cout << j++ << ". " << tList[i].name << ". Время: " << tList[i].racingTime << std::endl;
		}
	}
}

// ╤√уЁрЄ№ х∙╕?
bool oneMoreGame()
{
	int number{};
	while (true)
	{
		std::cout << "\n1. Провести ещё одну гонку\n2. Выйти\nВыберите действие: ";
		if (std::cin >> number) {
			if (number < 1 || number > 2)
			{
				std::cout << "\nВы ввели неправильное число\n" << std::endl;
				continue;
			}
			break;
		}
		std::cout << "\nВы ввели некорректный символ\n" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
	return (number == 1);
}