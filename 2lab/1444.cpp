#include <iostream>
#include <cmath>

using namespace std;
#define PI 3.14159265358979323846

struct Point {
    double x, y, angle;
    int id;
    double len;
};

const int MAX_N = 30001;
Point point[MAX_N];

bool compare(Point p1, Point p2) {
    if (abs(p1.angle - p2.angle) >0) {
        return p1.angle < p2.angle;
    }

    return p1.len < p2.len;
}

void sort(int left, int right) {
    int i = left;
    int j = right;

    Point x = point[(left + right) / 2];

    while (i <= j) {
        while (compare(point[i], x)) {
            i++;
        }
        while (compare(x, point[j])) {
            j--;
        }

        if (i <= j) {
            swap(point[i], point[j]);

            i++;
            j--;
        }
    }

    if (i < right) {
        sort(i, right);
    }
    if (left < j) {
        sort(left, j);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> point[i].x;
        cin >> point[i].y;
        point[i].id = i;

        if (i == 0) {
            point[i].angle = INT64_MIN;
            point[i].len = 0;
            continue;
        }

        if (point[i].x == point[0].x) {
            point[i].angle = (point[i].y > point[0].y) ? 90 : -90;
            point[i].len = abs(point[i].y - point[0].y);
            continue;
        }

        point[i].angle = atan((double) (point[i].y - point[0].y) / (point[i].x - point[0].x)) * 180.0 / PI;
        if (point[i].x <= point[0].x) {
            point[i].angle -= 180;
        }

        point[i].len = abs(sqrt((double) (pow((point[i].x - point[0].x), 2) + pow((point[i].y - point[0].y), 2))));
    }

    sort(0, n - 1);

    double max_a = 360 + point[1].angle - point[n - 1].angle;
    int k = 1;

    for (int i = 1; i < n - 1; i++) {
        if (point[i + 1].angle - point[i].angle > max_a) {
            max_a = point[i + 1].angle - point[i].angle;
            k = i + 1;
        }
    }

    cout << n << endl;
    cout << 1 << endl;

    for (int i = k; i < n; i++) {
        cout << point[i].id + 1 << endl;
    }

    for (int i = 1; i < k; i++) {
        cout << point[i].id + 1 << endl;
    }

    return 0;
}