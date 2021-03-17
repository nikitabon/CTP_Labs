/*
Варіант 1.
Як відомо, властивість послідовності чисел Фібоначі: 0, 1, 1, 2, 3, 5, 8, 13, 21, ... полягає у
тому, що кожне наступне число є сумою двох попередніх.
Написати нерекурсивну функцію fibonacci (n), що обчислює n-не число Фібоначі.
*/

#include<iostream>

int fibonacci(int fibonacci_number);

int main()
{
	int fibonacci_number;
	
	std::cout << "Enter number to find its equal of fibonacci list : ";
	std::cin >> fibonacci_number;
	
	std::cout << "Fibonacci list : ";
	fibonacci_number = fibonacci(fibonacci_number);
	std::cout << "\nThe corrent number is " << fibonacci_number << '\n';
	
	return 0;
}

int fibonacci(int fibonacci_number)
{
	if (fibonacci_number <= 0)
	{
		std::cout << "Wrong number !!!";
		return -1;
	}
	if (fibonacci_number == 1)
	{
		std::cout << "0";
		return 0;
	}
	else if (fibonacci_number == 2)
	{
		std::cout << "0 1";
		return 1;
	}
	else
	{
		std::cout << "0 1 ";
	}
	
	int first_number = 0;
	int second_number = 1;
	int temp;
	
	for (int i = 0; i < fibonacci_number - 2; i++)
	{
		temp = second_number;
		second_number += first_number;
		first_number = temp;
		std::cout << second_number << ' ';
	}
	return second_number;
}
