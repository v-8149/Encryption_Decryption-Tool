#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

#define AC_RED "\x1b[31m"
#define AC_GREEN "\x1b[32m"
#define AC_YELLOW "\x1b[33m"
#define AC_BLUE "\x1b[34m"
#define AC_CYAN "\x1b[36m"
#define AC_NORMAL "\x1b[m"

int main() {
    cout << AC_NORMAL << "\n\n\n---------------------------------------------------------\n|\n";
    cout << "|      " << AC_RED << "Welcome!" << AC_NORMAL << "\n|      \n|      \n|      This is an Encryption-Decryption program\n|      created by the " << AC_BLUE << "S10" << AC_NORMAL << " group, S Div, VIT Pune.\n|      \n|      \n";
    int running = 1;
    while (running == 1) {
        int a;
        cout << AC_NORMAL << "|      Press " << AC_YELLOW << "1" << AC_NORMAL << " for " << AC_YELLOW << "XOR Encryption-Decryption" << AC_NORMAL << " \n";
        cout << "|      Press " << AC_GREEN << "2" << AC_NORMAL << " for " << AC_GREEN << "Caesar Cipher Encryption" << AC_NORMAL << "\n";
        cout << "|      Press " << AC_CYAN << "3" << AC_NORMAL << " for " << AC_CYAN << "Caesar Cipher Decryption" << AC_NORMAL << " \n|      ";
        cin >> a;
        cout << "|      \n";
        char filename[500];
        char password[50];

        switch (a) {
            case 1: {
                cout << "|      " << AC_YELLOW << "Enter file name of file: " << AC_NORMAL;
                cin >> filename;
                ifstream inputFile(filename, ios::binary);
                if (!inputFile) {
                    cout << "|      " << AC_RED << "File '" << filename << "' cannot be opened" << AC_NORMAL << endl;
                    break;
                }
                cout << "|      " << AC_YELLOW << "Enter file name of new file, to be saved: " << AC_NORMAL;
                cin >> filename;
                cout << "|      " << AC_YELLOW << "Enter password: " << AC_NORMAL;
                cin >> password;
                int password_length = strlen(password);
                ofstream outputFile(filename, ios::binary);
                char ch;
                int i = 0;
                while (inputFile.get(ch)) {
                    ch ^= password[i];
                    outputFile.put(ch);
                    i = (i + 1) % password_length;
                }
                inputFile.close();
                outputFile.close();
                cout << "|      " << AC_YELLOW << "Done! Remember your password - " << AC_RED << password << AC_NORMAL << endl;
                break;
            }
            case 2: {
                string str;
                cout << "|      " << AC_GREEN << "Enter a message to encrypt: " << AC_NORMAL;
                cin.ignore();
                getline(cin, str);
                int k;
                cout << "|      " << AC_GREEN << "Enter the key: " << AC_NORMAL;
                cin >> k;
                cout << "|      " << AC_GREEN << "Your encrypted text - " << AC_NORMAL;
                for (char c : str) {
                    if (isalpha(c)) {
                        char base = isupper(c) ? 'A' : 'a';
                        cout << static_cast<char>((c - base + k) % 26 + base);
                    } else {
                        cout << c;
                    }
                }
                cout << endl << "|      " << AC_NORMAL << "Done! Remember your key - " << AC_RED << k << AC_NORMAL << endl;
                break;
            }
            case 3: {
                string str;
                cout << "|      " << AC_CYAN << "Enter a message to decrypt: " << AC_NORMAL;
                cin.ignore();
                getline(cin, str);
                int k;
                cout << "|      " << AC_CYAN << "Enter the key: " << AC_NORMAL;
                cin >> k;
                cout << "|      " << AC_CYAN << "Your decrypted text - " << AC_NORMAL;
                for (char c : str) {
                    if (isalpha(c)) {
                        char base = isupper(c) ? 'A' : 'a';
                        cout << static_cast<char>((c - base - k + 26) % 26 + base);
                    } else {
                        cout << c;
                    }
                }
                cout << endl << "|      " << AC_CYAN << "Done!" << AC_NORMAL << endl;
                break;
            }
            default:
                cout << "|      " << AC_RED << "Enter correct number!" << AC_NORMAL << endl;
        }
        cout << "|      Press " << AC_RED << "1" << AC_NORMAL << " to repeat, " << AC_RED << "0" << AC_NORMAL << " to terminate.....\n|      ";
        cin >> running;
        cout << "|      \n|      \n|      \n";
    }
    cout << "|      Thank you for using our program!\n";
    cout << "|       _________________________________\n";
    cout << "|       " << AC_YELLOW << "Vaishnavi Shivade" << AC_NORMAL << "   |\n";
    cout << "|      |_________________________________|\n";
    cout << "|      \n";
    cout << "---------------------------------------------------------\n\n";
    cin >> running;
    return 0;
}
