/*
--> Name: CS112_A2_T2_S27_20230054_20231109_20231143.cpp
--> Purpose: this program is for encryption and decription your important information like your password, ID, etc.

--> Author of cipher number 3 (Vignere Cipher): Mohammed Atef Abd EL-Kader Bayomi.    (ID:20231143)         (Section : S27)
--> Email : mohamed45452020@gmail.com

--> Author of cipher number 4 (Baconian Cipher): Esraa Emary Abd Elsalam.             (ID:20230054)         (Section : S27)
--> Email : esraaemary33@gmail.com

--> Author of cipher number 9 (Rail Fence Cipher): Aly El-Deen Yasser Aly.            (ID:20231109)         (Section : S27)
--> Email : aibakgaming747@gmail.com

==============================================================================================================================================*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// ======================================================= Affine Cipher ======================================================= //


// ======================================================= Route Cipher ======================================================= //

// Encryption Process of Route Cipher.
void encyption(string text){
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
    int num = new_text.size() / key;
    if (num % key == 0){
        char matrix[text.size()], arr[num][key];
        for (int i = 0; i < text.size(); i++){
            matrix[i] = new_text[i];
        }

        //2D Matrix
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
        char matrix[key * (num+1)], arr[num+1][key];
        int j = text.size();
        while (j < key*(num+1)){
            new_text += 'X';
            j++;
        }

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
        cout << "\nThe Encrypted Message is: " << res.substr(0,key*(num+1)) << endl;
    }
}

// Decipher the process of Route Cipher.
void decryption(string text){
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

int route_cipher()
{
    string Choice, choice1;
    cout << "\n# ===== Welcome to Route Cipher ===== #" << endl;
    while (true)
    {
        // Showing a list for user to choose encryption or decryption.
        cout << "What do you tend to do?\n [1] Cipher Message.\n [2] Decipher Message.\n [3] Exit This cipher.\n";
        cout << "Enter Your Choice: ";
        cin >> Choice;

        if (Choice == "1"){                         // If he chooses encryption.
            string message, result = "";
            cin.ignore(1,'\n');

            // To get the text and key from user.
            while (true){
                cout << "Enter Your Text you want to encrypt (80 char is max limit): ";
                getline(cin, message);

                // To check the length of text limit.
                if (message.size() <= 80){
                    encyption(message);
                    cout << endl;
                    break;}

                    // If it is more than 80 char.
                else
                    cout << "The input message should be restricted to 80 characters.\n";
            }
        }


        else if (Choice == "2"){                                // if a user chooses to decrypt.
            string result, text = "";
            cin.ignore(1, '\n');

            while(true){
                // Getting an Encrypted message from user.
                cout << "Enter Your Encrypted Message to decrypt it (80 char is max limit): ";
                getline(cin, result);

                // To check that text size is less than 80 chars and decrypt it.
                if (result.size() <= 80){
                    decryption(result);
                    cout << endl;
                    break;
                }

                    // If it is more than 80 chars.
                else
                    cout << "The input message should be restricted to 80 characters.\n";
            }
        }

            // Exit of this cipher.
        else if (Choice == "3")
            return 0;

            // If user entered invalid input.
        else{
            cout << "Please enter a valid choice."<<endl;
            continue;
        }

        // To see if a user wants to encrypt with the same type of cipher or no.
        while (true){
            cout << "Do you want to continue with same type of cipher?\n [1] Yes.\n [2] No.\nEnter Your choice: ";
            cin >> choice1;

            if (choice1 == "1" || choice1 == "2"){
                cout << endl;
                break;}

            else
                cout << "Please enter a valid choice."<<endl;
        }

        if (choice1 == "2")
            return 0 ;
    }
    return 0;
}

// ======================================================= Atbash Cipher ======================================================= //

//check if the input has any character except alphabet
void validity(string &text){
    while (true){
        int count = 0;
        for (int i = 0; i < int(text.size()); i++){
            if (isalpha(text[i]))
                count++;
            else{
                cout << "Invalid Input."<<endl;
                cout << "Please enter the message to encrypt that only contains letters of alphabet: ";
                getline(cin, text);
            }
        }
        if (count == int(text.size())){
            break;
        }
    }
}

//encrypt messages 
string encrypt(string &text, int choice){
    string result = "";
    validity(text);
    for (int i = 0; i < int(text.size()); i++){

        //encrypt a message on tne whole letters of alphabet
        if(choice == 1){
            //check if the letter is uppercase to encrypt
            if(isupper(text[i])){
                result += static_cast<char>(25+130-static_cast<int>(text[i]));
            }

            //check if the letter is lowercase to encrypt
            else if(islower(text[i])){
                result += static_cast<char>(25+194-static_cast<int>(text[i]));
            }
        }
        
        //encrypt a message on half letters of alphabet
        else if(choice == 2){
            //check if the letter is uppercase to encrypt
            int digit = static_cast<int>(text[i]);
            if(isupper(text[i])){
                if(digit <= 77){
                    result += static_cast<char>(12+130-static_cast<int>(text[i]));
                }
                else if(digit > 77){
                    result += static_cast<char>(12+156-static_cast<int>(text[i]));
                }
            }

            //check if the letter is lowercase to encrypt
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

//decryption messages
string decrypt(string &text, int choice){
    string result = "";
    validity(text);
    for (int i = 0; i < int(text.size()); i++){
        //decrypt a message on tne whole letters of alphabet
        if(choice == 1){
            //check if the letter is uppercase to decrypt
            if(isupper(text[i])){
                result += static_cast<char>(25+130-static_cast<int>(text[i]));
                }

            //check if the letter is lowercase to decrypt
            else if(islower(text[i])){
                result += static_cast<char>(25+194-static_cast<int>(text[i]));
            }
        }
        
        //decrypt a message on half letters of alphabet
        else if(choice == 2){
            //check if the letter is uppercase to decrypt
            int digit = static_cast<int>(text[i]);
            if(isupper(text[i])){
                if(digit <= 77){
                    result += static_cast<char>(12+130-static_cast<int>(text[i]));
                }
                else if(digit > 77){
                    result += static_cast<char>(12+156-static_cast<int>(text[i]));
                }
            }

            //check if the letter is lowercase to decrypt
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

//main program of Atbash Cipher
int atbash_cipher(){
    cout<<"=====Welcome to Atbash Cipher====="<<endl;
    while(true){
        //print the menue and check the validity of choice
        cout << "What do you want to do?\n[1]Encrypt a message.\n[2]Decrypt a message.\n[3]Exit.\nChoice: ";
        int choice;
        cin>>choice;
        while ((cin.fail())||(choice!= 1 && choice!= 2 && choice!=3)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<< "Invalid input."<<endl;
            cout<< "Please enter a valid choice: ";
            cin>>choice;
        }  
        //print the menue and check the validity of choice and encrypt a message
        if(choice == 1){
            cout << "What do you want to do?\n[1]Encrypt a message on the whole alphabet.\n[2]Encrypt a message on half alphabet.\n[3]Back.\nChoice: ";
            int choice3;
            cin>>choice3;
            while ((cin.fail())||(choice3!= 1 && choice3!= 2 && choice3!=3)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<< "Invalid input."<<endl;
                cout<< "Please enter a valid choice: ";
                cin>>choice3;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string text;
            while (true){
                if(choice3 == 1 || choice3 == 2){
                    cout<<"Please enter the message you want to encrypt: ";
                    getline(cin, text);
                    cout << "The encrypted message is: "<<encrypt(text, choice3)<<endl;
                    break;
                }else if(choice3 == 3){
                    break;
                }else{
                    cout <<"Please enter a valid choice: ";
                    cin >>choice3;
                }
            }
        }
        //print the menue and check the validity of choice and decrypt a message
        else if(choice == 2){
            cout << "What do you want to do?\n[1]Decrypt a message on the whole alphabet.\n[2]Decrypt a message on half alphabet.\n[3]Back."<< endl;
            int choice2;
            cin>>choice2;
             while ((cin.fail())||(choice2!= 1 && choice2!= 2 && choice2!=3)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<< "Invalid input."<<endl;
                cout<< "Please enter a valid choice: ";
                cin>>choice2;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string text;
            while (true){
                if(choice2 == 1 || choice2 == 2){
                    cout<<"Please enter the message you want to decrypt: ";
                    getline(cin, text);
                    cout << "The decrypted message is: "<<decrypt(text, choice2)<<endl;
                    break;
                }else if(choice2 == 3){
                    break;
                }else{
                    cout <<"Please enter a valid choice: ";
                    cin >>choice2;
                }
            }
        }
        //exit the cipher
        else if(choice == 3){
            break;
        }
        else{
            cout <<  "Invalid choice.\n";
            continue;
        }
        // To see if user want to encrype with the same type of cipher or no
        int choice1;
        while (true){
            cout<<"Do you want to continue with same type of cipher?\n[1] Yes\n[2] No\nYour choice: ";
            cin>>choice1;
            while ((cin.fail())|| (choice1 != 1 && choice1 != 2 )){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input.\n";
                cout << "Please select a valid choice from the previous menu: ";
                cin >> choice1;
            }
            if (choice1 == 1 || choice1 == 2)
                break;
            
            else
                cout << "Please enter a valid choice: ";
        }
        if (choice1 == 2)
            return 0 ;
    }
    return 0;
}

// ======================================================= Vignere Cipher ======================================================= //

// Encryption process of Vignere Cipher
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
        for (int i = 0; i < key.size() ;i++){
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

            // Encryptation process
            while (i < text.length()){
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

// Decipher the process of Vignere Cipher.
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
        for (int i = 0; i < key.size() ;i++){
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
            while (i < result.length()){
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

int vignere_cipher()
{
    string Choice, choice1;
    cout << "\n# ===== Welcome to Vignere Cipher ===== #" << endl;
    while (true)
    {
        // Showing a list for user to choose encryption or decryption
        cout << "What do you tend to do?\n [1] Cipher Message.\n [2] Decipher Message.\n [3] Exit This cipher.\n";
        cout << "Enter Your Choice: ";
        cin >> Choice;

        if (Choice == "1"){                         // If he chooses encryption
            string message, result = "";
            cin.ignore(1,'\n');

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


        else if (Choice == "2"){                                // if a user chooses to decrypt
            string result, text = "";
            cin.ignore(1, '\n');

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
        else if (Choice == "3")
            return 0;

            // If user entered invalid input
        else{
            cout << "Please enter a valid choice."<<endl;
            continue;
        }

        // To see if a user wants to encrypt with the same type of cipher or no
        while (true){
            cout << "Do you want to continue with same type of cipher?\n [1] Yes.\n [2] No.\nEnter Your choice: ";
            cin >> choice1;

            if (choice1 == "1" || choice1 == "2"){
                cout << endl;
                break;}

            else
                cout << "Please enter a valid choice."<<endl;
        }

        if (choice1 == "2")
            return 0 ;
    }
    return 0;
}

// ======================================================= Baconian Cipher ======================================================= //

// Encryption process of Baconian Cipher
string encryption4(string text)
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

// Decryption process of Baconian Cipher
string decryption4(string text)
{
    string result ="";
    string text2 = "";

    //convert every (A or a) into 0 and every (B or b) into 1 and add this to text2
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

// Check if the input has any character except A, B, a or b
string validity(string &text)
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

int baconoian_cipher()
{
    // To see if user wants to encrypt or decrypt
    cout << "\n# ===== Welcome to Baconian Cipher ===== #" << endl;
    while(true)
    {
        cout << "What do you want to do?\n [1] Encryption of Sentence. \n [2] Decryption of Sentence. \n [3] Exit.\nEnter Your choice: ";
        int main4;
        cin >> main4;
        while ((cin.fail())|| (main4 != 1 && main4 != 2 && main4 != 3))
        {
            cin.clear();                            // Clear the previous input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";             // Print an error message
            cout << "Please select a valid choice from the previous menu: ";
            cin >> main4;                           // Get a new clone then check it
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //check if the user wants to enter a message to encrypt
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
            cout <<"The Encrypted Message is: " << encryption4(text) << endl;
        }

            // Check if the user want to enter a message to dencrypt
        else if (main4 == 2)
        {
            string text;
            cout << "Please enter the message to decrypt that only contains A, B, a or b.: ";
            getline(cin, text);
            validity(text);

            // Print the decrypted message
            cout << "The Decrypted Message is: " << decryption4(text) << endl;          // Print the decrypted message
        }

            // Back to the main menu
        else if (main4 == 3)
            break;

            // Check the validity of the user choice
        else
        {cout << "Please enter a valid choice."<<endl;}
        cout << endl;


        // To see if user wants to encrype with the same type of cipher or no
        int choice1;
        while (true){
            cout << "Do you want to continue with same type of cipher?\n [1] Yes.\n [2] No.\nEnter Your choice: ";
            cin >> choice1;
            while ((cin.fail())|| (choice1 != 1 && choice1 != 2 ))
            {
                cin.clear();                                // Clear the previous input
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input.\n";                 // Print an error message
                cout << "Please select a valid choice from the previous menu: ";
                cin >> choice1;                             // Get a new clone then check it
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (choice1 == 1 || choice1 == 2)
                break;

            else
                cout << "Please enter a valid choice"<<endl;
        }

        if (choice1 == 2)
            return 0 ;
    }
}


// ======================================================= Simple Substitution Cipher ======================================================= //

//check if the input has any character except alphabet
void validity(string &text){
    while (true){
        int count = 0;
        while(text.size() == 0){
            cout << "Invalid Input."<<endl;
            cout << "Please enter the message to encrypt that only contains letters of alphabet: ";
            getline(cin, text);
        }

        for (int i = 0; i < int(text.size()); i++){
            if (isalpha(text[i]))
                count++;
            else{
                cout << "Invalid Input."<<endl;
                cout << "Please enter the message to encrypt that only contains letters of alphabet: ";
                getline(cin, text);
            }
        }
        if (count == int(text.size())){
            break;
        }
    }
}
//check if the input has any character except alphabet and it is 5 digits
void validity2(string &text){
    while (true){
        int count = 0;
        while(text.size() != 5){
            cout << "Invalid Input."<<endl;
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

//encrypt messages 
string encrypt(string &text, string keyword){
    string result = "";
    string text2 = "";
    string keyword2 = "";
    deque<char>alphabet;
    deque<char>key;
    deque<char>new_alphabet;
    //convert the message and keyword into uppercase
    for (int i = 0; i < int(text.size()); i++){
        text2 += toupper(text[i]);
    }
    for (int i = 0; i < int(keyword.size()); i++){
        keyword2 += toupper(keyword[i]);
    }
    //make a list for alphabetic letters and add keyword and rest of alphabetic letters to it
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

//decryption messages
string decrypt(string &text, string keyword){
    string result = "";
    string text2 = "";
    string keyword2 = "";
    deque<char>alphabet;
    deque<char>key;
    deque<char>new_alphabet;
    //convert the message and keyword into uppercase
    for (int i = 0; i < int(text.size()); i++){
        text2 += toupper(text[i]);
    }
    for (int i = 0; i < int(keyword.size()); i++){
        keyword2 += toupper(keyword[i]);
    }
    //make a list for alphabetic letters and add keyword and rest of alphabetic letters to it
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

//main program of Simple Substitution Cipher
int simple_substitution_cipher(){
    cout<<"=====Welcome to Simple Substitution Cipher====="<<endl;
    while(true){
        //print the menue and check the validity of choice
        cout << "What do you want to do?\n[1]Encrypt a message.\n[2]Decrypt a message.\n[3]Exit.\nChoice: ";
        int choice;
        cin>>choice;
        while ((cin.fail())||(choice!= 1 && choice!= 2 && choice!=3)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<< "Invalid input."<<endl;
            cout<< "Please enter a valid choice: ";
            cin>>choice;
        }  
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //get the message and encrypt messages
        if(choice == 1){
            string text, keyword;
            cout<<"Please enter the message you want to encrypt: ";
            getline(cin, text);
            validity(text);
            cout<<"Please enter the keyword: ";
            getline(cin, keyword);
            validity2(keyword);
            cout << "The encrypted message is: "<<encrypt(text, keyword)<<endl;
        }
        
        //get the message and decrypt messages
        else if(choice == 2){
            string text, keyword;
            cout<<"Please enter the message you want to decrypt: ";
            getline(cin, text);
            validity(text);
            cout<<"Please enter the keyword: ";
            getline(cin, keyword);
            validity2(keyword);
            cout << "The decrypted message is: "<<decrypt(text, keyword)<<endl;
        }
        //exit the cipher
        else if(choice == 3){
            break;
        }
        else{
            cout <<  "Invalid choice.\n";
            continue;
        }
        // To see if user want to encrype with the same type of cipher or no
        int choice1;
        while (true){
            cout<<"Do you want to continue with same type of cipher?\n[1] Yes\n[2] No\nYour choice: ";
            cin>>choice1;
            while ((cin.fail())|| (choice1 != 1 && choice1 != 2 )){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input.\n";
                cout << "Please select a valid choice from the previous menu: ";
                cin >> choice1;
            }
            if (choice1 == 1 || choice1 == 2)
                break;
            
            else
                cout << "Please enter a valid choice: ";
        }
        if (choice1 == 2)
            return 0 ;
    }
    return 0;
}


// ======================================================= Polybius Square Cipher ======================================================= //

// Encryption process of Polybius Square Cipher
void Polybius_Square_cipher(string text)
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

int polybius_square_cipher()
{
    string Choice, choice1;
    cout << "\n# ===== Welcome to Polybius Square Cipher ===== #" << endl;
    while (true)
    {
        // Showing a list for user to choose encryption or decryption
        cout << "What do you tend to do?\n [1] Cipher Message.\n [2] Decipher Message.\n [3] Exit This cipher.\n";
        cout << "Enter Your Choice: ";
        cin >> Choice;

        if (Choice == "1"){                         // If he chooses encryption
            string message, result = "";
            cin.ignore(1,'\n');

            // To get the text and key from user
            while (true){
                cout << "Enter Your Text you want to encrypt (80 char is max limit): ";
                getline(cin, message);

                // To check the length of text limit
                if (message.size() <= 80){
                    cout << endl;
                    Polybius_Square_cipher(message);
                    cout << endl << endl;
                    break;}

                    // If it is more than 80 char
                else
                    cout << "The input message should be restricted to 80 characters.\n";
            }
        }


            // else if (Choice == "2"){                                // if a user chooses to decrypt
            //     string result, text = "";
            //     cin.ignore(1, '\n');

            //     while(true){
            //         // Getting an Encrypted message from user
            //         cout << "Enter Your Encrypted Message to decrypt it (80 char is max limit): ";
            //         getline(cin, result);

            //         // To check that text size is less than 80 chars and decrypt it
            //         if (result.size() <= 80){
            //             vignere_decipher(result);
            //             cout << endl;
            //             break;
            //         }

            //         // If it is more than 80 chars
            //         else
            //             cout << "The input message should be restricted to 80 characters.\n";
            //     }
            // }

            // Exit of this cipher
        else if (Choice == "3")
            return 0;

            // If user entered invalid input
        else{
            cout << "Please enter a valid choice."<<endl;
            continue;
        }

        // To see if a user wants to encrypt with the same type of cipher or no
        while (true){
            cout << "Do you want to continue with same type of cipher?\n [1] Yes.\n [2] No.\nEnter Your choice: ";
            cin >> choice1;

            if (choice1 == "1" || choice1 == "2"){
                cout << endl;
                break;}

            else
                cout << "Please enter a valid choice."<<endl;
        }

        if (choice1 == "2")
            return 0 ;
    }
    return 0;
}

// ======================================================= Morse Cipher ======================================================= //

// Encryption process of Morse Cipher
void morse_cipher(string text)
{
    string result = "";
    for (char i : text)
    {
        i = toupper(i);
        if(isalpha(i))
        {
            if (i == 'A')
            {result += ".- ";}
            else if (i == 'B')
            {result += "-... ";}
            else if (i == 'C')
            {result += "-.-. ";}
            else if (i == 'D')
            {result += "-.. ";}
            else if (i == 'E')
            {result += ". ";}
            else if (i == 'F')
            {result += "..-.";}
            else if (i == 'G')
            {result += "--. ";}
            else if (i == 'H')
            {result += ".... ";}
            else if (i == 'I')
            {result += ".. ";}
            else if (i == 'J')
            {result += ".--- ";}
            else if (i == 'K')
            {result += "-.- ";}
            else if (i == 'L')
            {result += ".-.. ";}
            else if (i == 'M')
            {result += "-- ";}
            else if (i == 'N')
            {result += "-. ";}
            else if (i == 'O')
            {result += "--- ";}
            else if (i == 'P')
            {result += ".--. ";}
            else if (i == 'Q')
            {result += "--.- ";}
            else if (i == 'R')
            {result += ".-. ";}
            else if (i == 'S')
            {result += "... ";}
            else if (i == 'T')
            {result += "- ";}
            else if (i == 'U')
            {result += "..- ";}
            else if (i == 'V')
            {result += "...- ";}
            else if (i == 'W')
            {result += ".-- ";}
            else if (i == 'X')
            {result += "-..- ";}
            else if (i == 'Y')
            {result += "-.-- ";}
            else if (i == 'Z')
            {result += "--.. ";}
        }
        else if (isspace(i))
        {result += "  ";}
    }
    cout << "The Encrypted Message is: " << result;
}

int morse_cipher()
{
    string Choice, choice1;
    cout << "\n# ===== Welcome to Morse Cipher ===== #" << endl;
    while (true)
    {
        // Showing a list for user to choose encryption or decryption
        cout << "What do you tend to do?\n [1] Cipher Message.\n [2] Decipher Message.\n [3] Exit This cipher.\n";
        cout << "Enter Your Choice: ";
        cin >> Choice;

        if (Choice == "1"){                         // If he chooses encryption
            string message, result = "";
            cin.ignore(1,'\n');

            // To get the text and key from user
            while (true){
                cout << "Enter Your Text you want to encrypt (80 char is max limit): ";
                getline(cin, message);

                // To check the length of text limit
                if (message.size() <= 80){
                    cout << endl;
                    morse_cipher(message);
                    cout << endl << endl;
                    break;}

                    // If it is more than 80 char
                else
                    cout << "The input message should be restricted to 80 characters.\n";
            }
        }


            // else if (Choice == "2"){                                // if a user chooses to decrypt
            //     string result, text = "";
            //     cin.ignore(1, '\n');

            //     while(true){
            //         // Getting an Encrypted message from user
            //         cout << "Enter Your Encrypted Message to decrypt it (80 char is max limit): ";
            //         getline(cin, result);

            //         // To check that text size is less than 80 chars and decrypt it
            //         if (result.size() <= 80){
            //             vignere_decipher(result);
            //             cout << endl;
            //             break;
            //         }

            //         // If it is more than 80 chars
            //         else
            //             cout << "The input message should be restricted to 80 characters.\n";
            //     }
            // }

            // Exit of this cipher
        else if (Choice == "3")
            return 0;

            // If user entered invalid input
        else{
            cout << "Please enter a valid choice."<<endl;
            continue;
        }

        // To see if a user wants to encrypt with the same type of cipher or no
        while (true){
            cout << "Do you want to continue with same type of cipher?\n [1] Yes.\n [2] No.\nEnter Your choice: ";
            cin >> choice1;

            if (choice1 == "1" || choice1 == "2"){
                cout << endl;
                break;}

            else
                cout << "Please enter a valid choice."<<endl;
        }

        if (choice1 == "2")
            return 0 ;
    }
    return 0;
}

// ======================================================= XOR Cipher ======================================================= //



// ======================================================= Rail Fence Cipher ======================================================= //

// Remove spaces and return it in lower case
string remove_space(string str){
    string result;
    for(char ch : str) {
        if(ch != ' ')
            result += tolower(ch);
    }
    return result;
}

// To check that key is a number
ll check_number (string print){
    string key;
    while (true){
        bool check = true;
        cout << "Enter the key you want to " << print << " text by : ";
        cin >> key;

        for (char i : key){
            if(!isdigit(i) || stoll(key) < 0){
                check = false;
                break;}
        }

        if (check)
            return stoll(key);
        else
            cout << "Please enter a valid number" << endl;
        cout << endl;
    }
}

int rail_fence(){
    // To see if user wants to encrypt or decrypt
    cout << "\n# ===== Welcome to Rail Fence Cipher ===== #" << endl;
    while(true){

        // Declaring some variables
        string text;
        int  choice,choice1;
        ll key, counter = 0, num = 0;
        bool check = false;

        while (true){
            cout << "What do you want to do?\n [1] Encryption of Sentence. \n [2] Decryption of Sentence. \n [3] Exit This Cipher.\nEnter Your choice: ";
            cin >> choice;
            while ((cin.fail())|| (choice != 1 && choice != 2 && choice != 3))
            {
                cin.clear();                                // Clear the previous input
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input.\n";                 // Print an error message
                cout << "Please select a valid choice from the previous menu: ";
                cin >> choice;                              // Get a new clone then check it
            }
            cin.ignore(numeric_limits<streamsize>::max(),'\n');         // To avoid error in input
            cout << endl;

            if (choice == 1 ||choice == 2 ||choice == 3)      // Check user not entering another choice
                break;
            else
                cout << "Please enter a valid input !" << endl;
        }

        if (choice == 1)     // If he chooses to encrypt
        {
            // To get the sentence and the key from user
            cout << "Enter sentence you want to encrypt: ";
            getline(cin, text);
            text = remove_space(text);
            key = check_number("encrypt");
            char arr[key][text.length()];

            // To fill the 2D array with points to simplify it
            for (int i = 0 ; i < key ; i++){
                for(int j = 0 ; j < text.length();j++)
                    arr[i][j] = '.';
            }

            // To make the rail fence of the sentence
            for(int i = 0 ; i < text.size();i++){
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
                for(int j = 0 ; j < text.length() ; j++)
                    cout << arr[i][j];
                cout << endl;
            }

            // To print the encrypted code
            cout << "\nThe Encryption of your sentence is: ";
            for (int i = 0 ; i < key ; i++){
                for (int j = 0 ; j < text.length(); j++ ){
                    if(arr[i][j] != '.')
                        cout << arr[i][j];
                }
            }
            cout << endl;
        }

        else if (choice == 2)      // If he chooses to decrypt
        {
            // To get the sentence and the key from user
            cout << "Enter sentence you want to decrypt: ";
            getline(cin, text);
            text = remove_space(text);
            key = check_number("decrypt");
            char arr[key][text.length()];

            // To fill the 2D array with points to simplify it
            for (int i = 0 ; i < key ; i++){
                for(int j = 0 ; j < text.length();j++)
                    arr[i][j] = '.';
            }

            // To identify the place of characters in the rail fence to declare it
            for(int i = 0 ; i < text.size();i++){
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
                for (int j = 0 ; j < text.length(); j++ ){
                    if (arr[i][j] != '.'){
                        arr[i][j] = text[counter];
                        counter++;
                    }
                }
            }

            cout << "\n==== Decryption Process... ====" << endl;
            // To print the 2D array
            for (int i = 0 ; i < key ; i++){
                for(int j = 0 ; j < text.length() ; j++)
                    cout << arr[i][j];
                cout << endl;
            }

            // To print the text in its normal state after declaration
            cout << "\nThe Decription of your text: ";
            for (int i = 0 ; i < text.length() ; i++){
                for (int j = 0 ; j < key; j++ ){
                    if(arr[j][i] != '.')
                        cout<<arr[j][i];
                }
            }
            cout << endl;
        }

            // Exit
        else if (choice == 3)
            return 0;

        cout << endl;

        // To see if user wants to encrype with the same type of cipher or no
        while (true){
            cout << "Do you want to continue with same type of cipher?\n [1] Yes.\n [2] No.\nEnter Your choice: ";
            cin >> choice1;
            while ((cin.fail())|| (choice1 != 1 && choice1 != 2 ))
            {
                cin.clear();                                // Clear the previous input
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input.\n";                 // Print an error message
                cout << "Please select a valid choice from the previous menu: ";
                cin >> choice1;                             // Get a new clone then check it
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (choice1 == 1 || choice1 == 2)
                break;

            else
                cout << "Please enter a valid choice" << endl;
        }

        if (choice1 == 2)
            return 0 ;
    }
}




// ========================================================================>> Main Program <<======================================================================== //

int main(){
    int option, option1;

    // A description for user to simplify the program
    cout << "# The Description For User To Simplify The Program:" << endl;
    cout << "--> This program is for encryption your important information like password to be hard for strangers to get it." << endl;
    cout << "--> Also it can decryption if your password is already encrypt with one of this ciphers." << endl;
    cout << "--> The ciphers that is in the program is Vignere Cipher, Baconian Cipher and Rail Fence" << endl;
    cout << "==================================================================================================================" << endl;
    cout << "\n# ===== Welcome To Encryption and Decryption Program ===== #" << endl;

    // To keep the program running till user wants to exit
    while (true){

        // Show the available ciphers for user
        cout << "Which type of Cipher Do you want?\n [1] Affine Cipher.\n [2] Route Cipher.\n [3] Atbash Cipher.\n [4] Vignere Cipher.\n [5] Baconian Cipher.\n [6] Simple Substitution Cipher.\n [7] Polybius Square Cipher.\n [8] Morse Cipher.\n [9] XOR Cipher.\n [10] Rail-fence Cipher.\n [11] Exit Program.\nEnter Your choice : ";
        cin >> option;
        while ((cin.fail())|| (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6 && option != 7 && option != 8 && option != 9 && option != 10 && option != 11))
        {
            cin.clear();                        // Clear the previous input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid choice.\n";               // Print an error message
            cout << "Please select a valid choice from the previous menu: ";
            cin >> option;                      // Get a new clone then check it
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


            // Route Cipher
        if (option == 2)
            route_cipher();

        else if (option == 2)
            atbash_cipher();
            
            // Vignere Cipher
       else if (option == 4)
            vignere_cipher();

            // Baconoian Cipher
        else if (option == 5)
            baconoian_cipher();

        else if (option == 5)
            simple_substitution_cipher();

            // Polybius Square Cipher
        else if (option == 7)
            polybius_square_cipher();

            // Morse Cipher
        else if (option == 8)
            morse_cipher();

            // Rail Fence Cipher
        else if (option == 10)
            rail_fence();

            // Exit Program
        else if (option == 11){
            cout << "\n# ===== Thanks for using our Program! ===== #" << endl;
            break;
        }

        // To ask user if he wants to continue or not
        while (true){
            cout << endl;
            cout << "Do you want to continue?\n [1] Yes.\n [2] No.\nEnter Your choice: ";
            cin >> option1;
            while ((cin.fail())|| (option1 != 1 && option1 != 2))
            {
                cin.clear();                                            // Clear the previous input
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a valid choice.\n";               // Print an error message
                cout << "Please select a valid choice from the previous menu: ";
                cin >> option1;                                         // Get a new clone then check it
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // To Check option is valid
            if (option1 == 1 || option1 == 2){
                cout << endl;
                break;
            }

            else                                             // If it is invalid
                cout << "Please enter a valid option" << endl;
            cout << "\n";
        }

        // To Exit program
        if (option1 == 2){
            cout << "\n# ===== Thanks for using our Program! ===== #" << endl;
            break;}
    }
}
