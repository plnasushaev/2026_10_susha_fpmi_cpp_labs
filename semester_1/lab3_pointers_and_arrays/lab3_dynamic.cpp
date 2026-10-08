#include <iostream>
#include <string>
#include <random>
#include <ctime>

bool EnterStr(std::string &input)
{
    while (true)
    {
        std::getline(std::cin, input);
        if ((input == "manual") || (input == "MANUAL"))
        {
            return 1;
        }
        if ((input == "random") || (input == "RANDOM"))
        {
            return 0;
        }
        else
        {
            std::cout << "Enter either \"manual\" or \"random\"." << std::endl;
        }
    }
}

template <typename T>
void EnterNum(T &A)
{
    while (true)
    {
        if (std::cin >> A)
        {
            break;
        }
        else
        {
            std::cout << "Enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }
}

void ManualArray(float *array, int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

void RandomArray(float *array, int size)
{
    float a, b;
    std::cout << "Enter a, then b (a!=b). Generated values will be within the range [a; b] or [b; a]." << std::endl;
    EnterNum(a);
    EnterNum(b);
    float min = std::min(a, b);
    float max = std::max(a, b);
    std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_real_distribution<float> dist(min, max);
    for (unsigned int i = 0; i < size; i++)
    {
        array[i] = dist(gen);
    }
}

void EvenSort()
{
}

void PrintArray(float *array, int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
}

int main()
{
    int size;
    std::cout << "Enter the size of your array: " << std::endl;
    EnterNum(size);
    size = std::abs(size);
    std::cin.ignore(1000, '\n');

    float *userarray = new float[size];

    std::string input;
    std::cout << "You can determine your array manually or generate it. Type \"manual\" or \"random\" to choose." << std::endl;
    bool inp = EnterStr(input);

    if (inp == 1)
    {
        std::cout << "Enter " << size << " elements with spaces between them: " << std::endl;
        ManualArray(userarray, size);
        std::cin.ignore(1000, '\n');
    }

    if (inp == 0)
    {
        RandomArray(userarray, size);
    }

    std::cout << "Your array: ";
    PrintArray(userarray, size);

    EvenSort();

    delete[] userarray;
    return 0;
}