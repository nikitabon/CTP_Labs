/*
Варіант 1.
Обчислити середнє значення елементів одновимірного масиву.
*/
#include<iostream>

int recursion_func(int * array, int current_position, int finish_position);
int unrecursion_func(int * array, int current_position, int finish_position);

int main()
{
	int * array;
	int array_size;
	
	std::cout << "How many elements the array should store ? : ";
	std::cin >> array_size;
	
	array = new int[array_size];
	
	for (int i = 0; i < array_size; i++)
	{
		std::cout << "Enter " << i + 1 << " element : ";
		std::cin >> array[i]; 
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
