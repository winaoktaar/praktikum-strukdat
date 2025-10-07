#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

// Menambahkan dokumen ke antrian
void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};
    if (front == nullptr) { // Jika queue kosong
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Menghapus dokumen dari antrian
string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // Queue kosong

    Node* temp = front;
    string doc = temp->document;
    front = front->next;

    if (front == nullptr) rear = nullptr; // Jika queue kosong setelah dequeue
    delete temp;
    return doc;
}

// ini untuk memproses semua dokumen di antrian
void processAllDocuments(Node*& front, Node*& rear) {
    while (front != nullptr) {
        string doc = dequeue(front, rear);
        cout << "Memproses: " << doc << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}


// - Queue FIFO: data pertama masuk -> pertama keluar.
// - Front menunjuk elemen pertama (yang keluar duluan).
// - Rear menunjuk elemen terakhir (tempat data baru masuk).