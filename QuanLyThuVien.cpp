// Thành viên:
// Vo Thanh Hoang Phuc-6351071056
// Nguyen Xuan Khanh-6351071033
#include <iostream>
#include <cstring>
#include <iomanip> 
#include<cstdlib>
#include<ctime>
using namespace std;
#ifdef _WIN32
void clrscr() {
    system("cls");
}
#else
void clrscr() {
    system("clear");
}
#endif
class Sach
{
public:
    string maSach;
    string tenSach;
    string tacGia;
    int namXuatBan;
    float giaSach;
    bool daMuon;
    Sach* next; 
};

class DocGia
{
public:
    string hoTen;
    string cccd;
    string ngaySinh;
    string gioiTinh;
    string diaChi;
    DocGia* next; 
};

class PhieuMuon
{
public:
    string cccd;
    string maSach;
    int ngayMuon;
    int thangMuon;
    int namMuon;
    PhieuMuon* next;
};
// Ham in danh sach doc gia
void inDanhSachDocGia(DocGia* head)
{
    cout << "-------------------------------DANH SACH DOC GIA TRONG THU VIEN--------------------------------\n\n" << endl;
    cout << "+--------------------+------------+---------------+------------+----------------+\n";
      cout << "| " << left << setw(19) << "Ho ten " << "|"
             << setw(12) << "CCCD " << "|"
             << setw(15) << "Ngay sinh " << "|"
             << setw(12) << "Gioi tinh " << "|"
             << setw(16) << "Dia chi " << "|\n";
    cout << "+--------------------+------------+---------------+------------+----------------+\n";
    DocGia* node = head;
    while (node != nullptr)
    {
        cout << "| " << left << setw(19) << node->hoTen << "|"
             << setw(12) << node->cccd << "|"
             << setw(15) << node->ngaySinh << "|"
             << setw(12) << node->gioiTinh << "|"
             << setw(16) << node->diaChi << "|\n";
        node = node->next;
    }
     cout << "+--------------------+------------+---------------+------------+----------------+\n";
}

// Ham them doc gia vao danh sach lien ket
void themDocGia(DocGia*& head)
{
    DocGia* newDocGia = new DocGia;
    cout << "Nhap thong tin doc gia:" << endl;
    cout << "Ho ten: ";
    cin.ignore();
    getline(cin, newDocGia->hoTen);
    cout << "CCCD: ";
    cin >> newDocGia->cccd;
    cout << "Ngay sinh: ";
    cin.ignore();
    getline(cin, newDocGia->ngaySinh);
    cout << "Gioi tinh: ";
    getline(cin, newDocGia->gioiTinh);
    cout << "Dia chi: ";
    getline(cin, newDocGia->diaChi);
    newDocGia->next = head; // Thêm vào d?u danh sách
    head = newDocGia;
    cout << "Them doc gia thanh cong." << endl;
}

// Ham chinh sua thong tin doc gia
void chinhSuaDocGia(DocGia* head)
{
    string cccd;
    cout << "Nhap CCCD cua doc gia can chinh sua: ";
    cin >> cccd;

    DocGia* node = head;
    while (node != nullptr)
    {
        if (node->cccd == cccd)
        {
            cout << "Nhap thong tin moi:" << endl;
            cout << "Ho ten: ";
            cin.ignore();
            getline(cin, node->hoTen);
            cout << "Ngay sinh: ";
            cin.ignore();
            getline(cin, node->ngaySinh);
            cout << "Gioi tinh: ";
            getline(cin, node->gioiTinh);
            cout << "Dia chi: ";
            getline(cin, node->diaChi);
            cout << "Chinh sua thanh cong." << endl;
            return;
        }
        node = node->next;
    }

    cout << "Khong tim thay doc gia co CCCD nay trong danh sach." << endl;
}

// Ham xoa thong tin doc gia
void xoaDocGia(DocGia*& head)
{
    string cccd;
    cout << "Nhap CCCD cua doc gia can xoa: ";
    cin >> cccd;

    DocGia* node = head;
    DocGia* previous = nullptr;

    while (node != nullptr)
    {
        if (node->cccd == cccd)
        {
            if (previous != nullptr)
            {
                previous->next = node->next;
            }
            else
            {
                head = node->next;
            }

            delete node;
            cout << "Xoa doc gia thanh cong." << endl;
            return;
        }

        previous = node;
        node = node->next;
    }

    cout << "Khong tim thay doc gia co CCCD nay trong danh sach." << endl;
}

