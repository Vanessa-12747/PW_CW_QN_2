#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to get divisors in decreasing order
vector<int> getDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
        }
    }
    sort(divisors.rbegin(), divisors.rend()); // Sort in reverse order (decreasing)
    return divisors;
}

int main() {
    cout << "This program is designed to exhibit the positive divisors of positive integers supplied by you." << endl;
    cout << "The program will repeatedly prompt you to enter a positive integer." << endl;
    cout << "Each time you enter a positive integer, the program will print all the divisors of your integer in a column and in decreasing order." << endl;

    while (true) {
        int num;
        cout << "Please enter a positive integer: ";
        cin >> num;

        // Check if the entered number is positive
        while (num <= 0) {
            cout << num << " is not a positive integer." << endl;
            cout << "Please enter a positive integer: ";
            cin >> num;
        }

        // Get divisors
        vector<int> divisors = getDivisors(num);

        // Print divisors in decreasing order
        for (int divisor : divisors) {
            cout << divisor << endl;
        }

        // Ask if the user wants to try again
        char choice;
        cout << "Would you like to see the divisors of another integer (Y/N)? ";
        cin >> choice;

        while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
            cout << "Please respond with Y (or y) for yes and N (or n) for no." << endl;
            cout << "Would you like to see the divisors of another integer (Y/N)? ";
            cin >> choice;
        }

        if (choice == 'N' || choice == 'n') {
            cout << "Thank you for using the program!" << endl;
            break;
        }
    }

    return 0;
}
