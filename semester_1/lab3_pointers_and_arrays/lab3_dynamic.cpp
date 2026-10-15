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
    for (int i = 0; i < size; i++)
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
    for (int i = 0; i < size; i++)
    {
        array[i] = dist(gen);
    }
}

void PrintArray(float *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

void EvenSort(float *array, int size)
{
    int even = (size + 1) / 2;
    int amount = 0;
    for (int i = 0; i < size; i++)
    {
        if ((array[i] >= 0) && (array[i] <= 10))
        {
            float temp = array[i];
            for (int j = i; j > amount; j--)
            {
                array[j] = array[j - 1];
            }
            array[amount] = temp;
            amount++;
        }
    }
    if (even < amount)
    {
        std::cout << "Unable to sort your array: more numbers within [0,10] than even indexes.";
        std::exit(-1);
    }
    for (int i = 1; i < (2 * amount); i += 2)
    {
        for (int j = i; j < size; j++)
        {
            if (!((array[j] >= 0) && (array[j] <= 10)))
            {
                float temp = array[j];
                for (int k = j; k > i; k--)
                {
                    array[k] = array[k - 1];
                }
                array[i] = temp;
                break;
            }
        }
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

    EvenSort(userarray, size);

    std::cout << "Sorted array: ";
    PrintArray(userarray, size);

    delete[] userarray;
    return 0;
}