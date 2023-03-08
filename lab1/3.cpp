

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

using namespace std;

const int N = 100005;

struct Point3 {
    int x, y;
};

Point3 p[N];

bool comp3(Point3 a, Point3 b) {
    if (a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

int orientation3(Point3 p, Point3 q, Point3 r) {
    long long int val = (long long int) (q.y - p.y) * (r.x - q.x) -
                        (long long int) (q.x - p.x) * (r.y - q.y);


    if (val == 0)
        return 0;

    return (val > 0) ? 1 : 2;
}

vector<Point3> convexHull3(Point3 points[], int n) {
    sort(points, points + n, comp3);
    int m = 0;
    vector<Point3> hull(2 * n);

    for (int i = 0; i < n; i++) {
        while (m >= 2 && orientation3(hull[m - 2], hull[m - 1], points[i]) != 1)
            m--;
        hull[m++] = points[i];
    }

    int k = m;
    for (int i = n - 2; i >= 0; i--) {
        while (m > k && orientation3(hull[m - 2], hull[m - 1], points[i]) != 1)
            m--;
        hull[m++] = points[i];
    }

    hull.resize(m);
    return hull;
}

int main3() {
    ifstream cin("/Users/nabil.alhafez/CLionProjects/AlgoAvan/lab1/TestePubliceLab1/acoperire/stelat10.in");
    ifstream fout("/Users/nabil.alhafez/CLionProjects/AlgoAvan/lab1/TestePubliceLab1/acoperire/stelat10.out");

    int n;

    cin >> n;


    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;

    vector<Point3> hull = convexHull3(p, n);

//    int expectedSize;
//    fout >> expectedSize;
//    // Verify if calculated answer matches expected answer
//    if (expectedSize == hull.size()) {
//        cout << "Test passed" << endl;
//    } else {
//        cout << "Test failed: " << hull.size() << " " << expectedSize << endl;
//    }
//    cin.close();
//    fout.close();

//    cout << hull.size() - 1 << endl;
//    for (int i = hull.size() - 2; i >= 0; i--)
//        cout << hull[i].x << " " << hull[i].y << endl;

    return 0;
}