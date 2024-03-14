#include <bits/stdc++.h>
using namespace std;

//check the validity of the entered numbers
void validity(){


}

//function for Rational Number Calculator
string R_N_C(){



}

//main application
int main(){
    while (true)
    {
        cout << "# ===== Welcome To Our Application ===== #\nWhat do you want to do?\n [1] Rational Number Calculator.\n [2] Exit Program.\nEnter Your Choice: ";
        int choice;
        cin>> choice;
        while ((cin.fail())||(choice!= 1 && choice!= 2)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<< "Invalid input."<<endl;
            cout<< "Please enter a valid choice: ";
            cin>>choice;
        }  
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if(choice == 1){
            






            int choice2;
            cout << "Do you want to continue?\n[1]Yes.\n[2]No.\nChoice: ";
            cin >> choice2;
            while ((cin.fail())||(choice!= 1 && choice!= 2)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<< "Invalid input."<<endl;
                cout<< "Please enter a valid choice: ";
                cin>>choice;
            }  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(choice2 == 1)
                continue;
            else if(choice2 == 2)
                break;
        }
        if(choice == 2)
            break;
    }
    cout << "Thanks for using our application..."<<endl;
    return 0;
}
