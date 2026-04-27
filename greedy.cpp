#include <iostream>
using namespace std;

void activitySelection(int start[], int finish[], int n) {
    cout << "Selected activities:\n";

    int i = 0;
    cout << i << " ";

    for (int j = 1; j < n; j++) {
        if (start[j] >= finish[i]) {
            cout << j << " ";
            i = j;
        }
    }
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = 6;

    activitySelection(start, finish, n);
}