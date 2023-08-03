#include <iostream>
#include <cstring>

using namespace std;

class Nguoi
{
    private:
        int tuoi;
        char ten[30];
    public:
        friend istream &operator >> (istream &is, Nguoi &nguoi) {
            cout << "\tNhap ho ten: ";
            is.getline(nguoi.ten, 30);
            fflush(stdin);
            cout << "\tNhap tuoi: ";
            is >> nguoi.tuoi;
            fflush(stdin);
            return is;
        }
        
        friend ostream &operator << (ostream &os, Nguoi nguoi) {
            os << "Ten: " << nguoi.ten << endl;
            os << "Tuoi: " << nguoi.tuoi << endl;
            return os;
        }

        bool operator > (Nguoi nguoi) {
            // if (this->tuoi > nguoi.tuoi)
            //     return true;
            // return false;
            return this->tuoi > nguoi.tuoi;
        }

        bool operator == (Nguoi nguoi) {
            return strcmpi(this->ten, nguoi.ten) == 0;
        }

        Nguoi operator + (Nguoi nguoi) {
            Nguoi n;
            strcpy(n.ten, this->ten);
            strcat(n.ten, " ");
            strcat(n.ten, nguoi.ten);
            n.tuoi = this->tuoi + nguoi.tuoi;
            return n;
        }
};

int main() {
    Nguoi nguoi1, nguoi2;
    cout << "[-] Nhap thong tin nguoi 1:\n";
    cin >> nguoi1;
    cout << "[-] Nhap thong tin nguoi 2:\n";
    cin >> nguoi2;

    cout << "\nNguoi1:\n" << nguoi1 << endl;
    cout << "\nNguoi2:\n" << nguoi2 << endl;

    if ( !(nguoi1 == nguoi2) ) {
        cout << "Khac ten!!!" <<endl;
    }
    
    cout << "\nThuoc tinh 2 doi tuong cong vao nhau\n" << nguoi1 + nguoi2 << endl;

    return 0;
}