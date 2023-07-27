#include <bits/stdc++.h>

using namespace std;

class Nguoi {
    private:
        char name[30];
        int tuoi;
        float diem;
    public:
        // constructor without parameters
        // Nguoi() {
        //     strcpy(name, ""); //<cstring>
        //     tuoi = 0;
        //     diem = 0.0;
        // }
        // constructor w/ parameters
        // Nguoi(char name[30], int tuoi, float diem) {
        //     strcpy(this->name, name);
        //     this->tuoi = tuoi;
        //     this->diem = diem;
        // }
        // construct with parameters and default value
        Nguoi(char *name = "Duong", int tuoi = 19, float diem = 8.5) {
            // char name[] = "Duong" , ....
            strcpy(this->name, name);
            this->tuoi = tuoi;
            this->diem = diem;
        }

        ~Nguoi(){}
        
        void Nhap() {
            cout << "Nhap ten: ";
            cin.getline(name, 30);
            cout << "Nhap tuoi: ";
            cin >> this->tuoi;
            cout << "Nhap diem: ";
            cin >> this->diem;
        }
        void Xuat() {
            cout << "Ten: " << this->name << endl
                 << "Tuoi: " << this->tuoi << endl
                 << "Diem: " << this->diem << endl;
        }
};

int main() {
    //Nguoi nguoi("Duong", 19, 10);
    Nguoi nguoi;
    // nguoi.Nhap();
    nguoi.Xuat();


    return 0;
}