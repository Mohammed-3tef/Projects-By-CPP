/*
--> Name: CS112_A2_T4_S27_20230054_20231109_20231143.cpp
--> Purpose: this program is for encryption and decription your important information like your password, ID, etc.

--> Author 1: Mohammed Atef Abd EL-Kader Bayomi.    (ID:20231143)         (Section : S27)
--> Email : mohamed45452020@gmail.com

--> Author 2: Esraa Emary Abd Elsalam.             (ID:20230054)         (Section : S27)
--> Email : esraaemary33@gmail.com

--> Author 3: Aly El-Deen Yasser Aly.            (ID:20231109)         (Section : S27)
--> Email : aibakgaming747@gmail.com

==============================================================================================================================================*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Defining some functions.
// Defining a function for all the menus.
ll menu_check(vector<string> choices, string menu){
    string choice;
    while(true){
        cout << menu;
        getline(cin, choice);
        for(int i = 0 ; i < int(choices.size()) ;i++){
            if (choice == choices[i]){
                cin.ignore(0,'\n');
                return stoll(choice);
            }
        }
        cout << "Please enter a valid choice." << endl << endl;
    }
}

// To see if user wants to continue.
bool continue_or(){
    string choice;
    while (true){
        cout << "Do you want to continue in this cipher?\n [1] Yes.\n [2] No.\nEnter Your Choice :";
        getline(cin, choice);

        if(choice == "1"){
            cout << endl;
            return true;}
        else if (choice == "2"){
            cout << endl;
            return false;}
        else
            cout << "Please enter a valid input." << endl;
    }
}

// To check that key is a number.
ll check_number (string print){
    string key;
    while (true){
        bool check = true;
        cout << print;
        getline(cin, key);
        for (char i : key){
            if(!isdigit(i) || stoll(key) < 0){
                break;
            }
        }

        if (check)
            return stoll(key);
        else
            cout << "Please enter a valid number" << endl;
    }
}

// Check if the input has any character except alphabet for Atbash, and Simple Substitution.
void validity(string &text){
    while (true){
        int count = 0;
        while(text.size() == 0){
            cout << "Invalid Input." << endl;
            cout << "Please enter the message to encrypt that only contains letters of alphabet: ";
            getline(cin, text);
        }

        for (int i = 0; i < int(text.size()); i++){
            if (isalpha(text[i]))
                count++;
            else{
                cout << "Invalid Input." << endl;
                cout << "Please enter the message to encrypt that only contains letters of alphabet: ";
                getline(cin, text);
            }
        }
        if (count == int(text.size())){
            break;
        }
    }
}

// ======================================================= Affine Cipher ======================================================= //

// Main Program of Affine Cipher.
int affine_cipher(){
    int choice;
    ll a, b ,c;
    bool checkk = true;
    while (checkk){
        string menu, text, result = "";
        cout << "\n# ===== Welcome to Affine Cipher ===== #" << endl;
        menu = "What will you do ?\n [1] Encryption Function.\n [2] Decryption Function.\n [3] Exit This Cipher.\nEnter Your Choice : ";
        vector <string> choices = {"1", "2", "3"};
        choice = menu_check(choices, menu);

        // Encryption Process of Affine Cipher.
        if (choice == 1){
            cout << "Enter the Text you want to encrypt : ";
            getline(cin, text);
            a = check_number("Enter the number (a) to encrypt (the form of encryption is (a*(char Ascii value)+ b) % 26) : ");
            b = check_number("enter the number (b) to encrypt (the form of encryption is (a*(char Ascii value)+ b) % 26) : ");
            cout << endl << "Note the form of encryption is (a*(char Ascii value)+b) \nthe form of decryption is (c* (char ascii value - b )) \nwhere (a * c) % 26 must equal 1 for right encryption and decryption" << endl << endl;

            for(char i : text){
                if (isalpha(i))
                    result += char((( a * (toupper(i)-'A') + b ) % 26) + 'A');
                else
                    result += i;
            }
            cout << "The Encryption of your text : " << result << endl;
        }

            // Decryption Process of Affine Cipher.
        else if(choice == 2){
            cout << "Enter the Text you want to decrypt : ";
            getline(cin, text);
            c = check_number("Enter the number (c) to decrypt (the form of encryption is (c*(char Ascii value- b) % 26) : ");
            b = check_number("enter the number (b) to encrypt (the form of encryption is (c*(char Ascii value- b) % 26) : ");
            cout << endl << "Note the form of encryption is (a*(char Ascii value)+b) \nthe form of decryption is (c* (char ascii value - b )) \nwhere (a * c) % 26 must equal 1 for right encryption and decryption" << endl << endl;

            for(char i : text){
                if(isalpha(i)){
                    ll sum = (c * ( (toupper(i) - 'A') - b ) ) % 26;
                    if (sum < 0)
                        sum += 26;
                    result += char(sum + 'A');
                }
                else
                    result += i;
            }
            cout << "The Decryption of your message: " << result << endl;
        }

        else if(choice == 3)
            return 0;

        checkk = continue_or();
    }
    return 0;
}

// ======================================================= Route Cipher ======================================================= //

// Encryption the process of Route Cipher.
void encyption_route(string text){
    string new_text = "", result = "";
    ll key;
    cout << "Enter Your Key: ";
    cin >> key;

    for(char i : text){
        if (isalpha(i))
            new_text += i;
    }
    while (key < 2){
        cout << "Invalid Input.\nEnter Your Key: ";
        cin >> key;
    }
    int num = new_text.size();
    if (num % key == 0){
        char matrix[text.size()], arr[num][key];
        for (int i = 0; i < int(text.size()); i++){
            matrix[i] = new_text[i];
        }

        // 2D Matrix
        int m = 0;
        for (int row = 0; row < num; row++){
            for (int col = 0; col < key; col++){
                matrix[m] = toupper(matrix[m]);
                arr[row][col] = matrix[m];
                m++;
            }
        }

        int i, k = 0, l = 0, n = key;
        m = new_text.size() / key;
        /* k - starting row index
            m - ending row index
            l - starting column index
            n - ending column index
            i - iterator
        */
        string res = "";
        while (k < m && l < n) {
            /* Print the last column
             from the remaining columns */
            for (i = k; i < m; ++i) {
                res += arr[i][n - 1];
            }
            n--;

            /* Print the last row from
                    the remaining rows */
            if (k < m) {
                for (i = n - 1; i >= l; --i) {
                    res += arr[m - 1][i];
                }
                m--;
            }
            /* Print the first column from
                       the remaining columns */
            if (l < n) {
                for (i = m - 1; i >= k; --i) {
                    res += arr[i][l];
                }
                l++;
            }

            /* Print the first row from
                   the remaining rows */
            for (i = l; i < n; ++i) {
                res += arr[k][i];
            }
            k++;
        }
        cout << "\nThe Encrypted Message is: " << res << endl;
    }
    else{
        char matrix[key * ((num/2)+1)], arr[(num/2)+1][key];
        int j = new_text.size();
        while (j < key * ((num/key)+1)){
            new_text.push_back('X');
            j++;
        }
        cout << new_text << endl;
        for (int i = 0; i < key*(num+1); i++){
            matrix[i] = new_text[i];
        }

        //2D Matrix
        int m = 0;
        for (int row = 0; row < num+1; row++){
            for (int col = 0; col < key; col++){
                matrix[m] = toupper(matrix[m]);
                arr[row][col] = matrix[m];
                m++;
            }
        }

        int i, k = 0, l = 0, n = key;
        m = new_text.size() / key;
        /* k --> starting row index.
            m --> ending row index.
            l --> starting column index.
            n --> ending column index.
            i --> iterator.
        */
        string res = "";
        while (k < m && l < n) {

            /* Print the last column
             from the remaining columns */
            for (i = k; i < m; ++i) {
                res += arr[i][n - 1];
            }
            n--;

            /* Print the last row from
                    the remaining rows */
            if (k < m) {
                for (i = n - 1; i >= l; --i) {
                    res += arr[m - 1][i];
                }
                m--;
            }

            /* Print the first column from
                       the remaining columns */
            if (l < n) {
                for (i = m - 1; i >= k; --i) {
                    res += arr[i][l];
                }
                l++;
            }

            /* Print the first row from
                   the remaining rows */
            for (i = l; i < n; ++i) {
                res += arr[k][i];
            }
            k++;
        }
        cout << "\nThe Encrypted Message is: " << res.substr(0, key*((num/key)+1)) << endl;
    }
}

