#include <iostream>
#include <cmath>
using namespace std;

// Fungsi login
bool login() {
    string username, inputUsername;
    string password, inputPassword;
    username = "Sayid Annashir Ikhwan";
    password = "2409106097";
    
    cout << "Username: ";
    getline(cin, inputUsername);
    cout << "Password: ";
    cin >> inputPassword;
    cin.ignore();
    
    return (inputUsername == username && inputPassword == password);
}

// Fungsi perhitungan luas
float luasPersegi(float s) { return s * s; }
float luasPersegiPanjang(float p, float l) { return p * l; }
float luasLingkaran(float r) { return 3.14 * r * r; }
float luasSegitiga(float a, float t) { return 0.5 * a * t; }

// Fungsi perhitungan keliling
float kelilingPersegi(float s) { return 4 * s; }
float kelilingPersegiPanjang(float p, float l) { return 2 * (p + l); }
float kelilingLingkaran(float r) { return 2 * 3.14 * r; }
float kelilingSegitiga(float a, float b, float c) { return a + b + c; }

// Fungsi perhitungan volume
float volumeKubus(float s) { return s * s * s; }
float volumeBalok(float p, float l, float t) { return p * l * t; }
float volumeBola(float r) { return (4.0 / 3.0) * 3.14 * pow(r, 3); }
float volumeKerucut(float r, float t) { return (1.0 / 3.0) * 3.14 * pow(r, 2) * t; }

int main() {
    if (!login()) {
        cout << "Username atau password salah" << endl;
        return 0;
    }
    
    int pilihan;
    do {
        cout << "\n== SISTEM HITUNG BANGUN DATAR DAN BANGUN RUANG ==\n";
        cout << "1. Hitung luas\n2. Hitung keliling\n3. Hitung volume\n4. Logout\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            int sub;
            cout << "\n== HITUNG LUAS ==\n1. Persegi\n2. Persegi Panjang\n3. Lingkaran\n4. Segitiga\n5. Kembali\n";
            cout << "Pilih: "; cin >> sub;
            if (sub == 1) {
                float s;
                cout << "Masukkan sisi: "; cin >> s;
                cout << "Luas: " << luasPersegi(s) << endl;
            } else if (sub == 2) {
                float p, l;
                cout << "Masukkan panjang & lebar: "; cin >> p >> l;
                cout << "Luas: " << luasPersegiPanjang(p, l) << endl;
            } else if (sub == 3) {
                float r;
                cout << "Masukkan jari-jari: "; cin >> r;
                cout << "Luas: " << luasLingkaran(r) << endl;
            } else if (sub == 4) {
                float a, t;
                cout << "Masukkan alas & tinggi: "; cin >> a >> t;
                cout << "Luas: " << luasSegitiga(a, t) << endl;
            }
        } else if (pilihan == 2) {
            int sub;
            cout << "\n== HITUNG KELILING ==\n1. Persegi\n2. Persegi Panjang\n3. Lingkaran\n4. Segitiga\n5. Kembali\n";
            cout << "Pilih: "; cin >> sub;
            if (sub == 1) {
                float s;
                cout << "Masukkan sisi: "; cin >> s;
                cout << "Keliling: " << kelilingPersegi(s) << endl;
            } else if (sub == 2) {
                float p, l;
                cout << "Masukkan panjang & lebar: "; cin >> p >> l;
                cout << "Keliling: " << kelilingPersegiPanjang(p, l) << endl;
            } else if (sub == 3) {
                float r;
                cout << "Masukkan jari-jari: "; cin >> r;
                cout << "Keliling: " << kelilingLingkaran(r) << endl;
            } else if (sub == 4) {
                float a, b, c;
                cout << "Masukkan tiga sisi segitiga: "; cin >> a >> b >> c;
                cout << "Keliling: " << kelilingSegitiga(a, b, c) << endl;
            }
        } else if (pilihan == 3) {
            int sub;
            cout << "\n== HITUNG VOLUME ==\n1. Kubus\n2. Balok\n3. Bola\n4. Kerucut\n5. Kembali\n";
            cout << "Pilih: "; cin >> sub;
            if (sub == 1) {
                float s;
                cout << "Masukkan sisi: "; cin >> s;
                cout << "Volume: " << volumeKubus(s) << endl;
            } else if (sub == 2) {
                float p, l, t;
                cout << "Masukkan panjang, lebar & tinggi: "; cin >> p >> l >> t;
                cout << "Volume: " << volumeBalok(p, l, t) << endl;
            } else if (sub == 3) {
                float r;
                cout << "Masukkan jari-jari: "; cin >> r;
                cout << "Volume: " << volumeBola(r) << endl;
            } else if (sub == 4) {
                float r, t;
                cout << "Masukkan jari-jari & tinggi: "; cin >> r >> t;
                cout << "Volume: " << volumeKerucut(r, t) << endl;
            }
        }
    } while (pilihan != 4);
    
    cout << "Logout berhasil.\n";
    return 0;
}
