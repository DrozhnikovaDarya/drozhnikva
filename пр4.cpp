#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;


bool UserInput(string input) {
    if (input.empty()) return false; 

    try {
        size_t pos;
        stoi(input, &pos); 
        return pos == input.length();
    }
    catch (...) { 
        return false; 
    }
}

int EnterNumber(string label) {
    string raw_input;
    cout << endl << label << "";
    getline(cin, raw_input); 
    while (!UserInput(raw_input)) { 
        cout << label << "";
        getline(cin, raw_input);
    }

    return stoi(raw_input); }

void task1(){
    int n = EnterNumber( "Введите кол-во точек: ");
    double t;

    int x[n] = {0}; 
    int y[n] = {0};
    int d[n] = {0};
    int k=0, T=0;

    for (int i = 0; i < n; i++) {
        double t1, t2;
        cout << "Введите координаты точки (через пробел): ";
        cin >> t1 >> t2; 
        x[i] = t1;
        y[i] = t2;
        t = t1*t1 + t2*t2;
        d[i] = t;
        if (t > T){ T = t; k = i;}}

    cout << "Все точки:" << endl;
    for (int i=0; i<n; i++) {
                cout << "(" << x[i] << "; " << y[i] << ") растояние в квадрате: " << d[i] << endl;}

    cout << "Максималное растояние от центра  точки (" << x[k] << "; " << y[k] << ") оно равно " << d[k] << endl;
}
void task2(){
    int a = EnterNumber("Введите длинну массива: ");
    int t;
    int B[a] = {0};
    B[0] = 0;
    B[1] = 1;
    for (int i =2; i<a; i++){
        t = (B[i-2] + B[i-1]);
        B[i] = t;}

    for (int i = 0; i<a; i++){
        cout << B[i] << " ";}
}
void task3(){
    int N[] = {1, 0, 1, 2, 1, 0, 2, 2, 1, 0};
    int n = sizeof(N) / sizeof(N[0]);

    int count1 = 0, count2 = 0, count0 = 0;
    for (int i = 0; i < n; i++) {
        if (N[i] == 1) count1++;
        else if (N[i] == 2) count2++;
        else count0++;
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << N[i] << " ";
    }
    cout << endl;

    int K0 = 0, K1 = 0, K2 = 0;
    int t = 0; 
    while (t < n){
        if (N[t] == 0) K0++;
        if (N[t] == 1) K1++;
        if (N[t] == 2) K2++;
        t++;}
    t = 0;
    while (t<n){
        while (K1 != 0){N[t] = 1; K1--; t++;}
        while (K2 != 0){N[t] = 2; K2--; t++;}
        while (K0 != 0){N[t] = 0; K0--; t++;}
    }

    cout << "Отсортированный массив (1, 2, 0): ";
    for (int i = 0; i < n; i++) {
        cout << N[i] << " ";
    }
    cout << endl;
}


struct MenuItem {
    string title;
    void (*action)();};


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    srand(time(0));

    map<int, MenuItem> menu = {
        {1, {"1", task1}},
        {2, {"2", task2}},
        {3, {"3", task3}}, 
    };

    int choice = 0;
        while (true) {
        cout << "\nМеню:" << endl;

        for (const auto& item : menu) {
            cout << "Task " << item.first << ". " << item.second.title << endl;
        }

        cout << "0. Выход" << endl;
        // cin.ignore();

        choice = EnterNumber("Введите номер задания: ");

        if (choice == 0) {
            cout << "© 2026 FIO" << endl;
            break;
        }

        cout << endl;

        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            cout << "Некорректный ввод.";
        }

        cout << endl;
    }
    return 0;
}
