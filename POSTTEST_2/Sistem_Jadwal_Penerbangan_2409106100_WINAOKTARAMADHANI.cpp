#include <iostream>
#include <string>
#include <limits>
#include <unordered_map>
#include <cctype>

using namespace std;

const string USER_NAME = "Wina Okta Ramadhani";
const string USER_NIM  = "2409106100";

struct Node {
    string kodePenerbangan;
    string tujuan;
    string status;
    Node* next;
};

Node* head = nullptr;

unordered_map<string,int> baseCount;

string baseCode() {
    if (USER_NIM.size() >= 3)
        return "JT-" + USER_NIM.substr(USER_NIM.size() - 3);
    return "JT-" + USER_NIM;
}

string generateKode() {
    string base = baseCode();
    auto it = baseCount.find(base);
    if (it == baseCount.end()) {
        baseCount[base] = 0;
        return base;
    } else {
        baseCount[base]++;
        return base + "-" + to_string(baseCount[base]); 
    }
}

int insertionPositionByNIM() {
    if (USER_NIM.empty()) return 2;
    char last = USER_NIM.back();
    if (!isdigit(last)) return 2;
    int d = last - '0';
    if (d == 0) return 2;
    return d + 1;
}

bool isEmpty() {
    return head == nullptr;
}

void addFirst(const string& tujuan, const string& status) {
    string kode = generateKode();
    Node* nodeBaru = new Node{kode, tujuan, status, head};
    head = nodeBaru;
    cout << "Ditambahkan di depan: " << kode << " | " << tujuan << " | " << status << "\n";
}

void addLast(const string& tujuan, const string& status) {
    string kode = generateKode();
    Node* nodeBaru = new Node{kode, tujuan, status, nullptr};
    if (head == nullptr) {
        head = nodeBaru;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = nodeBaru;
    }
    cout << "Ditambahkan di akhir: " << kode << " | " << tujuan << " | " << status << "\n";
}

void addMiddle(const string& tujuan, const string& status, int posisi) {
    if (posisi <= 1 || head == nullptr) {
        addFirst(tujuan, status);
        return;
    }

    Node* temp = head;
    int hitung = 1;
    while (temp->next != nullptr && hitung < posisi - 1) {
        temp = temp->next;
        hitung++;
    }

    string kode = generateKode();
    Node* nodeBaru = new Node{kode, tujuan, status, temp->next};
    temp->next = nodeBaru;
    cout << "Disisipkan di posisi " << (hitung + 1) << ": " << kode << " | " << tujuan << " | " << status << "\n";
}

void deleteFirst() {
    if (head == nullptr) {
        cout << ">> LinkedList masih kosong <<\n";
        return;
    }
    Node* hapus = head;
    head = head->next;
    cout << "Dihapus (head): " << hapus->kodePenerbangan << " | " << hapus->tujuan << " | " << hapus->status << "\n";
    delete hapus;
}
void updateStatusByKode(const string& kode, const string& newStatus) {
    if (head == nullptr) {
        cout << "Daftar kosong.\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->kodePenerbangan == kode) {
            cout << "Sebelum: " << temp->kodePenerbangan << " | " << temp->tujuan << " | " << temp->status << "\n";
            temp->status = newStatus;
            cout << "Setelah:  " << temp->kodePenerbangan << " | " << temp->tujuan << " | " << temp->status << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Kode \"" << kode << "\" tidak ditemukan.\n";
}

void display() {
    if (head == nullptr) {
        cout << ">> LinkedList kosong <<\n";
        return;
    }
    Node* temp = head;
    int idx = 1;
    cout << "+---------------------------------------------------------+\n";
    cout << "|                  DAFTAR JADWAL PENERBANGAN              |\n";
    cout << "+---------------------------------------------------------+\n";
    while (temp != nullptr) {
        cout << idx << ". " << temp->kodePenerbangan << " | Tujuan: " << temp->tujuan
             << " | Status: " << temp->status << "\n";
        temp = temp->next;
        idx++;
    }
    cout << "+---------------------------------------------------------+\n";
}

void clearList() {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    cout << "Linked list berhasil dikosongkan.\n";
}

// --- UI helpers ---
void printHeader() {
    cout << "+------------------------------------------------------------+\n";
    cout << "|               FLIGHT SCHEDULE SYSTEM                       |\n";
    cout << "|  [ " << USER_NAME << " - " << USER_NIM << " ]";
    int printed = (int)USER_NAME.size() + 3 + (int)USER_NIM.size() + 3;
    int totalWidth = 60;
    for (int i = printed; i < totalWidth - 4; ++i) cout << ' ';
    cout << "|\n";
    cout << "+------------------------------------------------------------+\n";
}

void printMenu() {
    cout << " 1. Tambah Jadwal Penerbangan\n";
    cout << " 2. Sisipkan Jadwal Penerbangan (posisi personal berdasarkan NIM)\n";
    cout << " 3. Hapus Jadwal Paling Awal\n";
    cout << " 4. Update Status Penerbangan (berdasarkan kode)\n";
    cout << " 5. Tampilkan Semua Jadwal\n";
    cout << " 0. Keluar\n";
    cout << "+------------------------------------------------------------+\n";
    cout << "Pilih (0-5): ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int choice;
    while (true) {
        printHeader();
        printMenu();

        if (!(cin >> choice)) {
            cout << "Input tidak valid. Masukkan angka.\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 0) {
            cout << "Terima kasih. Keluar program.\n";
            break;
        }

        switch (choice) {
            case 1: {
                string tujuan, status;
                cout << "Masukkan tujuan: ";
                getline(cin, tujuan);
                if (tujuan.empty()) tujuan = "Tujuan tidak diisi";
                cout << "Masukkan status (contoh: Tepat Waktu / Terlambat / Naik Pesawat): ";
                getline(cin, status);
                if (status.empty()) status = "Tepat Waktu";
                addLast(tujuan, status);
                break;
            }
            case 2: {
                string tujuan, status;
                cout << "Masukkan tujuan untuk disisipkan: ";
                getline(cin, tujuan);
                if (tujuan.empty()) tujuan = "Tujuan tidak diisi";
                cout << "Masukkan status: ";
                getline(cin, status);
                if (status.empty()) status = "Tepat Waktu";
                int pos = insertionPositionByNIM();
                addMiddle(tujuan, status, pos);
                break;
            }
            case 3:
                deleteFirst();
                break;
            case 4: {
                string kode, newStatus;
                cout << "Masukkan kode penerbangan yang ingin diupdate (misal: JT-100 atau JT-100-1): ";
                getline(cin, kode);
                if (kode.empty()) { cout << "Kode kosong. Batal.\n"; break; }
                cout << "Masukkan status baru: ";
                getline(cin, newStatus);
                if (newStatus.empty()) newStatus = "Diperbarui";
                updateStatusByKode(kode, newStatus);
                break;
            }
            case 5:
                display();
                break;
            default:
                cout << "Pilihan tidak dikenali. Coba lagi.\n";
        }
        cout << "\n";
    }

    clearList();
    return 0;
}
