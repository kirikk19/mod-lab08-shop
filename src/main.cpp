// SMOMarket.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "market.h"
#include <ctime>
int main()
{
	srand(time(nullptr));
	Supermarket* supermarket = new Supermarket(15, 40, 10, 5);
	supermarket->run();
	return 0;
}
