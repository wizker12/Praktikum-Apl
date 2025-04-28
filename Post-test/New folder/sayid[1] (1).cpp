#include <iostream>
#include <string>
#include <algorithm> // Untuk fungsi sort
#include <cstdlib>   // Untuk system("cls") dan system("pause")

using namespace std;

// Definisi struct untuk menyimpan data tiket
struct Tiket {
    string namaPenumpang;
    int stasiunDipilih;
    int jumlahTiket;
    int totalHarga;
};

// Deklarasi fungsi dan prosedur
bool loginSystem();
void tampilkanMenu();
void tampilkanStasiunRute(const string* stasiun, const string* rute, const int* jumlahTiketStasiun, const int* harga, int JUMLAH_STASIUN);
void tampilkanTiketDipesan(const Tiket* tiket, const string* stasiun, const string* rute, int panjang);
void tambahTiket(Tiket* tiket, int* jumlahTiketStasiun, const int* harga, int* panjang, const string* stasiun, const string* rute, int MAX_TIKET, int JUMLAH_STASIUN);
void ubahTiket(Tiket* tiket, const int* harga, int panjang, const string* stasiun, const string* rute);
void hapusTiket(Tiket* tiket, int* jumlahTiketStasiun, int* panjang, const string* stasiun, const string* rute);
void hitungTotalHarga(Tiket* tiket, const int* harga);
void sortNamaAscending(Tiket* tiket, int panjang);
void sortTotalHargaDescending(Tiket* tiket, int panjang);
void bubbleSortJumlahTiketAscending(Tiket* tiket, int panjang);

