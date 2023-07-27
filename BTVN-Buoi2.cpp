#include <bits/stdc++.h>

using namespace std;

class GiaoVien {
    private:
        char hoTen[30], bangCap[15], chuyenNganh[20];
        int tuoi;
        float bacLuong;
    public:
        void Nhap() {
            cout << "\tNhap ho ten: ";
            cin.getline(this->hoTen, 30);
            cout << "\tNhap tuoi: ";
            cin >> this->tuoi;
            fflush(stdin);
            cout << "\tNhap bang cap: ";
            cin.getline(this->bangCap, 15);
            cout << "\tNhap chuyen nganh: ";
            cin.getline(this->chuyenNganh, 20);
            cout << "\tNhap bac luong: ";
            cin >> this->bacLuong;
            fflush(stdin);
        }

        float tinhLuongCB() {
            return this->bacLuong*610;
        }

        void Xuat() {
            cout << setw(30) << left << this->hoTen
                 << setw(7) << left << this->tuoi
                 << setw(15) << left << this->bangCap
                 << setw(20) << left << this->chuyenNganh
                 << setw(13) << left << this->bacLuong 
                 << setw(15) << left << this->tinhLuongCB() << endl;
        }

        char* getCN() {
            return this->chuyenNganh;
        }
};

void title() {
    cout << setw(30) << left << "HO TEN"
         << setw(7) << left << "TUOI"
         << setw(15) << left << "BANG CAP"
         << setw(20) << left << "CHUYEN NGANH"
         << setw(13) << left << "BAC LUONG"
         << setw(15) << left << "LUONG CB" << endl;
}

void Nhapds(GiaoVien gv[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin giao vien thu " << i + 1 << " la:\n";
        gv[i].Nhap();
    }
}

void Xuatds(GiaoVien gv[], int n) {
    title();
    for (int i = 0; i < n; i++) {
        gv[i].Xuat();
    }
}

void dsGiaoVienLuongDuoi2000(GiaoVien gv[], int n) {
    title();
    for (int i = 0; i < n; i++) {
        if (gv[i].tinhLuongCB() < 2000) {
            gv[i].Xuat();
        }
    }
}

void dsSXChuyenNganh(GiaoVien gv[], int n) {
    title();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(gv[i].getCN(), gv[j].getCN()) == 1) {
                swap(gv[i], gv[j]);
            }
        }
        gv[i].Xuat();
    }
}

int main() {
    int n;
    cout << "Nhap so luong giao vien: ";
    cin >> n;
    fflush(stdin);
    GiaoVien gv[n];
    Nhapds(gv, n);
    Xuatds(gv, n);
    dsGiaoVienLuongDuoi2000(gv, n);
    dsSXChuyenNganh(gv, n);
}