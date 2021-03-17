/* Варіант 1. Написати програму, яка перетворює масив таким чином, щоб спочатку розташовувалися нульові елементи, а потім всі інші. */

#include<iostream>

void restore_array(int * array, int array_size);
void show_array(int * array, int array_size);

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
	
	restore_array(array, array_size);
	
	std::cout << "The changed array : ";
	show_array(array, array_size);
	
	return 0;
}

void restore_array(int * array, int array_size)
{
	int * temp_array = new int[array_size];
	int element_number = 0;
	
	for (int i = 0; i < array_size; i++)
	{
		if (array[i] == 0)
		{
			temp_array[element_number] = array[i];
			element_number++;
		}
	}
	for (int i = 0; i < array_size; i++)
	{
		if (array[i] != 0)
		{
			temp_array[element_number] = array[i];
			element_number++;
		}
	}
	for (int i = 0; i < array_size; i++)
	{
		array[i] = temp_array[i];
	}
}

void show_array(int * array, int array_size)
{
	for (int i = 0; i < array_size; i++)
	{
		std::cout << array[i] << ' ';
	}
}
