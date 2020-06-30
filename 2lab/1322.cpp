#include <iostream>
#include <string>

using namespace std;

int main() {

    string str;
    int k;
    cin >> k;
    cin >> str;

    int N = str.size();
    int M = 1000000;
    k--;

    int *count = new int[M];
    int *t = new int[M];

    for (int i = 0; i < M; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        count[str[i]]++;
    }

    int sum = 0;
    for (int i = 0; i < M; i++) {
        sum += count[i];
        count[i] = sum - count[i];
    }

    for (int i = 0; i < N; i++) {
        t[count[str[i]]] = i;
        count[str[i]]++;
    }

    int j = t[k];
    char *result = new char[N];
    for (int i = 0; i < N; i++) {
        result[i] = str[j];
        j = t[j];
    }

    for (int i = 0; i < N; i++) {
        cout << result[i];
    }


    return 0;
}
