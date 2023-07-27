#include <bits/stdc++.h>

using namespace std;

class PS {
    private:
        float tuso;
        float mauso;
    public:
        PS(float tuso = 0.0, float mauso = 1) {
            this->tuso = tuso;
            this->mauso = mauso;
        }

        ~PS(){}

        void Nhap() {
            cout << "Nhap tu so: ";
            cin >> this->tuso;
            cout << "Nhap mau so: ";
            cin >> this->mauso;
        }
        
        void Xuat() {
            cout << this->tuso << "/" << this->mauso << endl;
        }

        // PS sum(int x) {
        //     PS t;
        //     t.tuso = 
        // }
};

int main() {
    PS ps;
    ps.Nhap();
    ps.Xuat();
    PS ps1;
    ps1.Nhap();
    ps1.Xuat();
}