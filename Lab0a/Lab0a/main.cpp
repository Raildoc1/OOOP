#include <iostream>
#include "module1.h"
#include "module2.h"
#include "module3.h"

int main(int argc, char** argv) {
	std::cout << "Hello world!" << "\n";

	std::cout << Module1::getMyName() << "\n";
	std::cout << Module2::getMyName() << "\n";

	using namespace Module1;
	std::cout << getMyName() << "\n"; // (A) <- ����� ������� ���������� �� Module1, �������������� ��������� "John"
	std::cout << Module2::getMyName() << "\n";

	using namespace Module2; // (B)
	std::cout << Module2::getMyName() << "\n"; // COMPILATION ERROR (C) <- ������ ���������� ��-�� ��������� ����, ��� � ����������� ���������� ���� ������� �� ������ ������������ ��� ������ ��������� �����

	using Module2::getMyName;
	std::cout << getMyName() << "\n"; // (D) <- ����� ������� ���������� �� Module2, �������������� ��������� "James"
	
	// ������� 5, 6
	using namespace std;
	cout << Module3::getMyName() << "\n";	
}
