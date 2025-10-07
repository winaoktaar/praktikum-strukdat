#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Fungsi untuk menambahkan elemen ke stack
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

// Fungsi untuk mengeluarkan elemen dari stack
char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

// Fungsi untuk membalik string menggunakan stack
string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = "";

    // 1. ini Push semua karakter ke stack
    for (char c : s) {
        push(stackTop, c);
    }

    // 2. Pop semua karakter dari stack dan gabungkan ke string hasil
    while (stackTop != nullptr) {
        reversed += pop(stackTop);
    }

    return reversed;
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; // Output: ataD rukurtS
    return 0;
}


// - Stack bersifat LIFO, jadi karakter terakhir masuk akan keluar lebih dulu.
// - Dengan menumpuk semua karakter, urutan terbalik terbentuk secara alami saat pop.
//             kurang lebih begitu sih bang, kalo ada salah saya mon maap :D