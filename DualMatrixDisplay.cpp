#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;

    cout << "Enter the number of rows and columns for your first array: ";
    cin >> a >> b;

    int arr1[a][b];

    cout << "Enter the values for the first array:" << endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> arr1[i][j];
        }
    }

    cout << "The values stored in the first array are:" << endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter the number of rows and columns for your second array: ";
    cin >> c >> d;

    int arr2[c][d];

    cout << "Enter the values for the second array:" << endl;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < d; j++) {
            cin >> arr2[i][j];
        }
    }

    cout << "The values stored in the second array are:" << endl;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < d; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
