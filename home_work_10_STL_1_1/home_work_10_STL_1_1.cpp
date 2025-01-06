#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "simple_functor.h"


int main()
{
    std::string str = "Hello world!!";
    std::map<char, int, std::greater<> > m{};
    std::multimap<int,char, std::greater<> > m_1{};
    std::cout << "[IN]: " << str << std::endl;

    std::sort(begin(str), end(str), simple_functor()); // сортировка

    int value{};
    int count{};
    for (auto i : str) // заполнение ключ - значение (уникальные ключи)
    {
        if (i == value) count++;
        else count = 1;
        value = i;
        m[i] = count ;
    };

    for (auto i : m) // обмен местами ключ-значение для сортировки по частоте
    {
       m_1.insert({i.second , i.first }); 
    };

    std::cout << "[OUT]: " << std::endl;

    for (const auto& elem : m_1)
    {
        std::cout << elem.second << ": " << elem.first << std::endl; // вывод на экран частоты символов в порядке убывания частоты
    }

    return EXIT_SUCCESS;

}

