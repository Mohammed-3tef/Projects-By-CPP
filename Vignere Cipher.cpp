// Program: In this method, a keyword is repeatedly added character by character to each alphabetic letter in
//          the original message. The addition is carried out using the ASCII codes for each of the characters,
//          modulo 26 (the number of letters in the alphabet), and the result is added to the code for the letter
//          'A' in the ASCII code sequence.
//          Assumptions and Restrictions. The message to be encoded and the keyword will both be read in
//          from the keyboard. Only alphabetic characters will be encoded; all other characters will be
//          outputted unchanged. Check to ensure keyword is only alphabetic characters. All alphabetic
//          characters should be converted to uppercase before the encoding process begins. The input
//          message should be restricted to 80 characters, the keyword to 8 characters (your program needs to
//          check these limits).
// ===================================================================================================== //
#include <iostream>
#include "string"
using namespace std;

void vignere_cipher(string text)               // Cipher a message (Vignere Cipher).
{
    string key, result = "";
    char character;
    cout << "";
    cout << "Enter Your Keyword: ";
    cin >> key;
    long long num = text.size();
    int i = 0;
    string repeated_keyword = "";
    for (int j = 0; j < num; j++)
    {repeated_keyword += key;}
    key = repeated_keyword.substr(0, num);

    while (i < text.length())
    {
        text[i] = toupper(text[i]);
        key[i] = toupper(key[i]);
        if (isalpha(text[i]))
        {
            int sum = int(text[i]) + int(key[i]);
            int rem = sum % 26;
            character = char(rem + 65);
            result += character;
        }
        else
        {result += text[i];}
        i++;
    }
    cout << "The Encrypted Message is: " << result << endl;
}

void vignere_decipher(string result)               // Decipher a message (Vignere Cipher).
{
    string key, text = "";
    int sum = 0;
    char character;
    cout << "";
    cout << "Enter Your Keyword: ";
    cin >> key;
    long long num = result.size();
    int i = 0;
    string repeated_keyword = "";
    for (int j = 0; j < num; j++)
    {repeated_keyword += key;}
    key = repeated_keyword.substr(0, num);

    while (i < result.length())
    {
        result[i] = toupper(result[i]);
        key[i] = toupper(key[i]);
        if (isalpha(result[i]))
        {
            int rem = int(result[i]) - 65;
            for (int h =0 ; h < 243 ;h++)
            {
                if (h % 26 == rem)
                {
                    if (h - key[i] <= 90 && h - key[i] >= 65)
                    {sum = h;}
                }
            }
            character = char(sum - int(key[i]));
            text += character;
        }
        else
        {text += result[i];}
        i++;
    }
    cout << "The Original Message is: " << text << endl;
}

// ================================================>> Main Program <<================================================ //

int main() {
    string choice_menu;
    while (true)
    {
        cout << "# ===== Welcome To Vignere Cipher Program ===== #\n";
        cout << "What do you like to do today?\n";
        cout << " 1) Cipher a message.\n 2) Decipher a message.\n 3) End.\n";
        cout << "Enter Your Choice: ";
        cin >> choice_menu;
        if (choice_menu == "1")
        {
            string text, choice_menu2;
            cout << "Please enter the message to cipher: ";
            cin.ignore(1, '\n');
            getline(cin, text);
            vignere_cipher(text);
            cout << endl;
        }

        else if (choice_menu == "2")
        {
            string result, choice_menu2;
            cout << "Please enter the message to decipher: ";
            cin.ignore(1, '\n');
            getline(cin, result);
            vignere_decipher(result);
            cout << endl;
        }

        else if (choice_menu == "3")
        { break;}

        else
        {cout << "Please enter a valid choice.\n\n";}
    }
    return 0;
}