// Decryption the process of Route Cipher.
void decyption_route(string text){
    string new_text = "", result = "";
    ll key;
    cout << "Enter Your Key: ";
    cin >> key;

    for(char i : text){
        if (isalpha(i))
            new_text += i;
    }
    while (key < 2 || key > new_text.size()/2){
        cout << "Invalid Input.\nEnter Your Key: ";
        cin >> key;
    }
}

// Main Program of Route Cipher.
int route_cipher()
{
    ll Choice;
    cout << "\n# ===== Welcome to Route Cipher ===== #" << endl;
    bool checkk = true;
    while (checkk)
    {
        // Showing a list for user to choose encryption or decryption.
        string menu1 = "What do you tend to do?\n [1] Cipher Message.\n [2] Decipher Message.\n [3] Exit This Cipher.\nEnter Your Choice: ";
        vector <string> choices = {"1", "2", "3"};
        Choice = menu_check(choices, menu1);


        if (Choice == 1){                         // If he chooses encryption.
            string message, result = "";
            cin.ignore(0,'\n');

            // To get the text and key from the user.
            while (true){
                cout << "Enter Your Text you want to encrypt (80 char is max limit): ";
                getline(cin, message);

                // To check the length of text limit.
                if (message.size() <= 80){
                    encyption_route(message);
                    cout << endl;
                    break;}

                    // If it is more than 80 char.
                else
                    cout << "The input message should be restricted to 80 characters.\n";
            }
        }


        else if (Choice == 2){                                // If a user chooses to decrypt.
            string result, text = "";
            cin.ignore(0, '\n');

            while(true){
                // Getting an Encrypted message from user.
                cout << "Enter Your Encrypted Message to decrypt it (80 char is max limit): ";
                getline(cin, result);

                // To check that text size is less than 80 chars and decrypt it.
                if (result.size() <= 80){
                    decyption_route(result);
                    cout << endl;
                    break;
                }

                    // If it is more than 80 chars.
                else
                    cout << "The input message should be restricted to 80 characters.\n";
            }
        }

            // Exit of this cipher.
        else if (Choice == 3)
            return 0;

        // To see if a user wants to encrypt with the same type of cipher or no.
        checkk = continue_or();
    }
    return 0;
}

// ======================================================= Atbash Cipher ======================================================= //

// Encryption the process of Atbash Cipher.
string encrypt_atbash(string &text, int choice){
    string result = "";
    validity(text);
    for (int i = 0; i < int(text.size()); i++){

        // Encrypt a message on tne whole letters of alphabet
        if(choice == 1){
            // Check if the letter is uppercase to encrypt
            if(isupper(text[i])){
                result += static_cast<char>(25+130-static_cast<int>(text[i]));
            }

                // Check if the letter is lowercase to encrypt
            else if(islower(text[i])){
                result += static_cast<char>(25+194-static_cast<int>(text[i]));
            }
        }

            // Encrypt a message on half-letters of the alphabet
        else if(choice == 2){
            // Check if the letter is uppercase to encrypt
            int digit = static_cast<int>(text[i]);
            if(isupper(text[i])){
                if(digit <= 77){
                    result += static_cast<char>(12+130-static_cast<int>(text[i]));
                }
                else if(digit > 77){
                    result += static_cast<char>(12+156-static_cast<int>(text[i]));
                }
            }

                // Check if the letter is lowercase to encrypt
            else if(islower(text[i])){
                if(digit <= 109){
                    result += static_cast<char>(12+194-static_cast<int>(text[i]));
                }
                else if(digit > 109){
                    result += static_cast<char>(12+220-static_cast<int>(text[i]));
                }
            }
        }
    }
    return result;
}

// Decryption the process of Atbash Cipher.
string decrypt_atbash(string &text, int choice){
    string result = "";
    validity(text);
    for (int i = 0; i < int(text.size()); i++){
        // Decrypt a message on tne whole letters of alphabet
        if(choice == 1){
            // Check if the letter is uppercase to decrypt
            if(isupper(text[i])){
                result += static_cast<char>(25+130-static_cast<int>(text[i]));
            }

                // Check if the letter is lowercase to decrypt
            else if(islower(text[i])){
                result += static_cast<char>(25+194-static_cast<int>(text[i]));
            }
        }

            // Decrypt a message on half-letters of the alphabet
        else if(choice == 2){
            // Check if the letter is uppercase to decrypt
            int digit = static_cast<int>(text[i]);
            if(isupper(text[i])){
                if(digit <= 77){
                    result += static_cast<char>(12+130-static_cast<int>(text[i]));
                }
                else if(digit > 77){
                    result += static_cast<char>(12+156-static_cast<int>(text[i]));
                }
            }

                // Check if the letter is lowercase to decrypt
            else if(islower(text[i])){
                if(digit <= 109){
                    result += static_cast<char>(12+194-static_cast<int>(text[i]));
                }
                else if(digit > 109){
                    result += static_cast<char>(12+220-static_cast<int>(text[i]));
                }
            }
        }
    }
    return result;
}

// Main Program of Atbash Cipher.
int atbash_cipher(){
    cout << "\n# ===== Welcome to Atbash Cipher ===== #" << endl;
    bool checkk = true;
    while(checkk){
        // Print the menu and check the validity of choice
        string menu2 ="What do you want to do?\n [1]Encrypt a message.\n [2]Decrypt a message.\n [3]Exit This Cipher.\nEnter Your Choice: ";
        ll choice;
        vector <string> choices = {"1", "2", "3"};
        choice = menu_check(choices, menu2);

        // Print the menu and check the validity of choice and encrypt a message
        if(choice == 1){
            string menu = "What do you want to do?\n [1]Encrypt a message on the whole alphabet.\n [2]Encrypt a message on half alphabet.\n [3]Back.\nEnter Your Choice: ";
            int choice3;
            vector <string> choices = {"1", "2", "3"};
            choice3 = menu_check(choices, menu);

            string text;
            if(choice3 == 1 || choice3 == 2){
                cout << "Please enter the message you want to encrypt: ";
                getline(cin, text);
                cout << "The encrypted message is: " << encrypt_atbash(text, choice3) << endl;
            }
        }
            // Print the menu and check the validity of choice and decrypt a message
        else if(choice == 2){
            string menu4 = "What do you want to do?\n [1]Decrypt a message on the whole alphabet.\n [2]Decrypt a message on half alphabet.\n [3]Back.\nEnter Your Choice:";
            ll choice2;
            vector <string> choices = {"1", "2", "3"};
            choice2 = menu_check(choices, menu4);

            string text;
            if(choice2 == 1 || choice2 == 2){
                cout << "Please enter the message you want to decrypt: ";
                getline(cin, text);
                cout << "The decrypted message is: " << decrypt_atbash(text, choice2) << endl;
            }

        }
            // Exit the cipher
        else if(choice == 3){
            break;
        }

        // To see if user wants to encrype with the same type of cipher or no
        checkk = continue_or();
    }
    return 0;
}

