#include <iostream>
#include <string> 
#include "Database.h"

int main() {
    system("chcp 1251");
    system("cls)");
    Database database;

    int choice;
    do {
        std::cout << "1. ������ �����\n";
        std::cout << "2. ������� ���� �����\n";
        std::cout << "3. ������� ����� �� �������\n";
        std::cout << "4. ������� ������ � ������� ������\n";
        std::cout << "0. �����\n";
        std::cout << "��� ����: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int licensePlate;
            std::string violation;
            std::cout << "������ ����� ������: ";
            std::cin >> licensePlate;
            std::cout << "������ ���������: ";
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
            std::cout << "������ ����� ������: ";
            std::cin >> licensePlate;
            database.printRecord(licensePlate);
            break;
        }
        case 4: {
            int start, end;
            std::cout << "������ ���������� ����� ������: ";
            std::cin >> start;
            std::cout << "������ ������� ����� ������: ";
            std::cin >> end;
            database.printRecordsInRange(start, end);
            break;
        }
        case 0:
            std::cout << "�������� ������� ������.\n";
            break;
        default:
            std::cout << "������� ����. ��������� �����.\n";
        }
    } while (choice != 0);

    return 0;
}
