#include <iostream>
#include <string>
#include <vector>

int CharToRoman(char a)
{
    switch (a)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}

int RomanToArabic(std::string roman)
{
    int arabic = 0;
    for (int i = 0; i < roman.length(); i++)
    {
        int current = CharToRoman(roman[i]);
        if (i == roman.length() - 1)
        {
            arabic += current;
            break;
        }
        int next = CharToRoman(roman[i + 1]);
        if ((current >= next))
        {
            arabic += current;
        }
        else
        {
            arabic -= current;
        }
    }
    return arabic;
}

std::vector<std::string> SeparateString(std::string str)
{
    std::vector<std::string> result;
    size_t first = 0;
    size_t space_index = str.find(' ');
    while (space_index != std::string::npos)
    {
        std::string word = str.substr(first, space_index - first);
        if (!word.empty()) {
        result.push_back(word);
        }
        first = ++space_index;
        space_index = str.find(' ', first);
    }
    if (first < str.size()) {
    result.push_back(str.substr(first));
    }
    return result;
}

int EvenSumAndSwap(std::vector<int> &arabic, std::vector<std::string> &roman)
{
    int sum = 0;
    int min = 0;
    int max = 0;
    for (int i = 0; i < arabic.size(); i++)
    {
        if (arabic[i] % 2 == 0)
        {
            sum += arabic[i];
        }
        if (arabic[i] > arabic[max])
        {
            max = i;
        }
        if (arabic[i] < arabic[min])
        {
            min = i;
        }
    }
    std::swap(arabic[min], arabic[max]);
    std::swap(roman[min], roman[max]);
    return sum;
}

int main()
{
    std::string romanstr;
    std::cout << "Your string: ";
    std::getline(std::cin, romanstr);
    std::vector<std::string> roman = SeparateString(romanstr);
    std::vector<int> arabic;
    for (int i = 0; i < roman.size(); i++)
    {
        arabic.push_back(RomanToArabic(roman[i]));
    }
    int evensum = EvenSumAndSwap(arabic, roman);
    std::cout << "Min&max swapped: ";
    for (std::string el : roman)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl
              << "Even values sum: " << evensum;
    return 0;
}