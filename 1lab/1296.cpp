#include <iostream>
using namespace std;

int main() {
    int count;
    cin >> count;
    int sum = 0;
    int potential = 0;
    for (int i = 0; i < count; i++) {

        int value;
        cin >> value;

        sum += value;

        if (sum<0){
            sum=0;
        }
        if (sum>potential){
            potential = sum;
        }
    }
    cout << potential;

    return 0;
}


