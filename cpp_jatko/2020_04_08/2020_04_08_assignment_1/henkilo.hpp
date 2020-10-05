#pragma once

#include <string>
#include <vector>

class Address {
private:
	std::string street_address{};
	std::string postal_code{};
	std::string city{};

public:

	Address();
	Address(const std::string&, const std::string&, const std::string&);
	~Address();

	const std::string getStreetAddress();
	void setStreetAddress(const std::string&);

	const std::string getPostalCode();
	void setPostalCode(const std::string&);

	const std::string getCity();
	void setCity(const std::string&);

	const void printInfo();
};

class Person {
private:
	std::string name;
	int age;
	Address address{};

public:

	Person();
	Person(const std::string&, const int&);
	Person(const std::string&, const int&, const Address&);
	Person(const Person&);
	~Person();

	const std::string getName();
	void setName(const std::string&);

	const int getAge();
	void setAge(const int&);

	const Address getAddress();
	void setAddress(const Address&);

	const void printPersonInfo();
};

class Student : public Person {
private:
	std::string studentNumber;
	std::vector<std::string> completedCourses{};
	int academicCredit;

public:
	std::vector<std::string> getCompletedCourses();
	void addCourse(const std::string&);

	const int getAcademicCredit();
	void setAcademicCredit(const int);
	void addAcademicCredit(const int);

	const std::string getStudentNumber();
	void setStudentNumber(const std::string&);

	void printInfo();

	Student();
	Student(const std::string&, const int&, const std::string&, const int&);
	Student(const Student&);
	~Student();
};

class Teacher : public Person {
private:
	std::string academicField;
	std::vector<std::string> courses{};

public:
	std::vector<std::string> getCourses();
	void addCourse(const std::string&);
	void removeCourse(const std::string&);
	const std::string& getAcademicField();
	void setAcademicField(const std::string&);
	void printInfo();

	Teacher();
	Teacher(const std::string&, const int&, const std::string&);
	Teacher(const Teacher&);
	~Teacher();
};