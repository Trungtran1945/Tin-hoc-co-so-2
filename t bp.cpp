// #include <iostream>
// using namespace std;
// int main()
// {
// 	int n, m;
// 	cin >> n >> m;
// 	int **a;
// 	a = new int *[n];
// 	for (int i = 0; i < n; i++)
// 	{
// 		a[i] = new int[m];
// 	}
// 	for (int i = 0; i < n; i++)
// 	{
// 		for (int j = 0; j < m; j++)
// 		{
// 			cin >> a[i][j];
// 		}
// 	}
// 	for (int i = 0; i < n; i++)
// 	{
// 		int sum = 0;
// 		for (int j = 0; j < m; j++)
// 		{
// 			sum += a[i][j];
// 		}
// 		cout << sum << " ";
// 	}
// 	for (int i = 0; i < n; i++)
// 	{
// 		delete[] a[i];
// 	}
// 	delete[] a;
// 	return 0;
// }
// .
// .
// .
// #include <iostream>
// using namespace std;
// struct student
// {
//     string name;
//     int age;
//     int score;
// };
// int main()
// {
//     int n;
//     cin >> n;
//     student s[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> s[i].name >> s[i].age >> s[i].score;
//     }
//     student a = s[0];
//     for (int i = 0; i < n; i++)
//     {
//         if (a.score < s[i].score)
//         {
//             a = s[i];
//         }
//     }
//     cout << "Ten: " << a.name << endl;
//     cout << "Tuoi: " << a.age << endl;
//     cout << "Diem: " << a.score << endl;
//     return 0;
// }
// .
// .
// .
// #include <iostream>
// using namespace std;
// class Hcn
// {
// public:
//     double a;
//     double b;
//     void nhap()
//     {
//         cin >> a;
//         cin >> b;
//     }
//     double getdientich()
//     {
//         return a * b;
//     }
//     double getchuvi()
//     {
//         return (a + b) * 2;
//     }
//     void display()
//     {
//         cout << "Area: " << getdientich() << endl;
//         cout << "Perimeter: " << getchuvi() << endl;
//     }
// };
// int main()
// {
//     Hcn p;
//     p.nhap();
//     p.display();
//     return 0;
// }
// .
// .
// .
// #include <iostream>
// using namespace std;
// class Student
// {
// private:
//     string name;
//     int age;

// public:
//     Student(string name, int age)
//     {
//         this->name = name;
//         this->age = age;
//     }
//     void display()
//     {
//         cout << "Name: " << name << endl;
//         cout << "Age: " << age << endl;
//     }
// };
// int main()
// {
//     Student s1("Long", 24);
//     s1.display();
//     Student s2("Kien", 29);
//     s2.display();
//     return 0;
// }
// .
// .
// .
// #include <iostream>

// using namespace std;

// class Student
// {
// private:
//     string name;
//     int age;

// public:
//     static int numberOfStudents;
//     Student(string name, int age)
//     {
//         this->name = name;
//         this->age = age;
//     }
// };

// int Student::numberOfStudents = 0;

// int main()
// {
//     Student s1("Manh", 19);
//     Student s2("Trung", 19);
//     s1.numberOfStudents = 3;
//     s2.numberOfStudents = 4;
//     cout << s1.numberOfStudents << " " << s2.numberOfStudents;
//     return 0;
// }
// .
// .
// .
// #include <iostream>

// using namespace std;

// class Math
// {
// public:
//     static int max(int a, int b)
//     {
//         return a > b ? a : b;
//     }
//     static int min(int a, int b)
//     {
//         return a < b ? a : b;
//     }
// };

// int main()
// {
//     cout << Math::max(2, 3) << endl;
//     cout << Math::min(2, 3) << endl;
//     return 0;
// }
// .
// .
// .
// #include <iostream>
// using namespace std;
// class Student
// {
// private:
//     string name;
//     char gender;