// ======================================================= Vignere Cipher ======================================================= //

// Encryption the process of Vignere Cipher.
void vignere_cipher(string text){
    string key, result = "";
    char character;
    cout << "";

    // To keep code running
    while (true){

        // To get the key from user to encrypt it with
        cout << "Enter Your Keyword to encrypt message by it (8 chars Maximum): ";
        getline(cin, key);
        ll count = 0;
        for (int i = 0; i < int(key.size()) ;i++){
            if(isalpha(key[i])){
                count++;
            }
        }
        // If key is valid
        if (key.size() <= 8 && count == key.size()){
            long long num = text.size();
            int i = 0;
            string repeated_keyword = "";

            // To repeat the key to encrypt the whole text
            for (int j = 0; j < num; j++){
                repeated_keyword += key;
                key = repeated_keyword.substr(0, num);
            }

            // Encryption process
            while (i < int(text.length())){
                text[i] = toupper(text[i]);
                key[i] = toupper(key[i]);

                // To check that char is alphabetic not any other chars
                if (isalpha(text[i])){
                    int sum = int(text[i]) + int(key[i]);
                    int rem = sum % 26;
                    character = char(rem + 65);
                    result += character;
                }

                    // If char is not alphabetic
                else
                    result += text[i];
                i++;
            }
            cout << "\nThe Encrypted Message is: " << result << endl;
            break;
        }

            // If key is more than 8 characters
        else
            cout << "The input message should be restricted to 8 characters.\n";
    }
}

// Decryption the process of Vignere Cipher.
void vignere_decipher(string result){
    string key, text = "";
    int sum = 0;
    char character;

    // To keep code running
    while (true){
        // To get key from user to decrypt the message
        cout << "Enter Your Keyword to decrypt the text (80 char Maximum): ";
        getline(cin, key);
        ll count = 0;
        for (int i = 0; i < int(key.size()) ;i++){
            if(isalpha(key[i]))
                count++;
        }

        // To check that size of key is less than 8
        if (key.size() <= 8 && count == key.size()){
            long long num = result.size();
            int i = 0;
            string repeated_keyword = "";

            // To repeat the key to encrypt the whole text
            for (int j = 0; j < num; j++)
                repeated_keyword += key;
            key = repeated_keyword.substr(0, num);

            // Decryption process
            while (i < int(result.length())){
                result[i] = toupper(result[i]);
                key[i] = toupper(key[i]);

                // If the char is alphabetic
                if (isalpha(result[i])){
                    int rem = int(result[i]) - 65;
                    for (int h =0 ; h < 243 ;h++){
                        if (h % 26 == rem){
                            if (h - key[i] <= 90 && h - key[i] >= 65)
                                sum = h;
                        }
                    }
                    character = char(sum - int(key[i]));
                    text += character;
                }

                    // If it is not alphabetic
                else
                    text += result[i];
                i++;
            }
            cout << "\nThe Original Message is: " << text << endl;
            break;
        }

            // If key size is more than 8 chars
        else
            cout << "The input message should be restricted to 8 characters.\n";
    }
}

// Main Program of Vignere Cipher.
int vignere_cipher()
{
    bool checkk = true;
    ll Choice;
    cout << "\n# ===== Welcome to Vignere Cipher ===== #" << endl;
    while (checkk)
    {
        // Showing a list for user to choose encryption or decryption
        string menu8 = "What do you tend to do?\n [1] Cipher Message.\n [2] Decipher Message.\n [3] Exit This Cipher.\nEnter Your Choice: ";
        vector <string> choices = {"1", "2", "3"};
        Choice = menu_check(choices, menu8);


        if (Choice == 1){                         // If he chooses encryption
            string message, result = "";
            cin.ignore(0,'\n');

            // To get the text and key from user
            while (true){
                cout << "Enter Your Text you want to encrypt (80 char is max limit): ";
                getline(cin, message);

                // To check the length of text limit
                if (message.size() <= 80){
                    vignere_cipher(message);
                    cout << endl;
                    break;}

                    // If it is more than 80 char
                else
                    cout << "The input message should be restricted to 80 characters.\n";
            }
        }


        else if (Choice == 2){                                // If a user chooses to decrypt
            string result, text = "";
            cin.ignore(0, '\n');

            while(true){
                // Getting an Encrypted message from user
                cout << "Enter Your Encrypted Message to decrypt it (80 char is max limit): ";
                getline(cin, result);

                // To check that text size is less than 80 chars and decrypt it
                if (result.size() <= 80){
                    vignere_decipher(result);
                    cout << endl;
                    break;
                }

                    // If it is more than 80 chars
                else
                    cout << "The input message should be restricted to 80 characters.\n";
            }
        }

            // Exit of this cipher
        else if (Choice == 3)
            return 0;

        // To see if a user wants to encrypt with the same type of cipher or no
        checkk = continue_or();
    }
    return 0;
}

// ======================================================= Baconian Cipher ======================================================= //

// Encryption the process of Baconian Cipher.
string encryption_baconian(string text)
{
    deque<string>elements;
    string old_result = "";
    string result ="";

    // Make a deque that contain binary conversion to elements from A to Z
    for (int i = static_cast<int>('A'); i <= static_cast<int>('Z'); i++)
    {
        int digit = 0;
        string digit2 = "";
        digit = i - 65;
        bitset<5>binary(digit);
        digit2 = binary.to_string();
        elements.push_back(digit2);
    }

    // Convert all characters into uppercase and add the opposite index to each character in elements deque from A to Z to old_result
    for (int i = 0; i < int(text.size()); i++)
    {
        int digit = 0;
        char index;
        index = toupper(text[i]);
        digit = static_cast<int>(index) - 65 ;
        old_result += elements[digit];
    }

    // Convert every '1' to b and every '0' to a then add it to result
    for (int i = 0; i < int(old_result.size()); i++)
    {
        if (old_result[i] == '1')
            result += 'b';
        else if (old_result[i] == '0')
            result += 'a';
    }
    return result;
}

