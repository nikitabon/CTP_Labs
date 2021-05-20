/*
Варіант 1.
Дано 2 масиви N з натуральними числами, написати програму, яка буде
відсортовувати ці масиви двома потоками і виведе на екран час і назву потоку, який
зробить це швидше.
*/

// g++ -std=c++11 Lab_11.cpp -pthread -o Lab_11
// ./Lab_11

#include<iostream>
#include<cstdlib>
#include<thread>
#include<future>
#include<ctime>

void fill_array(int * array, int size);
int sort(int * array, int size);
void show_array(int * array, int size);

int time_1, time_2;

int size = 100;

int array_1[100] = {};
int array_2[100] = {};

int main()
{
	
/*
БЛОК-Схема :
 ПОЧАТОК
	|
Заповнити 1-й масив 
 	|
Заповнити 2-й масив 
 	|
Вивести 1-й масив
 	|
Вивести 2-й масив
 	|
Стоврити 1-й потік
 	|
Стоврити 2-й потік
 	|
Отримати 1-й час виконання
 	|
Отримати 2-й час виконання
 	|
Якщо 1-й час меньше 2-го часу
|	|Ні			|Так
|	|	 Вивести First Thread worked faster
|	---> Вивести Second Thread worked faster
---|
Вивести 1-й відсортований масив
 	|
Вивести 2-й відсортований масив
 	|
  КІНЕЦЬ
*/
	fill_array(array_1, size);
	fill_array(array_2, size);

	std::cout << "Unsorted Array 1 : ";
	show_array(array_1, size);
	std::cout << "Unsorted Array 2 : ";
	show_array(array_2, size);
	
	auto future_1 = std::async(sort, array_1, size);
	auto future_2 = std::async(sort, array_2, size);
	
	int time_1 = future_1.get();
	int time_2 = future_2.get();
	
	/*
	std::thread first(sort, array_1, size); 
	std::thread second(sort, array_2, size);
	
	time_1 = first.join();
	second.join();
	*/
	
	std::cout << "\nFirst Thread Time : " << time_1 << '\n';
	std::cout << "Second Thread Time : " << time_2 << '\n';
	if (time_1 < time_2) {
		std::cout << "\nFirst Thread worked faster !!!\n\n";
	}
	else {
		std::cout << "\nSecond Thread worked faster !!!\n\n";
	}
	std::cout << "Sorted Array 1 : ";
	show_array(array_1, size);
	std::cout << "Sorted Array 2 : ";
	show_array(array_2, size);
	/*
	auto future = std::async(simplefunc, "hello world");
     int simple = future.get();
	*/
	return 0;
}
void fill_array(int * array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 10;
	}
}

int sort(int * array, int size) {
	clock_t start = clock();
	int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
	clock_t end = clock();
	return (int)(end - start);
}

void show_array(int * array, int size) {
	std::cout << "[ ";
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << ' ';
	}
	std::cout << "]\n";
}
