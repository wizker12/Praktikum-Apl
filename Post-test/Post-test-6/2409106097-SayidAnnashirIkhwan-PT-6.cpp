#include <iostream>
#include <string>
using namespace std;

// Definisi struct untuk menyimpan data tiket
struct Tiket {
    string namaPenumpang;
    int stasiunDipilih;
    int jumlahTiket;
    int totalHarga;
};

// Deklarasi fungsi dan prosedur dengan pointer
bool loginSystem();
void tampilkanMenu();
void tampilkanStasiunRute(const string* stasiun, const string* rute, const int* jumlahTiketStasiun, const int* harga, int JUMLAH_STASIUN);
void tampilkanTiketDipesan(const Tiket* tiket, const string* stasiun, const string* rute, int panjang);
void tambahTiket(Tiket* tiket, int* jumlahTiketStasiun, const int* harga, int* panjang, const string* stasiun, const string* rute, int MAX_TIKET, int JUMLAH_STASIUN);
void ubahTiket(Tiket* tiket, const int* harga, int panjang, const string* stasiun, const string* rute);
void hapusTiket(Tiket* tiket, int* jumlahTiketStasiun, int* panjang, const string* stasiun, const string* rute);
void hitungTotalHarga(Tiket* tiket, const int* harga);

// Deklarasi fungsi sorting
void sortingTiket(Tiket* tiket, int panjang, const string* stasiun, const string* rute);

int main() {
    const int MAX_TIKET = 100; 
    const int JUMLAH_STASIUN = 5; 

    string stasiun[] = {"Stasiun UNMUL", "Stasiun AI", "Stasiun ISO", "Stasiun APL", "Stasiun Masjaya"};
    string rute[] = {"Samarinda-Balikpapan", "Samarinda-Tenggarong", "Balikpapan-Berau", "Balikpapan-Tanah Grogot", "Samarinda-Bontang"};
    int jumlahTiketStasiun[] = {10, 10, 10, 10, 10};
    int harga[] = {500000, 250000, 350000, 150000, 300000};

    Tiket tiket[MAX_TIKET];
    int panjang = 0;

    if (!loginSystem()) {
        return 0;
    }

    int pilihan;
    do {
        system("cls");
        tampilkanMenu();
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

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
            case 6:
                cout << "Terima kasih sudah menggunakan program, sampai berjumpa kembali!" << endl;
                break;
            case 7:
                sortingTiket(tiket, panjang, stasiun, rute);
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }

        if (pilihan != 6) {
            cout << "Tekan Enter untuk melanjutkan...";
            cin.ignore();
        }

    } while (pilihan != 6);

    return 0;
}

bool loginSystem() {
    string namaUser, nimUser;
    int loginAttempts = 0;

    while (loginAttempts < 3) {
        cout << "Masukkan Nama: ";
        getline(cin, namaUser);
        cout << "Masukkan NIM: ";
        getline(cin, nimUser);

        if (namaUser == "Sayid Annashir Ikhwan" && nimUser == "2409106097") {
            cout << "Hore Login berhasil!" << endl;
            return true;
        } else {
            loginAttempts++;
            cout << "Maaf Login gagal. Percobaan " << loginAttempts << " dari 3." << endl;
        }
    }

    cout << "Anda telah gagal login 3 kali. Program berhenti." << endl;
    return false;
}

void tampilkanMenu() {
    cout << "=============================================================" << endl;
    cout << "Selamat datang di Program Booking Tiket Kereta Api" << endl;
    cout << "=============================================================" << endl;
    cout << "1. Tampilkan List Stasiun dan Rute" << endl;
    cout << "2. Tampilkan Tiket yang Dipesan" << endl;
    cout << "3. Tambah Tiket" << endl;
    cout << "4. Ubah Tiket" << endl;
    cout << "5. Hapus Tiket" << endl;
    cout << "6. Keluar" << endl;
    cout << "7. Urutkan Data Tiket" << endl;
}

void tampilkanStasiunRute(const string* stasiun, const string* rute, const int* jumlahTiketStasiun, const int* harga, int JUMLAH_STASIUN) {
    cout << "Daftar Stasiun dan Rute:" << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < JUMLAH_STASIUN; i++) {
        cout << "Stasiun: " << *(stasiun + i) << endl;
        cout << "Rute: " << *(rute + i) << endl;
        cout << "Jumlah Tiket Tersedia: " << *(jumlahTiketStasiun + i) << endl;
        cout << "Harga: Rp " << *(harga + i) << endl;
        cout << "-----------------------------" << endl;
    }
}

void tampilkanTiketDipesan(const Tiket* tiket, const string* stasiun, const string* rute, int panjang) {
    if (panjang == 0) {
        cout << "Belum ada tiket yang dipesan." << endl;
    } else {
        cout << "Daftar Tiket yang Dipesan:" << endl;
        cout << "-----------------------------" << endl;
        for (int i = 0; i < panjang; i++) {
            cout << "Tiket ke-" << i + 1 << ":" << endl;
            cout << "Nama Penumpang: " << (tiket + i)->namaPenumpang << endl;
            cout << "Stasiun: " << *(stasiun + (tiket + i)->stasiunDipilih) << endl;
            cout << "Rute: " << *(rute + (tiket + i)->stasiunDipilih) << endl;
            cout << "Jumlah Tiket: " << (tiket + i)->jumlahTiket << endl;
            cout << "Total Harga: Rp " << (tiket + i)->totalHarga << endl;
            cout << "-----------------------------" << endl;
        }
    }
}