// Decryption the process of Baconian Cipher.
string decryption_baconian(string text)
{
    string result ="";
    string text2 = "";

    // Convert every (A or a) into 0 and every (B or b) into 1 and add this to text2
    for (int i = 0; i < int(text.size()); i++)
    {
        if (text[i] == 'A' ||text[i] == 'a' )
            text2 += '0';
        else if (text[i] == 'B' ||text[i] == 'b')
            text2 += '1';
    }

    // Check about the existence of these unknown strings and ignore it
    deque<int>numbers;
    for (int i = 0; i < int(text2.size()); i++)
    {
        if ((text2[i]=='1' && text2[i+1]=='1' &&text2[i+2]=='1' && text2[i+3]=='1' && text2[i+4]=='1') ||
            (text2[i]=='1' && text2[i+1]=='1' &&text2[i+2]=='1' && text2[i+3]=='1' && text2[i+4]=='0') ||
            (text2[i]=='1' && text2[i+1]=='1' &&text2[i+2]=='1' && text2[i+3]=='0' && text2[i+4]=='1') ||
            (text2[i]=='1' && text2[i+1]=='1' &&text2[i+2]=='1' && text2[i+3]=='0' && text2[i+4]=='0') ||
            (text2[i]=='1' && text2[i+1]=='1' &&text2[i+2]=='0' && text2[i+3]=='1' && text2[i+4]=='0') ||
            (text2[i]=='1' && text2[i+1]=='1' &&text2[i+2]=='0' && text2[i+3]=='1' && text2[i+4]=='1'))
        {
            continue;
        }

            // Take every 5 characters in an index of a deque to evaluate it
        else if (((text2[i] =='1'||text2[i]=='0') && (text2[i+1]=='1'||text2[i+1]=='0') && (text2[i+2]=='1'||text2[i+2]=='0') && (text2[i+3]=='1'||text2[i+3]=='0') && (text2[i+4]=='1'||text2[i+4]=='0')))
        {
            int digit = 0;
            bitset<5>decimal(text2.substr(i, 5));
            digit = decimal.to_ulong();
            numbers.push_back(digit);
            i += 4;
        }
        else
            continue;
    }

    // Check if every index in the deque has a value and add it to the result
    for (int j = 0; j < int(numbers.size()); j++)
    {
        for (int i = static_cast<int>('A'); i <= static_cast<int>('Z'); i++)
        {
            if (numbers[j]==(i-65))
            {
                result += static_cast<char>(i);
            }
        }
    }
    return result;
}

// Check if the input has any character except A, B, a or b.
string validity1(string &text)
{
    while (true)
    {
        int count = 0;
        for (int i = 0; i < int(text.size()); i++)
        {
            if (text[i]!='A' && text[i]!='B' && text[i]!='a' && text[i]!='b' && !isspace(text[i]))
            {
                cout << "Invalid input." << endl;
                cout << "Please enter the message to decrypt that only contain A, B, a or b.: " ;
                cin >> text;
                break;
            }
            else
                count++;
        }
        if (count == int(text.size()))
        {
            break;
        }
    }
    return text;
}

// Main Program of Baconoian Cipher.
int baconoian_cipher()
{
    // To see if user wants to encrypt or decrypt
    cout << "\n# ===== Welcome to Baconian Cipher ===== #" << endl;
    bool checkk = true;
    while(checkk)
    {
        string menu3 = "What do you want to do?\n [1] Encryption of Sentence. \n [2] Decryption of Sentence. \n [3] Exit.\nEnter Your choice: ";
        ll main4;
        vector <string> choices = {"1", "2", "3"};
        main4 = menu_check(choices, menu3);

        // Check if the user wants to enter a message to encrypt
        if (main4 == 1)
        {
            string text;
            cout << "Please enter the message to encrypt that only contains letters of alphabet: ";
            getline(cin, text);

            // Check if the input has any character except alphabet
            while (true)
            {
                bool flag = false;
                for (int i = 0; i < int(text.size()); i++)
                {
                    if(!isalpha(text[i]) && !isspace(text[i])){
                        flag = true;
                        break;
                    }
                }
                if(flag == true)
                {
                    cout << "Invalid Input." << endl;
                    cout << "Please enter the message to encrypt that only contains letters of alphabet: ";
                    getline(cin, text);
                }
                else{
                    break;
                }
            }

            // Print the encrypted message
            cout << "The Encrypted Message is: " << encryption_baconian(text) << endl;
        }

            // Check if the user wants to enter a message to decrypt
        else if (main4 == 2)
        {
            string text;
            cout << "Please enter the message to decrypt that only contains A, B, a or b.: ";
            getline(cin, text);
            validity1(text);

            // Print the decrypted message
            cout << "The Decrypted Message is: " << decryption_baconian(text) << endl;
        }

            // Back to the main menu
        else if (main4 == 3)
            break;

        // To see if user wants to encrype with the same type of cipher or no
        string menu10 = "Do you want to continue with same cipher?\n [1] Yes. \n [2] No. \nEnter Your Choice : ";
        vector <string> choices10 = {"1", "2"};
        ll num  = menu_check(choices10, menu10);
        if (num == 2)
            checkk = false;
    }
    return 0;
}

// ======================================================= Simple Substitution Cipher ======================================================= //

// Check if the input has any character except alphabet, and it is 5 digits.
void validity2(string &text){
    while (true){
        int count = 0;
        while(text.size() != 5){
            cout << "Invalid Input." << endl;
            cout << "Please enter the keyword that only contains 5 letters of alphabet: ";
            getline(cin, text);
        }

        for (int i = 0; i < int(text.size()); i++){
            if (isalpha(text[i]))
                count++;
            else{
                cout << "Invalid Input."<<endl;
                cout << "Please enter the keyword that only contains 5 letters of alphabet: ";
                getline(cin, text);
            }
        }
        if (count == int(text.size())){
            break;
        }
    }
}

// Encryption the process of Simple Substitution Cipher.
string encrypt_simple_substitution(string &text, string keyword){
    string result = "";
    string text2 = "";
    string keyword2 = "";
    deque<char>alphabet;
    deque<char>key;
    deque<char>new_alphabet;
    // Convert the message and keyword into uppercase
    for (int i = 0; i < int(text.size()); i++){
        text2 += toupper(text[i]);
    }
    for (int i = 0; i < int(keyword.size()); i++){
        keyword2 += toupper(keyword[i]);
    }
    // Make a list for alphabetic letters and add keyword and rest of alphabetic letters to it
    for (int i = static_cast<int>('A'); i <= static_cast<int>('Z'); i++){
        alphabet.push_back(static_cast<char>(i));
    }
    for (int i = 0; i < int(keyword2.size()); i++){
        key.push_back(keyword2[i]);
        new_alphabet.push_back(keyword2[i]);
    }
    for (int i = 0; i < int(alphabet.size()); i++) {
        if (find(key.begin(), key.end(), alphabet[i]) == key.end())
            new_alphabet.push_back(alphabet[i]);
    }
    for (int i = 0; i < int(text2.size()); i++) {
        if (isalpha(text2[i]))
            result += new_alphabet[static_cast<int>(text2[i]) - 65];
    }
    return result;
}

// Decryption the process of Simple Substitution Cipher.
string decrypt_simple_substitution(string &text, string keyword){
    string result = "";
    string text2 = "";
    string keyword2 = "";
    deque<char>alphabet;
    deque<char>key;
    deque<char>new_alphabet;
    // Convert the message and keyword into uppercase
    for (int i = 0; i < int(text.size()); i++){
        text2 += toupper(text[i]);
    }
    for (int i = 0; i < int(keyword.size()); i++){
        keyword2 += toupper(keyword[i]);
    }
    // Make a list for alphabetic letters and add keyword and rest of alphabetic letters to it
    for (int i = static_cast<int>('A'); i <= static_cast<int>('Z'); i++){
        alphabet.push_back(static_cast<char>(i));
    }
    for (int i = 0; i < int(keyword2.size()); i++){
        key.push_back(keyword2[i]);
        new_alphabet.push_back(keyword2[i]);
    }
    for (int i = 0; i < int(alphabet.size()); i++) {
        if (find(key.begin(), key.end(), alphabet[i]) == key.end())
            new_alphabet.push_back(alphabet[i]);
    }
    for (int i = 0; i < int(text2.size()); i++){
        for (int j = 0; j < int(new_alphabet.size()); j++){
            if(text2[i] == new_alphabet[j])
                result += alphabet[j];
        }
    }
    return result;
}

