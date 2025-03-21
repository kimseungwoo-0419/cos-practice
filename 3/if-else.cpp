#include <iostream>

using namespace std;

int main(int argc, char *argv[]){

    int x{};

    cout << "Enter a numver:";
    cin >> x;
    if(x >= 0){
        cout << "You entered a positive interger!" << endl;
    }
    else{
        cout << "You entered a negative interger!" << endl;
        return 0;
    }

}