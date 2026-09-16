#include <iostream>
int main() {
	int n, n1, n2, n3, n4;
	std::cout << "Enter a 4-digit number: \n";
	std::cin >> n;
	n1 = n / 1000;
	n2 = (n / 100) % 10;
	n3 = (n / 10) % 10;
	n4 = n % 10;
	if ((n1 == n4) && (n2 == n3)) {
		std::cout << "This is a palindrome number.";
	}
	else std::cout << "This is not a palindrome number.";
}