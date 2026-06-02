#include <iostream>
#include <string>
#include <cctype>
using namespace std;
 
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}
 
string encrypt(string text, int key) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += (char)((((c - base) * key) % 26) + base);
        } else {
            result += c;
        }
    }
    return result;
}
 
string decrypt(string text, int key) {
    string result = "";
    int inv = modInverse(key, 26);
    if (inv == -1) return "Error: Key has no inverse (not coprime with 26)";
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += (char)((((c - base) * inv) % 26) + base);
        } else {
            result += c;
        }
    }
    return result;
}
 
int main() {
    string message = "HELLO WORLD";
    int key = 7;
    string cipherText = encrypt(message, key);
    string plainText = decrypt(cipherText, key);
    cout << "Original Message: " << message << endl;
    cout << "Encrypted: " << cipherText << endl;
    cout << "Decrypted: " << plainText << endl;
    return 0;
}
