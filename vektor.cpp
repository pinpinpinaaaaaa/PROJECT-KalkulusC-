#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Meminta input dari pengguna
    int jumlahTitik;
    cout << "Masukkan jumlah titik: ";
    cin >> jumlahTitik;

    // Membuat vektor untuk menyimpan koordinat titik
    vector<pair<int, int> > titik;

    // Meminta input koordinat titik dari pengguna
    for (int i = 0; i < jumlahTitik; ++i) {
        int x, y;
        cout << "Masukkan koordinat titik ke-" << i + 1 << " (x y): ";
        cin >> x >> y;
        titik.push_back({x, y});
    }

    // Mencari nilai maksimum dari input titik
    int maxAbsX = 0;
    int maxAbsY = 0;
    for (size_t i = 0; i < titik.size(); ++i) {
        maxAbsX = max(maxAbsX, abs(titik[i].first));
        maxAbsY = max(maxAbsY, abs(titik[i].second));
    }

    // Menampilkan grafik dengan sumbu x dan sumbu y
    for (int y = maxAbsY; y >= -maxAbsY; --y) {
        for (int x = -maxAbsX; x <= maxAbsX; ++x) {
            bool titikDitemukan = false;
            bool garisDitemukan = false;

            // Cek apakah ada sumbu x pada koordinat tersebut
            if (y == 0) {
                cout << '-';
            }
            // Cek apakah ada sumbu y pada koordinat tersebut
            else if (x == 0) {
                cout << '|';
            }
            // Cek apakah ada titik pada koordinat tersebut
            else {
                for (size_t i = 0; i < titik.size(); ++i) {
                    if (x == titik[i].first && y == titik[i].second) {
                        // Tampilkan karakter '*' pada titik
                        cout << '*';
                        titikDitemukan = true;
                        break;
                    }
                }

                // Cek apakah ada garis yang melalui koordinat tersebut
                for (size_t i = 0; i < titik.size(); ++i) {
                    int x1 = titik[i].first;
                    int y1 = titik[i].second;
                    int x2 = titik[(i + 1) % titik.size()].first;
                    int y2 = titik[(i + 1) % titik.size()].second;

                    // Cek jika ada garis horizontal
                    if (y1 == y2 && y == y1 && x >= min(x1, x2) && x <= max(x1, x2)) {
                        cout << '-';
                        garisDitemukan = true;
                        break;
                    }
                    // Cek jika ada garis vertikal
                    else if (x1 == x2 && x == x1 && y >= min(y1, y2) && y <= max(y1, y2)) {
                        cout << '|';
                        garisDitemukan = true;
                        break;
                    }
                }

                // Tampilkan karakter spasi jika tidak ada titik atau garis
                if (!titikDitemukan && !garisDitemukan) {
                    cout << ' ';
                }
            }
        }
        cout << endl;
    }

    return 0;
}
