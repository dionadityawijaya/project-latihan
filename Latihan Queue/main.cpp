#include <iostream>

// Struktur Node untuk menyimpan data dan pointer ke node berikutnya
template <typename T>
struct Node {
    T data;            // Data yang disimpan dalam node
    Node* next;        // Pointer ke node berikutnya
    Node(T value) : data(value), next(nullptr) {}  // Konstruktor untuk inisialisasi
};

// Kelas Queue dengan template
template <typename T>
class Queue {
private:
    Node<T>* frontNode; // Pointer ke node paling depan
    Node<T>* rearNode;  // Pointer ke node paling belakang
    int count;          // Menghitung jumlah elemen dalam queue

public:
    // Konstruktor untuk inisialisasi queue
    Queue() : frontNode(nullptr), rearNode(nullptr), count(0) {}

    // Destructor untuk membersihkan memori
    ~Queue() {
        while (!isEmpty()) {
            dequeue();  // Hapus semua elemen saat objek Queue dihancurkan
        }
    }

    // Metode untuk menambahkan elemen ke antrian
    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);  // Buat node baru dengan nilai yang diberikan

        if (isEmpty()) {
            frontNode = rearNode = newNode;  // Jika antrian kosong, depan dan belakang mengarah ke node baru
        } else {
            rearNode->next = newNode;  // Sambungkan node baru ke node belakang
            rearNode = newNode;        // Update rearNode ke node baru
        }
        count++;  // Tambah jumlah elemen
    }

    // Metode untuk menghapus elemen dari antrian
    void dequeue() {
        if (isEmpty()) {
            std::cerr << "Antrian kosong. Tidak bisa menghapus elemen.\n";  // Error jika antrian kosong
            return;
        }

        Node<T>* temp = frontNode;   // Simpan node depan sementara
        frontNode = frontNode->next; // Update frontNode ke node berikutnya
        delete temp;                 // Hapus node depan dari memori
        count--;                     // Kurangi jumlah elemen

        if (frontNode == nullptr) {
            rearNode = nullptr;  // Jika antrian kosong setelah dequeue, rearNode juga diupdate
        }
    }

    // Metode untuk melihat elemen paling depan tanpa menghapusnya
    T front() const {
        if (isEmpty()) {
            std::cerr << "Antrian kosong. Tidak ada elemen depan.\n";  // Error jika antrian kosong
            return T();  // Kembalikan nilai default dari tipe data
        }
        return frontNode->data;  // Kembalikan data dari node depan
    }

    // Metode untuk mengecek apakah antrian kosong
    bool isEmpty() const {
        return frontNode == nullptr;  // Antrian kosong jika frontNode adalah nullptr
    }

    // Metode untuk mendapatkan jumlah elemen dalam antrian
    int size() const {
        return count;  // Kembalikan jumlah elemen dalam antrian
    }
};

// Contoh penggunaan queue dengan input dari pengguna
int main() {
    Queue<int> q;  // Buat queue untuk tipe data int
    int input;     // Variabel untuk menyimpan input pengguna
    char pilihan;  // Variabel untuk menyimpan pilihan pengguna

    do {
        std::cout << "Masukkan angka untuk ditambahkan ke antrian: ";
        std::cin >> input;  // Ambil input dari pengguna
        q.enqueue(input);   // Tambahkan input ke dalam antrian

        std::cout << "Elemen depan saat ini: " << q.front() << std::endl;
        std::cout << "Ukuran antrian saat ini: " << q.size() << std::endl;

        std::cout << "Apakah Anda ingin menambahkan angka lagi? (y/n): ";
        std::cin >> pilihan;  // Ambil pilihan dari pengguna
    } while (pilihan == 'y' || pilihan == 'Y');

    // Menghapus elemen dari antrian
    while (!q.isEmpty()) {
        std::cout << "Menghapus elemen depan: " << q.front() << std::endl;
        q.dequeue();
    }

    return 0;
}
