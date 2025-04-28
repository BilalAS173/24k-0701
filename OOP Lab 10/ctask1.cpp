#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string encryptText(const string& text);
string decryptText(const string& encrypted);
void saveToFile(const string& filename, const string& content);
string readFromFile(const string& filename);

int main() {
    string input;
    cout << "Enter String = ";
    getline(cin, input);
    string encrypted = encryptText(input);
    cout << "Normal Text: " << input << endl;
    saveToFile("encrypted.txt", encrypted);
    cout << "Encrypted text inserted in file\n";
    cout << "Encrypted Text: " << encrypted << endl;
    string fileContent = readFromFile("encrypted.txt");
    string decrypted = decryptText(fileContent);
    cout << "Decrypted Text: " << decrypted << endl;
    return 0;
}
string encryptText(const string& text) {
    string result;
    for (int i = 0; i < text.length(); i++) {
        result += text[i] + (i + 1);  
    }
    return result;
}
string decryptText(const string& encrypted) {
    string result;
    for (int i = 0; i < encrypted.length(); i++) {
        result += encrypted[i] - (i + 1);  
    }
    return result;
}
void saveToFile(const string& filename, const string& content) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << content;
        outFile.close();
    } else {
        cerr << "Error opening file for writing!\n";
    }
}

string readFromFile(const string& filename) {
    string content;
    ifstream inFile(filename);
    if (inFile.is_open()) {
        getline(inFile, content);
        inFile.close();
    } else {
        cerr << "Error opening file for reading!\n";
    }
    return content;
}
