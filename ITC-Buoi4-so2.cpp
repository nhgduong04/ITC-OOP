#include <iostream>

using namespace std;

class PhanSo {
    private:
        // numorator: tuso
        float numorator;
        // denominator: mauso
        float denominator;
    public:
        PhanSo(float numorator = 0.0, float denominator = 1.0) {
            this->numorator = numorator;
            this->denominator = denominator;
        }
        ~PhanSo(){}

        friend istream &operator >> (istream &is, PhanSo &ps) {
            cout << "[-] Nhap tu so: ";
            is >> ps.numorator;
            cout << "[-] Nhap mau so: ";
            do
            {
                is >> ps.denominator;
                if (ps.denominator == 0) {
                    cout << "Nhap lai(mau > 0): ";
                }
            } while (ps.denominator == 0);            
            return is;
        }

        friend ostream &operator << (ostream &os, PhanSo ps) {
            os << ps.numorator << "/" << ps.denominator << endl;
            return os;
        }

        PhanSo operator + (PhanSo ps) {
            PhanSo PS;
            PS.numorator = this->numorator*ps.denominator + this->denominator*ps.numorator;
            PS.denominator = this->denominator * ps.denominator;
            return PS;
        }
        PhanSo operator - (PhanSo ps) {
            PhanSo PS;
            PS.numorator = this->numorator*ps.denominator - this->denominator*ps.numorator;
            PS.denominator = this->denominator * ps.denominator;
            return PS;
        }
        PhanSo operator * (PhanSo ps) {
            PhanSo PS;
            PS.numorator = this->numorator * ps.numorator;
            PS.denominator = this->denominator * ps.denominator;
            return PS;
        }
        PhanSo operator / (PhanSo ps) {
            PhanSo PS;
            PS.numorator = this->numorator*ps.denominator;
            PS.denominator = this->denominator * ps.numorator;
            return PS;
        }
};

int main() {
    PhanSo ps;
    cin >> ps;
    PhanSo ps1;
    cin >> ps1;

    cout << "Tong 2 phan so: " << ps + ps1 << endl;
    cout << "Hieu 2 phan so: " << ps - ps1 << endl;
    cout << "Tich 2 phan so: " << ps * ps1 << endl;
    cout << "Thuong 2 phan so: " << ps / ps1 << endl;


    return 0;
}