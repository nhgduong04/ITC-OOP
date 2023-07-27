#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class Nguoi {
    private:
        char hoTen[30];
        int tuoi;
        float diemTB;
    public:
        Nguoi() {
            strcpy(hoTen, "");
            tuoi = 0;
            diemTB = 0.0;
        }

        Nguoi(char hoTen[30], int tuoi, float diemTB) {
            strcpy(this->hoTen, hoTen);
            this->tuoi = tuoi;
            this->diemTB = diemTB;
        }

        void Nhap() {
            cout << "\t Nhap ho ten: ";
            cin.getline(this->hoTen, 30);
            cout << "\t Nhap tuoi: ";
            cin >> this->tuoi;
            cout << "\t Nhap diem TB: ";
            cin >> this->diemTB;
            fflush(stdin);
        }

        void Xuat() {
            cout << setw(30) << left << this->hoTen
                 << setw(10) << left << this->tuoi
                 << setw(10) << left << this->diemTB << endl;
        }

        float getDiemTB() {
            return this->diemTB;
        }
};



int main() {
    Nguoi nguoi;
    nguoi.Xuat();

    return 0;
}