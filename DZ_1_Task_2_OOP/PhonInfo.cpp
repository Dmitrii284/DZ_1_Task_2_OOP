#include "PhonInfo.h"

void PhonInfo::Print()
{
	std::cout << "ФИО: " << _fullname << std::endl;
	std::cout << "Домашний тел: " << _homephone << std::endl;
	std::cout << "Рабочий тел: " << _workphone << std::endl;
	std::cout << "Мобильный тел: " << _mobilephone << std::endl;
	std::cout << "Доп. информация: " << _additionalinf << std::endl;
}



