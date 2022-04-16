#include <bits/stdc++.h>

using namespace std;

class FalsePositionMethod {
private:
    double epsilon = 0.0001;
    double lower, upper;

    double function(double x) {
        return x * x * x + x * x - 1;
    }
public:
    double root;
    
    void solve() {
        srand((int)time(0));
        while(true) {
            lower = -9 + rand() % 10;
            upper = rand() % 10;
            if (function(lower) * function(upper) <= 0) {
                break;
            }
        }
        if (lower > upper) swap(lower, upper);
        double previousRoot = 1000;
        while (true) {
            root = upper - (function(upper) * (upper - lower)) / (function(upper) - function(lower));
            if (function(root) * function(lower) <= 0) {
                upper = root;
            }   
            else if (function(root) == 0.0) {
                break;
            }
            else {
                lower = root;
            }
            if (abs((root - previousRoot) / root) < epsilon) {
                break;
            }
            previousRoot = root;
        }
        cout << "The root is " << root << "\n";
    }
};

int main() {
    FalsePositionMethod x = FalsePositionMethod();
    x.solve();
    return 0;
}
