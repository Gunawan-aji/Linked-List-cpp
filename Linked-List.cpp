#include <iostream>
#include <string>

using namespace std;


// ======================================================
// STRUCT NODE
// ======================================================
// Node merupakan bagian utama dari Linked List.
//
// Setiap node memiliki 2 bagian:
// 1. video -> menyimpan data/nama video
// 2. next  -> pointer yang menunjuk ke node berikutnya
//
// Bentuknya:
//
// +------------------+------------------+
// |      video       |       next       |
// +------------------+------------------+
// |    "Video A"     |  -> Node berikut |
// +------------------+------------------+
// ======================================================

struct Node
{
    // Menyimpan nama video
    string video;

    // Pointer yang menunjuk ke node berikutnya
    Node* next;
};


// ======================================================
// FUNGSI MENAMPILKAN LINKED LIST
// ======================================================
// Fungsi ini digunakan untuk melakukan traversal.
//
// Traversal adalah proses mengunjungi node satu per satu
// mulai dari head sampai node terakhir.
//
// Contoh:
//
// head
//   |
//   v
// [A] -> [B] -> [C] -> nullptr
// ======================================================

void tampilkanList(Node* head)
{
    // Membuat pointer sementara yang dimulai dari head
    Node* current = head;

    cout << "\n=== DATA LINKED LIST ===" << endl;

    // Perulangan dilakukan selama current
    // tidak menunjuk ke nullptr
    while (current != NULL)
    {
        // Menampilkan data video
        cout << current->video;

        // Jika masih ada node berikutnya,
        // tampilkan tanda panah
        if (current->next != NULL)
        {
            cout << " -> ";
        }

        // Pindah ke node berikutnya
        current = current->next;
    }

    // Menandakan bahwa linked list sudah berakhir
    cout << " -> nullptr" << endl;
}


// ======================================================
// FUNGSI MENAMBAHKAN NODE DI AKHIR
// ======================================================
// Operasi ini disebut APPEND.
//
// Node baru akan ditambahkan setelah node terakhir.
//
// Contoh:
//
// Sebelum:
// A -> B -> C -> nullptr
//
// Tambah D:
//
// Sesudah:
// A -> B -> C -> D -> nullptr
// ======================================================

void tambahAkhir(Node*& head, string namaVideo)
{
    // Membuat node baru menggunakan dynamic memory
    Node* nodeBaru = new Node;

    // Mengisi data video
    nodeBaru->video = namaVideo;

    // Karena node baru menjadi node terakhir,
    // maka next harus nullptr
    nodeBaru->next = NULL;


    // Jika linked list masih kosong
    if (head == NULL)
    {
        // Node baru langsung menjadi head
        head = nodeBaru;

        return;
    }


    // Membuat pointer sementara
    // untuk mencari node terakhir
    Node* current = head;

    // Berjalan sampai menemukan node terakhir
    while (current->next != NULL)
    {
        current = current->next;
    }


    // Menghubungkan node terakhir
    // dengan node baru
    current->next = nodeBaru;
}


// ======================================================
// FUNGSI MENAMBAHKAN NODE DI DEPAN
// ======================================================
// Operasi ini disebut PREPEND.
//
// Node baru akan ditempatkan sebelum node pertama.
//
// Contoh:
//
// Sebelum:
// A -> B -> C -> nullptr
//
// Tambah X:
//
// Sesudah:
// X -> A -> B -> C -> nullptr
// ======================================================

void tambahDepan(Node*& head, string namaVideo)
{
    // Membuat node baru
    Node* nodeBaru = new Node;

    // Mengisi data video
    nodeBaru->video = namaVideo;

    // Node baru menunjuk ke head lama
    nodeBaru->next = head;

    // Head dipindahkan ke node baru
    head = nodeBaru;
}


// ======================================================
// FUNGSI MENGHAPUS NODE
// ======================================================
// Fungsi ini digunakan untuk menghapus node berdasarkan
// nama video.
//
// Contoh:
//
// Sebelum:
// A -> B -> C -> nullptr
//
// Hapus B:
//
// Sesudah:
// A -> C -> nullptr
// ======================================================