// public:
//     Student()
//     {
//         name = "Unknown";
//         gender = 'u';
//     }
//     Student(string name)
//     {
//         this->name = name;
//         gender = 'u';
//     }
//     Student(char gender)
//     {
//         this->gender = gender;
//         name = "Unknown";
//     }
//     Student(string name, char gender)
//     {
//         this->name = name;
//         this->gender = gender;
//     }
//     void display()
//     {
//         cout << "Name: " << name << endl;
//         if (gender == 'f')
//         {
//             cout << "Gender: Female" << endl;
//         }
//         if (gender == 'm')
//         {
//             cout << "Gender: Male" << endl;
//         }
//         if (gender == 'u')
//         {
//             cout << "Gender: Unknown" << endl;
//         }
//     }
// };
// int main()
// {
//     Student s1;
//     s1.display();
//     Student s2("Quang");
//     s2.display();
//     Student s3('m');
//     s3.display();
//     Student s4("Thu", 'f');
//     s4.display();
//     return 0;
// }
// .
// .
// .
// #include <iostream>
// using namespace std;
// class Student
// {
// private:
//     int id;
//     string name;
//     int age;
//     string address;
//     int score;

// public:
//     Student()
//     {
//     }

//     Student(int id, string name, int age, string address, int score)
//     {
//         this->id = id;
//         this->name = name;
//         this->age = age;
//         this->address = address;
//         this->setScore(score);
//     }
//     int getId()
//     {
//         return id;
//     }
//     void setId(int id)
//     {
//         this->id = id;
//     }
//     string getName()
//     {
//         return name;
//     }
//     void setName(string name)
//     {
//         this->name = name;
//     }
//     int getAge()
//     {
//         return age;
//     }
//     void setAge(int age)
//     {
//         this->age = age;
//     }
//     string getAddress()
//     {
//         return address;
//     }
//     void setAddress(string address)
//     {
//         this->address = address;
//     }
//     int getScore()
//     {
//         return score;
//     }
//     void setScore(int score)
//     {
//         if (score < 0)
//         {
//             this->score = 0;
//         }
//         else if (score > 10)
//         {
//             this->score = 10;
//         }
//         else
//         {
//             this->score = score;
//         }
//     }
// };
// int main()
// {
//     Student s(1001, "Trung", 24, "Ha Noi", 5);
//     cout << s.getId() << endl;
//     ;
//     cout << s.getName() << endl;
//     ;
//     cout << s.getAge() << endl;
//     ;
//     cout << s.getAddress() << endl;
//     ;
//     cout << s.getScore() << endl;
//     ;
//     s.setScore(-7);
//     cout << s.getScore() << endl;
//     ;
//     s.setScore(15);
//     cout << s.getScore() << endl;
//     ;
//     return 0;
// }
// .
// .
// .
// #include <iostream>
// using namespace std;

// class Person
// {
// private:
//     string name;
//     int dob;
//     double gpa;

// public:
//     Person(string name, int dob, double gpa)
//     {
//         this->name = name;
//         this->dob = dob;
//         this->gpa = gpa;
//     }
//     string getName()
//     {
//         return name;
//     }
//     void setName(string name)
//     {
//         this->name = name;
//     }
//     int getDob()
//     {
//         return dob;
//     }
//     void setDob(int dob)
//     {
//         this->dob = dob;
//     }
//     double getGpa()
//     {
//         return gpa;
//     }
//     void setGpa(double gpa)
//     {
//         this->gpa = gpa;
//     }
// };

// class Student : public Person
// {
// public:
//     Student(string name, int dob, double gpa) : Person(name, dob, gpa)
//     {
//     }
// };

// int main()
// {
//     Student s("Hai", 1999, 8.8);
//     cout << "Name: " << s.getName() << endl;
//     cout << "Date of birth: " << s.getDob() << endl;
//     cout << "GPA: " << s.getGpa() << endl;
//     return 0;
// }
// .
// .
// .
// #include <iostream>
// using namespace std;
// class Student
// {
// private:
//     string name;
//     int dob;
//     double gpa;

