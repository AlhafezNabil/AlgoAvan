////#include <iostream>
////#include <vector>
////
////#define ll long long
////
////using namespace std;
////
////
////int main1() {
////
////    int t;
////    cin >> t;
////    vector<ll> res;
////    while (t--) {
////        ll a, b;
////        cin >> a >> b;
////        res.push_back(a + b);
////    }
////    for(auto ans : res)cout << ans << endl;
////    return 0;
////}
//#include <iostream>
//#include <vector>
//#include <fstream>
//
//
//#define ll long long int
//using namespace std;
//
//struct Point {
//    ll x, y;
//};
//
//void readCin(Point &p) {
//    cin >> p.x >> p.y;
//}
//
//void readCin(Point &p, ifstream &ff) {
//    ff >> p.x >> p.y;
//}
//
//void printP(Point &p) {
//    cout << p.x << " " << p.y << ' ';
//}
//// Alpha     = (y2 - y1) / (x2 -x1)
//// Prow      = (y3 - y2) / (x3 -x2)
//// Ans = Alpha - Prow
//
//// Orientation (y2 - y1) (x3 -x2) - (x2 -x1) (y3 - y2)
//
//// To find orientation of ordered triplet (p1, p2, p3).
//// The function returns following values
//// 0 --> p, q and r are collinear
//// 1 --> Clockwise right
//// 2 --> Counterclockwise left
//int orientation(Point p1, Point p2, Point p3) {
//    ll val = (p2.y - p1.y) * (p3.x - p2.x)
//             - (p2.x - p1.x) * (p3.y - p2.y);
//
//    if (val == 0)
//        return 0; // collinear
//
//    return (val > 0) ? 1 : 2; // clock or counterclock wise
//}
//
//int main() {
//    ifstream ff;
//    ff.open("testorientare11.in");  // open file
//
//    ifstream fo;
//    fo.open("testorientare11.out");  // open file
//
//    int t, tests;
//    cin >> t;
//    tests = t;
////    vector<Point> vec(t);
//
//    while (t--) {
//        Point p, r, q;
//        readCin(p, ff);
//        readCin(r, ff);
//        readCin(q, ff);
//
//        int o = orientation(p, r, q);
//        string ans;
//        string realAns;
//        if (o == 0)
//            ans = "TOUCH";
//        else if (o == 1)
//            ans = "RIGHT";
//        else
//            ans = "LEFT";
//        fo >> realAns;
//        if (ans != realAns) {
//            cout << "Answer not correct with t " << t << endl;
//        }
////        cout << ans << endl;
//    }
//    ff.close();
//    fo.close();
//
//    return 0;
//}


//# calculul produsului vectorial

//#include <iostream>
//#include <vector>
//
//#define ll long long
//
//using namespace std;
//
//
//int main1() {
//
//    int t;
//    cin >> t;
//    vector<ll> res;
//    while (t--) {
//        ll a, b;
//        cin >> a >> b;
//        res.push_back(a + b);
//    }
//    for(auto ans : res)cout << ans << endl;
//    return 0;
//}
#include <iostream>
using namespace std;
//
//int main() {
//    int t;
//    cin >> t;
//
//    while (t--) {
//        long long int xP, yP, xQ, yQ, xR, yR;
//        cin >> xP >> yP >> xQ >> yQ >> xR >> yR;
//
//        long long int produs_vectorial = (long long)(xQ - xP) * (yR - yP) - (long long)(xR - xP) * (yQ - yP);
//
//        if (produs_vectorial < 0) {
//            cout << "RIGHT\n";
//        } else if (produs_vectorial > 0) {
//            cout << "LEFT\n";
//        } else {
//            cout << "TOUCH\n";
//        }
//    }
//
//    return 0;
//}