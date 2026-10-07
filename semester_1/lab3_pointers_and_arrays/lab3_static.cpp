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

void EnterUI(int &A)
{
    while (true)
    {
        if (std::cin >> A)
        {
            A = std::abs(A);
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
    std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> dist(-1000, 1000);
    for (unsigned int i = 0; i < size; i++)
    {
        array[i] = dist(gen);
    }
}

void DeleteElements(int *array, int size, int A)
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
    for (; j < size; j++)
    {
        array[j] = 0;
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
    EnterUI(size);
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
    EnterUI(T);

    DeleteElements(userarray, size, T);

    std::cout << "Modified array: ";
    PrintArray(userarray, size);

    delete[] userarray;
    return 0;
}