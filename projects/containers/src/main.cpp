#include <iostream>
#include <vector>
#include <algorithm>

auto generate_triangle(int rows)
{
    std::vector<std::vector<int>> triangle{{1}};
    for (int row = 1; row < rows; ++row)
    {
        triangle.push_back(get_next_row(triangle.back()));
    }
    return triangle;
}

std::vector<int> get_next_row(const std::vector<int> &previous_row)
{
    std::vector next_row{1};
    if (previous_row.empty())
    {
        return next_row;
    }
    for (size_t idx = 0; idx + 1 < previous_row.size(); ++idx)
    {
        next_row.emplace_back(previous_row[idx] + previous_row[idx + 1]);
    }
    next_row.emplace_back(1);
    return next_row;
}

void print_triangle(std::vector<int> &row)
{
    for (auto number : row)
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}

template <typename T>
std::ostream &operator<<(std::ostream &s,
                         const std::vector<std::vector<T>> &triangle)
{
    for (const auto &row : triangle)
    {
        std::ranges::copy(row, std::ostream_iterator<T>(s, " "));
        s << '\n';
    }
    return s;
}

int main()
{
    auto triangle = generate_triangle(3);
    std::cout << triangle;
}

