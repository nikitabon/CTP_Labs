/* Варіант 1. Написати програму, яка перетворює масив таким чином, щоб спочатку розташовувалися нульові елементи, а потім всі інші. */

#include<iostream>
#include<cstdlib>

void restore_array(int * array, int array_size);
void show_array(int * array, int array_size);

int main()
{
	int * array;
	int array_size;
	char simbols[50];
	
	up:;
	
	std::cout << "How many elements the array should store ? : ";
	std::cin >> simbols;
	
	for (int i = 0; simbols[i]; i++) {
		if (simbols[i] == '0' || simbols[i] == '1' || simbols[i] == '2' || simbols[i] == '3' || simbols[i] == '4' || simbols[i] == '5' || simbols[i] == '6' || simbols[i] == '7' || simbols[i] == '8' || simbols[i] == '9') {
			//
		}
		else {
			std::cout << "Wrong number !!!\n";
			goto up;
		}
	}
	
	array_size = atoi(simbols);
	
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

