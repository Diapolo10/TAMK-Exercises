#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

const int STUDENT_COUNT{ 1 };

struct Opiskelija {
	string etunimi;
	string sukunimi;
	string opiskelijanumero;
	int opintopisteet;
};

void tulostaOpiskelijanTiedot(vector<Opiskelija>);
Opiskelija luoOpiskelija(void);

int main(void) {
	vector<Opiskelija> students {};

	while (students.size() < STUDENT_COUNT) {

		std::cout << "Opiskelija #" << students.size() + 1 << ":\n";
		auto student = luoOpiskelija();

		std::cout << std::endl;

		students.push_back(student);
	}

	for (auto student : students) {
		tulostaOpiskelijanTiedot(student);
	}
}

void tulostaOpiskelijanTiedot(Opiskelija &student) {
	std::cout <<
		"Etunimi: " << student.etunimi << "\n" <<
		"Sukunimi: " << student.sukunimi << "\n" <<
		"Opiskelijanumero: " << student.opiskelijanumero << "\n" <<
		"Opintopisteet: " << student.opintopisteet << "\n";
	std::cout << std::endl;
}

Opiskelija luoOpiskelija(void) {
	string first_name{};
	string last_name{};
	string student_number{};
	int score{};

	std::cout << "Etunimi: ";
	std::cin >> first_name;

	std::cout << "Sukunimi: ";
	std::cin >> last_name;

	std::cout << "Opiskelijanumero: ";
	std::cin >> student_number;

	std::cout << "Opintopisteet: ";
	std::cin >> score;

	return Opiskelija{ first_name, last_name, student_number, score };
}