void hapusNode(Node*& head, string namaVideo)
{
    // Jika linked list kosong
    if (head == NULL)
    {
        cout << "Linked List masih kosong!" << endl;
        return;
    }


    // --------------------------------------------------
    // KASUS 1: NODE YANG DIHAPUS ADALAH HEAD
    // --------------------------------------------------

    if (head->video == namaVideo)
    {
        // Menyimpan node head lama
        Node* temp = head;

        // Head dipindahkan ke node berikutnya
        head = head->next;

        // Menghapus node lama dari memory
        delete temp;

        cout << "Node berhasil dihapus!" << endl;

        return;
    }


    // --------------------------------------------------
    // KASUS 2: NODE BERADA DI TENGAH / AKHIR
    // --------------------------------------------------

    // Pointer untuk mencari node
    // sebelum node yang akan dihapus
    Node* current = head;


    // Mencari node sebelum target
    while (
        current->next != NULL &&
        current->next->video != namaVideo
    )
    {
        current = current->next;
    }


    // Jika node tidak ditemukan
    if (current->next == NULL)
    {
        cout << "Video tidak ditemukan!" << endl;
        return;
    }


    // Menyimpan node yang akan dihapus
    Node* temp = current->next;

    // Melewati node yang akan dihapus
    current->next = temp->next;

    // Menghapus node dari memory
    delete temp;


    cout << "Node berhasil dihapus!" << endl;
}


// ======================================================
// FUNGSI MENGHAPUS SELURUH LINKED LIST
// ======================================================
// Fungsi ini digunakan untuk membersihkan semua node
// yang dibuat menggunakan "new".
//
// Hal ini penting agar tidak terjadi memory leak.
// ======================================================

void hapusSemua(Node*& head)
{
    // Selama masih terdapat node
    while (head != NULL)
    {
        // Menyimpan node yang sedang menjadi head
        Node* temp = head;

        // Memindahkan head ke node berikutnya
        head = head->next;

        // Menghapus node lama
        delete temp;
    }
}


// ======================================================
// PROGRAM UTAMA
// ======================================================

int main()
{
    // ==================================================
    // MEMBUAT LINKED LIST
    // ==================================================
    // Pada awal program, linked list masih kosong.
    //
    // head = nullptr berarti belum ada node.
    // ==================================================

    Node* head = NULL;


    // ==================================================
    // MEMBUAT NODE SEPERTI CONTOH PADA PDF
    // ==================================================
    // PDF memberikan contoh:
    //
    // Node 1 = "Video A"
    // Node 2 = "Video B"
    // Node 3 = "Video C"
    //
    // Kemudian node-node tersebut dihubungkan.
    // ==================================================

    Node* node1 = new Node;
    Node* node2 = new Node;
    Node* node3 = new Node;


    // Mengisi data masing-masing node
    node1->video = "Video A";
    node2->video = "Video B";
    node3->video = "Video C";


    // Menghubungkan node pertama ke node kedua
    node1->next = node2;

    // Menghubungkan node kedua ke node ketiga
    node2->next = node3;

    // Node ketiga merupakan node terakhir
    node3->next = NULL;


    // Menjadikan node pertama sebagai head
    head = node1;


    // ==================================================
    // MENAMPILKAN LINKED LIST AWAL
    // ==================================================

    cout << "==========================================" << endl;
    cout << "       PROGRAM LINKED LIST C++" << endl;
    cout << "==========================================" << endl;

    cout << "\nLinked List awal:" << endl;

    tampilkanList(head);


    // ==================================================
    // OPERASI APPEND
    // ==================================================
    // Menambahkan "Video D" ke bagian akhir.
    // ==================================================

    cout << "\n\n=== TAMBAH DI AKHIR (APPEND) ===" << endl;

    tambahAkhir(head, "Video D");

    tampilkanList(head);


    // ==================================================
    // OPERASI PREPEND
    // ==================================================
    // Menambahkan "Video Baru" ke bagian depan.
    // ==================================================

    cout << "\n\n=== TAMBAH DI DEPAN (PREPEND) ===" << endl;

    tambahDepan(head, "Video Baru");

    tampilkanList(head);


    // ==================================================
    // OPERASI DELETE
    // ==================================================
    // Menghapus node yang memiliki data "Video B".
    // ==================================================

    cout << "\n\n=== HAPUS NODE ===" << endl;

    hapusNode(head, "Video B");

    tampilkanList(head);


    // ==================================================
    // MEMBERSIHKAN MEMORY
    // ==================================================
    // Semua node yang dibuat menggunakan "new"
    // harus dihapus menggunakan "delete".
    // ==================================================

    hapusSemua(head);

    cout << "\n\nSemua node telah dihapus." << endl;


    // Program selesai
    return 0;
}
