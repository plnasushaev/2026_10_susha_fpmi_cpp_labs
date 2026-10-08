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

void EnterInt(int &A)
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

void ManualArray(int *array, int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

void RandomArray(int *array, int size)
{
    int a, b;
    std::cout << "Enter a, then b (a!=b). Generated values will be within the range [a; b] or [b; a]." << std::endl;
    EnterInt(a);
    EnterInt(b);
    int min = std::min(a, b);
    int max = std::max(a, b);
    std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> dist(min, max);
    for (unsigned int i = 0; i < size; i++)
    {
        array[i] = dist(gen);
    }
}

bool DeleteElements(int *array, int size, int A)
{
    unsigned int j = 0;
    for (unsigned int i = 0; i < size; i++)
    {
        if (!(std::abs(array[i]) == A))
        {
            array[j] = array[i];
            j++;
        }
    }
    for (unsigned int j1 = j; j1 < size; j1++)
    {
        array[j1] = 0;
    }
    if (j == size)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void PrintArray(int *array, int size)
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
    EnterInt(size);
    size = std::abs(size);
    std::cin.ignore(1000, '\n');

    int *userarray = new int[size];

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

    int T;
    std::cout << "\nEnter T. All the elements whose absolute value equals T's will be replaced with zeros." << std::endl;
    EnterInt(T);
    T = std::abs(T);

    bool del = DeleteElements(userarray, size, T);

    if (del == 0)
    {
        std::cout << "There are no elements whose absolute value equals T.";
    }
    else
    {
        std::cout << "Modified array: ";
        PrintArray(userarray, size);
    }

    delete[] userarray;
    return 0;
}