// Main Program of Simple Substitution Cipher.
int simple_substitution_cipher(){
    cout << "\n# ===== Welcome to Simple Substitution Cipher ===== #" << endl;
    bool checkk = true;
    while(checkk){
        // Print the menu and check the validity of choice
        string menu4 = "What do you want to do?\n [1] Encrypt a message.\n [2] Decrypt a message.\n [3] Exit This Cipher.\nEnter Your Choice: ";
        ll choice;
        vector <string> choices = {"1", "2", "3"};
        choice = menu_check(choices, menu4);

        // Get the message and encrypt messages
        if(choice == 1){
            string text, keyword;
            cout << "Please enter the message you want to encrypt: ";
            getline(cin, text);
            validity(text);
            cout << "Please enter the keyword: ";
            getline(cin, keyword);
            validity2(keyword);
            cout << "The Encrypted Message is: " << encrypt_simple_substitution(text, keyword) << endl;
        }

            // Get the message and decrypt messages
        else if(choice == 2){
            string text, keyword;
            cout << "Please enter the message you want to decrypt: ";
            getline(cin, text);
            validity(text);
            cout << "Please enter the keyword: ";
            getline(cin, keyword);
            validity2(keyword);
            cout << "The Decrypted Message is: " << decrypt_simple_substitution(text, keyword) << endl;
        }
            // Exit the cipher
        else if(choice == 3){
            break;
        }

        // To see if user wants to encrype with the same type of cipher or no
        checkk = continue_or();
    }
    return 0;
}

// ======================================================= Polybius Square Cipher ======================================================= //

// Encryption the process of Polybius Square Cipher.
void polybius_square_cipher(string text)
{
    int arr[5];
    for (int j = 0; j<5 ;j++)
    {
        cout << "Enter Your Keyword: ";
        cin >> arr[j];
    }
    string result = "";
    cout << "\nThe Encrypted Message is: ";
    for (char i : text)
    {
        i = toupper(i);
        if(isalpha(i))
        {
            if (i == 'A')
            {cout << arr[0] << arr[0];}
            else if (i == 'B')
            {cout << arr[0] << arr[1];}
            else if (i == 'C')
            {cout << arr[0] << arr[2];}
            else if (i == 'D')
            {cout << arr[0] << arr[3];}
            else if (i == 'E')
            {cout << arr[0] << arr[4];}
            else if (i == 'F')
            {cout << arr[1] << arr[0];}
            else if (i == 'G')
            {cout << arr[1] << arr[1];}
            else if (i == 'H')
            {cout << arr[1] << arr[2];}
            else if (i == 'I')
            {cout << arr[1] << arr[3];}
            else if (i == 'J')
            {cout << arr[1] << arr[3];}
            else if (i == 'K')
            {cout << arr[1] << arr[4];}
            else if (i == 'L')
            {cout << arr[2] << arr[0];}
            else if (i == 'M')
            {cout << arr[2] << arr[1];}
            else if (i == 'N')
            {cout << arr[2] << arr[2];}
            else if (i == 'O')
            {cout << arr[2] << arr[3];}
            else if (i == 'P')
            {cout << arr[2] << arr[4];}
            else if (i == 'Q')
            {cout << arr[3] << arr[0];}
            else if (i == 'R')
            {cout << arr[3] << arr[1];}
            else if (i == 'S')
            {cout << arr[3] << arr[2];}
            else if (i == 'T')
            {cout << arr[3] << arr[3];}
            else if (i == 'U')
            {cout << arr[3] << arr[4];}
            else if (i == 'V')
            {cout << arr[4] << arr[0];}
            else if (i == 'W')
            {cout << arr[4] << arr[1];}
            else if (i == 'X')
            {cout << arr[4] << arr[2];}
            else if (i == 'Y')
            {cout << arr[4] << arr[3];}
            else if (i == 'Z')
            {cout << arr[4] << arr[4];}
        }
        else if (isspace(i))
        {cout << " ";}
    }
    cout << result;
}

// Decryption the process of Polybius Square Cipher.
void polybius_square_decipher(string text)
{
    int arr[5];
    for (int j = 0; j<5 ;j++)
    {
        cout << "Enter Your Keyword: ";
        cin >> arr[j];
    }
    string result = "";

    for(int i = 0 ; i < int(text.size()) ;){
        if (isdigit(text[i]) && isdigit(text[i+1])){
            if(text.substr(i,2) == to_string(arr[0]) + to_string(arr[0])) {result += 'A';}
            else if(text.substr(i,2) == to_string(arr[0]) + to_string(arr[1])) {result += 'B';}
            else if(text.substr(i,2) == to_string(arr[0]) + to_string(arr[2])) {result += 'C';}
            else if(text.substr(i,2) == to_string(arr[0]) + to_string(arr[3])) {result += 'D';}
            else if(text.substr(i,2) == to_string(arr[0]) + to_string(arr[4])) {result += 'E';}
            else if(text.substr(i,2) == to_string(arr[1]) + to_string(arr[0])) {result += 'F';}
            else if(text.substr(i,2) == to_string(arr[1]) + to_string(arr[1])) {result += 'G';}
            else if(text.substr(i,2) == to_string(arr[1]) + to_string(arr[2])) {result += 'H';}
            else if(text.substr(i,2) == to_string(arr[1]) + to_string(arr[3])) {result += 'I';}
            else if(text.substr(i,2) == to_string(arr[1]) + to_string(arr[4])) {result += 'K';}
            else if(text.substr(i,2) == to_string(arr[2]) + to_string(arr[0])) {result += 'L';}
            else if(text.substr(i,2) == to_string(arr[2]) + to_string(arr[1])) {result += 'M';}
            else if(text.substr(i,2) == to_string(arr[2]) + to_string(arr[2])) {result += 'N';}
            else if(text.substr(i,2) == to_string(arr[2]) + to_string(arr[3])) {result += 'O';}
            else if(text.substr(i,2) == to_string(arr[2]) + to_string(arr[4])) {result += 'P';}
            else if(text.substr(i,2) == to_string(arr[3]) + to_string(arr[0])) {result += 'Q';}
            else if(text.substr(i,2) == to_string(arr[3]) + to_string(arr[1])) {result += 'R';}
            else if(text.substr(i,2) == to_string(arr[3]) + to_string(arr[2])) {result += 'S';}
            else if(text.substr(i,2) == to_string(arr[3]) + to_string(arr[3])) {result += 'T';}
            else if(text.substr(i,2) == to_string(arr[3]) + to_string(arr[4])) {result += 'U';}
            else if(text.substr(i,2) == to_string(arr[4]) + to_string(arr[0])) {result += 'V';}
            else if(text.substr(i,2) == to_string(arr[4]) + to_string(arr[1])) {result += 'W';}
            else if(text.substr(i,2) == to_string(arr[4]) + to_string(arr[2])) {result += 'X';}
            else if(text.substr(i,2) == to_string(arr[4]) + to_string(arr[3])) {result += 'Y';}
            else if(text.substr(i,2) == to_string(arr[4]) + to_string(arr[4])) {result += 'Z';}
            i += 2;
        }
        else if (isspace(text[i])){
            result += " ";
            i++;
        }
    }
    cout << "\nThe Original Message is: " << result << endl;
}

