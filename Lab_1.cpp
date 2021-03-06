/*
Варіант 1.
1.Описати структуру з ім'ям STUDENT, що містить наступні поля:
- прізвище і ініціали;
- номер групи;
- успішність (масив з п’яти елементів).
2. Написати програму, що виконує наступні дії:
- введення з клавіатури даних у масив, що складається з десяти структур типу STUDENT;
- записи повинні бути упорядковані по зростанню номера групи;
- вивід на дисплей прізвищ і номерів груп для всіх студентів, включених у масив, якщо
середній бал студента більше 4,0;
- якщо таких студентів немає, вивести відповідне повідомлення. 
*/

#include<iostream>

void input(char *string); // Function for inputing string
void move(char *string_1, char *string_2); // Function to move one string into other one

// Three main control points
#define student_number 3 // should be 10
#define marks_number 3
#define needed_mark 2.0

// Defining struct prototipe
struct STUDENT {
	char name[100] = {};
	char group_number[100] = {};
	int marks[marks_number] = {};
	float middle_mark = 0;
};

int main() {
	
	// Initialisingarray of structs
	STUDENT students_list[student_number];
	
	// Circle to input all student's information
	for (int num = 0; num < student_number; num++) {
		
		// Entering strudent's name
		std::cout << "Enter student's name : ";
		input(students_list[num].name);
 
        // Entering strudent's group number
		std::cout << "Enter student's group number : ";
		input(students_list[num].group_number);
		
		// Entering strudent's marks
		std::cout << "Enter " << marks_number << " student's marks :\n";
		for (int num_1 = 0; num_1 < marks_number; num_1++) {
		    std::cout << " Mark number " << num_1 + 1 << " : ";
			std::cin >> students_list[num].marks[num_1];
			
			students_list[num].middle_mark += students_list[num].marks[num_1];
		}
		// Entering strudent's midle mark
		students_list[num].middle_mark /= marks_number;
		
		std::cin.get();
		
		std::cout << '\n';
	}
	
	// Creating temp struct copy
	STUDENT temp_student;
	int num_3 = 0;
	// Bouble sort circle
	for (int num_1 = 0; num_1 < student_number - 1; num_1++) {
		for (int num_2 = 0; num_2 < student_number - 1; num_2++) {
			for (num_3 = 0; students_list[num_2].group_number[num_3] == students_list[num_2 + 1].group_number[num_3]/* && students_list[num_2].group_number[num_3] != '\0' && students_list[num_2 + 1].group_number[num_3] != '\0'*/; num_3++) {}
			if (students_list[num_2].group_number[num_3] > students_list[num_2 + 1].group_number[num_3]) {
			
			    // Comented text was used for debbuging
			    // std::cout << '\n' << students_list[num_2].group_number[0] << " > " <<  students_list[num_2 + 1].group_number[0] << '\n';;
				
			    // Swithing students' name
			    move(students_list[num_2].name, temp_student.name);
			    move(students_list[num_2 + 1].name, students_list[num_2].name);
			    move(temp_student.name, students_list[num_2 + 1].name);
			
			    // Swithing students' group number
			    move(students_list[num_2].group_number, temp_student.group_number);
			    move(students_list[num_2 + 1].group_number, students_list[num_2].group_number);
			    move(temp_student.group_number, students_list[num_2 + 1].group_number);
				
			    // Swithing students' marks
			    for (int num_3 = 0; num_3 < marks_number; num_3++) {
			        temp_student.marks[num_3] = students_list[num_2].marks[num_3];
			        students_list[num_2].marks[num_3] = students_list[num_2 + 1].marks[num_3];
			        students_list[num_2 + 1].marks[num_3] = temp_student.marks[num_3];
			    }
				
			    // Swithing students' middle mark
			    temp_student.middle_mark = students_list[num_2].middle_mark;
			    students_list[num_2].middle_mark = students_list[num_2 + 1].middle_mark;
			    students_list[num_2 + 1].middle_mark = temp_student.middle_mark;
		    }
		}
	}
	
	bool student_found = false;
	
	//  Showing students list
	std::cout << "\nStudents list (sorted by group number from big to small) :\n";
	for (int num_1 = 0; num_1 < student_number; num_1++) {
		if (students_list[num_1].middle_mark > needed_mark) {
			std::cout << "\n Name        : " << students_list[num_1].name
			          << "\n Group       : " << students_list[num_1].group_number
			          << "\n Makrs       : ";
			          
			for (int num_2 = 0; num_2 < marks_number; num_2++) {
				std::cout << students_list[num_1].marks[num_2] << ' ';
			}
			
			std::cout << "\n Middle mark : " << students_list[num_1].middle_mark; 
			std::cout << '\n';
			
			student_found = true;
		}
	}
	
	// If nobody was worst to be shown print such message
	if (!student_found) {
		std::cout << "Such student was not found !!!\n"; 
	}
	
	return 0;
}

// Input function body
void input(char *string) {
	for (int num_1 = 0; num_1 < 100; num_1++) {
	    string[num_1] = std::cin.get();
	    if (string[num_1] == '\n') {
			string[num_1] = '\0';
			break;
		}
	}
}

// Move function body
void move(char *string_1, char *string_2) {
    
    std::cout << "\nmove " << string_1 << " to " << string_2;
    
	for (int num = 0; string_2[num]; num++) {
		string_2[num] = '\0';
	}

	for (int num = 0; string_1[num] != '\0'; num++) {
		string_2[num] = string_1[num];
	}

}
