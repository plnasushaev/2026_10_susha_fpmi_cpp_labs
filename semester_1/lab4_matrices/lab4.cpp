#include <iostream>
#include <random>

void EnterNum(int &a)
{
    if (!(std::cin >> a))
    {
        std::cout << "You must enter an int value.";
        exit(-1);
    }
}

bool InputCheck()
{
    std::cin.ignore(1000, '\n');
    std::string input;
    std::cout << "Enter \"manual\" to determine your matrix manually, \"random\" to generate it." << std::endl;
    std::getline(std::cin, input);
    if ((input == "manual") || (input == "MANUAL"))
    {
        return 1;
    }
    else if ((input == "random") || (input == "RANDOM"))
    {
        return 0;
    }
    else
    {
        std::cout << "You must type either \"manual\" or \"random\".";
        exit(-1);
    }
}

void ManualMatrix(int **matrix, int n, int m)
{
    std::cout << "Enter your matrix elements with spaces/enters between: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void RandomMatrix(int **matrix, int n, int m, std::mt19937 gen)
{
    int a, b, min, max;
    std::cout << "Enter a, then b. Generated values will be within the range [a, b] or [b, a]." << std::endl;
    EnterNum(a);
    EnterNum(b);
    min = std::min(a, b);
    max = std::max(a, b);
    std::uniform_int_distribution<int> dist(min, max);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = dist(gen);
        }
    }
}

void LineSum(int **matrix, int *linesums, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += matrix[i][j];
        }
        linesums[i] = sum;
    }
}

void SortLines(int **matrix, int *linesums, int n, int m)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (linesums[j] > linesums[j + 1])
            {
                std::swap(matrix[j], matrix[j + 1]);
                std::swap(linesums[j], linesums[j + 1]);
            }
        }
    }
}

void PrintMatrix(int **matrix, int *linesums, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "| " << linesums[i] << std::endl;
    }
}

int main()
{
    int n, m;
    std::cout << "Enter n (lines) and m (columns): " << std::endl;
    EnterNum(n);
    EnterNum(m);
    int **Mtrx = new int *[n];
    for (int i = 0; i < n; i++)
    {
        Mtrx[i] = new int[m];
    }
    int *Sums = new int[n];

    bool choice = InputCheck();
    if (choice)
    {
        ManualMatrix(Mtrx, n, m);
    }
    else if (!(choice))
    {
        std::mt19937 gen(8362648932983);
        RandomMatrix(Mtrx, n, m, gen);
    }

    LineSum(Mtrx, Sums, n, m);
    std::cout << "Your matrix: " << std::endl;
    PrintMatrix(Mtrx, Sums, n, m);
    SortLines(Mtrx, Sums, n, m);
    std::cout << "Sorted matrix: " << std::endl;
    PrintMatrix(Mtrx, Sums, n, m);

    for (int i = 0; i < n; i++)
    {
        delete[] Mtrx[i];
    }
    delete[] Mtrx;
    delete[] Sums;
    return 0;
}