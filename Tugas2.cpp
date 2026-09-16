#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void tambahDepan(int nilai) {
    Node* baru = new Node{nilai, head};
    head = baru;
}

void tambahBelakang(int nilai) {
    Node* baru = new Node{nilai, nullptr};
    if (head == nullptr) {
        head = baru;
        return;
    }
    Node* cur = head;
    while (cur->next != nullptr) cur = cur->next;
    cur->next = baru;
}

void tambahSetelah(int nilaiAcuan, int nilaiBaru) {
    Node* cur = head;
    while (cur != nullptr && cur->data != nilaiAcuan) cur = cur->next;
    if (cur == nullptr) {
        cout << "Nilai " << nilaiAcuan << " tidak ditemukan!\n";
        return;
    }
    Node* baru = new Node{nilaiBaru, cur->next};
    cur->next = baru;
}

void hapusNilai(int nilai) {
    if (head == nullptr) return;

    if (head->data == nilai) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* cur = head;
    while (cur->next != nullptr && cur->next->data != nilai) cur = cur->next;

    if (cur->next == nullptr) {
        cout << "Nilai " << nilai << " tidak ditemukan!\n";
        return;
    }

    Node* temp = cur->next;
    cur->next = temp->next;
    delete temp;
}

void tampilkan() {
    Node* cur = head;
    cout << "Isi list: ";
    while (cur != nullptr) {
        cout << cur->data;
        if (cur->next != nullptr) cout << " -> ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    int dataAwal[10] = {100, 92, 45, 87, 71, 99, 95, 60, 55, 88};
    for (int i = 0; i < 10; i++) {
        tambahBelakang(dataAwal[i]);
    }

    cout << "Data awal:\n";
    tampilkan();
    cout << endl;

    tambahDepan(70);
    cout << "Setelah tambah 70 di depan:\n";
    tampilkan();
    cout << endl;

    tambahBelakang(50);
    cout << "Setelah tambah 50 di belakang:\n";
    tampilkan();
    cout << endl;

    tambahSetelah(45, 0);
    cout << "Setelah tambah 0 setelah 45:\n";
    tampilkan();
    cout << endl;

    hapusNilai(99);
    cout << "Setelah hapus 99:\n";
    tampilkan();
    cout << endl;

    hapusNilai(60);
    cout << "Setelah hapus 60:\n";
    tampilkan();
    cout << endl;

    return 0;
}
