#include <iostream>
#include <string>

using namespace std;

// Function to compare two version strings
string compareVersion(string version1, string version2) {
    // Initialize iterators for version strings
    int i = 0;
    int j = 0;
    // Iterate through version strings
    while (i < version1.size() || j < version2.size()) {
        // Initialize variables to store version numbers
        int n1 = 0;
        int n2 = 0;
        // Extract version number from version1 string
        while (i < version1.size() && version1[i] != '.') {
            n1 = n1 * 10 + (version1[i] - '0');
            i++;
        }
        // Extract version number from version2 string
        while (j < version2.size() && version2[j] != '.') {
            n2 = n2 * 10 + (version2[j] - '0');
            j++;
        }
        // Compare version numbers
        if (n1 > n2) {
            return "string 1 is greater than string 2";
        } else if (n2 > n1) {
            return "string 2 is greater than string 1";
        }
        // Move to the next version number
        i++;
        j++;
    }
    // Return equal if all version numbers are equal
    return "string 1 and string 2 are equal";
}

// Function to test compareVersion function
void test(string version1, string version2, string expected) {
    // Compare versions and check if result matches expected
    string ans = compareVersion(version1, version2);
    if (ans == expected)
        cout << "test case passed\n";
    else
        cout << "test case failed\n";
}

// Main function
int main() {
    string version1;
    string version2;
    // Input two version strings
    cin >> version1;
    cin >> version2;
    
    // Compare input versions
    string ans = compareVersion(version1, version2);
    // Print result
    cout << ans << "\n";
    
    // Run test cases
    test("1.2", "1.2", "string 1 and string 2 are equal");
    test("1.2", "1.2.0", "string 1 and string 2 are equal");
    test("1.2.0", "1.2", "string 1 and string 2 are equal");
    test("1.1", "1.2", "string 2 is greater than string 1");
    test("1.2", "1.1", "string 1 is greater than string 2");
    test("1.0.0", "1.0", "string 1 and string 2 are equal");
    
    return 0;
}
