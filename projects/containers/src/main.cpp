#include <iostream>
#include <vector>

void generate_triangle()
{
    std::vector<int> data = {1, 2, 5};
    for (auto number : data)
    {
        std::cout << number << std::endl;
    }
}

int main()
{
    generate_triangle();
}