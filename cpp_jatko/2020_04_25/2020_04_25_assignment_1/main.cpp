#include "henkilo.hpp"

void assignment_2() {
	std::vector<Person*> people;
	people.push_back(new Person{ "Tom", 42 });
	people.push_back(new Student{ "Scott", 23, "123456", 13 });
	people.push_back(new Teacher{ "Jake", 33, "physics" });

	for (Person* person : people) {
		person->printInfo();
	}

	for (auto* person : people) {
		delete person;
	}
}

void assignment_3_4_5() {
	std::string school_name{get_input<std::string>("School name: ")};


	School school{};
	
	if (school_name.size()) {
		school.setName(school_name);
	}

	bool running{ true };
	int option{};
	std::string current_teacher;
	std::string current_student;

	while (running) {
		std::cout << "Program options:\n"
			<< "1. Add teacher\n"
			<< "2. Add course for teacher\n"
			<< "3. Add student\n"
			<< "4. Add course for student\n"
			<< "5. Print teachers\n"
			<< "6. Print students\n"
			<< "7. Print school information\n"
			<< "8. Quit\n"
			<< std::endl;
		option = get_input<int>("Option: ");

		switch (option) {
		case 1:
			school.addTeacher();
			break;
		case 2:
			current_teacher = get_input<std::string>("Teacher name: ");
			for (auto teacher : school.getTeachers()) {
				if (teacher->getName() == current_teacher) {
					teacher->addCourse(get_input<std::string>("Course name: "));
					break;
				}
			}
			current_teacher = "";
			break;
		case 3:
			school.addStudent();
			break;
		case 4:
			current_student = get_input<std::string>("Student name: ");
			for (auto student : school.getStudents()) {
				if (student->getName() == current_student) {
					student->addCourse(get_input<std::string>("Course name: "));
					break;
				}
			}
			current_student = "";
			break;
		case 5:
			school.printTeachers();
			break;
		case 6:
			school.printStudents();
			break;
		case 7:
			school.printAllInfo();
			break;
		case 8:
			running = false;
			break;
		default:
			std::cout << "Error: no such option\n";
		}
		std::cout << std::endl;
	}
}

int main() {
	// assignment_2();
	assignment_3_4_5();
}