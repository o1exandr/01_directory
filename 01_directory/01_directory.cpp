/*
Завдання 1.

Создать класс СПРАВОЧНИК со следующими полями:
1. Название фирмы;
2. Владелец;
3. Телефон;
4. Адрес;
5. Род деятельности.
Реализовать следующие возможности:
1. Поиск по названию;
2. Поиск по владельцу;
3. Поиск по номеру телефона;
4. Поиск по роду деятельности;
5. Показ всех записей и добавление.
Вся информация, должна сохранятся в бинарном  файле, должна быть реализована возможность добавления новых данных.

*/

#include "stdafx.h"
#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;



struct Person
{
	char company[40];
	char name[40];
	char phone[15];
	char address[100];
	char profession[50];

	void print()
	{
		cout << name << "\n" << company << "\n" << phone << "\n" << address << "\n" << profession << "\n\t-----\n";
	}
};


class Directory
{
private:
	vector<Person> table;
public:

	// додавання запису, читаємо з клавіатури, пушимо у вектор, у файл і на екран
	void add()
	{
		Person p;
		cout << "\tAdd\nName:\t\t";
		cin.getline(p.name, 40);
		cout << "Company:\t";
		cin.getline(p.company, 40);
		cout << "Phone:\t\t";
		cin.getline(p.phone, 15);
		cout << "Address:\t";
		cin.getline(p.address, 100);
		cout << "Profession:\t";
		cin.getline(p.profession, 50);

		table.push_back(p); //додаємо у вектор
		save(p); // пишемо у файл
		printPerson(p); //виводимо у консоль

	}

	// запис у файл
	void save(const Person &prsn)
	{
		ofstream file("directory.bin", ios::binary | ios::app);
		file.write((char*)&prsn, sizeof(prsn));
		file.close();
	}

	// завантаження з файлу
	void load()
	{
		ifstream file("directory.bin", ios::binary);
		if (!file)
			return;
		Person elem;
		vector<Person> tmp;
		while (file.read((char*)&elem, sizeof(elem)))
		{
			tmp.push_back(elem);
		}

		file.close();
		table = tmp;
		printAll();

	}

	// друк конкретного запису
	void printPerson(Person &p)
	{
		p.print();
	}

	// вивід усіх записів
	void printAll()
	{
		cout << "\t= All base =\n";
		for (Person elem : table)
			elem.print();
		cout << "\t= End of base =\n\n";
	}

	//пошук за власником
	void findName(const char * name)
	{
		vector<Person>::iterator it = find_if(table.begin(), table.end(), [name](Person &p) { return (strcmp(name, p.name) == 0); });
		if (it != table.end())
		{
			cout << "\tFind by name:\t" << name << endl;
			table[it - table.begin()].print();
		}
		else
			cout << "\n\tElement " << name << " not found\n";
	}

	// пошук за компанією
	void findCompany(const char * company)
	{
		vector<Person>::iterator it = find_if(table.begin(), table.end(), [company](Person &p) { return (strcmp(company, p.company) == 0); });
		if (it != table.end())
		{
			cout << "\tFind by company:\t" << company << endl;
			table[it - table.begin()].print();
		}
		else
			cout << "\n\tElement " << company << " not found\n";
	}

	// пошук за телефоном
	void findPhone(const char * phone)
	{
		vector<Person>::iterator it = find_if(table.begin(), table.end(), [phone](Person &p) { return (strcmp(phone, p.phone) == 0); });
		if (it != table.end())
		{
			cout << "\tFind by phone:\t" << phone << endl;
			table[it - table.begin()].print();
		}
		else
			cout << "\n\tElement " << phone << " not found\n";
	}

	// пошук за адресою
	void findAddress(const char * address)
	{
		vector<Person>::iterator it = find_if(table.begin(), table.end(), [address](Person &p) { return (strcmp(address, p.address) == 0); });
		if (it != table.end())
		{
			cout << "\tFind by address:\t" << address << endl;
			table[it - table.begin()].print();
		}
		else
			cout << "\n\tElement " << address << " not found\n";
	}

	// пошук за професією
	void findProfession(const char * profession)
	{
		vector<Person>::iterator it = find_if(table.begin(), table.end(), [profession](Person &p) { return (strcmp(profession, p.profession) == 0); });
		if (it != table.end())
		{
			cout << "\tFind by profession:\t" << profession << endl;
			table[it - table.begin()].print();
		}
		else
			cout << "\n\tElement " << profession << " not found\n";
	}

};

int main()
{
	Directory d;

	d.load();
	//d.add();

	// пошук
	d.findName("Fedir Mykolayenko");
	d.findCompany("OIL Group");
	d.findPhone("+380671234567");
	d.findAddress("Rivne"); //не знайде
	d.findProfession("Singer");

	cout << endl;
	system("pause");
	return 0;
}
