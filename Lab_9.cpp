/*
Загальні умови:
1. Використати об’єкти класу-нащадку розробленого в попередній лабораторній
роботі.
2. Відповідно до варіанту перевантажити оператор.
3. Зробити віртуальною одну з функцій базового класу.
4. Написати програму, яка буде демонструвати роботу з віртуальними та
невіртуальними функціями-членами класу, дружньою функцією та перевантаженим
оператором. Для демонстрації роботи програма має містити меню. В програмі
використати один екземпляр класу для кожного конструктора.

Варіант 1. Клас «Залікова книжка»
Перевантажити оператор «>» для порівняння двох об’єктів. Порівняння має
здійснюватися по полю «Оцінка» структури «Дисципліна». При порівнянні об’єктів
оператор повертає TRUE у випадку якщо середній бал по всім дисциплінам одного
об’єкту (лівий операнд) вищий середнього балу по всім дисциплінам іншого об’єкту
(правий операнд), в противному випадку оператор повертає FALSE. 
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

bool operator>(child_class child1, child_class child2) {
	if (average(child1) > average(child2)) {
		return true;
	}
	else {
		return false;
	} 
}

int main() {
	// student_gradebook gradebook("Ivanov V.V.", "123456");
	// student_gradebook gradebook("zk.txt");
	
	// Discipline discipline("Phisics", 5, "Ivanov");
	
	// child_class children;
	
	child_class gradebook1, gradebook2;
	
	// gradebook.show_by_marks(3);
	
	// std::cout << "Average : " << average(gradebook) << std::endl;
	
	/////////////////////////////////////////////////////////////////////////////////
	int user_choice1, user_choise2;
	char file_name[20];
	ups:;
	
	std::cout << "Menu (menu_option gradebook_number):\n 0. Exit\n 1. Read file\n 2. Show all\n 3. Compare first and second objects\n>>> ";
	std::cin >> user_choice1;
	
	if (user_choice1 == 0) {
		std::cout << "Good buy !!!\n";
		return 0;
	}
	else if (user_choice1 == 3) {
		std::cout << "Compare [ gradebook1 > gradebook2 ] : ";
		if ((gradebook1 > gradebook2)) {
			std::cout << "TRUE\n";
		}
		else {
			std::cout << "FALSE\n";
		}
		goto ups;
	}
	
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