// Main Program of Polybius Square Cipher.
int Polybius_Square_cipher()
{
    ll Choice;
    cout << "\n# ===== Welcome to Polybius Square Cipher ===== #" << endl;
    bool checkk = true;
    while (checkk)
    {
        // Showing a list for user to choose encryption or decryption
        string menu5 ="What do you tend to do?\n [1] Cipher Message.\n [2] Decipher Message.\n [3] Exit This Cipher.\nEnter Your Choice: ";
        vector <string> choices = {"1", "2", "3"};
        Choice = menu_check(choices, menu5);

        if (Choice == 1){                                   // If he chooses encryption
            string message, result = "";
            cin.ignore(0,'\n');

            // To get the text and key from user
            while (true){
                cout << "Enter Your Text you want to encrypt (80 char is max limit): ";
                getline(cin, message);

                // To check the length of text limit
                if (message.size() <= 80){
                    cout << endl;
                    polybius_square_cipher(message);
                    cout << endl << endl;
                    break;}

                    // If it is more than 80 char
                else
                    cout << "The input message should be restricted to 80 characters.\n";
            }
        }

        else if (Choice == 2){                                // If the user chooses to decrypt
            string result, text = "";
            cin.ignore(0, '\n');

            while(true){
                // Getting an Encrypted message from user
                cout << "Enter Your Encrypted Message to decrypt it (80 char is max limit): ";
                getline(cin, result);

                // To check that the input contains digits and spaces or not
                while (true){
                    ll count = 0;
                    for (int i = 0; i<result.size() ;i++){
                        if (isdigit(result[i]) || isspace(result[i])){
                            count++;}
                    }
                    if (count == result.size())
                        break;
                    else{
                        cout << "The input should be only digits and spaces." << endl;
                        cout << "Enter Your Encrypted Message to decrypt it (80 char is max limit): ";
                        getline(cin, result);
                    }
                }

                // To check that text size is less than 80 chars and decrypt it
                if (result.size() <= 80){
                    polybius_square_decipher(result);
                    cout << endl;
                    break;
                }

                    // If it is more than 80 chars
                else
                    cout << "The input message should be restricted to 80 characters.\n";
            }
        }

            // Exit of this cipher
        else if (Choice == 3)
            return 0;

        checkk = continue_or();
    }
    return 0;
}

// ======================================================= Morse Cipher ======================================================= //

// Encryption the process of Morse Cipher.
void encryption_morse(string text)
{
    string result = "";
    for (char i : text)
    {
        i = toupper(i);
        if(isalpha(i))                              // Check if the character is alpha
        {
            if (i == 'A'){result += ".- ";}
            else if (i == 'B'){result += "-... ";}
            else if (i == 'C'){result += "-.-. ";}
            else if (i == 'D'){result += "-.. ";}
            else if (i == 'E'){result += ". ";}
            else if (i == 'F'){result += "..-.";}
            else if (i == 'G'){result += "--. ";}
            else if (i == 'H'){result += ".... ";}
            else if (i == 'I'){result += ".. ";}
            else if (i == 'J'){result += ".--- ";}
            else if (i == 'K'){result += "-.- ";}
            else if (i == 'L'){result += ".-.. ";}
            else if (i == 'M'){result += "-- ";}
            else if (i == 'N'){result += "-. ";}
            else if (i == 'O'){result += "--- ";}
            else if (i == 'P'){result += ".--. ";}
            else if (i == 'Q'){result += "--.- ";}
            else if (i == 'R'){result += ".-. ";}
            else if (i == 'S'){result += "... ";}
            else if (i == 'T'){result += "- ";}
            else if (i == 'U'){result += "..- ";}
            else if (i == 'V'){result += "...- ";}
            else if (i == 'W'){result += ".-- ";}
            else if (i == 'X'){result += "-..- ";}
            else if (i == 'Y'){result += "-.-- ";}
            else if (i == 'Z'){result += "--.. ";}
        }
        else if (isdigit(i)){                       // Check if the character is a digit
            if (i == '1') {result += ".---- ";}
            else if (i == '2') {result += "..--- ";}
            else if (i == '3') {result += "...-- ";}
            else if (i == '4') {result += "----. ";}
            else if (i == '5') {result += "..... ";}
            else if (i == '6') {result += "-.... ";}
            else if (i == '7') {result += "--... ";}
            else if (i == '8') {result += "---.. ";}
            else if (i == '9') {result += "----. ";}
            else if (i == '0') {result += "----- ";}
        }
        else if (isspace(i)){result += "  ";}       // Check if the character is space
    }
    cout << "The Original Message is: " << result << endl;
}

// Decryption the process of Morse Cipher.
void morse_decipher(string text)
{
    string result = "";
    deque<string>morse;
    deque<char>morse2;
    for (int i = '0'; i <= 'Z'; i++)
    {
        if (i == 'A'){morse.push_back(".-");            morse2.push_back('A');}
        else if (i == 'B') {morse.push_back("-...");    morse2.push_back('B');}
        else if (i == 'C') {morse.push_back("-.-.");    morse2.push_back('C');}
        else if (i == 'D') {morse.push_back("-..");     morse2.push_back('D');}
        else if (i == 'E') {morse.push_back(".");       morse2.push_back('E');}
        else if (i == 'F') {morse.push_back("..-.");    morse2.push_back('F');}
        else if (i == 'G') {morse.push_back("--.");     morse2.push_back('G');}
        else if (i == 'H') {morse.push_back("....");    morse2.push_back('H');}
        else if (i == 'I') {morse.push_back("..");      morse2.push_back('I');}
        else if (i == 'J') {morse.push_back(".---");    morse2.push_back('J');}
        else if (i == 'K') {morse.push_back("-.-");     morse2.push_back('K');}
        else if (i == 'L') {morse.push_back(".-..");    morse2.push_back('L');}
        else if (i == 'M') {morse.push_back("--");      morse2.push_back('M');}
        else if (i == 'N') {morse.push_back("-.");      morse2.push_back('N');}
        else if (i == 'O') {morse.push_back("---");     morse2.push_back('O');}
        else if (i == 'P') {morse.push_back(".--.");    morse2.push_back('P');}
        else if (i == 'Q') {morse.push_back("--.-");    morse2.push_back('Q');}
        else if (i == 'R') {morse.push_back(".-.");     morse2.push_back('R');}
        else if (i == 'S') {morse.push_back("...");     morse2.push_back('S');}
        else if (i == 'T') {morse.push_back("-");       morse2.push_back('T');}
        else if (i == 'U') {morse.push_back("..-");     morse2.push_back('U');}
        else if (i == 'V') {morse.push_back("...-");    morse2.push_back('V');}
        else if (i == 'W') {morse.push_back(".--");     morse2.push_back('W');}
        else if (i == 'X') {morse.push_back("-..-");    morse2.push_back('X');}
        else if (i == 'Y') {morse.push_back("-.--");    morse2.push_back('Y');}
        else if (i == 'Z') {morse.push_back("--..");    morse2.push_back('Z');}
        else if (i == '1') {morse.push_back(".----");   morse2.push_back('1');}
        else if (i == '2') {morse.push_back("..---");   morse2.push_back('2');}
        else if (i == '3') {morse.push_back("...--");   morse2.push_back('3');}
        else if (i == '4') {morse.push_back("----.");   morse2.push_back('4');}
        else if (i == '5') {morse.push_back(".....");   morse2.push_back('5');}
        else if (i == '6') {morse.push_back("-....");   morse2.push_back('6');}
        else if (i == '7') {morse.push_back("--...");   morse2.push_back('7');}
        else if (i == '8') {morse.push_back("---..");   morse2.push_back('8');}
        else if (i == '9') {morse.push_back("----.");   morse2.push_back('9');}
        else if (i == '0') {morse.push_back("-----");   morse2.push_back('0');}
    }

    deque<string>text1;
    string port = "";
    for (int i = 0; i < int(text.size()); i++)
    {
        if (i == int(text.size()) - 1){
            port += text[i];
            text1.push_back(port);
            break;
        }

        else if (isspace(text[i]) && isspace(text[i+1]) && isspace(text[i+2])){
            text1.push_back(port);
            text1.push_back(" ");
            port = "";
            i +=2 ;
        }

        else if (isspace(text[i]) && isspace(text[i+1])){
            text1.push_back(port);
            port = "";
            i +=1 ;
        }

        else if (isspace(text[i])){
            text1.push_back(port);
            port = "";
        }

        else {
            port += text[i];
        }
    }

    for (int i = 0; i < int(text1.size()); i++)
    {
        int count = 0;
        for (int j = 0; j < int(morse.size()); j++){
            if(text1[i] == morse[j]){
                result += morse2[j];
                count ++;
            }
        }
        if (count == 0 && text1[i] == " ")
            result += " ";
    }
    cout << "The Decrypted Message is: " << result << endl;
}