// public:
//     string getName()
//     {
//         return name;
//     }
//     void setName(string name)
//     {
//         this->name = name;
//     }
//     int getDob()
//     {
//         return dob;
//     }
//     void setDob(int dob)
//     {
//         this->dob = dob;
//     }
//     double getGpa()
//     {
//         return gpa;
//     }
//     void setGpa(double gpa)
//     {
//         this->gpa = gpa;
//     }
//     void nhap()
//     {
//         getline(cin, name);
//         cin >> dob;
//         cin >> gpa;
//     }
//     void xuat()
//     {
//         cout << "Name: " << name << endl;
//         cout << "Date of birth: " << dob << endl;
//         cout << "GPA: " << gpa << endl;
//     }
// };
// int main()
// {
//     Student s;
//     s.nhap();
//     s.xuat();
//     return 0;
// }
// .
// .
// .
// #include <bits/stdc++.h>
// using namespace std;
// #include <conio.h>
// int main()
// {
//     string n;
//     cin >> n;
//     string a;
//     a = n.substr(3, 3);
//     cout << a << endl;
//     getch();
//     system("cls");
//     return 0;
// }
// .
// .
// .
// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     string s;
//     cin >> s;
//     s.erase(5);
//     cout << s << endl;
//     return 0;
// }

#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

struct TNode
{
    int data;
    TNode *pLeft;
    TNode *pRight;
};
typedef TNode *tree;
typedef TNode *node;

int InitTree(tree &t)
{
    t = NULL;
}

bool emty(tree t)
{
    return (t == NULL);
}

tree makeNode(int x)
{
    tree tmp = new TNode();
    tmp->data = x;
    tmp->pLeft = NULL;
    tmp->pRight = NULL;
    return tmp;
}
void addNode(tree &t, int x)
{
    tree tmp = makeNode(x);
    if (t == NULL)
    {
        t = tmp;
    }
    else
    {
        if (t->data > x)
        {
            addNode(t->pLeft, x);
        }
        else if (t->data < x)
        {
            addNode(t->pRight, x);
        }
    }
}

void xuat_NLR(tree t)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        xuat_NLR(t->pLeft);
        xuat_NLR(t->pRight);
    }
}
void xuat_LNR(tree t) // tuong duong in ra phan tu tu be den lon
{
    if (t != NULL)
    {
        xuat_LNR(t->pLeft);
        cout << t->data << " ";
        xuat_LNR(t->pRight);
    }
}
void xuat_LRN(tree t)
{
    if (t != NULL)
    {
        xuat_LRN(t->pLeft);
        xuat_LRN(t->pRight);
        cout << t->data << " ";
    }
}

tree Search(tree t, int x)
{
    if (t == NULL)
    {
        return NULL;
    }
    else
    {
        if (x < t->data)
        {
            return Search(t->pLeft, x);
        }
        else if (x > t->data)
        {
            return Search(t->pRight, x);
        }
        else
        {
            return t;
        }
    }
}

void Node2Con(tree t)
{
    if (t != NULL)
    {
        if (t->pLeft != NULL && t->pRight != NULL)
        {
            cout << t->data << " ";
        }

        Node2Con(t->pLeft);
        Node2Con(t->pRight);
    }
}

void Node1Con(tree t)
{
    if (t != NULL)
    {
        if ((t->pLeft != NULL && t->pRight == NULL) || (t->pLeft == NULL && t->pRight != NULL))
        {
            cout << t->data << " ";
        }

        Node1Con(t->pLeft);
        Node1Con(t->pRight);
    }
}

void NodeLa(tree t)
{
    if (t != NULL)
    {
        if (t->pLeft == NULL && t->pRight == NULL)
        {
            cout << t->data << " ";
        }

        NodeLa(t->pLeft);
        NodeLa(t->pRight);
    }
}

int NodeMax(tree t)
{
    if (t->pRight == NULL)
    {
        return t->data;
    }
    return NodeMax(t->pRight);
}
int NodeMin(tree t)
{
    if (t->pLeft == NULL)
    {
        return t->data;
    }
    return NodeMin(t->pLeft);
}

void timNodeTheMang(tree &x, tree &y)
{
    // duyet sang trai nhat cua cay con phai
    if (y->pLeft != NULL)
    {
        timNodeTheMang(x, y->pLeft);
    }
    else
    {
        x->data = y->data; // cap nhat data cua node can xoa la data node the mang
        x = y;
        y = y->pRight;
    }
    // duyet sang phai nhat cua cay con trai
    // if (y->pRight != NULL)
    // {
    //     timNodeTheMang(x, y->pRight);
    // }
    // else
    // {
    //     x->data = y->data; // cap nhat data cua node can xoa la data node the mang
    //     x = y;
    //     y = y->pLeft;
    // }
}

