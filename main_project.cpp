#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include <windows.h>

#include "check_functions.h"
#include "main_functions.h"


using namespace std;

void task1(){
    cout << "\nЧасть А" << endl;
    
    string s = EnterString("Введите строку (на английском): ");
    
    cout << "Исходная строка: \"" << s << "\"" << endl;
    cout << "Длина исходной строки: " << s.length() << endl;
    
    int targetLength = EnterNumber("Введите целевую длину строки: ");
    
    process(s, targetLength);
    
    cout << "Результат: \"" << s << "\"" << endl;

    cout << "\nЧасть B" << endl;
    char str[500];
    cout << "Введите строку (на английском): ";
    cin.getline(str, 500);
    
    int wordNumber = EnterNumber("Введите номер слова: "); 
    
    char* result = process(str, wordNumber);

    if (result != nullptr) {
        cout << "Слово №" << wordNumber << ": \"" << result << "\"" << endl;
    } else {
        cout << "Слова с номером " << wordNumber << " не существует!" << endl;
    }
}


void task2(){
    cout << "\n--- Задание 2 (Пространства имен) ---\n";
    
    cout << " Пункт А:" << endl;
    string s1 = EnterString("Введите строку: ");
    int targetLength = EnterNumber("Введите целевую длину строки: ");
    
    SpaceJustify::process(s1, targetLength);
    cout << "Результат: \"" << s1 << "\"" << endl;

    cout << "\n Пункт Б:" << endl;
    string s2 = EnterString("Введите строку: ");
    int wordNumber = EnterNumber("Введите номер слова: ");
    
    WordExtractor::process(s2, wordNumber);
    if (!s2.empty()) {
        cout << "Результатслово №" << wordNumber << "): \"" << s2 << "\"" << endl;
    } else {
        cout << "Слово с номером " << wordNumber << " не найдено!" << endl;
    }
}

void task3(){
    
    int size = EnterNumber("Введите размер числового массива (минимум 2): ");
    while (size < 2) {
        cout << "Ошибка! Размер массива должен быть не менее 2 элементов.\n";
        size = EnterNumber("Введите размер числового массива: ");
    }

    int* arr = new int[size];
    
    for (int i = 0; i < size; ++i) {
        arr[i] = EnterNumber("Введите элемент [" + to_string(i) + "]: ");
    }

    int secondMax = findSecondLargest(arr, size);
    
    cout << "Второй по величине элемент в массиве: " << secondMax << endl;
    
    delete[] arr; 
}

void task4() {
    
    int size = EnterNumber("Введите размер массива для реверса: ");
    while (size <= 0) {
        cout << "Ошибка! Размер массива должен быть больше 0.\n";
        size = EnterNumber("Введите размер массива для реверса: ");
    }

    int* arr = new int[size];
    
    for (int i = 0; i < size; ++i) {
        arr[i] = EnterNumber("Введите элемент [" + to_string(i) + "]: ");
    }

    reverseArrayRecursive(arr, 0, size - 1);

    cout << "Реверсированный массив: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    srand(time(0));

    map<int, MenuItem> menu = {
        {1, {"Task 1", task1}},
        {2, {"Task 2", task2}},
        {3, {"Task 3", task3}},
        {4, {"Task 4", task4}},
        //{5, {"Task 5", task5}},

    };

    int choice = 0;

    while (true) {
        cout << "\nМеню:\n";

        for (const auto& item : menu) {
            cout << "Task " << item.first << ". "
                 << item.second.title << endl;
        }

        cout << "0. Выход\n";

        choice = EnterNumber("Введите номер задания: ");

        cin.ignore(10000, '\n');
        
        if (choice == 0) {
            cout << "© 2024 FIO\n"; 
            break;
        }

        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            cout << "Некорректный ввод.";
        }
    }

    return 0;
}