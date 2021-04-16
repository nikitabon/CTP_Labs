#include<iostream>

/*
Варіант 1.
1. Написати функцію, що записує у текстовий файл дані про сканер із приведеної
структури.
2. Написати функцію, що витягає з цього файлу дані про сканер у структуру типу
scan_іnfo. Обов'язковий параметр - номер необхідного запису. Функція повинна повертати нульове
значення, якщо читання пройшло успішно, і -1 у протилежному випадку.
3. Привести приклад програми, що створює файл із даними про сканери, (дані вводяться з
клавіатури) - 6-8 записів, і виводить на дисплей дані про запитуваний запис.
4. Усі необхідні дані для функцій повинні передаватися їм як параметри. Використання
глобальних змінних у функціях не допускається. 
*/

#define scaners_number 3

struct scan_info{
    char model[25]; //найменування моделі
    int price; // ціна
    double x_size; // області сканування // горизонтальний розмір
    double y_size; // області сканування // вертикальний розмір
    int optr; // оптичний дозвіл
    int grey; // число градацій сірого
};

void fill_struct(scan_info scaners[]);
void show_struct(scan_info scaners[]);
void write_struct(scan_info scaners[]);
int read_struct(scan_info scaners[]);
bool is_writen = false;

int main() {
	scan_info scaners[scaners_number];
	
	int user_choice;
	
	while (true) {
	
	    std::cout << "Menu :\n 0.Exit\n 1.Fill struct\n 2.Show struct\n 3.Write struct\n 4.Read struct\n>>> ";
	    std::cin >> user_choice;
	     
	    if (user_choice == 0) {
			std::cout << "Good buy\n";
			break;
		}
		else if (user_choice == 1) {
			fill_struct(scaners);
		}
		else if (user_choice == 2) {
			show_struct(scaners);
		}
		else if (user_choice == 3) {
			write_struct(scaners);
		}
		else if (user_choice == 4) {
			read_struct(scaners);
		}
		else {
			std::cout << "Wrong number !!!\n";
		}
    }
	
	return 0;
}

void fill_struct(scan_info scaners[]) {
	for (int i = 0; i < scaners_number; i++) {
		std::cout << "Enter scaner number " << i + 1 << " parameters :\n";
		
		std::cout << "Model : ";
		std::cin >> scaners[i].model;
		
		std::cout << "Price : ";
		std::cin >> scaners[i].price;
		
		std::cout << "X_size : ";
		std::cin >> scaners[i].x_size;
		
		std::cout << "Y_size : ";
		std::cin >> scaners[i].y_size;
		
		std::cout << "Optr : ";
		std::cin >> scaners[i].optr;
		
		std::cout << "Grey : ";
		std::cin >> scaners[i].grey;
		
		std::cout << '\n';
	}
	is_writen = true;
}

void show_struct(scan_info scaners[]) {
	if (is_writen == false) {
		std::cout << "the struct is empty !!!\n";
		return;
	}
	for (int i = 0; i < scaners_number; i++) {
		std::cout << "Scaner number " << i + 1<< " parameters :";
		
		std::cout << "\n Model : " << scaners[i].model;
		
		std::cout << "\n Price : " << scaners[i].price;
		
		std::cout << "\n X_size : " << scaners[i].x_size;
		
		std::cout << "\n Y_size : " << scaners[i].y_size;
		
		std::cout << "\n Optr : " << scaners[i].optr;
		
		std::cout << "\n Grey : " << scaners[i].grey;
		
		std::cout << "\n\n";
	}
}

void write_struct(scan_info scaners[]) {
	FILE * file;
	
	char file_name[20];
	std::cout << "Enter file name : ";
	std::cin >> file_name;
	
	file = fopen(file_name, "wb");
	/*
	    char model [25]; //найменування моделі
    int price; // ціна
    double x_size; // області сканування // горизонтальний розмір
    double y_size; // області сканування // вертикальний розмір
    int optr; // оптичний дозвіл
    int grey; // число градацій сірого 
	*/
	for (int i = 0; i < scaners_number; i++) {
	    fprintf(file, "%s,", scaners[i].model);	
	    fprintf(file, "%i,", scaners[i].price);
	    fprintf(file, "%lf,", scaners[i].x_size);
	    fprintf(file, "%lf,", scaners[i].y_size);
	    fprintf(file, "%i,", scaners[i].optr);
	    fprintf(file, "%i;", scaners[i].grey);
	}
	
	fclose(file);
}

int read_struct(scan_info scaners[]) {
	FILE * file;
	
	char file_name[20];
	std::cout << "Enter file name : ";
	std::cin >> file_name;
	
	file = fopen(file_name, "rb");
	
	if (file == NULL) {
		std::cout << "Can not open file !!!\n";
		return -1;
	}
	else {
		std::cout << "Data was read seccesfully !!!\n";
	}

	for (int i = 0; i < scaners_number; i++) {
		for (int j = 0; j < 25; j++) {
	        fscanf(file, "%c", &scaners[i].model[j]);
	        if (scaners[i].model[j] == ',') {
				scaners[i].model[j] = '\0';
				break;
			}
	    }
	    fscanf(file, "%i,", &scaners[i].price);
	    // fscanf(file, "%c");
	    fscanf(file, "%lf,", &scaners[i].x_size);
	    // fscanf(file, "%c");
	    fscanf(file, "%lf,", &scaners[i].y_size);
	    // fscanf(file, "%c");
	    fscanf(file, "%i,", &scaners[i].optr);
	    // fscanf(file, "%c");
	    fscanf(file, "%i;", &scaners[i].grey);
	    // fscanf(file, "%c");
	}
	
	fclose(file);
	is_writen = true;
	return 0;
}
