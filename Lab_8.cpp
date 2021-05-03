/*
Загальні умови:
1. Створити клас-нащадок класу розробленого в попередній лабораторній роботі.
Відповідно до варіанту добавити у клас-нащадок відповідні функції-члени, дані-члени та
дружні функції.
2. Написати програму, яка буде демонструвати роботу з функціями-членами класу
та дружньою функцією. Для демонстрації роботи програма повинна містити меню. В
програмі використати один екземпляр класу для кожного конструктора.

Варіант 1. Клас «Залікова книжка»
Створити константну функцію-член, яка буде виводити на екран інформацію по
дисциплінам з балом вищим чим вказаний в аргументі функції.
Створити дружню функцію, яка буде рахувати і повертати середній бал по всім
дисциплінам.
*/

#include<iostream>
#include<cstdlib>
#include<cstring>

void copy(char * text_1, char * text_2);
int lenght(char * text);

struct Discipline {
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
		
		if (!file){
			std::cout << "!!! Wrong file name !!!\n";
			return false;
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

int main() {
	// student_gradebook gradebook("Ivanov V.V.", "123456");
	// student_gradebook gradebook("zk.txt");
	
	// Discipline discipline("Phisics", 5, "Ivanov");
	
	// child_class children;
	
	child_class gradebook;
	
	// gradebook.config("zk.txt");
	
	int user_choice;
	char file_name[20];
	int value;
	
	ups:;
	
	std::cout << "Menu :\n 0. Exit\n 1. Read file\n 2. Show all\n 3. Show by mark\n 4. Show average mark\n>>> ";
	std::cin >> user_choice;
	
	switch (user_choice) {
		case 0:
			std::cout << "Good buy !!!\n";
			break;
		case 1:
			up:;
			std::cout << "Enter file name to read from : ";
			std::cin >> file_name;
			if (!gradebook.config(file_name)) {
				goto up;
			}
			std::cout << "Data was read successfully\n";
			break;
		case 2:
			gradebook.show_all();
			break;
		case 3:
			std::cout << "Enter mark to show by it : ";
			std::cin >> value;
			gradebook.show_by_marks(value);
			break;
		case 4:
			std::cout << "Average mark : " << average(gradebook) << std::endl;
			break;
		default:
			std::cout << "!!! Wrong number !!!\n";
	}
	if (user_choice != 0) {
		goto ups;
	}
	
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
