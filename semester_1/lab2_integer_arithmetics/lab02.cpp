#include <iostream>

int main() {
    long long n;
    long long d;
    long long i=1;
    std::cout << "Enter n: \n";
    if (!(std::cin >> n)) {
        std::cout << "Input error.";
        return 1;
    }
    std::cout << "Double palindromes up to " << n << ": \n";
while (i<=n) {
        long long i1=i; //чтобы было с чем сравнить
        long long r1=0;
while (i1>0) {
    d=i1 % 10;
    r1=r1*10+d;
    i1 /= 10;
}
if (i==r1) {
long long s=i*i;
long long s1=s;
long long r2=0;
while (s1>0) {
    d=s1 % 10;
    r2=r2*10+d;
    s1 /= 10;
}
if (s==r2) {
    std::cout << i << " ";
}
}
i++;
    }
return 0;
}