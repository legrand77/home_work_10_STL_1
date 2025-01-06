#include <iostream>
#include <set>


int main()
{
    std::set<int, std::greater<>> s{};
    int value{};
    int value_1{};
    std::cout << "[IN]: " <<  std::endl;
    std::cin >> value;
    for (int i = 0; i < value; i++)
    {
        std::cin >> value_1;
        s.insert(value_1);
    }
    std::cout << "[OUT]: " << std::endl;
    for (auto i : s)
    {
        std::cout << i << std::endl;
    }
    return EXIT_SUCCESS;
}
