/*
Загальні умови:
1. Створити список з об’єктів класу-нащадку розробленого в попередній
лабораторній роботі. Вид списку вказується у варіанті.
2. Створити функції, які будуть добавляти та знищувати елементи списку.
Створити функцію пошуку, реалізація якої вказана у варіанті. Використати меню,
реалізоване в попередній лабораторній роботі для демонстрації роботи всіх функцій
членів об’єкту, знайденого функцією пошуку.
3. За необхідністю модернізувати функції-члени класу для роботи зі списком.
4. Застосувати механізм виняткових ситуацій у вказаній у варіанті функції-члені. У
випадку спрацювання виняткової ситуації у блоці CATCH вивести на екран повідомлення
про причину виникнення виняткової ситуації та виконати дії вказані у варіанті.
5. Написати програму, яка буде демонструвати роботу зі списком. Для демонстрації
роботи програма має містити меню.

Варіант 1. Клас «Залікова книжка»
Створити однонаправленний нециклічний список. Створити функцію, яка буде
шукати в списку об’єкт в якому середній бал по полю «Оцінка» структури «Дисципліна»
динамічного масиву структур більше вказаного через аргумент функції.
Конструктор. Згенерувати виключення у випадку відсутності вхідного файлу,
вивести відповідне повідомлення. 
*/

#include<iostream>
#include<cstdlib>
#include<cstring>

void copy(char * text_1, char * text_2);
int lenght(char * text);

struct Discipline {
public:
	char * discipline;
	int mark;
	char * teacher_last_name;
	const char * faculty = "FKSA";
	void show_faculty() {
		std::cout << "Faculty : " << faculty << std::endl;
	}
	Discipline() {
		discipline = NULL;
		mark = 0;
		teacher_last_name = NULL;
	}
	Discipline(char * discipline, int mark,	char * teacher_last_name) {
		//std::cout << "Create an object !!!\n";
		this->discipline = new char[lenght(discipline)];
		this->teacher_last_name = new char[lenght(teacher_last_name)];
		
		copy(discipline, this->discipline);
		copy(teacher_last_name, this->teacher_last_name);
		
		this->mark = mark;
	}
};

class student_gradebook {
public:
	char * last_name;
	char * gradebook;
	int subjects_number;
	Discipline * discipline;
	void config(char * last_name, char * gradebook) {
		//std::cout << "Create an object !!!\n";
		
		this->last_name = new char[lenght(last_name)];
		this->gradebook = new char[lenght(gradebook)];
		
		copy(last_name, this->last_name);
		copy(gradebook, this->gradebook);
	}
	bool config(char * file_name) {
		char char_temp[100];
		int int_temp;
		
		FILE * file = fopen(file_name, "r");
		
		try {
			if (!file){
				throw 123;
			}
		}
		catch (int value_code) {
			if (value_code == 123) {
				std::cout << "!!! Wrong file name !!!\n";
				return false;
			}
		}
		
		fscanf(file, "%i\n", &subjects_number);
		
		fscanf(file, "%s\n", char_temp);
		last_name = new char[lenght(char_temp)];
		copy(char_temp, this->last_name);
		
		fscanf(file, "%s\n", char_temp);
		gradebook = new char[lenght(char_temp)];
		copy(char_temp, this->gradebook);
		
		this->discipline = new Discipline[subjects_number];
		
		// std::cout << "\nSubjects_number : " << subjects_number << "\nStudent's last name : " << last_name << "\nStudent's gradebook : " << gradebook << "\n\n";
		
		for (int i = 0; i < subjects_number; i++) {
			fscanf(file, "%s\n", char_temp);
			// std::cout << "Subject : " << char_temp << '\n';
			discipline[i].discipline = new char[strlen(char_temp)];
			strcpy(discipline[i].discipline, char_temp);
			
			fscanf(file, "%i\n", &int_temp);
			// std::cout << "Mark : " << int_temp << '\n';
			discipline[i].mark = int_temp;
			
			fscanf(file, "%s\n", char_temp);
			// std::cout << "Teacher : " << char_temp << "\n\n";
			discipline[i].teacher_last_name = new char[strlen(char_temp)];
			strcpy(discipline[i].teacher_last_name, char_temp);
		}

		fclose(file);
		return true;
	}
};

