#include <iostream>
#include <string>
#include <cctype>
using namespace std;
 
const string K1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string K2 = "ZVWYXUSRCABFEDIOJLKMNHTGPQ";
 
string encrypt(const string& plaintext) {
    string ciphertext = plaintext;
    for (char& c : ciphertext) {
        if (isalpha(c)) {
            int pos = toupper(c) - 'A';
            c = K2[pos];
        }
    }
    return ciphertext;
}
 
string decrypt(const string& ciphertext) {
    string plaintext = ciphertext;
    for (char& c : plaintext) {
        if (isalpha(c)) {
            int pos = K2.find(toupper(c));
            c = K1[pos];
        }
    }
    return plaintext;
}
 
int main() {
    string message = "See You Next Sunday?";
    string encrypted = encrypt(message);
    string decrypted = decrypt(encrypted);
    cout << "Plaintext : " << message << endl;
    cout << "Encrypted : " << encrypted << endl;
    cout << "Decrypted : " << decrypted << endl;
    return 0;
}
