#include <iostream>
int main() {
	int a, b, d;
	using std::cout;
	using std::cin; {
		    cout << "Enter a: \n";
			cin >> a;
			cout << "Enter b: \n";
			cin >> b;
			cout << "Enter d: \n";
			cin >> d;
			cout << "Progression terms [a,b] divisible by 3: \n";
	}
	int term = a;
	while (term <= b) {
		if (term % 3 == 0) {
			cout << term << " ";
			term += d;
		}
	}
	return 0;
}