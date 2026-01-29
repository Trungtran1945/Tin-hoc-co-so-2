#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Kiểm tra xem một số có cân bằng chẵn lẻ hay không
bool isBalanced(int number, int N)
{
    int evenCount = 0, oddCount = 0;
    while (number > 0)
    {
        int digit = number % 10;
        if (digit % 2 == 0)
            evenCount++;
        else
            oddCount++;
        number /= 10;
    }
    return evenCount == oddCount;
}

int main()
{
    int N;
    cin >> N;

    int start = pow(10, N - 1); // Số bắt đầu có N chữ số
    int end = pow(10, N) - 1;   // Số kết thúc có N chữ số

    vector<int> balancedNumbers;

    // Lặp qua tất cả các số có N chữ số
    for (int i = start; i <= end; i++)
    {
        if (isBalanced(i, N))
        {
            balancedNumbers.push_back(i);
        }
    }

    // In ra mỗi dòng 10 số
    for (int i = 0; i < balancedNumbers.size(); i++)
    {
        cout << balancedNumbers[i] << " ";
        if ((i + 1) % 10 == 0)
            cout << endl;
    }

    return 0;
}