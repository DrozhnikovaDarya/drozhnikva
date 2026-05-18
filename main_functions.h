#ifndef MAIN_FUNCTIONS_H
#define MAIN_FUNCTIONS_H


#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>


using namespace std;

void process(string& str, int targetLength) {
    if (targetLength <= (int)str.length()) {
        return; // Если целевая длина не больше исходной, ничего не меняем
    }if (targetLength <= (int)str.length()) {
        return; // Если целевая длина не больше исходной, ничего не меняем
    }
    
    // Разбиваем строку на слова
    stringstream ss(str);
    string word;
    string words[100]; // Максимум 100 слов
    int wordCount = 0;
    
    while (ss >> word) {
        words[wordCount++] = word;
    }
    
    if (wordCount <= 1) {
        return; // Если одно слово или нет слов - нечего распределять
    }
    
    // Вычисляем общую длину всех слов
    int totalLetters = 0;
    for (int i = 0; i < wordCount; ++i) {
        totalLetters += words[i].length();
    }
    
    // Количество пробелов, которые нужно добавить
    int totalSpacesNeeded = targetLength - totalLetters;
    int spacesBetweenWords = totalSpacesNeeded / (wordCount - 1);
    int extraSpaces = totalSpacesNeeded % (wordCount - 1);
    
    // Собираем новую строку с равномерными пробелами
    string result = words[0];
    for (int i = 1; i < wordCount; ++i) {
        // Добавляем пробелы (базовое количество + возможно один дополнительный)
        int spacesToAdd = spacesBetweenWords + (extraSpaces > 0 ? 1 : 0);
        for (int j = 0; j < spacesToAdd; ++j) {
            result += ' ';
        }
        if (extraSpaces > 0) extraSpaces--;
        result += words[i];
    }
    
    str = result;
}

char* process(char* str, int wordNumber) {
    if (str == nullptr || wordNumber < 1) {
        return nullptr;
    }
    
    // Копируем строку для безопасного разбора
    char temp[1000];
    strcpy(temp, str);
    
    // Разбиваем на слова
    char* words[100];
    int wordCount = 0;
    char* token = strtok(temp, " \t\n");
    
    while (token != nullptr && wordCount < 100) {
        words[wordCount++] = token;
        token = strtok(nullptr, " \t\n");
    }
    
    // Проверяем существование слова
    if (wordNumber > wordCount) {
        return nullptr; // Слова с таким номером нет
    }
    
    // Возвращаем указатель на слово (статический буфер для результата)
    static char result[256];
    strcpy(result, words[wordNumber - 1]);
    return result;
}

namespace SpaceJustify {
    // Использует функцию process из глобальной области для выравнивания
    void process(std::string& str, int targetLength) {
        ::process(str, targetLength); 
    }
}

namespace WordExtractor {
    void process(string& str, int wordNum) {
        stringstream ss(str);
        string word;
        int currentWord = 0;
        bool found = false;

        while (ss >> word) {
            currentWord++;
            if (currentWord == wordNum) {
                str = word;
                found = true;
                break;
            }
        }
        if (!found) {
            str = ""; // Если слово не найдено, возвращаем пустую строку
        }
    }
}

template <typename T>
T findSecondLargest(T* arr, int size) {
    if (size < 2) return T(); // Возвращаем пустое/дефолтное значение, если массив мал

    // Инициализируем первый и второй максимумы из первых двух элементов
    T first = arr[0] > arr[1] ? arr[0] : arr[1];
    T second = arr[0] > arr[1] ? arr[1] : arr[0];

    // Проходим по оставшейся части массива
    for (int i = 2; i < size; ++i) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    return second;
}

template <typename T>
void reverseArrayRecursive(T* arr, int start, int end) {
    if (start >= end) return; 

    T temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverseArrayRecursive(arr, start + 1, end - 1);
}

#endif