#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class Nguoi {
    private:
        char hoTen[30];
        int tuoi;
        float diemTB;
        char danhHieu[10];
    public:
        Nguoi() {
            strcpy(hoTen, "");
            tuoi = 0;
            diemTB = 0.0;
            strcpy(danhHieu, "");
        }

        Nguoi(char *hoTen, int tuoi, float diemTB, char *danhHieu) {
            strcpy(this->hoTen, hoTen);
            this->tuoi = tuoi;
            this->diemTB = diemTB;
            strcpy(this->danhHieu, danhHieu);
        }

        void Nhap() {
            cout << "\t Nhap ho ten: ";
            cin.getline(this->hoTen, 30);
            fflush(stdin);
            cout << "\t Nhap tuoi: ";
            cin >> this->tuoi;
            cout << "\t Nhap diem TB: ";
            cin >> this->diemTB;
            fflush(stdin);

            // if (diemTB >= 8) {
            //     strcpy(danhHieu, "Gioi");
            // }
            // else if (diemTB >= 7) {
            //     strcpy(danhHieu, "Kha");
            // }
            // else if(diemTB >= 5) {
            //     strcpy(danhHieu, "TB");
            // }
            // else {
            //     strcpy(danhHieu, "Kem");
            // }
        }

        void Xuat() {
            cout << setw(30) << left << this->hoTen
                 << setw(10) << left << this->tuoi
                 << setw(10) << left << this->diemTB //<< endl;
                 << setw(10) << left << this->getDanhHieu() << endl;
        }

        void setDiemTB(float diemTB) {
            this->diemTB = diemTB;
        }

        char *getDanhHieu() {
            if (diemTB >= 8) {
                return "Gioi";
            }
            else if (diemTB >= 7) {
                return "Kha";
            }
            else if(diemTB >= 5) {
                return "Trung Binh";
            }
            else {
                return "Kem";
            }
        }

        char *getTen() {
            return this->hoTen;
        }
};

void Title() {
    cout << setw(30) << left << "HO VA TEN"
         << setw(10) << left << "TUOI"
         << setw(10) << left << "DIEM TB" //<< endl;
         << setw(10) << left << "DANH HIEU" << endl;
}

void Nhapds(Nguoi nguoi[], int &n) {
    for (int i = 0; i < n; i++) {
        nguoi[i].Nhap();
    }
}

void Xuatds(Nguoi nguoi[], int &n) {
    Title();
    for (int i = 0; i < n; i++) {
        nguoi[i].Xuat();
    }
}

void sortByName(Nguoi nguoi[], int &n) {
    Title();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(nguoi[i].getTen(), nguoi[j].getTen()) == 1) {
                swap(nguoi[i], nguoi[j]);
            }
        }
        nguoi[i].Xuat();
    }
}

void findByName(Nguoi nguoi[], int &n) {
    Title();
    bool check = true;
    for (int i = 0; i < n; i++) {
        if (strcmpi(nguoi[i].getTen(), "Nguyen Van A") == 0) {
            nguoi[i].setDiemTB(10);
            nguoi[i].Xuat();
        }
    }
    if (!check) {
        cout << "Khong co sinh vien nao ten Nguyen Van A";
    }
}

int main() {
    int n;
    cout << "Nhap so luong doi tuong: ";
    cin >> n;
    fflush(stdin);
    Nguoi nguoi[n];
    Nhapds(nguoi, n);
    Xuatds(nguoi, n);
    sortByName(nguoi, n);
    findByName(nguoi, n);

    return 0;
}