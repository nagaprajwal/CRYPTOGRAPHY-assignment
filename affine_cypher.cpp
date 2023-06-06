#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

string encrypt(string plaintext, int a, int b) {
    string ciphertext = "";
    for (char c : plaintext) {
        if (isalpha(c)) {
            if (islower(c)) {
                int x = c - 'a';
                int y = (a * x + b) % 26;
                ciphertext += 'a' + y;
            } else if (isupper(c)) {
                int x = c - 'A';
                int y = (a * x + b) % 26;
                ciphertext += 'A' + y;
            }
        } else {
            ciphertext += c;
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, int a, int b) {
    string plaintext = "";
    int a_inverse = 0;
    int n = 26; 

    for (int i = 0; i < n; i++) {
        if ((a * i) % n == 1) {
            a_inverse = i;
            break;
        }
    }

    for (char c : ciphertext) {
        if (isalpha(c)) {
            if (islower(c)) {
                int y = c - 'a';
                int x = (a_inverse * (y - b + n)) % n;
                plaintext += 'a' + x;
            } else if (isupper(c)) {
                int y = c - 'A';
                int x = (a_inverse * (y - b + n)) % n;
                plaintext += 'A' + x;
            }
        } else {
            plaintext += c;
        }
    }
    return plaintext;
}

int main() {
    string plaintext;
    int a, b;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the value of 'a' (should be coprime with 26): ";
    cin >> a;

    if (gcd(a, 26) != 1) {
        cout << "'a' is not coprime with 26. Please choose a different value.\n";
        return 0;
    }

    cout << "Enter the value of 'b': ";
    cin >> b;

    string ciphertext = encrypt(plaintext, a, b);
    cout << "Ciphertext: " << ciphertext << endl;

    string decrypted_text = decrypt(ciphertext, a, b);
    cout << "Decrypted text: " << decrypted_text << endl;

    return 0;
}