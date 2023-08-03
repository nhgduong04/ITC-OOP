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
            if (this->mauso == 1) {
                cout << this->tuso << endl;
            }
            else {
                cout << this->tuso << "/" << this->mauso << endl;
            }
            
        }

        PS sum(PS ps) {
            PS p;
            p.tuso = this->tuso * ps.mauso + this->mauso * ps.tuso;
            p.mauso = this->mauso * ps.mauso;
            return p;
        }

        void reduce();
};

int UCLN(int x, int y) {
    while (x != y) {
        if (x > y) {
            x = x - y;
        }
        if (y > x) {
            y = y - x;
        }
    }
    return x;
}

void PS::reduce() {
    int k = UCLN(tuso, mauso);
    tuso = tuso / k;
    mauso = mauso / k;
}

int main() {
    PS ps;
    ps.Nhap();
    ps.Xuat();
    PS ps1;
    ps1.Nhap();
    ps1.Xuat();

    PS sum;
    sum = ps.sum(ps1);
    sum.reduce();
    sum.Xuat();
}