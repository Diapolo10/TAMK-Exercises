#include <algorithm>
#include <iostream>

#include "henkilo.hpp"

template<typename T>
T get_input(const std::string& prompt) {
	T input{};

	while (true) {
		std::cout << prompt;

		if (!(std::cin >> input)) {
			std::cerr << u8"Invalid input.\n\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		break;
	}

	return input;
}

template<>
std::string get_input(const std::string& prompt) {
	std::string input{};

	while (true) {
		std::cout << prompt;

		if (!(std::getline(std::cin, input))) {
			std::cerr << u8"Invalid input.\n\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		break;
	}

	return input;
}

template<>
bool get_input(const std::string& prompt) {
	std::string input{};

	while (true) {
		std::cout << prompt;

		if (!(std::getline(std::cin, input))) {
			std::cerr << u8"Invalid input.\n\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		break;
	}

	return input.size() && (input[0] == 'y' || input[0] == 'Y');
}

const std::string Person::getName() {
	return this->name;
}

void Person::setName(const std::string& name) {
	this->name = name;
}

const int Person::getAge() {
	return this->age;
}

void Person::setAge(const int& age) {
	this->age = age;
}

const Address Person::getAddress() {
	return this->address;
}

void Person::setAddress(const Address& address) {
	this->address = address;
}

const void Person::printInfo() {
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Age: " << this->getAge() << "\n" << std::endl;
	auto address = this->getAddress();
	address.printInfo();
}

Person::Person() {
	this->setName("");
	this->setAge(0);
	this->setAddress(Address{});
}

Person::Person(const std::string& name, const int& age) {
	this->setName(name);
	this->setAge(age);
	this->setAddress(Address{});
}

Person::Person(const std::string& name, const int& age, const Address& address) {
	this->setName(name);
	this->setAge(age);
	this->setAddress(address);
}

Person::Person(const Person& other) {
	this->setName(other.name);
	this->setAge(other.age);
	this->setAddress(other.address);
}

Person::~Person() {
	// std::cout << "Person destructor for:\n";
	// this->printInfo();
}

const std::string Address::getStreetAddress() {
	return this->street_address;
}

void Address::setStreetAddress(const std::string& street_address) {
	this->street_address = street_address;
}

const std::string Address::getPostalCode() {
	return this->postal_code;
}

void Address::setPostalCode(const std::string& postal_code) {
	this->postal_code = postal_code;
}

const std::string Address::getCity() {
	return this->city;
}

void Address::setCity(const std::string& city) {
	this->city = city;
}

const void Address::printInfo() {
	std::cout
		<< "Address:\n"
		<< "StreetAddress: " << this->getStreetAddress() << '\n'
		<< "PostalCode: " << this->getPostalCode() << '\n'
		<< "City: " << this->getCity() << '\n';
}

Address::Address() {
	this->setStreetAddress("");
	this->setPostalCode("0");
	this->setCity("");
}

Address::Address(const std::string& street_address, const std::string& postal_code, const std::string& city) {
	this->setStreetAddress(street_address);
	this->setPostalCode(postal_code);
	this->setCity(city);
}

Address::~Address() {
	// std::cout << "Address '" << this->getStreetAddress() << "' destroyed." << std::endl;
}

std::vector<std::string> Student::getCompletedCourses() {
	return this->completedCourses;
}

void Student::addCourse(const std::string& course) {
	this->completedCourses.push_back(course);
}

const int Student::getAcademicCredit() {
	return this->academicCredit;
}

void Student::setAcademicCredit(int credit) {
	this->academicCredit = credit;
}

void Student::addAcademicCredit(int credit) {
	this->academicCredit += credit;
}

const std::string Student::getStudentNumber() {
	return this->studentNumber;
}

void Student::setStudentNumber(const std::string& number) {
	this->studentNumber = number;
}

const void Student::printInfo() {
	std::cout << "Student("

		<< this->getName() << ", "
		<< this->getAge() << ", "
		<< this->getStudentNumber() << ", "
		<< this->getAcademicCredit()
		<< ", courses=[";
	for (auto& course : this->getCompletedCourses()) {
		std::cout << course << ", ";
	}
	std::cout << "])\n";
}

Student::Student() : Person() {
	// std::cout << "Default Student constructor used" << std::endl;
	this->setStudentNumber("STU-00000000");
	this->setAcademicCredit(0);
}

Student::Student(const std::string& name, const int& age, const std::string& student_number, const int& credit) : Person(name, age) {
	// std::cout << "Parameter Student constructor used" << std::endl;
	this->setStudentNumber(student_number);
	this->setAcademicCredit(credit);
}

Student::Student(const Student& other) : Person(other) {
	// std::cout << "Copy Student constructor used" << std::endl;
	this->setStudentNumber(other.studentNumber);
	this->setAcademicCredit(other.academicCredit);
}

Student::~Student() {
	// std::cout << "Student destructor used" << std::endl;
}

std::vector<std::string> Teacher::getCourses() {
	return this->courses;
}

void Teacher::addCourse(const std::string& course) {
	this->courses.push_back(course);
}

void Teacher::removeCourse(const std::string& course) {
	auto itr = std::find(this->courses.begin(), this->courses.end(), course);
	if (itr != this->courses.end()) this->courses.erase(itr);
}

const std::string& Teacher::getAcademicField() {
	return this->academicField;
}

void Teacher::setAcademicField(const std::string& field) {
	this->academicField = field;
}

const void Teacher::printInfo() {
	std::cout << "Teacher(" << this->getName() << ", " << this->getAge() << ", " << this->getAcademicField() << ", courses=[";
	for (auto& course : this->getCourses()) {
		std::cout << course << ", ";
	}
	std::cout << "])\n";
}

Teacher::Teacher() {
	// std::cout << "Teacher default constructor used" << std::endl;
	Teacher::Person();
	this->setAcademicField("None");
}

Teacher::Teacher(const std::string& name, const int& age, const std::string& field) {
	// std::cout << "Parameter Teacher constructor used" << std::endl;
	this->setName(name);
	this->setAge(age);
	this->setAcademicField(field);
}

Teacher::Teacher(const Teacher& other) : Person(other) {
	// std::cout << "Copy Teacher constructor used" << std::endl;
	this->setAcademicField(other.academicField);
}

Teacher::~Teacher() {
	// std::cout << "Teacher destructor used" << std::endl;
}

const std::string School::getName() {
	return this->name;
}

const void School::setName(const std::string& name) {
	this->name = name;
}

std::vector<Teacher*> School::getTeachers() {
	return this->teachers;
}

const void School::setTeachers(std::vector<Teacher*>& teachers) {
	this->teachers = teachers;
}

std::vector<Student*> School::getStudents() {
	return this->students;
}

const void School::setStudents(std::vector<Student*> students) {
	this->students = students;
}

const void School::addTeacher() {
	Teacher* teacher = new Teacher{};
	teacher->setName(get_input<std::string>("Name: "));
	teacher->setAge(get_input<int>("Age: "));
	teacher->setAddress(Address{
		get_input<std::string>("Street: "),
		get_input<std::string>("Postal code: "),
		get_input<std::string>("City: ")
	});
	teacher->setAcademicField(get_input<std::string>("Academic field: "));
	
	std::vector<std::string> courses{};
	std::string course;
	int idx{ 1 };

	while ((course = get_input<std::string>("Course #" + std::to_string(idx++) + ": ")) != "") {
		teacher->addCourse(course);
	}

	this->teachers.push_back(teacher);
}

const void School::addStudent() {
	Student* student = new Student{};
    student->setName(get_input<std::string>("Name: "));
	student->setAge(get_input<int>("Age: "));
	student->setAddress(Address{
		get_input<std::string>("Street: "),
		get_input<std::string>("Postal code: "),
		get_input<std::string>("City: ")
		});
	student->setStudentNumber(get_input<std::string>("Student number: "));
	student->setAcademicCredit(get_input<int>("Academic credit: "));

	std::vector<std::string> completed_courses{};
	std::string course;

	while ((course = get_input<std::string>("Completed course #" + std::to_string(completed_courses.size() + 1) + ": ")) != "") {
		student->addCourse(course);
	}

	this->students.push_back(student);
}

const void School::printTeachers() {
	std::cout << "Teacher info:\n";
	for (auto teacher : this->getTeachers()) {
		teacher->printInfo();
	}
}

const void School::printStudents() {
	std::cout << "Student info:\n";
	for (auto student : this->getStudents()) {
		student->printInfo();
	}
}

const void School::printAllInfo() {
	std::cout << "School name: " << this->getName() << std::endl;
	this->printTeachers();
	this->printStudents();
}

School::School() {
	this->setName("Tampere University of Applied Sciences");
}

School::School(const std::string& name) {
	this->setName(name);
}

School::School(const std::string& name, std::vector<Student*> students, std::vector<Teacher*> teachers) {
	this->setName(name);
	this->setStudents(students);
	this->setTeachers(teachers);
}

School::~School() {
	std::cout << "School destructor ran\n";
}
