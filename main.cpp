#include <iostream>
#include <string> 
#include "Database.h"

int main() {
    system("chcp 1251");
    system("cls)");
    Database database;

    int choice;
    do {
        std::cout << "1. Додати запис\n";
        std::cout << "2. Вивести базу даних\n";
        std::cout << "3. Вивести запис за номером\n";
        std::cout << "4. Вивести записи в діапазоні номерів\n";
        std::cout << "0. Вихід\n";
        std::cout << "Ваш вибір: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int licensePlate;
            std::string violation;
            std::cout << "Введіть номер машини: ";
            std::cin >> licensePlate;
            std::cout << "Введіть порушення: ";
            std::cin.ignore();
            std::getline(std::cin, violation);
            database.addRecord(licensePlate, violation);
            break;
        }
        case 2:
            database.printDatabase();
            break;
        case 3: {
            int licensePlate;
            std::cout << "Введіть номер машини: ";
            std::cin >> licensePlate;
            database.printRecord(licensePlate);
            break;
        }
        case 4: {
            int start, end;
            std::cout << "Введіть початковий номер машини: ";
            std::cin >> start;
            std::cout << "Введіть кінцевий номер машини: ";
            std::cin >> end;
            database.printRecordsInRange(start, end);
            break;
        }
        case 0:
            std::cout << "Програма завершує роботу.\n";
            break;
        default:
            std::cout << "Невірний вибір. Спробуйте знову.\n";
        }
    } while (choice != 0);

    return 0;
}
