#include <iostream>
#include <string>

using namespace std;

// Функция для шифрования текста с помощью шифра Виженера
string encryptVigenere(const string& text, const string& key) {
    string encryptedText;
    int keyLength = key.length();

    for (size_t i = 0; i < text.length(); i++) {
        // Получаем позицию символа текста и ключа относительно 'A'
        char textChar = text[i] - 'A';
        char keyChar = key[i % keyLength] - 'A';
        // Шифруем символ и добавляем в зашифрованный текст
        encryptedText += (textChar + keyChar) % 26 + 'A';
    }
    return encryptedText;
}

// Функция для дешифрования текста с помощью шифра Виженера
string decryptVigenere(const string& encryptedText, const string& key) {
    string decryptedText;
    int keyLength = key.length();

    for (size_t i = 0; i < encryptedText.length(); i++) {
        // Получаем позицию символа зашифрованного текста и ключа относительно 'A'
        char encryptedChar = encryptedText[i] - 'A';
        char keyChar = key[i % keyLength] - 'A';
        // Дешифруем символ и добавляем в расшифрованный текст
        decryptedText += (encryptedChar - keyChar + 26) % 26 + 'A';
    }
    return decryptedText;
}

int main() {
    setlocale(LC_ALL, "Russian");
    string text = "SHIFROVANIE";
//    string key = "LEMON"; ключ из презентации
    string key = "VIGER";

    cout << "Открытый текст: " << text << endl;
    cout << "Ключ: " << key << endl;

    // Шифруем текст
    string encryptedText = encryptVigenere(text, key);
    cout << "Зашифрованное сообщение: " << encryptedText << endl;

    // Дешифруем текст
    string decryptedText = decryptVigenere(encryptedText, key);
    cout << "Расшифрованное сообщение: " << decryptedText << endl;

    return 0;
}
