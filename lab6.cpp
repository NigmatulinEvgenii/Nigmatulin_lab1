#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string textInput;

    const char Alphabet[27] = "abcdefghijklmnopqrstuvwxyz";

    cout << "Enter text to encoder: ";

    getline(cin, textInput);
    int lenght = textInput.length();
    for (int i = 0; i < lenght; i++)
        textInput[i] = tolower(textInput[i]);

    for (int i = 0; i < lenght; i++) {
        int position = 0;
        for (int j = 0; j < 27; j++) {
            if (textInput[i] == Alphabet[j]) {
                position = j + 1;
                break;
            }
        }
        textInput[i] = Alphabet[26 - position];
    }

    cout << "Encoded string: " << textInput << endl;
    return 0;
}