void tambahTiket(Tiket* tiket, int* jumlahTiketStasiun, const int* harga, int* panjang, const string* stasiun, const string* rute, int MAX_TIKET, int JUMLAH_STASIUN) {
    if (*panjang < MAX_TIKET) {
        int index;
        cout << "Pilih Stasiun:" << endl;
        for (int i = 0; i < JUMLAH_STASIUN; i++) {
            cout << i + 1 << ". " << *(stasiun + i) << " (" << *(rute + i) << ")" << endl;
        }
        cout << "Masukkan nomor stasiun: ";
        cin >> index;
        cin.ignore();

        if (index > 0 && index <= JUMLAH_STASIUN) {
            if (*(jumlahTiketStasiun + index - 1) > 0) {
                cout << "Masukkan Nama Penumpang: ";
                getline(cin, (tiket + *panjang)->namaPenumpang);
                cout << "Masukkan Jumlah Tiket: ";
                cin >> (tiket + *panjang)->jumlahTiket;
                cin.ignore();

                if ((tiket + *panjang)->jumlahTiket <= *(jumlahTiketStasiun + index - 1)) {
                    (tiket + *panjang)->stasiunDipilih = index - 1;
                    hitungTotalHarga(tiket + *panjang, harga + index - 1);
                    *(jumlahTiketStasiun + index - 1) -= (tiket + *panjang)->jumlahTiket;
                    (*panjang)++;
                    cout << "Tiket berhasil ditambahkan!" << endl;
                } else {
                    cout << "Jumlah tiket tidak mencukupi." << endl;
                }
            } else {
                cout << "Tiket untuk stasiun ini sudah habis." << endl;
            }
        } else {
            cout << "Nomor stasiun tidak benar. Harap masukkan yang betul." << endl;
        }
    } else {
        cout << "Kapasitas tiket penuh. Tidak bisa menambah tiket lagi." << endl;
    }
}

void ubahTiket(Tiket* tiket, const int* harga, int panjang, const string* stasiun, const string* rute) {
    if (panjang == 0) {
        cout << "Belum ada tiket untuk diubah." << endl;
        return;
    }

    int index;
    tampilkanTiketDipesan(tiket, stasiun, rute, panjang);
    cout << "Masukkan nomor tiket yang akan diubah: ";
    cin >> index;
    cin.ignore();

    if (index > 0 && index <= panjang) {
        cout << "Masukkan Nama Penumpang baru: ";
        getline(cin, (tiket + index - 1)->namaPenumpang);
        cout << "Masukkan Jumlah Tiket baru: ";
        cin >> (tiket + index - 1)->jumlahTiket;
        cin.ignore();

        hitungTotalHarga(tiket + index - 1, harga + (tiket + index - 1)->stasiunDipilih);
        cout << "Tiket berhasil diubah!" << endl;
    } else {
        cout << "Nomor tiket tidak valid." << endl;
    }
}

void hapusTiket(Tiket* tiket, int* jumlahTiketStasiun, int* panjang, const string* stasiun, const string* rute) {
    if (*panjang == 0) {
        cout << "Belum ada tiket untuk dihapus." << endl;
        return;
    }

    int index;
    tampilkanTiketDipesan(tiket, stasiun, rute, *panjang);
    cout << "Masukkan nomor tiket yang akan dihapus: ";
    cin >> index;
    cin.ignore();

    if (index > 0 && index <= *panjang) {
        *(jumlahTiketStasiun + (tiket + index - 1)->stasiunDipilih) += (tiket + index - 1)->jumlahTiket;
        for (int i = index - 1; i < *panjang - 1; i++) {
            *(tiket + i) = *(tiket + i + 1);
        }
        (*panjang)--;
        cout << "Tiket berhasil dihapus!" << endl;
    } else {
        cout << "Nomor tiket tidak valid. Harap masukkan dengan benar." << endl;
    }
}

void hitungTotalHarga(Tiket* tiket, const int* harga) {
    tiket->totalHarga = tiket->jumlahTiket * (*harga);
}

// Tambahan fungsi sorting
void sortingTiket(Tiket* tiket, int panjang, const string* stasiun, const string* rute) {
    int pilihan;
    cout << "Pilihan sorting:" << endl;
    cout << "1. Nama Penumpang (Ascending)" << endl;
    cout << "2. Jumlah Tiket (Descending)" << endl;
    cout << "3. Stasiun (Ascending)" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;
    cin.ignore();

    for (int i = 0; i < panjang - 1; i++) {
        for (int j = i + 1; j < panjang; j++) {
            bool tukar = false;
            if (pilihan == 1 && (tiket + i)->namaPenumpang > (tiket + j)->namaPenumpang) {
                tukar = true;
            } else if (pilihan == 2 && (tiket + i)->jumlahTiket < (tiket + j)->jumlahTiket) {
                tukar = true;
            } else if (pilihan == 3 && *(stasiun + (tiket + i)->stasiunDipilih) > *(stasiun + (tiket + j)->stasiunDipilih)) {
                tukar = true;
            }
            if (tukar) {
                Tiket temp = *(tiket + i);
                *(tiket + i) = *(tiket + j);
                *(tiket + j) = temp;
            }
        }
    }

    cout << "Data tiket berhasil diurutkan!" << endl;
    tampilkanTiketDipesan(tiket, stasiun, rute, panjang);
}
