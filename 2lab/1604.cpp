#include <iostream>

using namespace std;

struct Sign{
    int count;
    int index;
};

int main() {

    int k;
    cin >> k;

    Sign *signs = new Sign[k];
    int maxCount = 0;
    int minCount = INT_MAX;
    int maxIndex = 0;
    int minIndex = 0;

    for(int i=0; i<k; i++) {

        cin >> signs[i].count;
        signs[i].index = i + 1;

        if (signs[i].count >= maxCount) {
            maxCount = signs[i].count;
            maxIndex = i;
        }
        if (signs[i].count < minCount) {
            minCount = signs[i].count;
            minIndex = i;
        }
    }

    while (minIndex != maxIndex && minCount != INT_MAX) {
        cout << signs[maxIndex].index << " " << signs[minIndex].index << " ";
        signs[maxIndex].count --;
        signs[minIndex].count --;
        maxCount = 0;
        minCount = INT_MAX;
        for (int i = 0; i < k; i++) {
            if (signs[i].count != 0 && signs[i].count >= maxCount) {
                maxCount = signs[i].count;
                maxIndex = i;
            }
            if (signs[i].count != 0 && signs[i].count < minCount) {
                minCount = signs[i].count;
                minIndex = i;
            }
        }
    }

    for (int i = 0; i < maxCount; i++) {
        cout << signs[maxIndex].index << " ";
    }

    return 0;

}