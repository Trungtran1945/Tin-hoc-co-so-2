#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Lưu thông tin sách
struct book
{
    string isbn;
    string tenSach;
    string tacGia;
};

// Tạo cây nhị phân để lưu thông tin sách trong thư viện
struct node
{
    book data;
    node *left;
    node *right;
};

// tạo đanh sách liên kết đơn để lưu thông tin sách đang mượn
struct borrowNode
{
    book data;
    borrowNode *next;
};

// Thêm sách vào thư viện (nếu cần)
node *insert(node *library, book sach)
{
    if (library == NULL)
    {
        node *temp = new node;
        temp->data = sach;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    else
    {
        if (sach.isbn < library->data.isbn)
        {
            library->left = insert(library->left, sach);
        }
        else
        {
            library->right = insert(library->right, sach);
        }
        return library;
    }
}

// Tìm kiếm sách trong thư viện dựa theo mã ISBN
book *search(node *library, const string &isbn)
{
    if (library == NULL)
        return NULL;
    if (isbn == library->data.isbn)
    {
        return &library->data;
    }
    if (isbn < library->data.isbn)
    {
        return search(library->left, isbn);
    }
    else
    {
        return search(library->right, isbn);
    }
}

// Tạo Node sách đang mượn
borrowNode *createBorrowNode(book sach)
{
    borrowNode *temp = new borrowNode;
    temp->data = sach;
    temp->next = NULL;
    return temp;
}
// Thêm sách vào danh sách đang mượn
borrowNode *addBorrowNode(borrowNode *library, book sach)
{
    borrowNode *temp = createBorrowNode(sach);

    if (library == NULL)
    {
        return temp; // danh sách đang rỗng -> node mới là đầu
    }

    borrowNode *p = library;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    return library; // trả về đầu danh sách không thay đổi
}

// Trả sách đang mượn về thư viện
borrowNode *returnBook(borrowNode *library, string isbn, bool &success)
{
    success = false;
    if (library == NULL)
        return NULL;

    // Trường hợp node đầu
    if (library->data.isbn == isbn)
    {
        borrowNode *temp = library;
        temp = temp->next;
        delete (library);
        success = true;
        return temp;
    }
    // Trường hợp node giữa/cuối
    borrowNode *prev = library;
    borrowNode *curr = library->next;
    while (curr != NULL)
    {
        if (curr->data.isbn == isbn)
        {

            {
                prev->next = curr->next;
                delete (curr);
                success = true;
                return library;
            }
        }
        prev = curr;
        curr = curr->next;
    }

    return library;
}

// In sách trong thư viện
void printSachThuVien(node *library)
{
    if (library != NULL)
    {
        printSachThuVien(library->left);
        cout << "ISBN: " << library->data.isbn << endl;
        cout << "TIEU DE: " << library->data.tenSach << endl;
        cout << "TAC GIA: " << library->data.tacGia << endl;
        cout << "     .....     " << endl;
        printSachThuVien(library->right);
    }
}

// In sách đang mượn
void printSachMuon(borrowNode *library)
{
    borrowNode *p = library;
    if (p == NULL)
    {
        cout << "Khong co sach nao dang duoc muon!\n";
        return;
    }
    while (p != NULL)
    {
        cout << "ISBN: " << p->data.isbn << endl;
        cout << "TIEU DE: " << p->data.tenSach << endl;
        cout << "TAC GIA: " << p->data.tacGia << endl;
        cout << "     .....     " << endl;
        p = p->next;
    }
}

// ==== Đọc dữ liệu sách từ file ====
void loadBooksFromFile(const string &filename, node *&root)
{
    ifstream file(filename);
    if (!file)
    {
        cout << "Khong mo duoc file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        book newBook;
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);

        if (pos1 != string::npos && pos2 != string::npos)
        {
            newBook.isbn = line.substr(0, pos1);
            newBook.tenSach = line.substr(pos1 + 1, pos2 - pos1 - 1);
            newBook.tacGia = line.substr(pos2 + 1);
            root = insert(root, newBook);
        }
    }

    file.close();
    cout << "DA NAP DU LIEU TU FILE '" << filename << "' VAO THU VIEN.\n";
}

void showMenu()
{
    cout << "\n==== MENU QUAN LY SACH ====\n";
    cout << "1. Them sach vao thu vien\n";
    cout << "2. Hien thi danh sach sach trong thu vien\n";
    cout << "3. Muon sach\n";
    cout << "4. Tra sach\n";
    cout << "5. Hien thi danh sach sach dang muon\n";
    cout << "9. Hien thi lai Menu \n";
    cout << "0. Thoat\n";
}
int main()
{
    node *library = NULL;
    borrowNode *borrowedList = NULL;
    int choice;
    // Tải dữ liệu sách từ file trước khi chạy menu
    loadBooksFromFile("books.txt", library);
    showMenu();
    while (true)
    {
        cout << "\nNHAP LUA CHON: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            book newBook;
            cout << "Nhap ISBN: ";
            getline(cin, newBook.isbn);
            cout << "Nhap Tieu De: ";
            getline(cin, newBook.tenSach);
            cout << "Nhap Ten Tac Gia: ";
            getline(cin, newBook.tacGia);
            library = insert(library, newBook);
            cout << "DA THEM DANH SACH VAO THU VIEN.\n";
            break;
        }
        case 2:
        {
            cout << "\nDANH SACH CAC SACH TRONG THU VIEN: \n";
            printSachThuVien(library);
            break;
        }
        case 3:
        {
            string isbn;
            cout << "Nhap ISBN sach can muon: ";
            getline(cin, isbn);
            book *Book = search(library, isbn);
            if (Book != NULL)
            {
                borrowedList = addBorrowNode(borrowedList, *Book);
                cout << "DA MUON SACH: " << Book->tenSach << endl;
            }
            else
            {
                cout << "KHONG TIM THAY SACH VOI ISBN NAY.\n";
            }
            break;
        }
        case 4:
        {
            string isbn;
            cout << "\nNHAP ISBN SACH MUON TRA: ";
            getline(cin, isbn);
            bool success;
            borrowedList = returnBook(borrowedList, isbn, success);
            if (success)
                cout << "DA TRA SACH THANH CONG!\n";
            else
                cout << "KHONG TIM THAY SACH VOI ISBN NAY TRONG DANH SACH MUON!\n";

            break;
        }

        case 5:
        {
            cout << "DANH SACH TAT CA SACH DANG MUON: \n";
            printSachMuon(borrowedList);
            break;
        }
        case 9:
        {
            showMenu();
            break;
        }
        case 0:
        {
            cout << "TAM BIET!\n";
            return 0;
        }
        default:
            cout << "LUA CHON KHONG HOP LE. VUI LONG CHON LAI!\n";
            showMenu();
        }
    }
    return 0;
}