// Main Program of Morse Cipher.
int morse_cipher()
{
    ll Choice;
    cout << "\n# ===== Welcome to Morse Cipher ===== #" << endl;
    bool checkk = true;
    while (checkk){
        // Showing a list for user to choose encryption or decryption
        string menu7  = "What do you tend to do?\n [1] Cipher Message.\n [2] Decipher Message.\n [3] Exit This cipher.\nEnter your choice : ";
        vector <string> choices = {"1", "2", "3"};
        Choice = menu_check(choices, menu7);

        // If he chooses encryption
        if (Choice == 1){
            string message;
            cin.ignore(0,'\n');

            // To get the text from the user and check the validity of it
            while (true) {
                int count = 0;
                cout << "Enter your text you want to encrypt: ";
                getline(cin, message);

                for (int i = 0; i < int(message.size()); i++) {
                    if (!isalpha(message[i]) && !isdigit(message[i]) && !isspace(message[i])) {
                        cout << "Please enter a valid message." << endl;
                        break;
                    }
                    else {count += 1;}
                }

                if (count == int(message.size())) {break;}
            }
            encryption_morse(message);
            cout << endl;
        }

            // If a user chooses to decrypt
        else if (Choice == 2){
            string message;
            cin.ignore(0,'\n');

            // To get the text from the user and check the validity of it
            while(true){
                int count = 0;
                cout << "Enter your text you want to encrypt: ";
                getline(cin, message);

                for (int i = 0; i < int(message.size()); i++) {
                    if (static_cast<int>(message[i]) != 46 && static_cast<int>(message[i]) != 45 && !isspace(message[i])) {
                        cout << "Please enter a valid message." << endl;
                        break;
                    }
                    else {count += 1;}
                }

                if (count == int(message.size())) {break;}
            }
            morse_decipher(message);
            cout << endl;
        }

        else
            return 0;

        // Exit of this cipher
        checkk = continue_or();
    }
    return 0;
}

// ======================================================== XOR Cipher ======================================================== //

// Encryption the process of XOR Cipher.
int hexa_dec(string number){
    int j = 0,sum = 0;
    for (int i = number.length() - 1 ; i >= 0 ; i--)
    {
        if((number[i]-'0') <= 9)
            sum += (number[i]-'0') * pow(16,j);
        else if (toupper(number[i]) == 'A')
            sum += 10 * pow(16,j);
        else if (toupper(number[i]) == 'B')
            sum += 11 * pow(16,j);
        else if (toupper(number[i]) == 'C')
            sum += 12 * pow(16,j);
        else if (toupper(number[i]) == 'D')
            sum += 13 * pow(16,j);
        else if (toupper(number[i]) == 'E')
            sum += 14 * pow(16,j);
        else if (toupper(number[i]) == 'F')
            sum += 15 * pow(16,j);
        j++;
    }
    return sum;
}

// Decryption the process of XOR Cipher.
string dec_hex(string number){
    int num = 0;
    string result = "";
    for (int i = stoi(number);i > 0 ; i /= 16)
    {
        num = i%16;
        if (num <= 9)
            result = to_string(num) + result;
        else if ( num == 10)
            result = "A" + result;
        else if ( num == 11)
            result = "B" + result;
        else if ( num == 12)
            result = "C" + result;
        else if ( num == 13)
            result = "D" + result;
        else if ( num == 14)
            result = "E" + result;
        else if ( num == 15)
            result = "F" + result;
    }
    return result;
}

// Main Program of XOR Cipher.
int XOR_cipher(){
    cout << "# ===== Welcome to XOR Cipher ===== #" << endl;
    string text, text1, key, key1 = "";
    ll choice;
    bool check = true;

    while (check){
        string menu9 = "What do you want to do?\n [1] Encryption Text.\n [2] Decryption Text.\n [3] Exit This Cipher.\nEnter Your Choice : ", res = "";
        vector <string> choices = {"1", "2", "3"};
        choice = menu_check(choices ,menu9);

        if(choice == 1){
            cout << "Enter the text you want to encrypt :";
            getline(cin, text);
            for(char i : text){
                if (i != ' ')
                    text1 += i;
            }
            text = text1;

            while (true){
                bool alpha = false;
                cout << "Enter the key for Encryption (Only Letters) : ";
                getline(cin, key);
                for(char i : key){
                    if(!isalpha(i)){
                        alpha = true;
                        break;
                    }
                }
                if (!alpha)
                    break;
                else
                    cout << "Please enter a valid key." << endl;
            }

            for(int i = 0 ; i < ceil(double(text.length()/key.length())); i++)
                key1 += key;

            for(int i = 0 ; i < int(text.length());i++){
                res += char(key1[i]^text[i]);
            }

            vector <string> result;
            for(char i : res){
                string sum = dec_hex(to_string(int(i)));
                result.push_back(sum);
            }

            cout << "The cipher of your text : " << res << endl;
            cout << "The Hexa Cipher : ";
            for(string i : result)
                cout << i << ' ';
            cout << endl << endl;
        }

        else if(choice == 2){

            vector <string> arr;
            while(true){
                bool check = false;
                cout << "Enter the text you want to decrypt by hexa (composed of 2 digit hexadecimal separated by space):";
                getline(cin, text);
                for(char i : text){
                    if(!isspace(i)&&!isdigit(i)&&toupper(i) != 'A'&&toupper(i) != 'B'&&toupper(i) != 'C'&&toupper(i) != 'D'&&toupper(i) != 'E'&&toupper(i) != 'F'){
                        check = true;
                        break;
                    }
                }

                if(check){
                    cout << "Please enter a valid hexadecimal number." << endl;
                    continue;
                }
                cin.ignore(0, '\n');

                string str = "";
                for(int i = 0 ; i < int(text.length()); i++){
                    if(isspace(text[i]) && !isspace(text[i-1])){
                        arr.push_back(str);
                        str = "";
                        continue;
                    }
                    else if(isspace(text[i]) && isspace(text[i-1]))
                        continue;
                    str += text[i];
                }
                arr.push_back(str);

                bool check1 = true;
                for(string i : arr){
                    if(i.length() > 2){
                        check1 = false;
                        break;
                    }
                }

                if (check1)
                    break;
                cout << "Please enter a valid hexadecimal composed of 2 digits" << endl;
                arr.clear();
            }

            while (true){
                bool alpha = false;
                cout << "Enter the key for decryption (only letters) : ";
                getline(cin, key);
                for(char i : key){
                    if(!isalpha(i)){
                        alpha = true;
                        break;
                    }
                }
                if (!alpha)
                    break;
                else
                    cout << "Please enter a valid key." << endl;
            }

            for(int i = 0 ; i < ceil(double(text.length()/key.length())); i++)
                key1 += key;

            for(int i = 0 ; i < int(arr.size());i++){
                res += char(key1[i]^char(hexa_dec(arr[i])));
            }

            cout << "The Original Message is " << res << endl << endl;
        }
        else
            return 0;
        check = continue_or();
    }
    return 0;
}

