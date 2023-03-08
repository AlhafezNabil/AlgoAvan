//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//#define ll long long
//
//using namespace std;
//
//bool compareInterval(pair<int, int> doc1, pair<int, int> doc2) {
//    return (doc1.second - doc1.first + 1) > (doc2.second - doc2.first - 1);
//}
//
//int main() {
//
//    int t;
//    int a, b;
//    cin >> a >> b;
//    vector<pair<int, int>> doctors;
//    vector<pair<int, int>> res;
//    cin >> t;
//    int N = t;
//    while (t--) {
//        ll x, y;
//        cin >> x >> y;
//        doctors.emplace_back(x, y);
//    }
//    sort(doctors.begin(), doctors.end(), compareInterval);
//    for (auto ans: doctors) {
//        doctors;
//        cout << ans.first << ' ' << ans.second << endl; }
//
//    return 0;
//}
