#include <iostream>
#include <string>

using namespace std;

bool isVowel(char letter) {
    return letter == 'a' || letter == 'e';
}

string breakIntoSyllables(const string& word) {
    string syllables;

    size_t i = 0;
    while (i < word.length())
    {
        char currentChar = word[i];
        char nextChar = (i < word.length() - 1) ? word[i + 1] : '\0';
        char prevChar = (i >=0) ? word[i -1] : '\0';

        if (isVowel(currentChar)) 
        {
            if (!isVowel(nextChar) && nextChar != '\0' && !isVowel(prevChar) && prevChar != '\0') 
            {
                syllables += prevChar;
                syllables += currentChar;
                syllables += nextChar;
                syllables += '.';
                i=i+1;
            }
        } 
        else if(!isVowel(currentChar))
        {
            if (isVowel(nextChar) && nextChar != '\0') 
            {
                syllables += currentChar;
                syllables += nextChar;
                syllables += '.';
                i=i+1;
            }
        }
        else
        {

        }
        ++i;
    }

    return syllables;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string word;
        cin >> word;

        // Break the word into syllables
        string syllables = breakIntoSyllables(word);

        // Output the result
        cout << syllables << endl;
    }

    return 0;
}
