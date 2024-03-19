/*
--> Name: CS112_A2_T3_S27_20230054_20231109_20231143.cpp
--> Purpose: In this application create a rational number calculator that is capable of taking two rational numbers
             and an operation to perform on them. The Program should handle cases of –ve numbers and nominators without a denominator.
             It should also use defensive programming to reject bad inputs.

--> Author 1: Mohammed Atef Abd EL-Kader Bayomi.      (ID:20231143)         (Section : S27)
--> Email : mohamed45452020@gmail.com

--> Author 2: Esraa Emary Abd Elsalam.                (ID:20230054)         (Section : S27)
--> Email : esraaemary33@gmail.com

--> Author 3: Aly El-Deen Yasser Aly.                 (ID:20231109)         (Section : S27)
--> Email : aibakgaming747@gmail.com

=============================================================== Algorithm for: ========================================================================
======================================================== (Rational Number Calculator) =================================================================

•	Print	“a welcome message and lines in brief to define the application.”
•	Make a while loop to make the program running until the user chooses to exit after each operation.
•	Define some variables.
•	Take an expression from user to calculate as a string.
•	Check the validity of the expression as it doesn’t have characters except numbers and (-, +, /or*), if that didn’t achieve print a warning message and take another expression from the user.
•	Turn the expression into numbers and operators in the form [numerator1/denominator1 (-, +, /or*) numerator2/ denominator2] as numerator1, denominator1, numerator2 and denominator2 are integers positive or negative.

•	If operation is /, do the following lines:

        o	Check if denominator1, numerator2 or denominator2 is zero, and if this happened, print a warning message and take another expression from the user.
        o	The result of the expression will be (numerator1*denominator2)/ (denominator1*numerator2).


•	If operation is *, do the following lines:

        o	Check if denominator1 or denominator2 is zero, and if this happened, print a warning message and take another expression from the user.
        o	The result of the expression will be (numerator1* numerator2)/ (denominator1* denominator2).


•	If operation is +, do the following lines:

        o	Check if denominator1 or denominator2 is zero, and if this happened, print a warning message and take another expression from the user.
        o	The result of the expression will be ((numerator1* denominator2) + (numerator2 * denominator1)) / (denominator1* denominator2).


•	If operation is -, do the following lines:

        o	Check if denominator1 or denominator2 is zero, and if this happened, print a warning message and take another expression from the user.
        o	The result of the expression will be ((numerator1* denominator2) - (numerator2 * denominator1)) / (denominator1* denominator2).
*/
// ==========================================================>> Main Code <<=================================================================== //

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Function for simplifying.
void simple (ll a, ll b)
{
    ll r, n = a, d = b;
    a = abs(a);
    b = abs(b);

    while((r = a%b)!= 0){
        a = b;
        b = r;
    }

    if (n<0 && d<0){
        n = abs(n);
        d = abs(d);
    }
    cout << "\nThe Result = " << n/b << "/" << d/b << endl;
}

// =====================================================================>> Main Application <<===================================================================== //

