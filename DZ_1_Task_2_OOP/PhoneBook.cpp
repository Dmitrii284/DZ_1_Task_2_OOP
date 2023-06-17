#include "PhoneBook.h"
#include"PhonInfo.h"

void PhoneBook::PrintAllAbonents()
{
	std::vector<PhonInfo*>::iterator it;
	int counter = 1;
	for (const auto& it : _abonents)
	{
		std::cout << "\n������� � " << counter << std::endl;
		it->Print();
		counter++;
	}
}

void PhoneBook::AddAbonent()
{
	std::string fullname;
	std::string homephone;
	std::string workphone;
	std::string mobilephone;
	std::string additionalinfo;	

	std::cout << "������� ��� -> ";
	std::cin.ignore();
	std::getline(std::cin, fullname);
	std::cout << "������� ����� ��������� �������� -> ";
	std::getline(std::cin, homephone);
	std::cout << "������� ����� �������� �������� -> ";
	std::getline(std::cin, workphone);
	std::cout << "������� ����� ���������� �������� -> ";
	std::getline(std::cin, mobilephone);
	std::cout << "������� �������������� ���������� -> ";	
	std::getline(std::cin, additionalinfo);

	PhonInfo* tmp = new PhonInfo(fullname, homephone,
		workphone, mobilephone, additionalinfo);
	_abonents.push_back(tmp);
}

int PhoneBook::Select()
{
	 int n = 0;
	do
	{
		std::cout << "\n�� ���������� � ���������� �����!!\n";
		std::cout << "1. ������� ��� ������ �� �����.\n";
		std::cout << "2. �������� ������.\n";
		std::cout << "3. ������� ������.\n";		
		std::cout << "4. ����� ������.\n";
		std::cout << "5. ���������� ������ !!!\n";
		std::cout << "�������� ����� �������� -> ";
		std::cin >> n;
	} while (n < 1 || n > 5);
	return n;
}

void PhoneBook::SubscriberSearch(std::string &str)
{
	std::vector<PhonInfo*>::iterator it;
	for (const auto it : _abonents)
	{
		if (str == it->GetFullName())
			it->Print();
	}
}

void PhoneBook::EraseRec(int num)
{
	if (num < 0 || num > _abonents.size() - 1)
		return;
	
	_abonents.erase(_abonents.begin() + num);
	delete _abonents.at(num);
}

bool PhoneBook::FileWrit()
{
	std::ofstream outinFile;
	outinFile.open("file_path.txt", std::ios::app);
	if(outinFile.is_open())
	{
		std::vector<PhonInfo*>::iterator it;
		for (it = _abonents.begin(); it != _abonents.end(); ++it)
		{
			outinFile << (*it)->GetFullName() << '\n';
			outinFile << (*it)->GetHomePhone() << '\n';
			outinFile << (*it)->GetWorkePhone() << '\n';
			outinFile << (*it)->GetMobilePhone() << '\n';
			outinFile << (*it)->GetAdditionalInfo() << '\n';
		}
		outinFile.close();
		return true;
	}
	outinFile.close();
	return false;
}

bool PhoneBook::FileRid()
{
	static std::ifstream inFile;
	inFile.open("file_path.txt", std::ios::in);
	if (inFile.is_open())
	{
		std::string fullname;
		std::string homephone;
		std::string workphone;
		std::string mobilephone;
		std::string additionalinfo;
		while (!inFile.eof())
		{
			std::getline(inFile, fullname);			
			std::getline(inFile, homephone);			
			std::getline(inFile, workphone);			
			std::getline(inFile, mobilephone);			
			std::getline(inFile, additionalinfo);		
		}	
		inFile.close();
		return true;
	}	
	inFile.close();
	return false;	
}


