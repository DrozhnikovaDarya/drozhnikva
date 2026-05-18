#ifndef CHECK_FUNCTIONS_H
#define CHECK_FUNCTIONS_H


#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>

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

// Функция проверки корректности ввода непустой строки типа string
bool UserInputStr(string input) {
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
    return !input.empty(); 
}

// Функция ввода строки с повторением запроса до корректного ввода
string EnterString(string label) {
    string raw_input;
    cout << label;
    getline(cin, raw_input);

    while (!UserInputStr(raw_input)) {
        cout << label;
        getline(cin, raw_input);
    }
    return raw_input;
}

// Функция проверки корректности ввода непустой строки типа char[]
bool UserInputArrChar(const char str[]) {
    const char *p = str;
    while (*p != '\0') {
        if (*p++ != ' ') return true;
    }
    return false;
}

void EnterArrChar(const char label[], char output[], size_t size) {
    cout << label;
    cin.getline(output, size);

    while (!UserInputArrChar(output)) {
        cout << label;
        cin.getline(output, size);
    }
}


struct MenuItem {
    string title;
    void (*action)();
};

#endif
