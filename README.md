# Tiny C++ Projects
> A collection of small `C++` projects, exploring several modern features of the language.

## Libraries Required
- fmt: https://fmt.dev/latest/index.html

## Build
- `g++ -Wall --std=c++2a -o main.out main.cpp`
- `g++ -Wall --std=c++2a -o ./bin/ranges2.out ./src/ranges.cpp -I../../libraries/fmt-10.0.0/include`

## Introduction
### Use Cases
> Used for almost anything; *"the invisible foundation of everything"* - Bjarne Stroustrup

- libraries for other languages
- performance critical paths
- small embedded systems
- financial applications
- complex video games
    - game engines
    - rendering graphics
    - calculating physics
    - detecting collisions
    - providing sound and artificial intelligence
- browsers

The language is **compiled** and **targeted for specific hardware**, thus **needs to be recompiled** every time you want **the program to run on different types of machines**. This generaly means more performance at the expense of having more to maintain. 

# Containers, Iterators and Ranges
- Associative Containers: `map`
- Unordered Associative Containers: `unordered_map`

`Vectors` are the most popular containers in C++.