void DeleteNode(tree &t, int data) // data la gia tri node can
{
    if (t == NULL)
    {
        return;
    }
    else
    {
        if (data < t->data)
        {
            DeleteNode(t->pLeft, data);
        }
        else if (data > t->data)
        {
            DeleteNode(t->pRight, data);
        }
        else
        {
            tree x = t;
            if (t->pLeft == NULL)
            {
                t = t->pRight;
            }
            else if (t->pRight == NULL)
            {
                t = t->pLeft;
            }
            else // node can xoa la node co 2 con
            {
                // c1: tim node trai nhat cua cay con phai
                timNodeTheMang(x, t->pRight);
                // c2: tim node phai nhat cua cay con trai
                //  timNodeTheMang(x, t->pLeft);
            }
            delete x;
        }
    }
}

void DeleteTree(tree &t)
{
    t = NULL;
}

int DoCaoCay(tree t)
{
    if (t == NULL || (t->pLeft == NULL && t->pRight == NULL))
    {
        return 0;
    }
    else
    {
        int left = DoCaoCay(t->pLeft);
        int right = DoCaoCay(t->pRight);
        return 1 + max(left, right);
    }
}

void InSoNodeTungMuc(tree t, int start, int level)
{
    if (t != NULL)
    {
        if (start == level)
        {
            cout << t->data << " ";
        }
        else
        {
            start++;
            InSoNodeTungMuc(t->pLeft, start, level);
            InSoNodeTungMuc(t->pRight, start, level);
        }
    }
}
int DoDaiDuongDi(tree t, int x, int length)
{
    if (t == NULL)
    {
        return -1;
    }
    else
    {
        if (t->data > x)
        {
            return DoDaiDuongDi(t->pLeft, x, length + 1);
        }
        else if (t->data < x)
        {
            return DoDaiDuongDi(t->pRight, x, length + 1);
        }
        else
        {
            return length;
        }
    }
}
bool timSoNguyenTo(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return n > 1;
}
void XuatSoNguyenTo(tree t)
{
    if (t != NULL)
    {
        XuatSoNguyenTo(t->pLeft);
        if (timSoNguyenTo(t->data))
        {
            cout << t->data << " ";
        }
        XuatSoNguyenTo(t->pRight);
    }
}

