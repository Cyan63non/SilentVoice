#include <iostream>
#include <string>
using namespace std;
 
string encrypt(string text, int key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i])) {
            result += char(int(text[i] + key - 65) % 26 + 65);
        } else if (islower(text[i])) {
            result += char(int(text[i] + key - 97) % 26 + 97);
        } else {
            result += text[i];
        }
    }
    return result;
}
 
string decrypt(string text, int key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i])) {
            result += char(int(text[i] - key - 65 + 26) % 26 + 65);
        } else if (islower(text[i])) {
            result += char(int(text[i] - key - 97 + 26) % 26 + 97);
        } else {
            result += text[i];
        }
    }
    return result;
}
 
int main() {
    string message;
    int shift;
    cout << "Enter message: ";
    getline(cin, message);
    cout << "Enter shift key (0-25): ";
    cin >> shift;
    string encrypted = encrypt(message, shift);
    string decrypted = decrypt(encrypted, shift);
    cout << "\nEncrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;
    return 0;
}
