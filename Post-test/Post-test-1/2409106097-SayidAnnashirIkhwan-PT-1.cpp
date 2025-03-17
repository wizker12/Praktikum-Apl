#include <iostream>
using namespace std;

int main() {
    string username, password;
    bool loggedIn = false;

    // Login System
    while (!loggedIn) {
        cout << "Selamat Datang Silahkan Login >_<" << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (username == "SayidAnnashirIkhwan" && password == "2409106097") {
            loggedIn = true;
            cout << "Login berhasil!" << endl;
        } else {
            cout << "Username atau password salah. Silakan coba lagi." << endl;
        }
    }

    // Main Menu
    while (loggedIn) {
        cout << "\n== SISTEM HITUNG BANGUN DATAR DAN BANGUN RUANG ==" << endl;
        cout << "1. Hitung Luas" << endl;
        cout << "2. Hitung Keliling" << endl;
        cout << "3. Hitung Volume" << endl;
        cout << "4. Logout" << endl;
        cout << "Pilih menu: ";
        int mainMenuChoice;
        cin >> mainMenuChoice;

        if (mainMenuChoice == 1) {
            // Submenu Hitung Luas
            while (true) {
                cout << "\n== HITUNG LUAS ==" << endl;
                cout << "1. Persegi" << endl;
                cout << "2. Persegi Panjang" << endl;
                cout << "3. Lingkaran" << endl;
                cout << "4. Segitiga" << endl;
                cout << "5. Kembali" << endl;
                cout << "Pilih bangun: ";
                int luasChoice;
                cin >> luasChoice;

                if (luasChoice == 5) break; // Kembali ke menu utama

                if (luasChoice == 1) {
                    double sisi;
                    cout << "Masukkan panjang sisi persegi: ";
                    cin >> sisi;
                    cout << "Luas persegi: " << sisi * sisi << endl;
                } else if (luasChoice == 2) {
                    double panjang, lebar;
                    cout << "Masukkan panjang persegi panjang: ";
                    cin >> panjang;
                    cout << "Masukkan lebar persegi panjang: ";
                    cin >> lebar;
                    cout << "Luas persegi panjang: " << panjang * lebar << endl;
                } else if (luasChoice == 3) {
                    double jariJari;
                    cout << "Masukkan jari-jari lingkaran: ";
                    cin >> jariJari;
                    cout << "Luas lingkaran: " << 3.14 * jariJari * jariJari << endl;
                } else if (luasChoice == 4) {
                    double alas, tinggi;
                    cout << "Masukkan alas segitiga: ";
                    cin >> alas;
                    cout << "Masukkan tinggi segitiga: ";
                    cin >> tinggi;
                    cout << "Luas segitiga: " << 0.5 * alas * tinggi << endl;
                } else {
                    cout << "Mohon masukkan angka dengan benar." << endl;
                }
            }
        } else if (mainMenuChoice == 2) {
            // Submenu Hitung Keliling
            while (true) {
                cout << "\n== HITUNG KELILING ==" << endl;
                cout << "1. Persegi" << endl;
                cout << "2. Persegi Panjang" << endl;
                cout << "3. Lingkaran" << endl;
                cout << "4. Segitiga" << endl;
                cout << "5. Kembali" << endl;
                cout << "Pilih bangun: ";
                int kelilingChoice;
                cin >> kelilingChoice;

                if (kelilingChoice == 5) break; // Kembali ke menu utama

                if (kelilingChoice == 1) {
                    double sisi;
                    cout << "Masukkan panjang sisi persegi: ";
                    cin >> sisi;
                    cout << "Keliling persegi: " << 4 * sisi << endl;
                } else if (kelilingChoice == 2) {
                    double panjang, lebar;
                    cout << "Masukkan panjang persegi panjang: ";
                    cin >> panjang;
                    cout << "Masukkan lebar persegi panjang: ";
                    cin >> lebar;
                    cout << "Keliling persegi panjang: " << 2 * (panjang + lebar) << endl;
                } else if (kelilingChoice == 3) {
                    double jariJari;
                    cout << "Masukkan jari-jari lingkaran: ";
                    cin >> jariJari;
                    cout << "Keliling lingkaran: " << 2 * 3.14 * jariJari << endl;
                } else if (kelilingChoice == 4) {
                    double sisi1, sisi2, sisi3;
                    cout << "Masukkan panjang sisi 1 segitiga: ";
                    cin >> sisi1;
                    cout << "Masukkan panjang sisi 2 segitiga: ";
                    cin >> sisi2;
                    cout << "Masukkan panjang sisi 3 segitiga: ";
                    cin >> sisi3;
                    cout << "Keliling segitiga: " << sisi1 + sisi2 + sisi3 << endl;
                } else {
                    cout << "Mohon masukkan angka dengan benar." << endl;
                }
            }
        } else if (mainMenuChoice == 3) {
            // Submenu Hitung Volume
            while (true) {
                cout << "\n== HITUNG VOLUME ==" << endl;
                cout << "1. Kubus" << endl;
                cout << "2. Balok" << endl;
                cout << "3. Bola" << endl;
                cout << "4. Kerucut" << endl;
                cout << "5. Kembali" << endl;
                cout << "Pilih bangun: ";
                int volumeChoice;
                cin >> volumeChoice;

                if (volumeChoice == 5) break; // Kembali ke menu utama

                if (volumeChoice == 1) {
                    double sisi;
                    cout << "Masukkan panjang sisi kubus: ";
                    cin >> sisi;
                    cout << "Volume kubus: " << sisi * sisi * sisi << endl;
                } else if (volumeChoice == 2) {
                    double panjang, lebar, tinggi;
                    cout << "Masukkan panjang balok: ";
                    cin >> panjang;
                    cout << "Masukkan lebar balok: ";
                    cin >> lebar;
                    cout << "Masukkan tinggi balok: ";
                    cin >> tinggi;
                    cout << "Volume balok: " << panjang * lebar * tinggi << endl;
                } else if (volumeChoice == 3) {
                    double jariJari;
                    cout << "Masukkan jari-jari bola: ";
                    cin >> jariJari;
                    cout << "Volume bola: " << (4.0 / 3.0) * 3.14 * jariJari * jariJari * jariJari << endl;
                } else if (volumeChoice == 4) {
                    double jariJari, tinggi;
                    cout << "Masukkan jari-jari kerucut: ";
                    cin >> jariJari;
                    cout << "Masukkan tinggi kerucut: ";
                    cin >> tinggi;
                    cout << "Volume kerucut: " << (1.0 / 3.0) * 3.14 * jariJari * jariJari * tinggi << endl;
                } else {
                    cout << "Mohon masukkan angka dengan benar." << endl;
                }
            }
        } else if (mainMenuChoice == 4) {
            // Logout
            loggedIn = false;
            cout << "Logout berhasil. Terima kasih!" << endl;
        } else {
            cout << "Mohon masukkan angka dengan benar." << endl;
        }
    }

    return 0;
}