#include <algorithm>
#include <iostream>

#include "henkilo.hpp"

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

const void Person::printPersonInfo() {
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
	std::cout << "Person destructor for:\n";
	this->printPersonInfo();
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
	std::cout << "Address '" << this->getStreetAddress() << "' destroyed." << std::endl;
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

void Student::printInfo() {
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
	std::cout << "Default Student constructor used" << std::endl;
	this->setStudentNumber("STU-00000000");
	this->setAcademicCredit(0);
}

Student::Student(const std::string& name, const int& age, const std::string& student_number, const int& credit) : Person(name, age) {
	std::cout << "Parameter Student constructor used" << std::endl;
	this->setStudentNumber(student_number);
	this->setAcademicCredit(credit);
}

Student::Student(const Student& other) : Person(other) {
	std::cout << "Copy Student constructor used" << std::endl;
	this->setStudentNumber(other.studentNumber);
	this->setAcademicCredit(other.academicCredit);
}

Student::~Student() {
	std::cout << "Student destructor used" << std::endl;
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

void Teacher::printInfo() {
	std::cout << "Teacher(" << this->getName() << ", " << this->getAge() << ", " << this->getAcademicField() << ", courses=[";
	for (auto& course : this->getCourses()) {
		std::cout << course << ", ";
	}
	std::cout << "])\n";
}

Teacher::Teacher() {
	std::cout << "Teacher default constructor used" << std::endl;
	Teacher::Person();
	this->setAcademicField("None");
}

Teacher::Teacher(const std::string& name, const int& age, const std::string& field) {
	std::cout << "Parameter Teacher constructor used" << std::endl;
	this->setName(name);
	this->setAge(age);
	this->setAcademicField(field);
}

Teacher::Teacher(const Teacher& other) : Person(other) {
	std::cout << "Copy Teacher constructor used" << std::endl;
	this->setAcademicField(other.academicField);
}

Teacher::~Teacher() {
	std::cout << "Teacher destructor used" << std::endl;
}
