#include <iostream>
#include <string>
#include "vector.h"





int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	vector<char> c;
	c.push_back('s');
	c.push_back(2);
	c.push_back(3);
	c.push_back(6);
	c.push_back('j');
	c.push_back(12);
	c.push_back('9');
	c.push_back(34);
	c.push_back(56);

	for(int i=0; i < c.size(); i++)
	{
	  std::cout << "vector[" << i << "]:  " << c.at(i) << std::endl;
    }

	std::cout << "size:  "<< c.size() << std::endl;;
    std::cout << "capacity:  " << c.capacity() << std::endl;
	std::cout << c.at(11) << std::endl; // проверка выброса исключения

	return EXIT_SUCCESS;
}