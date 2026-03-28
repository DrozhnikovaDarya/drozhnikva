#include <iostream>
using namespace std;

void task1() {
    
    float x;
    float k;
    cin >> x;
    k = x * 0.10668;
     cout << "№1:  " << x << " вёрст = " << k << " километров" << endl;
}

void task2(){
    int x;
    int k;
    cin >> x;
    cin >> k;
    x = x / 10;
    k = k / 10;
    cout << "№2:  " << x % 10 + k % 10 << endl;
}

void task3(){
    int a;
    int b;
    int c;
    cin >> a;
    cin >> b;
    cin >> c;

    if (a > b and b > c) {
        cout << "№3:  " << 3 * a << " " << 3 * b  << " " << 3 * c << endl;
    }
    else {
        cout << "№3:  " << (-1) * a  << " " << (-1) * b  << " " << (-1) * c << endl;
    }
}

void task4(){
    float a;
    cin >> a;

    if (a <= -1) {
        cout << "№4:  " << 1 / (a * a) << endl;
    }
    if (a > -1 and a <= 2) {
        cout << "№4:  " << (a * a) << endl;
    }
    if (a > 2) {
        cout << "№4:  " << 4 << endl;
    }
}

void task5(){
    int a;
    cin >> a;
    switch (a) {
        case 7:
            cout << "№5:  " << "Воскресенье";
            break;
        case 6:
            cout << "№5:  " << "Суббота";
            break;
    
        default:
            cout << "№5:  " << "Другой день";
            break;
    }
}

int main() {
    int funcSelect;
    cin >> funcSelect;
    for (;;)
    {

        if (funcSelect == 0) break; 
        switch (funcSelect) 
        {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            default:
                cout << "Ошибка: выберите номер от 1 до 5 или 0 для выхода." << endl;
                break;
        }
    }
    return 0;
}


