﻿#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

bool IsPrimeNumber(int num1, int num2) {
    if (num1 == num2) {
        return num1 == 1;
    }
    else {
        if (num1 > num2) {
            return IsPrimeNumber(num1 - num2, num2);
        }
        else {
            return IsPrimeNumber(num2 - num1, num1);
        }
    }
}

int FindPrimeNumber(int fi_n) {
    int primeNumber = 1;
    for (int i = 2; i < fi_n; ++i) {
        if (IsPrimeNumber(fi_n, i)) {
            primeNumber = i;
            return primeNumber;
        }
    }
    return primeNumber;
}

int FindD(int fi_n, int e) {
    int d = (fi_n + 1) / e;
    int p = 1; // множитель

    while (d * e % fi_n != 1) {
        p++;
        d = (fi_n * p + 1) / e;
    }
    return d;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Заданные простые числа
    int p = 19, q = 5;
    int n = p * q;                    // Вычисляем n
    int fi_n = (p - 1) * (q - 1);

    // Определяем e и d
    int e = FindPrimeNumber(fi_n);
    int d = FindD(fi_n, e);

    // Алфавит
    string alphabet = "ABCDEFGHIGKLMNOPQRSTUVWXYZ";

    // Выводим ключи и φ(n)
    cout << "Открытый ключ (e, n): (" << e << ", " << n << ")" << endl;
    cout << "Закрытый ключ (d, n): (" << d << ", " << n << ")" << endl;
    cout << "Число φ(n): " << fi_n << endl;

    // Сообщение для шифрования
    string openMessage = "CABLE";
    vector<int> messageNumbers;
    vector<int> code;

    // Шифрование
    for (char c : openMessage) {
        int letterNumber = alphabet.find(c) + 1;
        messageNumbers.push_back(letterNumber);

        // Шифрование буквы: letterNumber ^ e
        int numberInCode = static_cast<int>(pow(letterNumber, e)) % n;
        code.push_back(numberInCode);
    }

    // Вывод исходного сообщения в числах
    cout << "Сообщение в числах: ";
    for (int num : messageNumbers)
        cout << num << " ";
    cout << endl;

    // Вывод зашифрованного сообщения
    cout << "Зашифрованное сообщение: ";
    for (int num : code)
        cout << num << " ";
    cout << endl;

    // Расшифровка
    vector<int> deCode;
    for (int num : code) {
        int numberInCode = static_cast<int>(pow(num, d)) % n;
        deCode.push_back(numberInCode);
    }

    cout << "Расшифрованное сообщение в числах: ";
    for (int num : deCode)
        cout << num << " ";
    cout << endl;

    // Преобразование чисел обратно в текст
    cout << "Расшифрованное сообщение: ";
    for (int num : deCode)
        cout << alphabet[num - 1]; // -1 для приведения к индексу
    cout << endl;

    return 0;
}
