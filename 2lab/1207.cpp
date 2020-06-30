#include <iostream>
#include <math.h>

using namespace std;

void bubbleSort(double angle[], int id[], int size){

    for(int i=0; i < size; i++) {
        for(int j = size-1; j > i; j-- ) {
            if ( angle[j-1] > angle[j] ) {
                swap(angle[j-1], angle[j]);
                swap(id[j-1], id[j]);
            }
        }
    }
}

int main() {

    int count;
    cin >> count;
    int *id = new int[count];
    double *x = new double [count];
    double *y = new double[count];
    double *angle = new double[count];
    for (int i = 0; i < count; i++) {
        cin >> x[i] >> y[i];
        id[i] = i + 1;
        if (x[i]<x[0]){
            swap(x[i], x[0]);
            swap(y[i], y[0]);
            swap(id[i], id[0]);

        }
    }
    angle[0] = -6.28;
    for (int i = 0; i < count; i++) {
        if (x[i]-x[0]!=0){
            angle[i] = atan((y[i]-y[0])/(x[i]-x[0]));
        }

        if (x[i]-x[0]==0 && y[i]-y[0]>0)
            angle[i] = 1.57;
        if (x[i]-x[0]==0 && y[i]-y[0]<0)
            angle[i] = -1.57;
    }
    bubbleSort(angle, id, count);

    cout<<id[0]<<" "<<id[count/2];

    return 0;
}