class child_class : public student_gradebook {
public:
	void show_by_marks(int mark) {
		std::cout << "Student\'s last name : " << last_name << "\nGradebook number : " << gradebook << std::endl << '\n';
		std::cout << "Mark height than " << mark << " is :\n\n";
		for (int i = 0; i < subjects_number; i++) {
			if (discipline[i].mark > mark) {
				std::cout << "Subject : " << discipline[i].discipline << '\n';
				std::cout << "Mark : " << discipline[i].mark << '\n';
				std::cout << "Teacher : " << discipline[i].teacher_last_name << "\n\n";
			}
		}
	}
	void show_all() {
		std::cout << "Student\'s last name : " << last_name << "\nGradebook number : " << gradebook << std::endl << '\n';
		for (int i = 0; i < subjects_number; i++) {
			std::cout << "Subject : " << discipline[i].discipline << '\n';
			std::cout << "Mark : " << discipline[i].mark << '\n';
			std::cout << "Teacher : " << discipline[i].teacher_last_name << "\n\n";
		}
	}
	float average(child_class &);
};

float average(child_class &child) {
	float average = 0;
	for (int i = 0; i < child.subjects_number; i++) {
		average += child.discipline[i].mark;
	}
	return average / child.subjects_number;
}

bool operator>(child_class child1, child_class child2) {
	if (average(child1) > average(child2)) {
		return true;
	}
	else {
		return false;
	} 
}

struct list {
	child_class child;
	list * next;
};

list * Begin;
list * pointer;
list * pointer_for_search;

int main() {
	
	Begin = new list;
	pointer = Begin;
	pointer_for_search = pointer;
	// student_gradebook gradebook("Ivanov V.V.", "123456");
	// student_gradebook gradebook("zk.txt");
	
	// Discipline discipline("Phisics", 5, "Ivanov");
	
	// child_class children;
	
	// child_class gradebook1, gradebook2;
	
	// gradebook.show_by_marks(3);
	
	// std::cout << "Average : " << average(gradebook) << std::endl;
	
	/////////////////////////////////////////////////////////////////////////////////
	int user_choice;
	char file_name[20];
	int number;
	bool value = false;
	ups:;
	
	std::cout << "Menu :\n 0. Exit\n 1. Create new gradebook\n 2. Find in list\n>>> ";
	std::cin >> user_choice;
	
	switch (user_choice) {
		case 0:
			std::cout << "Good buy !!!\n";
			return 0;
		case 1:
			up:;
			std::cout << "Enter file name to read from : ";
			std::cin >> file_name;
			
			if (!pointer->child.config(file_name)) { goto up; }
			
			std::cout << "\nData was read successfully\n\n";		
			
			pointer->child.show_all();
			
			pointer->next = new list;
			pointer->next->next = NULL;
			pointer = pointer->next;
			goto ups;
			break;
		case 2:
			std::cout << "Enter an average number to find in the list : ";
			std::cin >> number;

			std::cout << "Suck objects :\n";
			
			pointer_for_search = Begin;
			
			while (pointer_for_search->next != NULL) {
				if (average(pointer_for_search->child) > number) {
					pointer_for_search->child.show_all();
					value = true;
				}
				pointer_for_search = pointer_for_search->next;
			}
			
			if (!value) {
				std::cout << " Nobody !!!\n";
			}
			goto ups;
			break;
		default:
			std::cout << "!!! Wrong number !!!\n";
			goto ups;
	}
	/*
	std::cin >> user_choise2;
	
	switch (user_choice1) {
		case 1:
			up:;
			std::cout << "Enter file name to read from : ";
			std::cin >> file_name;
			if (user_choise2 == 1) {
				if (!gradebook1.config(file_name)) { goto up; }
			}
			else if (user_choise2 == 2) {
				if (!gradebook2.config(file_name)) { goto up; }
			}
			else {
				std::cout << "!!! Wrong number !!!\n Choice number 1 or 2 only\n";
			}
			std::cout << "Data was read successfully\n";
			break;
		case 2:
			if (user_choise2 == 1) {
				gradebook1.show_all();
			}
			else if (user_choise2 == 2) {
				gradebook2.show_all();
			}
			else {
				std::cout << "!!! Wrong number !!!\n Choice number 1 or 2 only\n";
			}
			break;
		default:
			std::cout << "!!! Wrong number !!!\n";
	}
	if (user_choice1 != 0) {
		goto ups;
	}
	/////////////////////////////////////////////////////////////////////////////////
	* */
}

void copy(char * text_1, char * text_2) {
	int i = 0;
	for ( ; text_1[i] != '\0'; i++) {
		text_2[i] = text_1[i];
	}
	for ( ; text_2[i] != '\0'; i++) {
		text_2[i] = '\0';
	}
}

int lenght(char * text) {
	int i = 0;
	for ( ; text[i] != '\0'; i++) {}
	return i;
}
