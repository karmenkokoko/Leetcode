#include <bits/stdc++.h>
using namespace std;
// 高精度乘法

vector<int> multi(vector<int>& A, int b)
{
    vector<int> C;
    int t;
    for (int i = 0; i < A.size() || t; i++)
    {
        // 可能进位大于10
        if(i < A.size()) t = t + A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

int main()
{
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    vector<int> C;

    C = multi(A, b);

    for(int i = C.size()-1; i>=0; i--) cout << C[i];
    cout << endl;
    return 0;
}