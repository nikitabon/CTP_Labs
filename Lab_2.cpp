/*
Варіант 1.
Написати програму, яка визначає скільки разів у файлі зустрічаються символ введений з
клавіатури.
*/

#include<iostream>
#include<cstdlib>

int main() {
	char str_array[100 * 100]; // ~ string str_array;
	char file_name[20] = "file.dat";
	char character = 'a';
	int user_choice;
	// int lines_number = 0;
	int character_number = 0;
    
    up:;
    
    std::cout << "\nMenu :\n 0.Exit\n 1.Create a file\n 2.Read a file\n 3.Colculation\n>>> ";
    std::cin >> user_choice;
    
    FILE * file;
    
    if (user_choice == 0) {
		std::cout << " Good buy !!!\n";
		return 0;
	}
	else if (user_choice == 1) {
		std::cout << " Create a file :\n";
	    std::cout << " Enter file name : ";
    	std::cin >> file_name;
    	
		file = fopen(file_name, "wb");
		
		std::cin.get();
		
		std::cout << " Enter a sentence : ";
	    for (int num_1 = 0; num_1 < 10000; num_1++) {
			character = std::cin.get();
		    fprintf(file, "%c", character);
		    if (character == '\n') {
		        break;
			}
		}
		fclose(file);
	}
	else if (user_choice == 2) {
		do {
		    std::cout << " Enter file name : ";
    	    std::cin >> file_name;
		    file = fopen(file_name, "rb");
	    } while (file == NULL);
	    
	    std::cout << " The current text :\n";
	    
	    for (int num_1 = 0; num_1 < 10000; num_1++) {
		    fscanf(file, "%c", &str_array[num_1]);
    	    if (str_array[num_1] == EOF || str_array[num_1] == '*') {
			    str_array[num_1] = '\0';
			    break;
		    }
		    else {
				std::cout << str_array[num_1];
			}
        }
        
	    fclose(file);
	}
	else if (user_choice == 3) {
		std::cout << " Enter a character : ";
	    std::cin >> character;
	    
	    for (int num_1 = 0; num_1 < 10000 && str_array[num_1] != '\0'; num_1++) {
    	    if (str_array[num_1] == character) {
		        character_number++;
		    }
	    }
	    
	    std::cout << " Character " << character << " repeats in text " << character_number << " times\n";
	}
    else {
		std::cout << " Wrong humber !!!\n";
	}
	
	goto up;
	
	return 0;
}