int main()
{
    tree t;
    InitTree(t);

    while (1)
    {
        cout << "\n============MENU============\n";
        cout << "0. Thoat khoi chuong trinh\n";
        cout << "1. Chen phan tu vao cay\n";
        cout << "2. Xuat cay NLR\n";
        cout << "3. Xuat cay LNR (xuat tu be den lon)\n";
        cout << "4. Xuat cay LRN\n";
        cout << "5. Tim kiem phan tu trong cay\n";
        cout << "6. Node co 2 con\n";
        cout << "7. Node co 1 con\n";
        cout << "8. Node co la\n";
        cout << "9. Node co gia tri MAX\n";
        cout << "10.Node co gia tri MIN\n";
        cout << "11.Xoa 1 Node\n";
        cout << "12.Xoa toan bo cay\n";
        cout << "13.Do cao cay\n";
        cout << "14.In so Node tren tung muc\n";
        cout << "15.Do dai duong di tu Node goc den Node X\n";
        cout << "16.Cac so nguyen to co trong cay\n";
        cout << "\n============================\n";
        cout << "Nhap lua chon: ";
        int lc;
        cin >> lc;

        if (lc == 0)
        {
            system("cls");
            cout << "\nCam on da su dung chuong trinh!\n \n";
            exit(1);
        }
        else if (lc == 1)
        {
            // int x;
            // cout << "Nhap gia tri can chen: ";
            // cin >> x;
            // addNode(t, x);
            addNode(t, 5);
            addNode(t, -5);
            addNode(t, -6);
            addNode(t, 0);
            addNode(t, 6);
            addNode(t, 7);
            addNode(t, 10);
            addNode(t, 9);
            addNode(t, 18);

            cout << "\nNhap mot phim bat ki de tiep tuc!\n";
            _getch();
            system("cls");
        }
        else if (lc == 2)
        {
            if (emty(t))
                cout << "Cay rong!\n";
            else
                xuat_NLR(t);
            cout << "\nNhap mot phim bat ki de tiep tuc!\n";
            _getch();
            system("cls");
        }
        else if (lc == 3)
        {
            if (emty(t))
                cout << "Cay rong!\n";
            else
                xuat_LNR(t);
            cout << "\nNhap mot phim bat ki de tiep tuc!\n";
            _getch();
            system("cls");
        }
        else if (lc == 4)
        {
            if (emty(t))
                cout << "Cay rong!\n";
            else
                xuat_LRN(t);
            cout << "\nNhap mot phim bat ki de tiep tuc!\n";
            _getch();
            system("cls");
        }
        else if (lc == 5)
        {
            int tmp;
            cout << "\tNhap so can tim: ";
            cin >> tmp;
            tree check = Search(t, tmp);
            if (check == NULL)
            {
                cout << "Cay khong ton tai phan tu nay!\n";
            }
            else
            {
                cout << "Cay ton tai phan tu nay!\n";
            }
            cout << "\nNhap mot phim bat ki de tiep tuc!\n";
            _getch();
            system("cls");
        }
        else if (lc == 6)
        {
            Node2Con(t);
            cout << "\nNhap mot phim bat ki de tiep tuc!\n";
            _getch();
            system("cls");
        }
        else if (lc == 7)
        {
            Node1Con(t);
            cout << "\nNhap mot phim bat ki de tiep tuc!\n";
            _getch();
            system("cls");
        }
        else if (lc == 8)
        {
            NodeLa(t);
            cout << "\nNhap mot phim bat ki de tiep tuc!\n";
            _getch();
            system("cls");
        }
        else if (lc == 9)
        {
            cout << NodeMax(t);
            cout << "\nNhap mot phim bat ki de tiep tuc!\n";
            _getch();
            system("cls");
        }
        else if (lc == 10)
        {
            cout << NodeMin(t);
            cout << "\nNhap mot phim bat ki de tiep tuc!\n";
            _getch();
            system("cls");
        }
        else if (lc == 11)
        {
            int tmp;
            cout << "\tNhap so can xoa: ";
            cin >> tmp;
            tree check = Search(t, tmp);
            if (check == NULL)
            {
                cout << "Cay khong ton tai phan tu nay!\n";
            }
            else
            {
                DeleteNode(t, tmp);
            }
            cout << "\nNhap mot phim bat ki de tiep tuc!\n";
            _getch();
            system("cls");
        }
        else if (lc == 12)
        {
            DeleteTree(t);
            cout << "\nNhap mot phim bat ki de tiep tuc!\n";
            _getch();
            system("cls");
        }
        else if (lc == 13)
        {
            cout << "Do cao cay: " << DoCaoCay(t) << endl;
            cout << "\nNhap mot phim bat ki de tiep tuc!\n";
            _getch();
            system("cls");
        }
        else if (lc == 14)
        {
            int h = DoCaoCay(t);
            for (int i = 0; i <= h; i++)
            {
                cout << "\nMuc " << i << ": ";
                InSoNodeTungMuc(t, 0, i);
            }
            cout << "\nNhap mot phim bat ki de tiep tuc!\n";
            _getch();
            system("cls");
        }
        else if (lc == 15)
        {
            int x;
            cout << "Nhap x = ";
            cin >> x;
            cout << DoDaiDuongDi(t, x, 0);
            cout << "\nNhap mot phim bat ki de tiep tuc!\n";
            _getch();
            system("cls");
        }
        else if (lc == 16)
        {
            XuatSoNguyenTo(t);
            cout << "\nNhap mot phim bat ki de tiep tuc!\n";
            _getch();
            system("cls");
        }
        else
        {
            cout << "-->Vui long nhap nhung ky tu ghi trong MENU!\n";
            cout << "\nNhap mot phim bat ki de tiep tuc!\n";
            _getch();
            system("cls");
        }
    }
}