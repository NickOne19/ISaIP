#include <iostream>
#include <string>

using namespace std;

// ������� ��� ���������� ������ � ������� ����� ��������
string encryptVigenere(const string& text, const string& key) {
    string encryptedText;
    int keyLength = key.length();

    for (size_t i = 0; i < text.length(); i++) {
        // �������� ������� ������� ������ � ����� ������������ 'A'
        char textChar = text[i] - 'A';
        char keyChar = key[i % keyLength] - 'A';
        // ������� ������ � ��������� � ������������� �����
        encryptedText += (textChar + keyChar) % 26 + 'A';
    }
    return encryptedText;
}

// ������� ��� ������������ ������ � ������� ����� ��������
string decryptVigenere(const string& encryptedText, const string& key) {
    string decryptedText;
    int keyLength = key.length();

    for (size_t i = 0; i < encryptedText.length(); i++) {
        // �������� ������� ������� �������������� ������ � ����� ������������ 'A'
        char encryptedChar = encryptedText[i] - 'A';
        char keyChar = key[i % keyLength] - 'A';
        // ��������� ������ � ��������� � �������������� �����
        decryptedText += (encryptedChar - keyChar + 26) % 26 + 'A';
    }
    return decryptedText;
}

int main() {
    setlocale(LC_ALL, "Russian");
    string text = "SHIFROVANIE";
//    string key = "LEMON"; ���� �� �����������
    string key = "VIGER";

    cout << "�������� �����: " << text << endl;
    cout << "����: " << key << endl;

    // ������� �����
    string encryptedText = encryptVigenere(text, key);
    cout << "������������� ���������: " << encryptedText << endl;

    // ��������� �����
    string decryptedText = decryptVigenere(encryptedText, key);
    cout << "�������������� ���������: " << decryptedText << endl;

    return 0;
}
