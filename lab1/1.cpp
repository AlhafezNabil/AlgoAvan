
#include <iostream>
#include <vector>
#include <fstream>

#include <iostream>

using namespace std;

int main1() {
    int t;
    cin >> t;

    while (t--) {
        long long int xP, yP, xQ, yQ, xR, yR;
        cin >> xP >> yP >> xQ >> yQ >> xR >> yR;

        long long int produs_vectorial = (long long) (xQ - xP) * (yR - yP) - (long long) (xR - xP) * (yQ - yP);

        if (produs_vectorial < 0) {
            cout << "RIGHT\n";
        } else if (produs_vectorial > 0) {
            cout << "LEFT\n";
        } else {
            cout << "TOUCH\n";
        }
    }

    return 0;
}