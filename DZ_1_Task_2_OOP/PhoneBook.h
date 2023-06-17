#pragma once
#include"PhonInfo.h"
#include<vector>
#include<fstream>
#include<iostream>

class PhoneBook
{
private:
	std::vector<PhonInfo*> _abonents;
public:
	PhoneBook() {}
	PhoneBook(std::vector<PhonInfo*>& abonents) : _abonents(abonents){ }

	int Select();
	void PrintAllAbonents();
	void AddAbonent();	
	void SubscriberSearch(std::string &str);
	void EraseRec(int num);
	~PhoneBook()
	{
		for (int i = 0; i < _abonents.size(); ++i)
			delete _abonents.at(i);
		std::cout << "Отработал деструктор\n";
	}
	bool FileWrit();
	bool FileRid();
};