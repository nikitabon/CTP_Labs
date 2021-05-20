/*
Варіант 1. Задача про Вінні-Пуха або правильні бджоли.
В одному лісі живуть n бджіл і один ведмідь, які використовують один
горщик меду, місткістю Н ковтків. Спочатку горщик порожній. Поки горщик
не наповниться, ведмідь спить. Як тільки горщик заповнюється, ведмідь
прокидається і з'їдає весь мед, після чого знову засинає. Кожна бджола
багаторазово збирає по одному ковтку меду і кладе його в горщик. Бджола,
яка приносить останню порцію меду, будить ведмедя. Створити
багатопотоковий додаток, що моделює поведінку бджіл і ведмедя. 
*/

#include<iostream>
#include<thread>
#include<future>
#include<unistd.h>

int honey_pot = 0;
int honey_pot_size = 5;

/*
Блок-Схема :
ПОЧАТОК
	|
Поки вірно <------------------------\
|Ні	    |Так						|
|	Створити потік бджола			|
|		|							|
|	Якщо горщик повний				|
|	|Ні		|Так					|
|	|	Вивести відповідний текст	|
|	|		|						|
|	|	Запустити потік ведмедя		|
|	|		|						|
|	|	Отримати стан горщика		|
|	\------>|						|
|			|						|
|	Вивести вміст горщика			|
|			|						|
|	Отримати стан горщика >---------/
\-->|
  КІНЕЦЬ
*/

int eat_all_homey(int honey_pot) {
	honey_pot = 0;
	std::cout << "\n  Bear has eaten all honey\n";
	sleep(2);
	std::cout << "\n Honey pot is empty : " << honey_pot << '\n';
	sleep(2);
	std::cout << "\nRun everything again\n\n";
	sleep(2);
	return honey_pot;
}

int put_some_homey(int honey_pot) {
	if (honey_pot >= honey_pot_size) {
		std::cout << "\nBee gonna wake up the Bear\n";
		sleep(2);
		std::cout << "\n Bear woke up\n";
		sleep(2);
		auto tbear = std::async(eat_all_homey, honey_pot);
		honey_pot = tbear.get();
	}
	std::cout << "Bee has put some honey\n Honey pot : " << ++honey_pot << '\n';
	return honey_pot;
}

int main()
{
	while (true) {
		auto tbee = std::async(put_some_homey, honey_pot);
		honey_pot = tbee.get();
		sleep(2);
	}
	return 0;
}

