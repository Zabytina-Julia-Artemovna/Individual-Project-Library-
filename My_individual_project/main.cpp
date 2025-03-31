#include <iostream>
#include <clocale>
#include <stdexcept>
#include <conio.h>
int main() {
	setlocale(LC_ALL, "rus");
	std::string administrator_password = "qwerty12345"; 

	std::string admins_input;
	char admin_choice = 0;
	
		std::cout << "--- БИБЛИОТЕКА ---\n";
		std::cout << "Пожалуйста, введите индивидуальный пароль для входа в систему\n";
		std::cin >> admins_input;
		while (1) {
		if (admins_input != administrator_password) {
			std::cout << "Забыли пароль?(1 - да, 0 - нет)\n"; 
			admin_choice = _getch();
	
			if (admin_choice == '1') {
				std::cout << "Обратитесь по номеру ... чтобы сбросить пароль\n";
			} else {
				break;
			}

		} else {
			system("cls");
			std::cout << "Добро пожаловать в систему!\n";
			system("pause");
		}
		while (1) {
			if (admin_choice == '1') {
				break;
			} 
			system("cls");
			std::cout << "--- БИБЛИОТЕКА ---\n";
			std::cout << "---------------------------------\n";
			std::cout << "1. Сотрудники\n" << "2. Читатели\n" << "3. Книги\n";
			admin_choice = _getch();
			switch (admin_choice) {
			case 1:
				system("cls");
				std::cout << "TBD\n";
				break;
			case 2:
				system("cls");
				std::cout << "ЧИТАТЕЛИ\n";
				std::cout << "1. Добавить читателя\n";
				std::cout << "2. Удалить читателя\n";
				std::cout << "3. Найти читательский билет\n"; // по ID билета - вывети из него информацию
				std::cout << "Редактировать читательский билет\n"; // чей - по ID, и вводим - что меняем
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