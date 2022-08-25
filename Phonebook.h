#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person
{
	public:
		Person();
		Person(string new_name, int new_phone);
		string get_name() const;
		int get_phone() const;
		bool operator < (Person p) const;
		bool operator > (Person p) const;
		void print() const;

	private:
		string name;
		int phone;
};
Person::Person()
{
	name = "";
	phone = 0;
}
Person::Person(string new_name, int new_phone)
{
	name = new_name;
	phone = new_phone;
}
string Person::get_name() const
{
	return name;
}
int Person::get_phone() const
{
	return phone;
}
bool Person::operator < (Person p) const
{
	return (name < p.get_name());
}
bool Person::operator > (Person p) const
{
	return (name > p.get_name());
}
void Person::print() const
{
	cout << "Name = " << name << endl;
	cout << "Phone = " << phone << endl;
}
void add_people(vector<Person> &phone_book);
void erase(vector<Person> &phone_book, string name);
void sort(vector<Person> &phone_book);
void shuffle(vector<Person> &phone_book);
void reverse(vector<Person> &phone_book);
void print(vector<Person> &phone_book);
int lookup(const vector<Person> &phone_book, string name);
#endif


