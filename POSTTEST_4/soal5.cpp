#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void exchangeHeadAndTail(Node *&head_ref) {
    // Jika kosong atau hanya 1 elemen tidak ada yang perlu ditukar
    if (head_ref == nullptr || head_ref->next == head_ref) return;

    Node* head = head_ref;
    Node* tail = head_ref->prev;

    // Jika hanya 2 node, cukup ubah head_ref ke tail (node tetap saling terhubung)
    if (head->next == tail && tail->next == head) {
        head_ref = tail;
        return;
    }

    // Simpan referensi yang diperlukan sebelum merubah pointer
    Node* headNext = head->next;   // node setelah head (akan menjadi node ke-2 setelah swap)
    Node* tailPrev = tail->prev;   // node sebelum tail (akan menjadi node ke-(n-1) setelah swap)

    // Lakukan relink sesuai target:
    // After swap: tail becomes head, sequence: tail -> headNext ... tailPrev -> head -> back to tail

    // 1) head (yang akan jadi tail baru)
    head->next = tail;     // H->next = T (H menjadi elemen terakhir, next ke new head)
    head->prev = tailPrev; // H->prev = Tp

    // 2) tail (yang akan jadi head baru)
    tail->next = headNext; // T->next = Hn
    tail->prev = head;     // T->prev = H

    // 3) perbaiki tetangga langsung
    headNext->prev = tail; // Hn->prev = T
    tailPrev->next = head; // Tp->next = H

    // 4) update head_ref ke tail (karena tail jadi node pertama sekarang)
    head_ref = tail;
}

void printList(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

void insertEnd(Node *&head_ref, int data) {
    Node *newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main() {
    Node *head = nullptr;

    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    printList(head); 

    return 0;
}