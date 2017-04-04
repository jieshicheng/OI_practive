#include <iostream>
#include <utility>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> x(n), y(n), z(n);
    vector<int> times(n);
    pair<int,int> bx, by, bz;
    for(int i = 0; i != n; ++i)
    {
        cin>>x[i].first>>y[i].first>>z[i].first;
        cin>>x[i].second>>y[i].second>>z[i].second;
        cin>>times[i];
    }
    cin>>bx.first>>by.first>>bz.first;
    cin>>bx.second>>by.second>>bz.second;
    for(int i = 0; i != n; ++i)
    {
        bx.first += (x[i].first) * times[i];
        by.first += (y[i].first) * times[i];
        bz.first += (z[i].first) * times[i];
        bx.second += (x[i].second) * times[i];
        by.second += (y[i].second) * times[i];
        bz.second += (z[i].second) * times[i];
    }
    float ans = sqrt(pow(bx.second - bx.first, 2) + pow(by.second - by.first, 2) + pow(bz.second - bz.first, 2));
    printf("%.4f", ans);
    return 0;
}
