#include <iostream>
#include <limits>
#include <string>
#include <optional>

unsigned some_const_number()
{
    return 42;
}

unsigned input()
{
    unsigned number;
    while (!(std::cin >> number))
    {
        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a number.\n>";
    }
    return number;
}

void guess_number(unsigned number)
{
    std::cout << "Guess the number.\n>";
    unsigned guess = input();
    while (guess != number)
    {
        std::cout << guess << " is wrong. Try again\n>";
        guess = input();
    }
    std::cout << "Well done.\n";
}

std::optional<int> read_number(std::istream &in)
{
    int result{};
    if (in >> result)
    {
        return result;
    }
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return {};
}

void guess_number_or_give_up(int number)
{
    std::cout << "Guess the number.\n>";
    std::optional<int> guess;
    while (guess = read_number(std::cin))
    {
        if (guess.value() == number)
        {
            std::cout << "Well done.";
            return;
        }
        std::cout << guess.value() << " is wrong. Try again\n>";
    }
    std::cout << "The number was " << number << "\n";
}

int main()
{
    guess_number_or_give_up(some_const_number());
}