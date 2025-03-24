<<<<<<< HEAD
#include <iostream>
#include <string>
using namespace std;

int main() {
    const int MAX_TIKET = 100; // Konstanta untuk ukuran maksimum tiket
    const int JUMLAH_STASIUN = 5; // Konstanta untuk jumlah stasiun

    string namaUser, nimUser;
    int loginAttempts[1] = {0}; // Menggunakan array untuk loginAttempts
    int loggedIn[1] = {0}; // Menggunakan array untuk loggedIn (0 = false, 1 = true)

    // Login System
    while (loginAttempts[0] < 3 && loggedIn[0] == 0) {
        cout << "Masukkan Nama: ";
        getline(cin, namaUser);
        cout << "Masukkan NIM: ";
        getline(cin, nimUser);

        if (namaUser == "Sayid Annashir Ikhwan" && nimUser == "2409106097") {
            loggedIn[0] = 1; // Login berhasil
            cout << "Hore Login berhasil!" << endl;
        } else {
            loginAttempts[0]++;
            cout << "Maaf Login gagal. Percobaan " << loginAttempts[0] << " dari 3." << endl;
        }
    }

    if (loggedIn[0] == 0) {
        cout << "Anda telah gagal login 3 kali. Program berhenti." << endl;
        return 0;
    }

    // Data stasiun, rute, jumlah tiket, dan harga
    string stasiun[] = {"Stasiun UNMUL", "Stasiun AI", "Stasiun ISO", "Stasiun APL", "Stasiun Masjaya"};
    string rute[] = {"Samarinda-Balikpapan", "Samarinda-Tenggarong", "Balikpapan-Berau", "Balikpapan-Tanah Grogot", "Samarinda-Bontang"};
    int jumlahTiketStasiun[] = {10, 10, 10, 10, 10};
    int harga[] = {500000, 250000, 350000, 150000, 300000};

    // Array untuk tiket yang dipesan
    string namaPenumpang[MAX_TIKET];
    int stasiunDipilih[MAX_TIKET];
    int jumlahTiket[MAX_TIKET];
    int totalHarga[MAX_TIKET];
    int panjang[1] = {0}; // Menggunakan array untuk panjang

    int pilihan, index;
    do {
        system("cls"); // Membersihkan layar 
        cout << "=============================================================" << endl;
        cout << "Selamat datang di Program Booking Tiket Kereta Api" << endl;
        cout << "=============================================================" << endl;
        cout << "1. Tampilkan List Stasiun dan Rute" << endl;
        cout << "2. Tampil kan Tiket yang Dipesan" << endl;
        cout << "3. Tambah Tiket" << endl;
        cout << "4. Ubah Tiket" << endl;
        cout << "5. Hapus Tiket" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer

        switch (pilihan) {
            case 1: // Tampilkan List Stasiun dan Rute
                cout << "Daftar Stasiun dan Rute:" << endl;
                cout << "-----------------------------" << endl;
                for (int i = 0; i < JUMLAH_STASIUN; i++) {
                    cout << "Stasiun: " << stasiun[i] << endl;
                    cout << "Rute: " << rute[i] << endl;
                    cout << "Jumlah Tiket Tersedia: " << jumlahTiketStasiun[i] << endl;
                    cout << "Harga: Rp " << harga[i] << endl;
                    cout << "-----------------------------" << endl;
                }
                break;

            case 2: // Tampilkan Tiket yang Dipesan
                if (panjang[0] == 0) {
                    cout << "Belum ada tiket yang dipesan." << endl;
                } else {
                    cout << "Daftar Tiket yang Dipesan:" << endl;
                    cout << "-----------------------------" << endl;
                    for (int i = 0; i < panjang[0]; i++) {
                        cout << "Tiket ke-" << i + 1 << ":" << endl;
                        cout << "Nama Penumpang: " << namaPenumpang[i] << endl;
                        cout << "Stasiun: " << stasiun[stasiunDipilih[i]] << endl;
                        cout << "Rute: " << rute[stasiunDipilih[i]] << endl;
                        cout << "Jumlah Tiket: " << jumlahTiket[i] << endl;
                        cout << "Total Harga: Rp " << totalHarga[i] << endl;
                        cout << "-----------------------------" << endl;
                    }
                }
                break;

            case 3: // Tambah Tiket
                if (panjang[0] < MAX_TIKET) {
                    cout << "Pilih Stasiun:" << endl;
                    for (int i = 0; i < JUMLAH_STASIUN; i++) {
                        cout << i + 1 << ". " << stasiun[i] << " (" << rute[i] << ")" << endl;
                    }
                    cout << "Masukkan nomor stasiun: ";
                    cin >> index;
                    cin.ignore(); // Membersihkan buffer

                    if (index > 0 && index <= JUMLAH_STASIUN) {
                        if (jumlahTiketStasiun[index - 1] > 0) {
                            cout << "Masukkan Nama Penumpang: ";
                            getline(cin, namaPenumpang[panjang[0]]);
                            cout << "Masukkan Jumlah Tiket: ";
                            cin >> jumlahTiket[panjang[0]];
                            cin.ignore(); // Membersihkan buffer

                            if (jumlahTiket[panjang[0]] <= jumlahTiketStasiun[index - 1]) {
                                stasiunDipilih[panjang[0]] = index - 1;
                                totalHarga[panjang[0]] = jumlahTiket[panjang[0]] * harga[index - 1];
                                jumlahTiketStasiun[index - 1] -= jumlahTiket[panjang[0]];
                                panjang[0]++;
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
                break;

            case 4: // Ubah Tiket
                if (panjang[0] == 0) {
                    cout << "Belum ada tiket untuk diubah." << endl;
                } else {
                    cout << "Daftar Tiket yang Dipesan:" << endl;
                    cout << "-----------------------------" << endl;
                    for (int i = 0; i < panjang[0]; i++) {
                        cout << "Tiket ke-" << i + 1 << ":" << endl;
                        cout << "Nama Penumpang: " << namaPenumpang[i] << endl;
                        cout << "Stasiun: " << stasiun[stasiunDipilih[i]] << endl;
                        cout << "Rute: " << rute[stasiunDipilih[i]] << endl;
                        cout << "Jumlah Tiket: " << jumlahTiket[i] << endl;
                        cout << "Total Harga: Rp " << totalHarga[i] << endl;
                        cout << "-----------------------------" << endl;
                    }
                    cout << "Masukkan nomor tiket yang akan diubah: ";
                    cin >> index;
                    cin.ignore(); // Membersihkan buffer

                    if (index > 0 && index <= panjang[0]) {
                        cout << "Masukkan Nama Penumpang baru: ";
                        getline(cin, namaPenumpang[index - 1]);
                        cout << "Masukkan Jumlah Tiket baru: ";
                        cin >> jumlahTiket[index - 1];
                        cin.ignore(); // Membersihkan buffer

                        totalHarga[index - 1] = jumlahTiket[index - 1] * harga[stasiunDipilih[index - 1]];
                        cout << "Tiket berhasil diubah!" << endl;
                    } else {
                        cout << "Nomor tiket tidak valid." << endl;
                    }
                }
                break;

            case 5: // Hapus Tiket
                if (panjang[0] == 0) {
                    cout << "Belum ada tiket untuk dihapus." << endl;
                } else {
                    cout << "Daftar Tiket yang Dipesan:" << endl;
                    cout << "-----------------------------" << endl;
                    for (int i = 0; i < panjang[0]; i++) {
                        cout << "Tiket ke-" << i + 1 << ":" << endl;
                        cout << "Nama Penumpang: " << namaPenumpang[i] << endl;
                        cout << "Stasiun: " << stasiun[stasiunDipilih[i]] << endl;
                        cout << "Rute: " << rute[stasiunDipilih[i]] << endl;
                        cout << "Jumlah Tiket: " << jumlahTiket[i] << endl;
                        cout << "Total Harga: Rp " << totalHarga[i] << endl;
                        cout << "-----------------------------" << endl;
                    }
                    cout << "Masukkan nomor tiket yang akan dihapus: ";
                    cin >> index;
                    cin.ignore(); // Membersihkan buffer

                    if (index > 0 && index <= panjang[0]) {
                        jumlahTiketStasiun[stasiunDipilih[index - 1]] += jumlahTiket[index - 1];
                        for (int i = index - 1; i < panjang[0] - 1; i++) {
                            namaPenumpang[i] = namaPenumpang[i + 1];
                            stasiunDipilih[i] = stasiunDipilih[i + 1];
                            jumlahTiket[i] = jumlahTiket[i + 1];
                            totalHarga[i] = totalHarga[i + 1];
                        }
                        panjang[0]--;
                        cout << "Tiket berhasil dihapus!" << endl;
                    } else {
                        cout << "Nomor tiket tidak valid. Harap masukkan dengan benar." << endl;
                    }
                }
                break;

            case 6: // Keluar
                cout << "Terima kasih sudah menggunakan program, sampai berjumpa kembali!" << endl;
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
=======
#include <iostream>
#include <string>
using namespace std;

int main() {
    const int MAX_TIKET = 100; // Konstanta untuk ukuran maksimum tiket
    const int JUMLAH_STASIUN = 5; // Konstanta untuk jumlah stasiun

    string namaUser, nimUser;
    int loginAttempts[1] = {0}; // Menggunakan array untuk loginAttempts
    int loggedIn[1] = {0}; // Menggunakan array untuk loggedIn (0 = false, 1 = true)

    // Login System
    while (loginAttempts[0] < 3 && loggedIn[0] == 0) {
        cout << "Masukkan Nama: ";
        getline(cin, namaUser);
        cout << "Masukkan NIM: ";
        getline(cin, nimUser);

        if (namaUser == "Sayid Annashir Ikhwan" && nimUser == "2409106097") {
            loggedIn[0] = 1; // Login berhasil
            cout << "Hore Login berhasil!" << endl;
        } else {
            loginAttempts[0]++;
            cout << "Maaf Login gagal. Percobaan " << loginAttempts[0] << " dari 3." << endl;
        }
    }

    if (loggedIn[0] == 0) {
        cout << "Anda telah gagal login 3 kali. Program berhenti." << endl;
        return 0;
    }

    // Data stasiun, rute, jumlah tiket, dan harga
    string stasiun[] = {"Stasiun UNMUL", "Stasiun AI", "Stasiun ISO", "Stasiun APL", "Stasiun Masjaya"};
    string rute[] = {"Samarinda-Balikpapan", "Samarinda-Tenggarong", "Balikpapan-Berau", "Balikpapan-Tanah Grogot", "Samarinda-Bontang"};
    int jumlahTiketStasiun[] = {10, 10, 10, 10, 10};
    int harga[] = {500000, 250000, 350000, 150000, 300000};

    // Array untuk tiket yang dipesan
    string namaPenumpang[MAX_TIKET];
    int stasiunDipilih[MAX_TIKET];
    int jumlahTiket[MAX_TIKET];
    int totalHarga[MAX_TIKET];
    int panjang[1] = {0}; // Menggunakan array untuk panjang

    int pilihan, index;
    do {
        system("cls"); // Membersihkan layar 
        cout << "=============================================================" << endl;
        cout << "Selamat datang di Program Booking Tiket Kereta Api" << endl;
        cout << "=============================================================" << endl;
        cout << "1. Tampilkan List Stasiun dan Rute" << endl;
        cout << "2. Tampil kan Tiket yang Dipesan" << endl;
        cout << "3. Tambah Tiket" << endl;
        cout << "4. Ubah Tiket" << endl;
        cout << "5. Hapus Tiket" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer

        switch (pilihan) {
            case 1: // Tampilkan List Stasiun dan Rute
                cout << "Daftar Stasiun dan Rute:" << endl;
                cout << "-----------------------------" << endl;
                for (int i = 0; i < JUMLAH_STASIUN; i++) {
                    cout << "Stasiun: " << stasiun[i] << endl;
                    cout << "Rute: " << rute[i] << endl;
                    cout << "Jumlah Tiket Tersedia: " << jumlahTiketStasiun[i] << endl;
                    cout << "Harga: Rp " << harga[i] << endl;
                    cout << "-----------------------------" << endl;
                }
                break;

            case 2: // Tampilkan Tiket yang Dipesan
                if (panjang[0] == 0) {
                    cout << "Belum ada tiket yang dipesan." << endl;
                } else {
                    cout << "Daftar Tiket yang Dipesan:" << endl;
                    cout << "-----------------------------" << endl;
                    for (int i = 0; i < panjang[0]; i++) {
                        cout << "Tiket ke-" << i + 1 << ":" << endl;
                        cout << "Nama Penumpang: " << namaPenumpang[i] << endl;
                        cout << "Stasiun: " << stasiun[stasiunDipilih[i]] << endl;
                        cout << "Rute: " << rute[stasiunDipilih[i]] << endl;
                        cout << "Jumlah Tiket: " << jumlahTiket[i] << endl;
                        cout << "Total Harga: Rp " << totalHarga[i] << endl;
                        cout << "-----------------------------" << endl;
                    }
                }
                break;

            case 3: // Tambah Tiket
                if (panjang[0] < MAX_TIKET) {
                    cout << "Pilih Stasiun:" << endl;
                    for (int i = 0; i < JUMLAH_STASIUN; i++) {
                        cout << i + 1 << ". " << stasiun[i] << " (" << rute[i] << ")" << endl;
                    }
                    cout << "Masukkan nomor stasiun: ";
                    cin >> index;
                    cin.ignore(); // Membersihkan buffer

                    if (index > 0 && index <= JUMLAH_STASIUN) {
                        if (jumlahTiketStasiun[index - 1] > 0) {
                            cout << "Masukkan Nama Penumpang: ";
                            getline(cin, namaPenumpang[panjang[0]]);
                            cout << "Masukkan Jumlah Tiket: ";
                            cin >> jumlahTiket[panjang[0]];
                            cin.ignore(); // Membersihkan buffer

                            if (jumlahTiket[panjang[0]] <= jumlahTiketStasiun[index - 1]) {
                                stasiunDipilih[panjang[0]] = index - 1;
                                totalHarga[panjang[0]] = jumlahTiket[panjang[0]] * harga[index - 1];
                                jumlahTiketStasiun[index - 1] -= jumlahTiket[panjang[0]];
                                panjang[0]++;
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
                break;

            case 4: // Ubah Tiket
                if (panjang[0] == 0) {
                    cout << "Belum ada tiket untuk diubah." << endl;
                } else {
                    cout << "Daftar Tiket yang Dipesan:" << endl;
                    cout << "-----------------------------" << endl;
                    for (int i = 0; i < panjang[0]; i++) {
                        cout << "Tiket ke-" << i + 1 << ":" << endl;
                        cout << "Nama Penumpang: " << namaPenumpang[i] << endl;
                        cout << "Stasiun: " << stasiun[stasiunDipilih[i]] << endl;
                        cout << "Rute: " << rute[stasiunDipilih[i]] << endl;
                        cout << "Jumlah Tiket: " << jumlahTiket[i] << endl;
                        cout << "Total Harga: Rp " << totalHarga[i] << endl;
                        cout << "-----------------------------" << endl;
                    }
                    cout << "Masukkan nomor tiket yang akan diubah: ";
                    cin >> index;
                    cin.ignore(); // Membersihkan buffer

                    if (index > 0 && index <= panjang[0]) {
                        cout << "Masukkan Nama Penumpang baru: ";
                        getline(cin, namaPenumpang[index - 1]);
                        cout << "Masukkan Jumlah Tiket baru: ";
                        cin >> jumlahTiket[index - 1];
                        cin.ignore(); // Membersihkan buffer

                        totalHarga[index - 1] = jumlahTiket[index - 1] * harga[stasiunDipilih[index - 1]];
                        cout << "Tiket berhasil diubah!" << endl;
                    } else {
                        cout << "Nomor tiket tidak valid." << endl;
                    }
                }
                break;

            case 5: // Hapus Tiket
                if (panjang[0] == 0) {
                    cout << "Belum ada tiket untuk dihapus." << endl;
                } else {
                    cout << "Daftar Tiket yang Dipesan:" << endl;
                    cout << "-----------------------------" << endl;
                    for (int i = 0; i < panjang[0]; i++) {
                        cout << "Tiket ke-" << i + 1 << ":" << endl;
                        cout << "Nama Penumpang: " << namaPenumpang[i] << endl;
                        cout << "Stasiun: " << stasiun[stasiunDipilih[i]] << endl;
                        cout << "Rute: " << rute[stasiunDipilih[i]] << endl;
                        cout << "Jumlah Tiket: " << jumlahTiket[i] << endl;
                        cout << "Total Harga: Rp " << totalHarga[i] << endl;
                        cout << "-----------------------------" << endl;
                    }
                    cout << "Masukkan nomor tiket yang akan dihapus: ";
                    cin >> index;
                    cin.ignore(); // Membersihkan buffer

                    if (index > 0 && index <= panjang[0]) {
                        jumlahTiketStasiun[stasiunDipilih[index - 1]] += jumlahTiket[index - 1];
                        for (int i = index - 1; i < panjang[0] - 1; i++) {
                            namaPenumpang[i] = namaPenumpang[i + 1];
                            stasiunDipilih[i] = stasiunDipilih[i + 1];
                            jumlahTiket[i] = jumlahTiket[i + 1];
                            totalHarga[i] = totalHarga[i + 1];
                        }
                        panjang[0]--;
                        cout << "Tiket berhasil dihapus!" << endl;
                    } else {
                        cout << "Nomor tiket tidak valid. Harap masukkan dengan benar." << endl;
                    }
                }
                break;

            case 6: // Keluar
                cout << "Terima kasih sudah menggunakan program, sampai berjumpa kembali!" << endl;
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
>>>>>>> 1d2a16dbb757cabcbebebe3989297ed678fe4866
}