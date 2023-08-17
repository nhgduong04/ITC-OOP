#include <iostream>

using namespace std;

class patient
{
    protected:
        string maHoSo, hoTen, chanDoanBenh;
        int ngaySinh;
    public:
        patient(string maHoSo, string hoTen, int ngaySinh, string chanDoanBenh) {
            this->maHoSo = maHoSo;
            this->hoTen = hoTen;
            this->ngaySinh = ngaySinh;
            this->chanDoanBenh = chanDoanBenh;
        }

        //patient(string maHoSo, string hoTen, int ngaySinh, string chanDoanBenh)
        // : maHoSo(maHoSo), hoTen(hoTen), ngaySinh(ngaySinh), chanDoanBenh(chanDoanBenh);

        virtual void Nhap() {
            cout << "\t[-]Nhap ma ho so: ";
            getline(cin, this->maHoSo);
            cout << "\t[-]Nhap ho ten: ";
            getline(cin, this->hoTen);
            cout << "\t[-]Nhap ngay sinh: ";
            cin >> this->ngaySinh;fflush(stdin);
            cout << "\t[-]Nhap chuan doan benh: ";
            getline(cin, this->chanDoanBenh);
        }
        virtual void Xuat() {
            cout << "Ma ho so: " << this->maHoSo << endl
                 << "Ho ten: " << this->hoTen << endl
                 << "Ngay sinh: " << this->ngaySinh << endl
                 << "Chuan doan benh: " << this->chanDoanBenh << endl;
        }

        virtual bool loaiHoSo() = 0; //pure virtual method

        int get_NgaySinh() {
            return this->ngaySinh;
        }
};

class inPatient : public patient {
    private:
        int ngayNhapVien, ngayRaVien, soGiuong;
        string tenKhoa;
    public:
        inPatient(string maHoSo, string hoTen, int ngaySinh, string chanDoanBenh, int ngayNhapVien, int ngayRaVien, string tenKhoa, int soGiuong) : patient(maHoSo, hoTen, ngaySinh, chanDoanBenh) {
            this->ngayNhapVien = ngayNhapVien;
            this->ngayRaVien = ngayRaVien;
            this->tenKhoa = tenKhoa;
            this->soGiuong = soGiuong;
        }

        // inPatient(int ngayNhapVien, int ngayRaVien, string tenKhoa, int soGiuong)
        // : patient(maHoSo, hoTen, ngaySinh, chanDoanBenh), ngayNhapVien(ngayNhapVien), ngayRaVien(ngayRaVien), tenKhoa(tenKhoa), soGiuong(soGiuong);

        void Nhap() override {
            patient::Nhap();
            cout << "\t[-]Nhap ngay nhap vien: ";
            cin >> ngayNhapVien;
            cout << "\t[-]Nhap ngay ra vien: ";
            cin >> ngayRaVien;
            fflush(stdin);
            cout << "\t[-]Nhap ten khoa: ";
            getline(cin, this->tenKhoa);
            cout << "\t[-]Nhap so giuong: ";
            cin >> soGiuong;
            fflush(stdin);
        }

        void Xuat() override {
            
            patient::Xuat();
            cout << "Ngay nhap vien: " << ngayNhapVien << endl
                 << "Ngay ra vien: " << ngayRaVien << endl
                 << "Ten khoa: " << tenKhoa << endl
                 << "So giuong: " << soGiuong << endl;
        }

        bool loaiHoSo() override {
            return true;
        }
};

class outPatient : public patient
{
    private:
        int ngayChuyen;
        string noiChuyen;
    public:
        outPatient(string maHoSo, string hoTen, int ngaySinh, string chanDoanBenh, int ngayChuyen, string noiChuyen) : patient(maHoSo, hoTen, ngaySinh, chanDoanBenh) {
            this->ngayChuyen = ngayChuyen;
            this->noiChuyen = noiChuyen;
        }

        void Nhap() override {
            patient::Nhap();
            cout << "\t[-]Nhap ngay chuyen: ";
            cin >> ngayChuyen;
            fflush(stdin);
            cout << "\t[-]Nhap noi chuyen: ";
            getline(cin, this->noiChuyen);
        }

        void Xuat() override {
            
            patient::Xuat();
            cout << "Ngay chuyen: " << ngayChuyen << endl
                 << "Noi chuyen: " << noiChuyen << endl;
        }

        bool loaiHoSo() override {
            return false;
        }
};

class quanLyHoSo {
    private:
        patient *p[1000];
        int n;
    public:
        void Nhapds() {
            int lc;
            cout << "Nhap so luong benh nhan trong danh sach: ";
            cin >> n;
            cout << "Nhap danh sach cho " << n << " benh nhan:\n";
            for (int i = 0; i < n; i++) {
                do
                {
                    cout << "\t>Chon loai benh nhan:\n";
                    cout << "\t\t [+]Benh nhan noi tru(1)\n";
                    cout << "\t\t [+]Benh nhan ngoai tru(2)\n";
                    cout << "\t\t Ban chon? ";
                    cin >> lc; fflush(stdin);
                    if (lc < 1 || lc > 2) {
                        cout << "Lua chon nay khong ton tai, vui long chon lai:\n";
                    }
                } while (lc < 1 || lc > 2);
                if (lc == 1) {
                    p[i] = new inPatient("", "", 0, "", 0, 0, "", 0);
                }
                if (lc == 2) {
                    p[i] = new outPatient("", "", 0, "", 0, "");
                }
                p[i]->Nhap();
            }
        }

        void Xuatds() {
            for (int i = 0; i < n; i++) {
                cout << "\n\t\t XUAT THONG TIN HO SO BENH NHAN " << (p[i]->loaiHoSo() ? "NOI TRU" : "NGOAI TRU") << " THU " << i+1 <<endl;
                p[i]->Xuat();
            }
        }

        void demHoSo() {
            int x;
            cout << "\n\nNhap ngay sinh X: "; cin >> x;
            int count_nt = 0, count_ngt = 0;
            for (int i = 0; i < n; i++) {
                if (p[i]->get_NgaySinh() > x) {
                    p[i]->loaiHoSo() ? count_nt++ : count_ngt++;
                }
            }
            cout << ">>So luong benh nhan co ngay sinh lon hon x la:\n";
            cout << "\t>Benh nhan noi tru: " << count_nt << endl;
            cout << "\t>Benh nhan ngoai tru: " << count_ngt << endl;
        }
};

int main() {
    
    quanLyHoSo *qlhs = new quanLyHoSo();
    qlhs->Nhapds();
    qlhs->Xuatds();
    qlhs->demHoSo();
    return 0;
}