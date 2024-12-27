#include <iostream>
#include <cmath>

using namespace std;

// Fungsi untuk menghitung nilai y berdasarkan fungsi kuadrat
double hitungNilaiYAljabar(double x, double a, double b, double c) {
    return a * pow(x, 2) + b * x + c;
}

// Fungsi untuk menghitung nilai y berdasarkan fungsi trigonometri yang dipilih
double hitungNilaiYTrigonometri(double x, int pilihan) {
    switch (pilihan) {
        case 1: // Sin(x)
            return sin(x);
        case 2: // Cos(x)
            return cos(x);
        case 3: // Tan(x)
            return tan(x);
        case 4: // Cosec(x)
            return 1 / sin(x);
        case 5: // Sec(x)
            return 1 / cos(x);
        case 6: // Cot(x)
            return 1 / tan(x);
        default:
            return 0.0;
    }
}

int main() {
    int menu;
    cout << "Pilih jenis fungsi:\n";
    cout << "1. Aljabar\n";
    cout << "2. Trigonometri\n";
    cout << "Masukkan pilihan (1/2): ";
    cin >> menu;

    if (menu == 1) {
        //  memasukkan Fungsi Aljabar
        double a, b, c;
        cout << "Masukkan nilai a: ";
        cin >> a;
        cout << "Masukkan nilai b: ";
        cin >> b;
        cout << "Masukkan nilai c: ";
        cin >> c;

        // Batas-batas grafik yang ingin ditampilkan
        double batasAwal = -5.0;
        double batasAkhir = 5.0;

        // Jarak antar titik pada sumbu x (kerapatan titik)
        double jarakX;
        cout << "Masukkan kerapatan titik: ";
        cin >> jarakX;

        // Menampilkan grafik dengan sumbu x dan sumbu y
        for (double y = 10.0; y >= -10.0; --y) {
            for (double x = batasAwal; x <= batasAkhir; x += jarakX) {
                if (y == 0) {
                    // Tampilkan sumbu x
                    cout << '-';
                } else if (x == 0) {
                    // Tampilkan sumbu y
                    cout << '|';
                } else {
                    // Tampilkan karakter '*' sesuai dengan nilai y fungsi
                    double fungsiY = hitungNilaiYAljabar(x, a, b, c);
                    int tinggiGrafik = static_cast<int>(round(fungsiY));
                    cout << (tinggiGrafik == static_cast<int>(y) ? '*' : ' ');
                }
            }
            cout << endl;
        }

        // Menampilkan titik koordinat di bawah grafik
        cout << "Titik Koordinat:" << endl;
        for (double x = batasAwal; x <= batasAkhir; x += jarakX) {
            double y = hitungNilaiYAljabar(x, a, b, c);
            cout << "(" << x << ", " << y << ") ";
        }
    } else if (menu == 2) {
        // Fungsi Trigonometri
        // Batas-batas grafik yang ingin ditampilkan
        double batasAwal = -3.14;  // Nilai pi (p) sebagai batas awal
        double batasAkhir = 3.14; // Nilai pi (p) sebagai batas akhir

        // Jarak antar titik pada sumbu x
        double jarakX = 0.1;

        // Pilihan fungsi trigonometri
        int pilihan;
        cout << "Pilih fungsi trigonometri:\n";
        cout << "1. Sin(x)\n";
        cout << "2. Cos(x)\n";
        cout << "3. Tan(x)\n";
        cout << "4. Cosec(x)\n";
        cout << "5. Sec(x)\n";
        cout << "6. Cot(x)\n";
        cout << "Masukkan pilihan (1-6): ";
        cin >> pilihan;

        // Menampilkan grafik dengan sumbu x dan sumbu y
        for (double y = 1.0; y >= -1.0; y -= 0.1) {
            for (double x = batasAwal; x <= batasAkhir; x += jarakX) {
                if (y >= -0.05 && y <= 0.05) {
                    // Tampilkan garis sumbu x
                    cout << '-';
                } else if (x >= -0.05 && x <= 0.05) {
                    // Tampilkan garis sumbu y
                    cout << '|';
                } else {
                    // Tampilkan karakter '*' sesuai dengan nilai y fungsi
                    double fungsiY = hitungNilaiYTrigonometri(x, pilihan);
                    int tinggiGrafik = static_cast<int>((fungsiY + 1.0) * 10); // Menyesuaikan skala tinggi grafik
                    cout << (tinggiGrafik == static_cast<int>(y * 10) ? '*' : ' ');
                }
            }
            cout << endl;
        }

        // Menampilkan titik koordinat di bawah grafik
        cout << "Titik Koordinat:" << endl;
        for (double x = batasAwal; x <= batasAkhir; x += jarakX) {
            double y = hitungNilaiYTrigonometri(x, pilihan);
            cout << "(" << x << ", " << y << ") ";
        }
    } else {
        cout << "Pilihan tidak valid.\n";
    }

    return 0;
}
