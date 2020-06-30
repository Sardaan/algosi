#include <iostream>
#include <stack>

using namespace std;

int findMax(int data[], int m, int max) {

    int x = 1;
    while (2*x < max) {
        if (data[x*2] >= m) {
            x *= 2;
        }
        else {
            m -= data[x*2];
            x = x * 2 + 1;
        }
    }

    if (data[x] == 2)
        return data[2*x+m-1];
    else
    if (data[2*x+1] == 0)
        return data[2*x];
    else
        return data[2*x+1];

}

int main() {
    int n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << 1;
        exit(0);

    }

    int max = 1;

    while (max < n)
        max <<= 1;

    int* data = new int[2*max];
    for (int i = 0; i < n; i++)
        data[max+i] = i + 1;

    for (int i = max - 1; i > 0; i--) {
        if (2 * i >= max) {
            data[i] = 0;
            if (data[2*i] != 0)
                data[i]++;

            if (data[2*i+1] != 0)
                data[i]++;
        }else
            data[i] = data[2*i] + data[2*i+1];
    }

    int prev = 0;
    while (n > 0) {
        prev = (prev + k - 1) % n;
        n--;
        int index = findMax(data, prev + 1, max);
        cout << index << " ";
        data[max+index-1] = 0;
        int j = max + index - 1;
        while (j > 1) {
            j /= 2;
            data[j]--;
        }

    }

    return 0;

}

