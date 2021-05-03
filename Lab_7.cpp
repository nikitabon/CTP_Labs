/*
Варіант 1. Клас «Залікова книжка»
. Закриті дані-члени класу:
- Прізвище студента;
- Номер залікової книжки.
Відкриті функції-члени класу:
- Ініціалізація (введення через аргументи функції інформації у дані-члени класу); -
Виведення на екран інформації збереженої в даних-членах.
2.Створити структуру «Дисципліна»:
- Дисципліна;
- Оцінка;
- Прізвище викладача.
До закритих даних-членів добавити:
- назва факультету (статичний елемент);
До відкритих функцій-членів добавити:
- функцію яка виводить на екран назву факультету (статичний елемент);
Створити два конструктори, які будуть зчитувати дані для заповнення масиву
структур та даних-членів класу з текстового файлу. Перший конструктор без параметрів.
В другий конструктор через параметр зчитується назва текстового файлу.
У конструкторі створити динамічний масив, з елементами типу «Дисципліна».
Кількість елементів задається з файлу.
Деструктор має виводити на екран вміст об’єкту типу «Залікова книжка».
Приклад текстового файлу (zk.txt):
2
Васаженко
А-111111
АМтаПР
3
Яценюк
Фізика
3
Ющенко
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
private:
	const char * faculty = "FKSA";
public:
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
	~Discipline() {
		//std::cout << "Delete a object !!!\n";	
		delete [] discipline;
		delete [] teacher_last_name;
	}
};

class student_gradebook {
private:
	char * last_name;
	char * gradebook;
	int subjects_number;
	Discipline * discipline;
public:
	student_gradebook(char * last_name, char * gradebook) {
		//std::cout << "Create an object !!!\n";
		
		this->last_name = new char[lenght(last_name)];
		this->gradebook = new char[lenght(gradebook)];
		
		copy(last_name, this->last_name);
		copy(gradebook, this->gradebook);
	}
	student_gradebook(char * file_name) {
		char char_temp[100];
		int int_temp;
		
		FILE * file = fopen(file_name, "r");
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
	}
	
	~student_gradebook() {
		//std::cout << "Delete a object !!!\n";
		std::cout << "Student\'s last name : " << last_name << "\nGradebook number : " << gradebook << std::endl << std::endl;
		for (int i = 0; i < subjects_number; i++) {
			std::cout << "Subject : " << discipline[i].discipline << '\n';
			std::cout << "Mark : " << discipline[i].mark << '\n';
			std::cout << "Teacher : " << discipline[i].teacher_last_name << "\n\n";
		}
		delete [] last_name;
		delete [] gradebook;
	}
};

int main() {
	// student_gradebook gradebook("Ivanov V.V.", "123456");
	student_gradebook gradebook("zk.txt");
	
	// Discipline discipline("Phisics", 5, "Ivanov");
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
