#include <iostream>
using namespace std;

// Function to check if two line segments overlap
bool overlapLineCheck(double x1, double x2, double x3, double x4) {
    // Ensure x1 is less than x2 and x3 is less than x4
    if (x1 > x2) {
        swap(x1, x2);
    }
    if (x3 > x4) {
        swap(x3, x4);
    }
    if (x1 > x3) {
        swap(x1, x3);
        swap(x2, x4);
    }
    // Check for overlap conditions
    if ((x1 <= x3 && x2 >= x3) || (x3 <= x1 && x4 >= x1) || (x1 <= x4 && x2 >= x4) || (x3 <= x2 && x4 >= x2)) {
        return true; // partial overlap
    } else {
        return false;
    }
}

// Function to test overlapLineCheck function
void test(bool (*overlapLineCheck)(double,double,double,double), double x1, double x2, double x3, double x4) {
    if (overlapLineCheck(x1, x2, x3, x4)) {
        cout << "Overlap" << endl;
    } else {
        cout << "Do not Overlap" << endl;
    }
}

// Main function
int main() {
    // Input for line segments
    pair<double, double> line1;
    pair<double, double> line2;
    cin >> line1.first >> line1.second;
    cin >> line2.first >> line2.second;
    
    // Check if the line segments overlap
    string points = overlapLineCheck(line1.first, line1.second, line2.first, line2.second) ? "overlap" : "do not overlap";
    cout << points << "\n";
    
    // Run test cases
    test(overlapLineCheck, 1, 5, 2, 6);
    test(overlapLineCheck, 1, 5, 6, 8);
    
    // Test case: Lines don't overlap
    test(overlapLineCheck,3, 7, 8, 10);

    // Test case: Lines overlap
    test(overlapLineCheck,1, 5, 3, 7);

    // Test case: x1 > x2 and x3 > x4, but lines overlap
    test(overlapLineCheck,7, 3, 8, 5);

    // Test case: x1 > x2 and x3 > x4, lines don't overlap
    test(overlapLineCheck,7, 3, 10, 8);

    // Test case: Negative values of x's, lines overlap
    test(overlapLineCheck,-3, -7, -8, -10);

    // Test case: One of the points is common, lines don't overlap
    test(overlapLineCheck,0, 4, 4, 8);

    // Test case: Line lies between 1st and 2nd coordinate, lines overlap
    test(overlapLineCheck,-1, 4, 0, 2);

    // Test case: Line 1 lies between Line 2, lines overlap
    test(overlapLineCheck,-1, 4, -2, 6);


    return 0;
}
