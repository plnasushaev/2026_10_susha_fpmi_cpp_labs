#include <iostream>
int main() {
	int n, h1, h2, s1, s2;
	std::cout << "Enter a 6-digit number: \n";
	std::cin >> n;
	h1 = n / 1000;
	h2 = n % 1000;
	s1 = (h1 / 100) + ((h1 / 10) % 10) + (h1 % 10);
	s2 = (h2 / 100) + ((h2 / 10) % 10) + (h2 % 10);
	if (s1 == s2) {
		std::cout << "You entered a lucky number.";
	}
	else std::cout << "You did not enter a lucky number.";
}