int main(){
    // To show the user the rules of the calculator.
    cout << "# ==================================== Welcome to Rational Numbers Calculator ======================================= #" << endl << endl;
    cout << "--> In this calculator we will enter two fractional number and make addition, subtraction, multiplication and division " << endl;
    cout << "    to give you the answer of your expression." << endl;
    cout << "--> The form that you will enter must be like that [num/num (+, -, * or /) num/num]." << endl;
    cout << "Note : Space after the the fractional number is important." << endl;
    cout << "======================================================================================================================" << endl;

    // To keep the program running.
    while (true){
        string text, continue_or, numerator_1 = "", denominator_1 = "", numerator_2 = "", denominator_2 = "", num1, num2;
        ll numerator1 = 1, denominator1 = 1, numerator2 = 1, denominator2 = 1, denominator_result, numerator_result;
        bool check = false, check1 = false;
        char operation;
        regex formela ("(\\s*[-+]?\\s*[0-9]+\\s*/\\s*[-+]?\\s*[0-9]+\\s*|\\s*[-+]?\\s*[0-9]+\\s*)\\s+([+*/-])\\s+(\\s*[-+]?\\s*[0-9]+\\s*/\\s*[-+]?\\s*[0-9]+\\s*|\\s*[-+]?\\s*[0-9]+\\s*)");
        smatch matches;

        // To check program is as the required form
        while(true){

            // Defining some variables.
            check = false, check1 = false;
            numerator_1 = "", denominator_1 = "", numerator_2 = "", denominator_2 = "";
            numerator1 = 1, denominator1 = 1, numerator2 = 1, denominator2 = 1;
            cout << "Enter the equation you want to calculate : ";
            getline(cin, text);

            if(regex_match(text, matches, formela)){

                operation = matches[2].str()[0];
                num1 = matches[1];
                num2 = matches[3];

                for(char i : num1){
                    if(i == '/'){
                        check = true;
                        continue;
                    }
                    if(!check && i != '+' && i != ' ')
                        numerator_1 += i;
                    else if (i != '+' && i != ' ')
                        denominator_1 += i;
                }

                for(char i : num2){
                    if(i == '/'){
                        check1 = true;
                        continue;
                    }
                    if(!check1 && i != '+' && i != ' ')
                        numerator_2 += i;
                    else if(i != '+' && i != ' ')
                        denominator_2 += i;
                }

                numerator1 = stoll(numerator_1);
                numerator2 = stoll(numerator_2);
                if(denominator_1 != "")
                    denominator1 = stoll(denominator_1);
                if(denominator_2 != "")
                    denominator2 = stoll(denominator_2);

                // to check if denomerator not equal to zero
                if(operation == '/'){
                    if(denominator1 != 0 && denominator2 != 0 && numerator2 != 0)
                        break;
                    else
                        cout << "Please don't enter a zero in the denominator." << endl << endl;
                }
                else{
                    if(denominator1 != 0 && denominator2 != 0)
                        break;
                    else
                        cout << "Please don't enter a zero in the denominator." << endl << endl;
                }
            }

            else
                cout << "Please enter with the defined formula and don't enter a zero in the denominator." << endl << endl;
        }

        // To do what user wants.
        switch (operation){
            // Addition.
            case '+':
                numerator_result = (numerator1 * denominator2) + (numerator2 * denominator1);
                denominator_result = denominator1 * denominator2;
                if(numerator_result % denominator_result == 0){
                    numerator_result /= denominator_result;
                    denominator_result = 1;
                }
                simple(numerator_result, denominator_result);
                cout << endl;
                break;

                // Subtraction.
            case '-':
                numerator_result = (numerator1 * denominator2) - (numerator2 * denominator1);
                denominator_result = denominator1 * denominator2;
                if(numerator_result % denominator_result == 0){
                    numerator_result /= denominator_result;
                    denominator_result = 1;
                }
                simple(numerator_result, denominator_result);
                cout << endl;
                break;

                // Multiplication.
            case '*':
                numerator_result = numerator1 * numerator2;
                denominator_result = denominator1 * denominator2;
                if(numerator_result % denominator_result == 0){
                    numerator_result /= denominator_result;
                    denominator_result = 1;
                }
                simple(numerator_result, denominator_result);
                cout << endl;
                break;

                // Division.
            case '/':
                numerator_result = numerator1 * denominator2;
                denominator_result = denominator1 * numerator2;
                if(denominator_result == 0)
                    break;
                if(numerator_result % denominator_result == 0){
                    numerator_result /= denominator_result;
                    denominator_result = 1;
                }
                simple(numerator_result, denominator_result);
                cout << endl;
                break;
        }

        // To check if user wants to continue using calculator or not.
        while(true){
            cout << "Do you want to continue?\n [1] Yes.\n [2] No.\nEnter Your Choice : " ;
            getline(cin, continue_or);

            if (continue_or == "1")
                break;
            else if (continue_or == "2"){
                cout << "\nThanks For Using Rational Number Calculator ....\n";
                return 0;
            }
            else
                cout << "Please enter a valid choice !!" << endl;
            cout << endl;
        }
    }

    return 0;
}
