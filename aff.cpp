#include <iostream>
#include <string>
#include <cctype>
using namespace std;
 
const int a = 17;
const int b = 20;
 
int modInverse(int n) {
    for (int x = 1; x < 26; x++) {
        if (((n % 26) * (x % 26)) % 26 == 1)
            return x;
    }
    return -1;
}
 
string encryptMessage(string msg) {
    string cipher = "";
    for (int i = 0; i < msg.length(); i++) {
        if (isalpha(msg[i])) {
            char base = isupper(msg[i]) ? 'A' : 'a';
            cipher += (char)((((a * (msg[i] - base)) + b) % 26) + base);
        } else {
            cipher += msg[i];
        }
    }
    return cipher;
}
 
string decryptCipher(string cipher) {
    string msg = "";
    int a_inv = modInverse(a);
    if (a_inv == -1) return "Invalid key 'a': no modular inverse exists.";
    for (int i = 0; i < cipher.length(); i++) {
        if (isalpha(cipher[i])) {
            char base = isupper(cipher[i]) ? 'A' : 'a';
            int val = (a_inv * (cipher[i] - base - b + 26)) % 26;
            msg += (char)(val + base);
        } else {
            msg += cipher[i];
        }
    }
    return msg;
}
 
int main() {
    string inputText;
    cout << "Enter a message: ";
    getline(cin, inputText);
    string encrypted = encryptMessage(inputText);
    string decrypted = decryptCipher(encrypted);
    cout << "\nOriginal:  " << inputText << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;
    return 0;
}
