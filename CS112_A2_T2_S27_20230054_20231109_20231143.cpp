/*
--> Name: CS112_A2_T2_S27_20230054_20231109_20231143.cpp
--> Purpose: this program is for encryption and decription your important information like your password, ID, etc., by three ways: Vignere cipher, Baconian cipher and Rail Fence cipher.

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
        cout << "Which type of Cipher Do you want?\n [1] Vignere Cipher.\n [2] Baconoian Cipher.\n [3] Rail Fence Cipher.\n [4] Exit Program.\nEnter Your choice : ";
        cin >> option;
        while ((cin.fail())|| (option != 1 && option != 2 && option != 3 && option != 4))
        {
            cin.clear();                        // Clear the previous input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid choice.\n";               // Print an error message
            cout << "Please select a valid choice from the previous menu: ";
            cin >> option;                      // Get a new clone then check it
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        // Vignere Cipher
        if (option == 1)
            vignere_cipher();

        // // Baconoian Cipher
        else if (option == 2)
            baconoian_cipher();

        // Rail Fence Cipher
        else if (option == 3)
            rail_fence();

        // Exit Program
        else if (option == 4){
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

            else                            // If it is invalid
                cout << "Please enter a valid option" << endl;
            cout << "\n";
        }

        // To Exit program
        if (option1 == 2){
            cout << "\n# ===== Thanks for using our Program! ===== #" << endl;
            break;}
    }
}