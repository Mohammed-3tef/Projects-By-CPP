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

==========================================================Algorithm===================================================================*/

// FUNCTION simple(a, b)
//     r, n, d = a, a, b
//     a = ABS(a)
//     b = ABS(b)

//     WHILE (r = a % b) != 0
//         a = b
//         b = r

//     IF n < 0 AND d < 0 THEN
//         n = ABS(n)
//         d = ABS(d)

//     OUTPUT "The Result = ", n/b, "/", d/b

// FUNCTION main()
//     OUTPUT "Welcome to Rational Numbers Calculator"
//     OUTPUT "In this calculator, we will enter two fractional numbers and perform addition, subtraction, multiplication, and division to give you the answer."
//     OUTPUT "The format you will enter must be like this: [num/num (+, -, * or /) num/num]."
//     OUTPUT "Note: Space after the fractional number is important."

//     WHILE true
//         DECLARE text, continue_or, numerator_1, denominator_1, numerator_2, denominator_2, num1, num2
//         DECLARE numerator1, denominator1, numerator2, denominator2, denominator_result, numerator_result, operation
//         DECLARE check, check1 BOOLEAN

//         SET numerator1, denominator1, numerator2, denominator2 TO 1
//         SET check, check1 TO FALSE

//         OUTPUT "Enter the equation you want to calculate: "
//         READ text

//         IF text matches regex pattern "(\\s*[-+]?\\s*[0-9]+\\s*/\\s*[-+]?\\s*[0-9]+\\s*|\\s*[-+]?\\s*[0-9]+\\s*)\\s+([+*/-])\\s+(\\s*[-+]?\\s*[0-9]+\\s*/\\s*[-+]?\\s*[0-9]+\\s*|\\s*[-+]?\\s*[0-9]+\\s*)" THEN
//             SET operation TO extracted operation from text
//             SET num1 TO extracted num1 from text
//             SET num2 TO extracted num2 from text

//             FOR each character i IN num1
//                 IF i = '/' THEN
//                     SET check TO TRUE
//                     CONTINUE
//                 END IF

//                 IF NOT check AND i != '+' AND i != ' ' THEN
//                     APPEND i TO numerator_1
//                 ELSE IF i != '+' AND i != ' ' THEN
//                     APPEND i TO denominator_1
//                 END IF
//             END FOR

//             FOR each character i IN num2
//                 IF i = '/' THEN
//                     SET check1 TO TRUE
//                     CONTINUE
//                 END IF

//                 IF NOT check1 AND i != '+' AND i != ' ' THEN
//                     APPEND i TO numerator_2
//                 ELSE IF i != '+' AND i != ' ' THEN
//                     APPEND i TO denominator_2
//                 END IF
//             END FOR

//             SET numerator1 TO CONVERT_TO_INTEGER(numerator_1)
//             SET numerator2 TO CONVERT_TO_INTEGER(numerator_2)

//             IF denominator_1 != "" THEN
//                 SET denominator1 TO CONVERT_TO_INTEGER(denominator_1)
//             END IF

//             IF denominator_2 != "" THEN
//                 SET denominator2 TO CONVERT_TO_INTEGER(denominator_2)
//             END IF

//             IF operation = '/' THEN
//                 IF denominator1 != 0 AND denominator2 != 0 AND numerator2 != 0 THEN
//                     BREAK
//                 ELSE
//                     OUTPUT "Please don't enter a zero in the denominator."
//                 END IF
//             ELSE
//                 IF denominator1 != 0 AND denominator2 != 0 THEN
//                     BREAK
//                 ELSE
//                     OUTPUT "Please don't enter a zero in the denominator."
//                 END IF
//             END IF
//         ELSE
//             OUTPUT "Please enter with the defined formula and don't enter a zero in the denominator."
//         END IF
//     END WHILE

//     SWITCH operation
//         CASE '+':
//             SET numerator_result TO (numerator1 * denominator2) + (numerator2 * denominator1)
//             SET denominator_result TO denominator1 * denominator2

//             IF numerator_result % denominator_result = 0 THEN
//                 SET numerator_result TO numerator_result / denominator_result
//                 SET denominator_result TO 1
//             END IF

//             CALL simple(numerator_result, denominator_result)
//             BREAK

//         CASE '-':
//             SET numerator_result TO (numerator1 * denominator2) - (numerator2 * denominator1)
//             SET denominator_result TO denominator1 * denominator2

//             IF numerator_result % denominator_result = 0 THEN
//                 SET numerator_result TO numerator_result / denominator_result
//                 SET denominator_result TO 1
//             END IF

//             CALL simple(numerator_result, denominator_result)
//             BREAK

//         CASE '*':
//             SET numerator_result TO numerator1 * numerator2
//             SET denominator_result TO denominator1 * denominator2

//             IF numerator_result % denominator_result = 0 THEN
//                 SET numerator_result TO numerator_result / denominator_result
//                 SET denominator_result TO 1
//             END IF

//             CALL simple(numerator_result, denominator_result)
//             BREAK

//         CASE '/':
//             SET numerator_result TO numerator1 * denominator2
//             SET denominator_result TO denominator1 * numerator2

//             IF denominator_result = 0 THEN
//                 BREAK
//             END IF

//             IF numerator_result % denominator_result = 0 THEN
//                 SET numerator_result TO numerator_result / denominator_result
//                 SET denominator_result TO 1
//             END IF

//             CALL simple(numerator_result, denominator_result)
//             BREAK
//     END SWITCH

//     WHILE true
//         OUTPUT "Do you want to continue?"
//         OUTPUT "[1] Yes."
//         OUTPUT "[2] No."
//         OUTPUT "Enter Your Choice: "
//         READ continue_or

//         IF continue_or = "1" THEN
//             BREAK
//         ELSE IF continue_or = "2" THEN
//             OUTPUT "Thanks For Using Rational Number Calculator ...."
//             RETURN 0
//         ELSE
//             OUTPUT "Please enter a valid choice !!"
//         END IF
//     END WHILE
// END FUNCTION

// ==========================================================Main Code===================================================================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// function for simplifing
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
    cout << "# ===== Welcome to Rational Numbers Calculator ===== #" << endl;
    cout << "--> In this calculator we will enter two fractional number and make addition, subtraction, multiplication and division " << endl;
    cout << "    to give you the answer of your equation." << endl;
    cout << "--> The form that you will enter must be like that [num/num (+, -, * or /) num/num]." << endl;
    cout << "Note : space after the the fractional number is important." << endl;
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
                        cout << "please don't enter a zero in the denominator." << endl;
                }
                else{
                    if(denominator1 != 0 && denominator2 != 0) 
                        break;
                    else
                        cout << "please don't enter a zero in the denominator." << endl;
                }
            }

            else
                cout << "Please enter with the defined formula and don't enter a zero in the denominator." << endl;
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
