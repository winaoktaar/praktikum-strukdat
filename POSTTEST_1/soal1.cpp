#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

void fillWithPrimes(vector<int> &arr, int count) {
    arr.clear();
    int num = 2;
    while ((int)arr.size() < count) {
        if (isPrime(num)) arr.push_back(num);
        ++num;
    }
}

void reverseArray(vector<int> &arr) { 
    reverse(arr.begin(), arr.end());
}

int main() {
    const int N = 7;
    vector<int> arr;
    fillWithPrimes(arr, N);

    cout << "Array sebelum dibalik:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n\n";

    reverseArray(arr);

    cout << "Array sesudah dibalik:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}

