#include <iostream>
#include <vector>
#include <algorithm>
#define FMT_HEADER_ONLY
#include <fmt/core.h>

std::vector<int> get_next_row(const std::vector<int> &previous_row)
{
    std::vector next_row{1}; // always starts with 1
    if (previous_row.empty())
    {
        return next_row;
    }
    for (size_t idx = 0; idx + 1 < previous_row.size(); ++idx) // unsigned (0+) integer type scales to compiler
    {
        next_row.emplace_back(previous_row[idx] + previous_row[idx + 1]);
    }
    next_row.emplace_back(1); // always ends with 1
    return next_row;
}

auto generate_triangle(int rows) // auto can be used to declare variables with complicated types
{
    std::vector<std::vector<int>> triangle{{1}}; // top generic row
    for (int row = 1; row < rows; ++row)
    {
        triangle.push_back(get_next_row(triangle.back()));
    }
    return triangle;
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
    for (const auto &row : triangle) // const ref avoids copy
    {
        std::ranges::copy(row, std::ostream_iterator<T>(s, " "));
        s << '\n';
    }
    return s;
}

void show_vectors(std::ostream &s,
                  const std::vector<std::vector<int>> &v)
{
    size_t final_row_size = v.back().size();
    std::string spaces(final_row_size * 3, ' '); // 3 spaces per row
    for (const auto &row : v)
    {
        s << spaces;
        if (spaces.size() > 3)
            spaces.resize(spaces.size() - 3); // each row, shrink spaces by 3
        for (const auto &data : row)
        {
            s << fmt::format("{: ^{}}", data, 6); // centre each number in a block of 6
        }
        s << '\n';
    }
}

#include <cassert>
#include <numeric>
void check_properties(const std::vector<std::vector<int>> & triangle)
{
    size_t row_number = 1;
    for (const auto & row : triangle)
    {
        assert(row.front() == 1);
        assert(row.back() == 1);
        int sum = std::accumulate(row.begin(), row.end(), 0);
        assert(pow(2, (row_number - 1)) == (sum) );
        assert(row.size() == row_number++);
    }
}

int main()
{
    auto triangle = generate_triangle(16);
    check_properties(triangle);
    show_vectors(std::cout, triangle);
}
