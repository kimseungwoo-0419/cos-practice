#include <iostream>

using namespace std;



int main(int argc, char *argv[])
{
    
    if(atoi(argv[1]) > atoi(argv[2]))
    {
        return 0;
    }

    int sum = 0;
    for(int i = atoi(argv[1]); i <= atoi(argv[2]); i++)
    {
        sum += i;
    }
    cout << sum << endl;
    return 0;
}