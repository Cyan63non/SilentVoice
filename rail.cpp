#include <iostream>
#include <string>
using namespace std;
 
string encrypt(string text) {
    string row1 = "", row2 = "";
    for (int i = 0; i < text.length(); i++) {
        if (i % 2 == 0)
            row1 += text[i];
        else
            row2 += text[i];
    }
    return row1 + row2;
}
 
string decrypt(string cipher) {
    int n = cipher.length();
    int mid = (n + 1) / 2;
    string row1 = cipher.substr(0, mid);
    string row2 = cipher.substr(mid);
    string original = "";
    for (int i = 0; i < mid; i++) {
        original += row1[i];
        if (i < row2.length())
            original += row2[i];
    }
    return original;
}
 
int main() {
    string message;
    cout << "Enter a message: ";
    getline(cin, message);
    string encrypted = encrypt(message);
    cout << "Encrypted: " << encrypted << endl;
    string decrypted = decrypt(encrypted);
    cout << "Decrypted: " << decrypted << endl;
    return 0;
}
