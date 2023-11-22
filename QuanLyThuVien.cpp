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
// Ham lap phieu muon
void lapPhieuMuon(PhieuMuon*& head, DocGia* danhSachDocGia, Sach* danhSachSach)
{
    PhieuMuon* newPhieuMuon = new PhieuMuon;
    cout << "Nhap thong tin phieu muon sach:" << endl;

   
    cout << "CCCD doc gia: ";
    cin >> newPhieuMuon->cccd;
    if (!isValidCCCD(newPhieuMuon->cccd, danhSachDocGia)) {
        cout << "CCCD khong hop le. Lap phieu muon that bai." << endl;
        delete newPhieuMuon;
        return;
    }
    

    
    cout << "Ma sach muon: ";
    cin >> newPhieuMuon->maSach;
    if (!isValidMaSach(newPhieuMuon->maSach, danhSachSach)) {
        cout << "Ma sach khong hop le. Lap phieu muon that bai." << endl;
        delete newPhieuMuon;
        return;
    }
    
    PhieuMuon* temp = head;
    while (temp != nullptr) {
        if (temp->maSach == newPhieuMuon->maSach) {
            cout << "Sach da duoc muon. Lap phieu muon that bai." << endl;
            delete newPhieuMuon;
            return;
        }
        temp = temp->next;
    }

    
    cout << "Nhap ngay muon (dd): ";
    cin >> newPhieuMuon->ngayMuon;
    cout << "Nhap thang muon (mm): ";
    cin >> newPhieuMuon->thangMuon;
    cout << "Nhap nam muon (yyyy): ";
    cin >> newPhieuMuon->namMuon;
    newPhieuMuon->next = head;
    head = newPhieuMuon;
    cout << "Lap phieu muon thanh cong." << endl; 
}

// Khai bao cho biet so ngay muon toi da la 7
const int MAX_BORROW_DAYS = 7;


// Ham lap phieu tra
void lapPhieuTra(PhieuMuon*& danhSachPhieuMuon, Sach* danhSachSach)
{
    string cccd;
    string maSach;
    cout << "Nhap thong tin phieu tra sach:" << endl;
    cout << "CCCD doc gia: ";
    cin >> cccd;
    cout << "Ma sach tra: ";
    cin >> maSach;

    // Kiem tra xem co phieu muon nao tuong ung khong
    PhieuMuon* phieuMuon = danhSachPhieuMuon;
    PhieuMuon* phieuMuonTruocDo = nullptr;

    while (phieuMuon != nullptr)
    {
        if (phieuMuon->cccd == cccd && phieuMuon->maSach == maSach)
        {
            // Nhap ngay tra
            int ngayTra, thangTra, namTra;
            cout << "Nhap ngay tra (dd): ";
            cin >> ngayTra;
            cout << "Nhap thang tra (mm): ";
            cin >> thangTra;
            cout << "Nhap nam tra (yyyy): ";
            cin >> namTra;

            // Tinh so ngay tre han
            int soNgayTreHan = 0;

            // Tinh ngay tra du kien
            int ngayTraDuKien = phieuMuon->ngayMuon + MAX_BORROW_DAYS;
            int thangTraDuKien = phieuMuon->thangMuon;
            int namTraDuKien = phieuMuon->namMuon;

            while (ngayTraDuKien > 30)
            {
                ngayTraDuKien -= 30;
                thangTraDuKien++;
                if (thangTraDuKien > 12)
                {
                    thangTraDuKien = 1;
                    namTraDuKien++;
                }
            }

            // So sanh ngay tra du kien voi ngay tra thuc te
            if (namTra > namTraDuKien || (namTra == namTraDuKien && thangTra > thangTraDuKien) || (namTra == namTraDuKien && thangTra == thangTraDuKien && ngayTra > ngayTraDuKien))
            {
                // Tinh so ngay tre han
                time_t now = time(0);
                tm* ltm = localtime(&now);

                int ngayHienTai = ltm->tm_mday;
                int thangHienTai = 1 + ltm->tm_mon;
                int namHienTai = 1900 + ltm->tm_year;

                soNgayTreHan = (ngayTra - ngayTraDuKien) + (thangTra - thangTraDuKien) * 30 + (namTra - namTraDuKien) * 365;
            }

            // Tinh tien phat
            float tienPhat = 0;
            if (soNgayTreHan > 0)
            {
                tienPhat = soNgayTreHan * 5000; // Phat 5000 VND moi ngay tre han
            }

            // In thong tin phieu tra
            cout << "\n----- Thong tin phieu tra -----\n";
            cout << "CCCD doc gia: " << cccd << endl;
            cout << "Ma sach tra: " << maSach << endl;
            cout << "Ngay muon: " << phieuMuon->ngayMuon << "/" << phieuMuon->thangMuon << "/" << phieuMuon->namMuon << endl;
            cout << "Ngay tra du kien: " << ngayTraDuKien << "/" << thangTraDuKien << "/" << namTraDuKien << endl;
            cout << "Ngay tra thuc te: " << ngayTra << "/" << thangTra << "/" << namTra << endl;
            cout << "So ngay tre han: " << soNgayTreHan << endl;
            cout << "Tien phat: " << tienPhat << " VND\n";
            cout << "-----------------------------\n";
            
            Sach* sach = danhSachSach;
    while (sach != nullptr)
    {
        if (sach->maSach == maSach)
        {
            sach->daMuon = false; // Mark the book as returned
            break;
        }
        sach = sach->next;
    }

            // Xoa phieu muon khoi danh sach
            if (phieuMuonTruocDo != nullptr)
            {
                phieuMuonTruocDo->next = phieuMuon->next;
            }
            else
            {
                danhSachPhieuMuon = phieuMuon->next;
            }
            delete phieuMuon;

            cout << "Lap phieu tra thanh cong." << endl;
            return;
        }

        phieuMuonTruocDo = phieuMuon;
        phieuMuon = phieuMuon->next;
    }

    cout << "Khong tim thay thong tin phieu muon tuong ung. Lap phieu tra that bai." << endl;
}

