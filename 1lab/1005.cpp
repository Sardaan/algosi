#include <iostream>

using namespace std;


int findMin(int count, int sum1, int sum2, int values[]) {
    if (count == 0)
        return abs(sum1 - sum2);
    else {
        int first = findMin(count - 1, sum1 + values[count - 1], sum2, values);
        int second = findMin(count - 1, sum1, sum2 + values[count - 1], values);
        return min(first, second);
    }
}


int min(int x, int y) {
    return x < y ? x : y;
}

int main() {
    int count;
    cin >> count;
    int values[count];
    for (int i = 0; i < count; i++) {
        cin >> values[i];
    }
    cout << findMin(count, 0, 0, values);
}

