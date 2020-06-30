#include <iostream>
#include <string>

using namespace std;

int cube[8];
string ans = "";
string dict[8] = {"A", "B", "C", "D", "E", "F", "G", "H"};

void inc(int i, int i1, int i2);

void dec(int first, int second, int num) {
    if (cube[second]>cube[first]){
        inc(first, num,cube[second]-cube[first]);
    }

    for (int i = 0; i < cube[second]; i++) {
        ans = ans + dict[second] + dict[first] + "-\n" ;
    }
    cube[first] -= cube[second];
    cube[second] -= cube[second];

}


void inc(int first, int second, int num) {

    for (int i = 0; i < num; i++) {
        ans = ans + dict[second] + dict[first] + "+\n";
    }
    cube[second] += num;
    cube[first] += num;
}

int main() {
    for (int i = 0; i < 8; i++){
        cin >> cube[i];

    }
    if (cube[0] + cube[2] + cube[5] + cube[7] != cube[1] + cube[3] + cube[4] + cube[6] ){
        cout<< "IMPOSSIBLE";
        return 0;
    }


    dec(0, 3, 1);
    dec(0, 4, 1);
    dec(1, 0, 5);
    dec(5, 1, 6);
    dec(6, 5, 2);
    dec(6, 7, 2);
    dec(6, 2, 0);
    cout<<ans;

    return 0;
}