void thongKeSach(DocGia* danhSachDocGia, Sach* danhSachSach) {
    cout << "\n";
    inDanhSachSach(danhSachSach);
    cout << "\n";
    inDanhSachDocGia(danhSachDocGia);
}


// Ham giai phong bo nho
void giaiPhongDanhSach(DocGia*& head)
{
    while (head != nullptr)
    {
        DocGia* temp = head;
        head = head->next;
        delete temp;
    }
}

void giaiPhongDanhSach(Sach*& head)
{
    while (head != nullptr)
    {
        Sach* temp = head;
        head = head->next;
        delete temp;
    }
}

void giaiPhongDanhSach(PhieuMuon*& head)
{
    while (head != nullptr)
    {
        PhieuMuon* temp = head;
        head = head->next;
        delete temp;
    }
}



int main()
{
    int Menu;
    bool flagmenu = true;
    DocGia* danhSachDocGia = nullptr;
    Sach* danhSachSach = nullptr;
    PhieuMuon* danhSachPhieuMuon = nullptr; 
    int Menucon;
    bool flagmenucon;

    clrscr();
	cout << "Chuong trinh quan ly thu vien" << endl;
    do
    {
    	
        cout << "1. Quan ly doc gia" << endl;
        cout << "2. Quan ly sach" << endl;
        cout << "3. Lap phieu muon sach" << endl;
        cout << "4. Lap phieu tra sach" << endl;
        cout << "5. Thong ke" << endl;
        cout << "6. Thoat" << endl;
        cout << "Chon chuc nang: ";
        cin >> Menu;

        switch (Menu)
        {
        case 1:
        	clrscr();
            cout << "Chuc nang quan ly doc gia" << endl;
            do
            {
            	
                cout << "1. Xem danh sach doc gia trong thu vien" << endl;
                cout << "2. Them doc gia" << endl;
                cout << "3. Chinh sua thong tin doc gia" << endl;
                cout << "4. Xoa thong tin 1 doc gia" << endl;
                cout << "5. Tim kiem doc gia theo cccd" << endl;
                cout << "6. Tim kiem doc gia theo ho ten" << endl;
                cout << "7. Quay lai" << endl;
                cout << "Chon chuc nang: ";
                cin >> Menucon;
                

                switch (Menucon)
                {
                case 1:
                	clrscr();
                    inDanhSachDocGia(danhSachDocGia);
                    break;
                case 2:
                    themDocGia(danhSachDocGia);
                    break;
                case 3:
                    chinhSuaDocGia(danhSachDocGia);
                    break;
                case 4:
                    xoaDocGia(danhSachDocGia);
                    break;
                case 5:
                    timKiemDocGiaTheoCCCD(danhSachDocGia);
                    break;
                case 6:
                    timKiemDocGiaTheoTen(danhSachDocGia);
                    break;
                default:
                    flagmenucon = false;
                    break;
                }

            } while (flagmenucon);
            
        break;
       case 2:
    clrscr();
    cout << "Chuc nang quan ly sach" << endl;
    do
    {
        cout << "1. Xem danh sach sach trong thu vien" << endl;
        cout << "2. Them sach" << endl;
        cout << "3. Sap xep sach theo gia tien" << endl;
        cout << "4. Quay lai" << endl;
        cout << "Chon chuc nang: ";
        cin >> Menucon;

        switch (Menucon)
        {
        case 1:
            clrscr();
            inDanhSachSach(danhSachSach);
            break;
        case 2:
            themSach(danhSachSach);
            break;
        case 3:
            sapXepSachTheoGia(danhSachSach);
            cout << "Danh sach sach da duoc sap xep theo gia tien." << endl;
            break;
        // Thêm x? lý cho các ch?c nang qu?n lý sách khác
        default:
            flagmenucon = false;
            break;
        }

    } while (flagmenucon);
    break;

        case 3:
            clrscr();
            cout << "Lap phieu muon sach" << endl;
            lapPhieuMuon(danhSachPhieuMuon, danhSachDocGia, danhSachSach);
            break;
        case 4:
    clrscr();
    cout << "Lap phieu tra sach" << endl;
    lapPhieuTra(danhSachPhieuMuon, danhSachSach);
    break;
        case 5:
        clrscr();
        cout << "Thong ke" << endl;
        thongKeSach(danhSachDocGia, danhSachSach);
        break;
         case 6:
            flagmenu = false;
            cout << "Ket thuc chuong trinh." << endl;
            break;
		
        }
         
    } while (flagmenu);
    	

    // Giai phong bo nho truoc khi ket thuc chuong trinh
    giaiPhongDanhSach(danhSachDocGia);
    giaiPhongDanhSach(danhSachSach);
    giaiPhongDanhSach(danhSachPhieuMuon);
    return 0;
}
