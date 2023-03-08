#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


struct Point2 {
    long long int x, y;
};

int orientation2(Point2 p1, Point2 p2, Point2 p3) {
    long long int val = (long long int) (p2.y - p1.y) * (p3.x - p2.x) - (long long int) (p2.x - p1.x) * (p3.y - p2.y);
    if (val == 0) return 0;  // colinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}


void solve2() {
    int n;
//    ifstream cin("/Users/nabil.alhafez/CLionProjects/AlgoAvan/lab1/TestePubliceLab1/roby/roby12.in");
//    ifstream fout("/Users/nabil.alhafez/CLionProjects/AlgoAvan/lab1/TestePubliceLab1/roby/roby12.out");

    cin >> n;

    vector<Point2> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    int left_turns = 0, right_turns = 0, straight = 0;
    for (int i = 0; i < n - 2; i++) {
        int o = orientation2(points[i], points[i + 1], points[i + 2]);
        if (o == 0) {
            straight++;
        } else if (o == 1) {
            right_turns++;
        } else {
            left_turns++;
        }
    }
    // check orientation of last two points to determine final turn
    int o = orientation2(points[n - 2], points[n - 1], points[0]);
    if (o == 0) {
        straight++;
    } else if (o == 1) {
        right_turns++;
    } else {
        left_turns++;
    }

//    int expectedLeftTurns, expectedRightTurns, expectedSameDir;
//    fout >> expectedLeftTurns >> expectedRightTurns >> expectedSameDir;
//    fout.close();
//    // Verify if calculated answer matches expected answer
//    if (left_turns == expectedLeftTurns && right_turns == expectedRightTurns && straight == expectedSameDir) {
//        cout << "Test passed" << endl;
//    } else {
//        cout << "Test failed" << endl;
//        cout << "Expected answer: " << expectedLeftTurns << " " << expectedRightTurns << " " << expectedSameDir << endl;
//        cout << "Calculated answer: " << left_turns << " " << right_turns << " " << straight << endl;
//    }
    cout << left_turns << " " << right_turns << " " << straight << endl;
}

int main2() {
    solve2();
    return 0;
}

