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
	string company;
	string name;
	string phone;
	string address;
	string profession;

	void print()
	{
		cout << company << "\n" << name << "\n" << phone << "\n" << address << "\n" << profession << "\n\t-----\n";
	}
};


class Directory
{
private:
	vector<Person> table;
public:

	void add()
	{
		Person p;
		cout << "\tAdd\nName:\t\t";
		getline(cin,p.name);
		cout << "Company:\t";
		getline(cin, p.company);
		cout << "Phone:\t\t";
		getline(cin, p.phone);
		cout << "Address:\t";
		getline(cin, p.address);
		cout << "Profession:\t";
		getline(cin, p.profession);
		table.push_back(p);
		printPerson(p);

	}

	void save()
	{
		ofstream file("directory.bin", ios::binary | ios::app);
		for (Person elem : table)
			file.write((char*)&elem, sizeof(elem));
		file.close();
	}

	void load()
	{
		ifstream file("directory.bin", ios::binary);
		if (!file)
			return;
		Person elem;
		vector<Person> tmp;
		int count = 0;
		/*
		do 
		{

				if (file.read((char*)&elem, sizeof(elem)))
					elem.print();
				else
					break;
				cout << ++count << endl;

				//if (!file.eof()) //Если выставился EOF
					//break;//Выходим из ци
				tmp.push_back(elem);
		
			
		//	cout << elem.name << endl;

			//cout << "read";
		} while (!file.eof());
		*/
		file.seekg(0);
		while (file.read((char*)&elem, sizeof(elem)))
		{
			++count;
			tmp.push_back(elem);
			if (count > 2)
				break;
		}
	
		
		file.close();
		table = tmp;
		printAll();
		//cout << "Load";

		//data_star d;
		//QVector <data_star> vec;
		//ifstream in(filename.toUtf8().constData(), ios::binary);
		//while (in.read((char*)&d, sizeof(data_star)))// считываем в вектор структур
		//{
		//	vec.push_back(d);
		//}
		//in.close();
		
	}

	void printPerson(Person &p)
	{
		p.print();
	}

	void printAll()
	{
		for (Person elem : table)
			elem.print();
	}

	void findName(const string & name)
	{
/*
		vector<Person>::iterator it;
					
		it = find(table.begin, table.end, name);
		if (it != table.end())
			cout << "Element found in myvector: " << &it << '\n';
		else
			cout << "Element not found in myvector\n";
*/
	}


};

int main()
{
	Directory d;
	d.load();
	d.add();
	d.printAll();
	d.save();



	//vector<int> v;
	//v.push_back(17);
	//v.push_back(23);
	//v.push_back(30);
	//v.push_back(45);
	//print(v);

	//v.insert(v.begin() + v.size() / 2, 100);
	//print(v);

	//random_shuffle(v.begin(), v.end());
	//print(v);

	//sort(v.begin(), v.end());
	//print(v);

	//vector<int> w(10);

	//copy_if(v.begin(), v.end(), w.begin(), [](int elem) {return elem % 5 == 0; });
	//print(w);


	cout << endl;
	system("pause");
	return 0;

}