// Ham tim kiem doc gia theo cccd
void timKiemDocGiaTheoCCCD(DocGia* head)
{
    string cccd;
    cout << "Nhap CCCD can tim kiem: ";
    cin >> cccd;

    DocGia* node = head;
    while (node != nullptr)
    {
        if (node->cccd == cccd)
        {
           cout << "-------------------------------DANH SACH DOC GIA TRONG THU VIEN--------------------------------\n\n" << endl;
    cout << "+--------------------+------------+---------------+------------+----------------+\n";
      cout << "| " << left << setw(19) << "Ho ten " << "|" 
             << setw(12) << "CCCD " << "|" 
             << setw(15) << "Ngay sinh " << "|" 
             << setw(12) << "Gioi tinh " << "|" 
             << setw(16) << "Dia chi " << "|\n";
    cout << "+--------------------+------------+---------------+------------+----------------+\n";
    cout << "| " << left << setw(19) << node->hoTen << "|"
             << setw(12) << node->cccd << "|"
             << setw(15) << node->ngaySinh << "|"
             << setw(12) << node->gioiTinh << "|"
             << setw(16) << node->diaChi << "|\n";
    cout << "+--------------------+------------+---------------+------------+----------------+\n";
    }
    
        node = node->next;

    
}
}
// Ham tim kiem doc gia theo ten
void timKiemDocGiaTheoTen(DocGia* head)
{
    string ten;
    cout << "Nhap ten can tim kiem: ";
    cin.ignore();
    getline(cin, ten);

    DocGia* node = head;
    while (node != nullptr)
    {
        if (node->hoTen.find(ten) != string::npos)
        {
           cout << "-------------------------------DANH SACH DOC GIA TRONG THU VIEN--------------------------------\n\n" << endl;
    cout << "+--------------------+------------+---------------+------------+----------------+\n";
      cout << "| " << left << setw(19) << "Ho ten " << "|" 
             << setw(12) << "CCCD " << "|" 
             << setw(15) << "Ngay sinh " << "|" 
             << setw(12) << "Gioi tinh " << "|" 
             << setw(16) << "Dia chi " << "|\n";
    cout << "+--------------------+------------+---------------+------------+----------------+\n";
    cout << "| " << left << setw(19) << node->hoTen << "|"
             << setw(12) << node->cccd << "|"
             << setw(15) << node->ngaySinh << "|"
             << setw(12) << node->gioiTinh << "|"
             << setw(16) << node->diaChi << "|\n";
    cout << "+--------------------+------------+---------------+------------+----------------+\n";
        }
       node = node->next;
    }
     
}
// Ham sap xep sach theo gia tien
void sapXepSachTheoGia(Sach*& head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    Sach* node = head;
    int n = 0;
    while (node != NULL) {
        n++;
        node = node->next;
    }

    for (int i = 0; i < n - 1; i++) {
        node = head;
        for (int j = 0; j < n - i - 1; j++) {
            if (node->giaSach > node->next->giaSach) {
                Sach* temp = node->next;
                node->next = temp->next;
                temp->next = node;
                if (node == head) {
                    head = temp;
                } else {
                    Sach* prev = head;
                    while (prev->next != node) {
                        prev = prev->next;
                    }
                    prev->next = temp;
                }
                node = temp;
            }
            node = node->next;
        }
    }
    node = node->next;

}
// Ham in danh sach sach
void inDanhSachSach(Sach* head)
{
    cout << "-------------------------------DANH SACH SACH TRONG THU VIEN--------------------------------\n\n" << endl;
    cout << "+--------------------+---------------+------------+---------------+------------+\n";
    cout << "| " << left << setw(19) << "Ma sach " << "|"
         << setw(15) << "Ten sach " << "|"
         << setw(12) << "Tac gia " << "|"
         << setw(15) << "Nam xuat ban " << "|"
         << setw(12) << "Gia sach " << "|\n";
    cout << "+--------------------+---------------+------------+---------------+------------+\n";
    Sach* node = head;
    while (node != nullptr)
    {
        cout << "| " << left << setw(19) << node->maSach << "|"
             << setw(15) << node->tenSach << "|"
             << setw(12) << node->tacGia << "|"
             << setw(15) << node->namXuatBan << "|"
             << setw(12) << node->giaSach << "|\n";
        node = node->next;
    }
    cout << "+--------------------+---------------+------------+---------------+------------+\n";
}


// Ham them sach vao danh sach lien ket
void themSach(Sach*& head)
{
    Sach* newSach = new Sach;
    cout << "Nhap thong tin sach:" << endl;
    cout << "Ma sach: ";
    cin >> newSach->maSach;
    cout << "Ten sach: ";
    cin.ignore();
    getline(cin, newSach->tenSach);
    cout << "Tac gia: ";
    getline(cin, newSach->tacGia);
    cout << "Nam xuat ban: ";
    cin >> newSach->namXuatBan;
    cout << "Gia sach: ";
    cin >> newSach->giaSach;
    newSach->next = head; // Thêm vào d?u danh sách
    head = newSach;
    cout << "Them sach thanh cong." << endl;
}
// Ham kiem tra cccd co hop le hay khong
bool isValidCCCD(const string& cccd, DocGia* danhSachDocGia) {
    DocGia* node = danhSachDocGia;
    while (node != nullptr) {
        if (node->cccd == cccd) {
            return true;
        }
        node = node->next;
    }
    return false;
}

// Ham kiem tra ma sach co hop le hay khong
bool isValidMaSach(const string& maSach, Sach* danhSachSach) {
    Sach* node = danhSachSach;
    while (node != nullptr) {
        if (node->maSach == maSach) {
            return true;
        }
        node = node->next;
    }
    return false;
}
