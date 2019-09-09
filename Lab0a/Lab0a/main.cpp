#include <iostream>
#include "module1.h"
#include "module2.h"
#include "module3.h"

int main(int argc, char** argv) {
	std::cout << "Hello world!" << "\n";

	std::cout << Module1::getMyName() << "\n";
	std::cout << Module2::getMyName() << "\n";

	using namespace Module1;
	std::cout << getMyName() << "\n"; // (A) <- вызов функции произойдет из Module1, соответственно выведется "John"
	std::cout << Module2::getMyName() << "\n";

	using namespace Module2; // (B)
	std::cout << Module2::getMyName() << "\n"; // COMPILATION ERROR (C) <- ошибка происходит из-за конфликта имен, для её исправления необходимо явно указать из какого пространства имён должен произойти вызов

	using Module2::getMyName;
	std::cout << getMyName() << "\n"; // (D) <- вызов функции произойдет из Module2, соответственно выведется "James"
	
	// задания 5, 6
	using namespace std;
	cout << Module3::getMyName() << "\n";	
}
