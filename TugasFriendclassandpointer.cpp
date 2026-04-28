#include <iostream>
using namespace std;

class LayangLayang;

class BelahKetupat {
private:
    float d1, d2;
    float sisi;
public:
    // Input data
    void input() {
        cout << "\n--- Input Belah Ketupat ---" << endl;
        cout << "Diagonal 1 : "; cin >> d1;
        cout << "Diagonal 2 : "; cin >> d2;
        cout << "Sisi       : "; cin >> sisi;
    }

    // Hitung luas
    float luas() { return 0.5 * d1 * d2; }

    // Hitung keliling
    float keliling() { return 4 * sisi; }

    // Output
    void output() {
        cout << "\nLuas Belah Ketupat     : " << luas() << endl;
        cout << "Keliling Belah Ketupat : " << keliling() << endl;
    }

    // Friend method untuk keliling Layang-Layang
    float keliling(LayangLayang L);
};

class LayangLayang {
private:
    float d1, d2;
    float sisiA, sisiB;
public:
    // Input data
    void input() {
        cout << "\n--- Input Layang-Layang ---" << endl;
        cout << "Diagonal 1 : "; cin >> d1;
        cout << "Diagonal 2 : "; cin >> d2;
        cout << "Sisi A     : "; cin >> sisiA;
        cout << "Sisi B     : "; cin >> sisiB;
    }

    // Hitung luas
    float luas() { return 0.5 * d1 * d2; }

    // Hitung keliling
    float keliling() { return 2 * (sisiA + sisiB); }

    // Output
    void output() {
        cout << "\nLuas Layang-Layang     : " << luas() << endl;
        cout << "Keliling Layang-Layang : " << keliling() << endl;
    }

    // deklarasi Friend method
    friend float BelahKetupat::keliling(LayangLayang L);
};

// implementasi friend method
float BelahKetupat::keliling(LayangLayang L) {
    return 2 * (L.sisiA + L.sisiB);
}

int main() {
    // object pointer
    LayangLayang *LL = new LayangLayang();
    BelahKetupat *BK = new BelahKetupat();

    cout << "\n--- Input Data ---" << endl;
    LL->input();
    BK->input();

    cout << "\n--- Output Data ---" << endl;
    LL->output();
    BK->output();

    cout << "\nKeliling Layang-Layang (via friend method) : "
         << BK->keliling(*LL) << endl;

    // Hapus memory
    delete LL;
    delete BK;

    return 0;
}