#pragma once
#include<iostream>
#include<string>

class PhonInfo
{
private:
	//const char* _fullname;
	std::string _fullname;
	std::string _homephone;
	std::string _workphone;
	std::string _mobilephone;
	std::string _additionalinf;
public:	
	//PhonInfo() { }
	PhonInfo(std::string fullname, std::string homephone,std::string workphone,
		std::string mobilephone, std::string additionalinf) :
		_fullname(fullname), _homephone(homephone), _workphone(workphone), _mobilephone(mobilephone), _additionalinf(additionalinf)
	{
		/*_fullname = new char[fullname.length()];
		_fullname = fullname.c_str();*/
	}
	std::string GetFullName() const {return  _fullname;}
	std::string GetHomePhone() const {return  _homephone;}
	std::string GetWorkePhone() const {return _workphone;}
	std::string GetMobilePhone() const {return  _mobilephone;}
	std::string GetAdditionalInfo() const {return  _additionalinf;}	
	void Print();	
};
