#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class SinhVien {
private:
    string maSV;
    string tenSV;
    int tuoi;
    float diem;

public:
    SinhVien() {}
    // Hàm nhập thông tin sinh viên
    friend istream& operator>>(istream& is, SinhVien& sv) {
        cout << "Nhap ma sinh vien: ";
        is >> sv.maSV;
        cout << "Nhap ten sinh vien: ";
        is.ignore(); 
        getline(is, sv.tenSV);
        cout << "Nhap tuoi sinh vien: ";
        is >> sv.tuoi;
        cout << "Nhap diem sinh vien: ";
        is >> sv.diem;
        return is;
    }

    // Hàm xuất thông tin sinh viên
    friend ostream& operator<<(ostream& os, const SinhVien& sv) {
        os << "Ma SV: " << sv.maSV << ", Ten: " << sv.tenSV 
           << ", Tuoi: " << sv.tuoi << ", Diem: " << sv.diem;
        return os;
    }

    // Toán tử so sánh < theo điểm
    bool operator<(const SinhVien& sv) const {
        return this->diem < sv.diem;
    }

    // Lấy mã sinh viên
    string getMaSV() const {
        return maSV;
    }

    // Lấy diem sinh viên
    float getDiem() const {
        return diem;
    }
};

// Lập DanhSachSinhVien quản lý danh sách sinh viên
class DanhSachSinhVien {
private:
    vector<SinhVien>để quản lý menu và thao tác
class App {
public:
    void run() {
        DanhSachSinhVien dssv;
        int choice;

        do {
            cout << "\n===== Menu Quan Ly Sinh Vien =====" << endl;
            cout << "1. Nhap danh sach sinh vien" << endl;
            cout << "2. Xuat danh sach sinh vien" << endl;
            cout << "3. Sap xep danh sach theo diem" << endl;
            cout << "4. Tim sinh vien co diem cao nhat" << endl;
            cout << "5. Tim sinh vien co diem thap nhat" << endl;
            cout << "6. Tim sinh vien theo ma" << endl;
            cout << "7. Xoa sinh vien theo ma" << endl;
            cout << "0. Thoat" << endl;
            cout << "Nhap lua chon: ";
            cin >> choice;
            cout << endl;

            switch (choice) {
            case 1: {
                int n;
                cout << "Nhap so luong sinh vien: ";
                cin >> n;
                dssv.nhapDS(n);
                break;
            }
            case 2:
                dssv.xuatDS();
                break;
            case 3:
                dssv.sapXepTheoDiem();
                cout << "Danh sach da duoc sap xep theo diem." << endl;
                break;
            case 4: {
                SinhVien sv = dssv.timMaxDiem();
                cout << "Sinh vien co diem cao nhat: " << endl;
                cout << sv << endl;
                break;
            }
            case 5: {
                SinhVien sv = dssv.timMinDiem();
                cout << "Sinh vien co diem thap nhat: " << endl;
                cout << sv << endl;
                break;
            }
            case 6: {
                string ma;
                cout << "Nhap ma sinh vien can tim: ";
                cin >> ma;
                SinhVien* sv = dssv.timKiemTheoMa(ma);
                if (sv) {
                    cout << "Tim thay sinh vien: " << endl;
                    cout << *sv << endl;
                } else {
                    cout << "Khong tim thay sinh vien co ma " << ma << endl;
                }
                break;
            }
            case 7: {
                string ma;
                cout << "Nhap ma sinh vien can xoa: ";
                cin >> ma;
                dssv.xoaTheoMa(ma);
                break;
            }
            case 0:
                cout << "Thoat chuong trinh!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
            }
        } while (choice != 0);
    }
};

// Hàm main
int main() {
    App app;
    app.run();
    return 0;
}
