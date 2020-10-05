#pragma once

#include <iostream>
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
	Address address;

protected:
	std::string name;
	int age;

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

	virtual const void printInfo();
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

	const void printInfo();

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
	const void printInfo();

	Teacher();
	Teacher(const std::string&, const int&, const std::string&);
	Teacher(const Teacher&);
	~Teacher();
};

class School {
private:
	std::vector<Teacher*> teachers;
	std::vector<Student*> students;
	std::string name;

public:
	const void addTeacher();
	const void addStudent();
	const void printTeachers();
	const void printStudents();
	const void printAllInfo();

	std::vector<Teacher*> getTeachers();
	const void setTeachers(std::vector<Teacher*>&);
	std::vector<Student*> getStudents();
	const void setStudents(std::vector<Student*>);
	const std::string getName();
	const void setName(const std::string&);

	School();
	School(const std::string&);
	School(const std::string&, std::vector<Student*>, std::vector<Teacher*>);
	~School();

};

template<typename T>
T get_input(const std::string& prompt);

template<>
std::string get_input(const std::string& prompt);

template<>
bool get_input(const std::string& prompt);
