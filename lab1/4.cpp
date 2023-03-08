
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
//#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    bool operator <(const Point& other) const {
        if (x < other.x)
            return true;
        else if (x == other.x)
            return y < other.y;
        else
            return false;
    }
};

double get_polar_angle(const Point& p1, const Point& p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return atan2(dy, dx);
}

vector<Point> graham_scan(const vector<Point>& points) {
    int n = points.size();
    vector<Point> hull;
    vector<Point> sorted_points = points;
    sort(sorted_points.begin(), sorted_points.end());
    hull.push_back(sorted_points[0]);
    hull.push_back(sorted_points[1]);
    for (int i = 2; i < n; i++) {
        while (hull.size() >= 2) {
            Point p2 = hull.back();
            hull.pop_back();
            Point p1 = hull.back();
            if (get_polar_angle(p1, sorted_points[i]) <= get_polar_angle(p1, p2)) {
                hull.push_back(p2);
                break;
            }
        }
        hull.push_back(sorted_points[i]);
    }
    return hull;
}

double dist(const Point& p1, const Point& p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

void prim(const vector<Point>& points, vector<vector<double>>& adj) {
    int n = points.size();
    vector<bool> mst(n, false);
    mst[0] = true;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> heap;
    for (int i = 1; i < n; i++) {
        double d = dist(points[0], points[i]);
        heap.push(make_pair(d, i));
    }
    while (!heap.empty()) {
        double d = heap.top().first;
        int u = heap.top().second;
        heap.pop();
        if (mst[u])
            continue;
        mst[u] = true;
        for (int v = 0; v < n; v++) {
            if (!mst[v]) {
                double w = dist(points[u], points[v]);
                adj[u][v] = adj[v][u] = w;
                heap.push(make_pair(w, v));
            }
        }
    }
}

void find_cycle(  vector<vector<double>>& adj, vector<int>& cycle) {
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> stack;
    stack.push_back(0);
    while (!stack.empty()) {
        int u = stack.back();
        bool found = false;
        for (int v = 0; v < n; v++) {
            if (adj[u][v] > 0) {
                stack.push_back(v);
                adj[u][v] = adj[v][u] = 0;
                found = true;
                break;
            }
        }
        if (!found) {
            cycle.push_back(u);
            stack.pop_back();
        }
    }
}


//int main() {
//    int n;
//    cin >>

int main() {
    int n;
    cin >> n;
    vector<Point> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    vector<Point> hull = graham_scan(points);
    int m = hull.size();
    vector<vector<double>> adj(m, vector<double>(m, 0));
    prim(hull, adj);
    vector<int> cycle;
    find_cycle(adj, cycle);
    int start = min_element(hull.begin(), hull.end(), [](const Point& p1, const Point& p2) { return p1.x < p2.x; }) - hull.begin();
    int i = 0;
    while (cycle[i] != start)
        i++;
    for (int j = i; j < i + m; j++) {
        int k = cycle[j % m];
        cout << hull[k].x << " " << hull[k].y << "\n";
    }
    return 0;
}

/*
gives wrong answer:
-10 -1
-10 -1
-10 -1

Filed on this test case:
10
6 10
0 5
4 -7
3 8
3 -8
-4 -2
-10 -1
0 -9
4 -3
-7 10

And the Right answer should be:
-10 -1
-4 -2
0 -9
3 -8
4 -7
4 -3
6 10
3 8
0 5
-7 10
-10 -1

 */