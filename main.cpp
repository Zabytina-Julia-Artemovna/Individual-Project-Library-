#include <iostream>
#include <clocale>
#include <stdexcept>
#include <conio.h>
int main() {
	setlocale(LC_ALL, "rus");
	std::string administrator_password = "qwerty12345"; 

	std::string admins_input;
	char admin_choice = 0;
	
		std::cout << "--- ���������� ---\n";
		std::cout << "����������, ������� �������������� ������ ��� ����� � �������\n";
		std::cin >> admins_input;
		while (1) {
		if (admins_input != administrator_password) {
			std::cout << "������ ������?(1 - ��, 0 - ���)\n"; 
			admin_choice = _getch();
	
			if (admin_choice == '1') {
				std::cout << "���������� �� ������ ... ����� �������� ������\n";
			} else {
				break;
			}

		} else {
			system("cls");
			std::cout << "����� ���������� � �������!\n";
			system("pause");
		}
		while (1) {
			if (admin_choice == '1') {
				break;
			} 
			system("cls");
			std::cout << "--- ���������� ---\n";
			std::cout << "---------------------------------\n";
			std::cout << "1. ����������\n" << "2. ��������\n" << "3. �����\n";
			admin_choice = _getch();
			switch (admin_choice) {
			case 1:
				system("cls");
				std::cout << "TBD\n";
				break;
			case 2:
				system("cls");
				std::cout << "��������\n";
				std::cout << "1. �������� ��������\n";
				std::cout << "2. ������� ��������\n";
				std::cout << "3. ����� ������������ �����\n"; // �� ID ������ - ������ �� ���� ����������
				std::cout << "������������� ������������ �����\n"; // ��� - �� ID, � ������ - ��� ������
				break;
			case 3:
				system("cls");
				std::cout << "TBD\n";
				break;
			}
		}
		return 0;
	}
}