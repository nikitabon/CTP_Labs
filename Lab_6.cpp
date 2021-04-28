/*
Варіант 1.
Обчислити середнє значення елементів одновимірного масиву.
*/
#include<iostream>

int recursion_func(int * array, int current_position, int finish_position);
int unrecursion_func(int * array, int current_position, int finish_position);
int check_for_numbers(char * simbols);

int main()
{
	int * array;
	int array_size;
	char simbols[20];
	up:;
	std::cout << "How many elements the array should store ? : ";
	std::cin >> simbols;
	
	array_size = check_for_numbers(simbols);
	
	if (array_size == 0) {
		std::cout << "Wrong number !!!\n";
		goto up;
	}
	
	array = new int[array_size];
	
	for (int i = 0; i < array_size; i++)
	{		
		up_to:;
		std::cout << "Enter " << i + 1 << " element : ";
		std::cin >> simbols; 
		
		for (int i = 0; simbols[i]; i++) {
			if (simbols[i] == '0' || simbols[i] == '1' || simbols[i] == '2' || simbols[i] == '3' || simbols[i] == '4' || simbols[i] == '5' || simbols[i] == '6' || simbols[i] == '7' || simbols[i] == '8' || simbols[i] == '9') {
				//
			}
			else {
				std::cout << "Wrong number !!!\n";
				goto up_to;
			}
		}
		
		array[i] = atoi(simbols);
		
	}
	
	std::cout << "The example : (";
	int temp = (recursion_func(array, 0, array_size) / array_size);
	
	std::cout << ") / " << array_size << " = " << temp << "\nThe recursion func rusult : " << temp << '\n';
	std::cout << "The unrecursion func rusult : " << (unrecursion_func(array, 0, array_size) /  array_size)<< '\n';
	
	return 0;
}

int recursion_func(int * array, int current_position, int finish_position)
{
	if (current_position == finish_position)
	{
		return 0;
	}
	else
	{
		std::cout << * array;
		if (current_position < finish_position - 1)
		{
			std::cout << " + ";
		}
		return * array + recursion_func(array + 1, current_position + 1, finish_position);
	}
}

int unrecursion_func(int * array, int current_position, int finish_position)
{
	int middle_sum = 0;
	for ( ; current_position < finish_position; current_position++)
	{
		// std::cout << current_position << ' ' <<  finish_position << ' ' << array[current_position] << '\n';
		middle_sum += array[current_position];
	}
	return middle_sum;
}

int check_for_numbers(char * simbols) {
	for (int i = 0; simbols[i]; i++) {
		if (simbols[i] == '0' || simbols[i] == '1' || simbols[i] == '2' || simbols[i] == '3' || simbols[i] == '4' || simbols[i] == '5' || simbols[i] == '6' || simbols[i] == '7' || simbols[i] == '8' || simbols[i] == '9') {
			//
		}
		else {
			// std::cout << "Wrong number !!!";
			return 0;
		}
	}
	return atoi(simbols);
}
