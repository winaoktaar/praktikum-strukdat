#include <bits/stdc++.h>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int N = 4; 
    vector<Mahasiswa> v;
    v.reserve(N);

    cout << "Input data " << N << " mahasiswa:\n";
    for (int i = 0; i < N; ++i) {
        Mahasiswa m;
        cout << "Mahasiswa ke-" << i+1 << ":\n";
        cout << "  Nama: ";
        getline(cin >> ws, m.nama); 
        cout << "  NIM: ";
        getline(cin, m.nim);
        cout << "  IPK: ";
        cin >> m.ipk;
        v.push_back(m);
    }

    sort(v.begin(), v.end(), [](const Mahasiswa &a, const Mahasiswa &b) {
        return a.ipk < b.ipk; 
    });

    cout << "\nDaftar mahasiswa setelah diurutkan (IPK ascending):\n";
    for (int i = 0; i < N; ++i) {
        cout << i+1 << ". Nama: " << v[i].nama
             << " | NIM: " << v[i].nim
             << " | IPK: " << fixed << setprecision(2) << v[i].ipk << "\n";
    }

    return 0;
}
