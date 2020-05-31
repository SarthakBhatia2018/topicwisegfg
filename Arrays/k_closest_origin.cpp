    #include <iostream>
    #include <queue>
    #include <math.h>

    using namespace std;

    void find_close(pair<int, int> arr[], int n, int k)
    {
        priority_queue<pair<int, pair<int, int>>> f;
        for (int i = 0; i < n; ++i)
        {
            int x = arr[i].first;
            int y = arr[i].second;
            f.push({(x * x + y * y), {x, y}});
            if (f.size() > k)
                f.pop();
        }
        while (!f.empty())
        {
            cout << f.top().second.first << " " << f.top().second.second << endl;
            f.pop();
        }
    }

    int main()
    {
        pair<int, int> arr[] = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}, {0, 2}};
        int k = 3;
        int n = sizeof(arr) / sizeof(arr[0]);
        find_close(arr, n, k);
        return 0;
    }