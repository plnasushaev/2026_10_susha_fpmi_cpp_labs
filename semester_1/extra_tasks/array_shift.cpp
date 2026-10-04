#include <iostream>

void SingleShiftNeg(int *array, int size)
{
    int last = array[size - 1];
    for (int i = size - 1; i > 0; i--)
    {
        array[i] = array[i - 1];
    }
    array[0] = last;
}

void SingleShiftPos(int *array, int size)
{
    int first = array[0];
    for (int i = 0; i < size - 1; i++)
    {
        array[i] = array[i + 1];
    }
    array[size - 1] = first;
}

void InputCheck(int &a)
{
    if (!(std::cin >> a))
    {
        std::cout << "Enter a valid number." << std::endl;
        std::cin.clear();
        std::cin.ignore(100, '\n');
        InputCheck(a);
    }
}

void ArrayPrint(int *array, int size)
{
    std::cout << "Modified array: \n";
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
}

int main()
{
    int my_array[] = {2, 4, 6, 8, 9};
    int size = sizeof(my_array) / sizeof(my_array[0]);
    int k;
    std::cout << "Enter k. Elements of the array will shift k positions. k can be positive or negative." << std::endl;
    InputCheck(k);
    for (int i = 0; i < std::abs(k); i++)
    {
        if (k >= 0)
        {
            SingleShiftPos(my_array, size);
        }
        else
        {
            SingleShiftNeg(my_array, size);
        }
    }
    ArrayPrint(my_array, size);
    return 0;
}