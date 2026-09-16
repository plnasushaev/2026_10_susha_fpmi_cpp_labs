#include <iostream>;
int main() {
	int n;
	double f0 = 0, f1 = 1, fn;
	std::cout << "Enter n: \n";
	std::cin >> n;
	if (n >= 1) {
		std::cout << f0 << " ";
	}
	if (n >= 2) {
		std::cout << f1 << " ";
	}
	for (int i = 3;i <= n;i++) {
		fn = f0 + f1;
		std::cout << fn << " ";
		f0 = f1;
		f1 = fn;
	}
	return 0;
}