int main() {
    const int MAX_TIKET = 100;
    const int JUMLAH_STASIUN = 5;

    // Data stasiun, rute, jumlah tiket, dan harga
    string stasiun[] = {"Stasiun UNMUL", "Stasiun AI", "Stasiun ISO", "Stasiun APL", "Stasiun Masjaya"};
    string rute[] = {"Samarinda-Balikpapan", "Samarinda-Tenggarong", "Balikpapan-Berau", "Balikpapan-Tanah Grogot", "Samarinda-Bontang"};
    int jumlahTiketStasiun[] = {10, 10, 10, 10, 10};
    int harga[] = {500000, 250000, 350000, 150000, 300000};

    Tiket tiket[MAX_TIKET];
    int panjang = 0;

    if (!loginSystem()) {
        cout << "Login gagal. Program berhenti.\n";
        system("pause");
        return 0;
    }

    int pilihan;
    do {
        system("cls"); // Bersihkan layar
        tampilkanMenu();
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore(); // Bersihkan buffer enter

        switch (pilihan) {
            case 1:
                tampilkanStasiunRute(stasiun, rute, jumlahTiketStasiun, harga, JUMLAH_STASIUN);
                break;
            case 2:
                tampilkanTiketDipesan(tiket, stasiun, rute, panjang);
                break;
            case 3:
                tambahTiket(tiket, jumlahTiketStasiun, harga, &panjang, stasiun, rute, MAX_TIKET, JUMLAH_STASIUN);
                break;
            case 4:
                ubahTiket(tiket, harga, panjang, stasiun, rute);
                break;
            case 5:
                hapusTiket(tiket, jumlahTiketStasiun, &panjang, stasiun, rute);
                break;
            case 6: {
                int sortChoice;
                cout << "Pilih metode sorting:\n";
                cout << "1. Sortir Nama (Ascending)\n";
                cout << "2. Sortir Total Harga (Descending)\n";
                cout << "3. Sortir Jumlah Tiket (Ascending) - Bubble Sort\n";
                cout << "Pilihan: ";
                cin >> sortChoice;

                switch (sortChoice) {
                    case 1:
                        sortNamaAscending(tiket, panjang);
                        cout << "Data berhasil disorting berdasarkan Nama (Ascending).\n";
                        break;
                    case 2:
                        sortTotalHargaDescending(tiket, panjang);
                        cout << "Data berhasil disorting berdasarkan Total Harga (Descending).\n";
                        break;
                    case 3:
                        bubbleSortJumlahTiketAscending(tiket, panjang);
                        cout << "Data berhasil disorting berdasarkan Jumlah Tiket (Ascending).\n";
                        break;
                    default:
                        cout << "Pilihan sorting tidak valid.\n";
                        break;
                }
                break;
            }
            case 7:
                cout << "Terima kasih telah menggunakan program!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }

        if (pilihan != 7) {
            system("pause"); // Tunggu user tekan tombol
        }

    } while (pilihan != 7);

    return 0;
}

// ---------------------- Fungsi Pendukung ----------------------

bool loginSystem() {
    string username, password;
    const string USER_VALID = "admin";
    const string PASS_VALID = "1234";
    int attempts = 3;

    while (attempts > 0) {
        system("cls");
        cout << "===== LOGIN =====\n";
        cout << "Username: ";
        getline(cin, username);
        cout << "Password: ";
        getline(cin, password);

        if (username == USER_VALID && password == PASS_VALID) {
            cout << "Login berhasil!\n";
            return true;
        } else {
            attempts--;
            cout << "Login salah! Sisa percobaan: " << attempts << endl;
            system("pause");
        }
    }
    return false;
}

void tampilkanMenu() {
    cout << "===== MENU UTAMA =====\n";
    cout << "1. Lihat Stasiun dan Rute\n";
    cout << "2. Lihat Tiket Dipesan\n";
    cout << "3. Tambah Tiket\n";
    cout << "4. Ubah Tiket\n";
    cout << "5. Hapus Tiket\n";
    cout << "6. Sorting Data\n";
    cout << "7. Keluar\n";
}

void tampilkanStasiunRute(const string* stasiun, const string* rute, const int* jumlahTiketStasiun, const int* harga, int JUMLAH_STASIUN) {
    cout << "===== Daftar Stasiun dan Rute =====\n";
    for (int i = 0; i < JUMLAH_STASIUN; ++i) {
        cout << i+1 << ". " << stasiun[i] << " - " << rute[i] 
             << " (Harga: Rp" << harga[i] 
             << ", Tiket Tersisa: " << jumlahTiketStasiun[i] << ")\n";
    }
}

void tampilkanTiketDipesan(const Tiket* tiket, const string* stasiun, const string* rute, int panjang) {
    if (panjang == 0) {
        cout << "Belum ada tiket yang dipesan.\n";
        return;
    }
    cout << "===== Tiket Dipesan =====\n";
    for (int i = 0; i < panjang; ++i) {
        cout << i+1 << ". Nama: " << tiket[i].namaPenumpang
             << ", Stasiun: " << stasiun[tiket[i].stasiunDipilih]
             << ", Rute: " << rute[tiket[i].stasiunDipilih]
             << ", Jumlah Tiket: " << tiket[i].jumlahTiket
             << ", Total Harga: Rp" << tiket[i].totalHarga << "\n";
    }
}

void tambahTiket(Tiket* tiket, int* jumlahTiketStasiun, const int* harga, int* panjang, const string* stasiun, const string* rute, int MAX_TIKET, int JUMLAH_STASIUN) {
    if (*panjang >= MAX_TIKET) {
        cout << "Kapasitas penuh!\n";
        return;
    }

    tampilkanStasiunRute(stasiun, rute, jumlahTiketStasiun, harga, JUMLAH_STASIUN);

    cout << "Pilih stasiun (1-" << JUMLAH_STASIUN << "): ";
    int pilih;
    cin >> pilih;
    cin.ignore();
    pilih--;

    if (pilih < 0 || pilih >= JUMLAH_STASIUN) {
        cout << "Pilihan tidak valid!\n";
        return;
    }

    if (jumlahTiketStasiun[pilih] <= 0) {
        cout << "Tiket habis di stasiun tersebut!\n";
        return;
    }

    cout << "Nama Penumpang: ";
    getline(cin, tiket[*panjang].namaPenumpang);

    cout << "Jumlah Tiket: ";
    cin >> tiket[*panjang].jumlahTiket;
    cin.ignore();

    if (tiket[*panjang].jumlahTiket <= 0 || tiket[*panjang].jumlahTiket > jumlahTiketStasiun[pilih]) {
        cout << "Jumlah tiket tidak valid!\n";
        return;
    }

    tiket[*panjang].stasiunDipilih = pilih;
    tiket[*panjang].totalHarga = tiket[*panjang].jumlahTiket * harga[pilih];
    jumlahTiketStasiun[pilih] -= tiket[*panjang].jumlahTiket;
    (*panjang)++;

    cout << "Tiket berhasil ditambahkan.\n";
}

void ubahTiket(Tiket* tiket, const int* harga, int panjang, const string* stasiun, const string* rute) {
    if (panjang == 0) {
        cout << "Belum ada tiket yang bisa diubah.\n";
        return;
    }

    tampilkanTiketDipesan(tiket, stasiun, rute, panjang);

    cout << "Pilih tiket yang ingin diubah (1-" << panjang << "): ";
    int idx;
    cin >> idx;
    cin.ignore();
    idx--;

    if (idx < 0 || idx >= panjang) {
        cout << "Pilihan tidak valid!\n";
        return;
    }

    cout << "Nama Penumpang Baru: ";
    getline(cin, tiket[idx].namaPenumpang);
    cout << "Jumlah Tiket Baru: ";
    cin >> tiket[idx].jumlahTiket;
    tiket[idx].totalHarga = tiket[idx].jumlahTiket * harga[tiket[idx].stasiunDipilih];

    cout << "Tiket berhasil diubah.\n";
}

void hapusTiket(Tiket* tiket, int* jumlahTiketStasiun, int* panjang, const string* stasiun, const string* rute) {
    if (*panjang == 0) {
        cout << "Belum ada tiket yang bisa dihapus.\n";
        return;
    }

    tampilkanTiketDipesan(tiket, stasiun, rute, *panjang);

    cout << "Pilih tiket yang ingin dihapus (1-" << *panjang << "): ";
    int idx;
    cin >> idx;
    cin.ignore();
    idx--;

    if (idx < 0 || idx >= *panjang) {
        cout << "Pilihan tidak valid!\n";
        return;
    }

    jumlahTiketStasiun[tiket[idx].stasiunDipilih] += tiket[idx].jumlahTiket;

    for (int i = idx; i < *panjang - 1; ++i) {
        tiket[i] = tiket[i + 1];
    }

    (*panjang)--;
    cout << "Tiket berhasil dihapus.\n";
}

void sortNamaAscending(Tiket* tiket, int panjang) {
    sort(tiket, tiket + panjang, [](const Tiket& a, const Tiket& b) {
        return a.namaPenumpang < b.namaPenumpang;
    });
}

void sortTotalHargaDescending(Tiket* tiket, int panjang) {
    sort(tiket, tiket + panjang, [](const Tiket& a, const Tiket& b) {
        return a.totalHarga > b.totalHarga;
    });
}

void bubbleSortJumlahTiketAscending(Tiket* tiket, int panjang) {
    for (int i = 0; i < panjang - 1; ++i) {
        for (int j = 0; j < panjang - i - 1; ++j) {
            if (tiket[j].jumlahTiket > tiket[j + 1].jumlahTiket) {
                swap(tiket[j], tiket[j + 1]);
            }
        }
    }
}
