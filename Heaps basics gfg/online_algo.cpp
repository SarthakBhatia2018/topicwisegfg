#include <iostream>
#include <vector>

using namespace std;

double find_median(vector<int> v)
{
    int n = v.size();
    if (n & 1 == 1)
        return v[n / 2];
    else
        return double(v[n / 2] + v[n / 2 - 1]) / 2.0;
}

void print_vec(vector<int> v)
{
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}

void insertion_sort(vector<int> &v, int key)
{
    int n = v.size();
    v.resize(n + 1);
    bool flag = true;
    for (int i = 0; i < v.size(); ++i)
    {
        if (key < v[i])
        {
            flag = false;
            for (int j = n - 1; j >= i; --j)
            {
                v[j + 1] = v[j];
            }
            v[i] = key;
            break;
        }
        if (!flag)
            break;
    }
    if (flag)
        v[n] = key;
}
int main()
{
    vector<int> v;
    cout << "Enter integers to find median :(Press Ctrl-C to stop)\n\n";
    while (true)
    {
        int n;
        cin >> n;
        insertion_sort(v, n);
        print_vec(v);
        cout << find_median(v) << endl;
    }
    return 0;
}