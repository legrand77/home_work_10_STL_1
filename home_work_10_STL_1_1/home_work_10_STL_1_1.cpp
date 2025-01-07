#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "simple_functor.h"


int main()
{
    std::string str = "Hello world!!";
    std::multimap<int, char, std::greater<> > m_1{};
    std::cout << "[IN]: " << str << std::endl;

    std::sort(begin(str), end(str), simple_functor()); // сортировка

    int value{};
    int count{};
    for (int i = 0; i < str.length(); i++) // заполнение ключ - значение 
    {
        if (str[i] == value) count++;
        else count = 1;
        value = str[i];
        if (str[i] != str[i+1] && str[i+1] != str.length()-1) m_1.insert({count , str[i]});   
    };

    std::cout << "[OUT]: " << std::endl;

    for (const auto& elem : m_1)
    {
        std::cout << elem.second << ": " << elem.first << std::endl; // вывод на экран частоты символов в порядке убывания частоты
    }
    return EXIT_SUCCESS;
}

