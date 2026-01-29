// CHỈNH HỢP CHẬP K
// #include <iostream>
// #include <vector>
// using namespace std;

// int n, k;
// vector<int> x;	   // Chứa 1 chỉnh hợp
// vector<bool> used; // Đánh dấu phần tử đã dùng

// void Try(int i)
// {
// 	for (int j = 1; j <= n; j++)
// 	{
// 		if (!used[j])
// 		{
// 			x[i] = j;
// 			used[j] = true;
// 			if (i == k)
// 			{
// 				// In chỉnh hợp
// 				for (int t = 1; t <= k; t++)
// 					cout << x[t] << " ";
// 				cout << endl;
// 			}
// 			else
// 			{
// 				Try(i + 1);
// 			}
// 			used[j] = false; // backtrack
// 		}
// 	}
// }

// int main()
// {
// 	cout << "Nhap n va k (n >= k): ";
// 	cin >> n >> k;

// 	x.resize(k + 1);
// 	used.resize(n + 1, false);

// 	cout << "Tat ca cac chinh hop chap " << k << " cua " << n << " phan tu:\n";
// 	Try(1);

// 	return 0;
// }

// TẬP CON CỦA N PHẦN TỬ
// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;

// int main()
// {
// 	int n;
// 	cout << "Nhap n: ";
// 	cin >> n;

// 	int total = pow(2, n); // Có 2^n tập con

// 	cout << "Tat ca cac tap con cua {1, 2, ..., " << n << "} la:\n";

// 	for (int i = 0; i < total; i++)
// 	{
// 		cout << "{ ";
// 		for (int j = 0; j < n; j++)
// 		{
// 			if (i & (1 << j))
// 			{
// 				cout << j + 1 << " ";
// 			}
// 		}
// 		cout << "}\n";
// 	}

// 	return 0;
// }

// PHÂN TÍCH SỐ NGUYÊN DƯƠNG
#include <iostream>
#include <vector>
using namespace std;

// Hàm đệ quy tìm các cách phân tích số n
void phanTich(int n, int maxSo, vector<int> &total)
{
	// Nếu n == 0, tức là đã phân tích xong
	if (n == 0)
	{
		for (int x : total)
			cout << x << " ";
		cout << endl;
		return;
	}

	// Thử tất cả các số từ min(n, maxSo) trở xuống đến 1
	for (int i = min(n, maxSo); i >= 1; i--)
	{
		total.push_back(i);		   // Thêm số i vào phân tích hiện tại
		phanTich(n - i, i, total); // Gọi đệ quy với n giảm i và maxSo mới là i
		total.pop_back();		   // Quay lui
	}
}

int main()
{
	int n;
	cout << "Nhap so nguyen duong n: ";
	cin >> n;

	vector<int> total;
	cout << "Cac cach phan tich " << n << " la:\n";
	phanTich(n, n, total);

	return 0;
}