// ======================================================= Rail Fence Cipher ======================================================= //

// Remove spaces and return it in lower case.
string remove_space(string str){
    string result;
    for(char ch : str) {
        if(ch != ' ')
            result += tolower(ch);
    }
    return result;
}

// Main Program of Rail-Fence Cipher.
int rail_fence(){
    // To see if user wants to encrypt or decrypt
    cout << "\n# ===== Welcome to Rail-Fence Cipher ===== #" << endl;
    bool checkk = true;
    while(checkk){

        // Declaring some variables
        string text;
        int  choice;
        ll key, counter = 0, num = 0;
        bool check = false;

        string menu10 = "What do you want to do?\n [1] Encryption of Sentence. \n [2] Decryption of Sentence. \n [3] Exit This Cipher.\nEnter Your choice: ";
        vector <string> choices = {"1", "2", "3"};
        choice = menu_check(choices ,menu10);

        if (choice == 1)                                    // If he chooses to encrypt
        {
            // To get the sentence and the key from user
            cout << "Enter sentence you want to encrypt: ";
            getline(cin, text);
            text = remove_space(text);
            key = check_number("Enter the key you want to encrypt by :");
            char arr[key][text.length()];

            // To fill the 2D array with points to simplify it
            for (int i = 0 ; i < key ; i++){
                for(int j = 0 ; j < int(text.length());j++)
                    arr[i][j] = '.';
            }

            // To make the rail fence of the sentence
            for(int i = 0 ; i < int(text.size());i++){
                arr[num][i] = text[i];
                if(!check)
                    num++;
                else
                    num--;
                if ((num % (key - 1) == 0 && i != 0 && key > 2 )||((num == 1 || num == 0) && key <= 2))
                    check = !check;
            }

            // Print the process that is done
            cout << "\n==== Encryption Process... ===="<<endl;
            // To print the 2D array
            for (int i = 0 ; i < key ; i++){
                for(int j = 0 ; j < int(text.length()) ; j++)
                    cout << arr[i][j];
                cout << endl;
            }

            // To print the encrypted code
            cout << "\nThe Encryption of your sentence is: ";
            for (int i = 0 ; i < key ; i++){
                for (int j = 0 ; j < int(text.length()); j++ ){
                    if(arr[i][j] != '.')
                        cout << arr[i][j];
                }
            }
            cout << endl;
        }

        else if (choice == 2)                               // If he chooses to decrypt
        {
            // To get the sentence and the key from user
            cout << "Enter sentence you want to decrypt: ";
            getline(cin, text);
            text = remove_space(text);
            key = check_number("Enter the key you want to decrypt text by");
            char arr[key][text.length()];

            // To fill the 2D array with points to simplify it
            for (int i = 0 ; i < key ; i++){
                for(int j = 0 ; j < int(text.length());j++)
                    arr[i][j] = '.';
            }

            // To identify the place of characters in the rail fence to declare it
            for(int i = 0 ; i < int(text.size());i++){
                arr[num][i] = '#';
                if(!check)
                    num++;
                else
                    num--;
                if ((num % (key - 1) == 0 && i != 0&& key > 2 )||((num == 1 || num == 0) && key <= 2))
                    check = !check;
            }

            // To declare it by arranging the characters
            for (int i = 0 ; i < key ; i++){
                for (int j = 0 ; j < int(text.length()); j++ ){
                    if (arr[i][j] != '.'){
                        arr[i][j] = text[counter];
                        counter++;
                    }
                }
            }

            cout << "\n==== Decryption Process... ====" << endl;
            // To print the 2D array
            for (int i = 0 ; i < key ; i++){
                for(int j = 0 ; j < int(text.length()) ; j++)
                    cout << arr[i][j];
                cout << endl;
            }

            // To print the text in its normal state after declaration
            cout << "\nThe Decription of your text: ";
            for (int i = 0 ; i < int(text.length()) ; i++){
                for (int j = 0 ; j < key; j++ ){
                    if(arr[j][i] != '.')
                        cout << arr[j][i];
                }
            }
            cout << endl;
        }

            // Exit
        else if (choice == 3)
            return 0;

        cout << endl;
        // To see if user wants to encrype with the same type of cipher or no
        checkk = continue_or();
    }
    return 0;
}

// ========================================================================>> Main Program <<======================================================================== //

int main(){
    int option;
    string option1;

    // A description for user to simplify the program.
    cout << "# The Description For User To Simplify The Program:" << endl;
    cout << "--> This program is for encryption your important information like password to be hard for strangers to get it." << endl;
    cout << "--> Also it can decryption if your password is already encrypt with one of this ciphers." << endl;
    cout << "// ================================================================================================================== //";
    cout << "\n# ===== Welcome To Encryption and Decryption Program ===== #" << endl;

    // To keep the program running till user wants to exit.
    while (true){

        // Show the available ciphers for user.
        string menu11 = "Which type of Cipher do you want?\n [1] Affine Cipher.\n [2] Route Cipher.\n [3] Atbash Cipher.\n [4] Vignere Cipher.\n [5] Baconian Cipher.\n [6] Simple Substitution Cipher.\n [7] Polybius Square Cipher.\n [8] Morse Cipher.\n [9] XOR Cipher.\n [10] Rail-Fence Cipher.\n [11] Exit Program.\nEnter Your Choice : ";
        vector <string> choices = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11"};
        option = menu_check(choices ,menu11);

        // Affine Cipher.
        if (option == 1)
            affine_cipher();

            // Route Cipher.
        else if (option == 2)
            route_cipher();

            // Atbash Cipher.
        else if (option == 3)
            atbash_cipher();

            // Vignere Cipher.
        else if (option == 4)
            vignere_cipher();

            // Baconoian Cipher.
        else if (option == 5)
            baconoian_cipher();

            // Simple Substitution Cipher.
        else if (option == 6)
            simple_substitution_cipher();

            // Polybius Square Cipher.
        else if (option == 7)
            Polybius_Square_cipher();

            // Morse Cipher.
        else if (option == 8)
            morse_cipher();

            // XOR Cipher.
        else if (option == 9)
            XOR_cipher();

            // Rail-Fence Cipher.
        else if (option == 10)
            rail_fence();

            // Exit Program.
        else if (option == 11){
            cout << "\n# ===== Thanks For Using Our Program ===== #" << endl;
            break;}

        // To ask the user if he wants to continue or not
//        while (true){
//            cout << "Do you want to continue?\n [1] Yes.\n [2] No.\nEnter Your Choice:";
//            getline(cin, option1);
//
//            if(option1 == "1" || option1 == "2")
//                break;
//            else
//                cout << "Please enter a valid input." << endl;
//
//            // To Exit program
//            if (option1 == "2"){
//                cout << "\n# ===== Thanks For Using Our Program ===== #" << endl;
//                break;}
//        }
    }
    return 0;
}
