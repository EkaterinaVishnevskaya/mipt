//
//  main.cpp
//  waterway
//
//  Created by Екатерина Вишневская on 17.12.15.
//  Copyright (c) 2015 Екатерина Вишневская. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace::std;

class Fenwic
{
public:
    Fenwic()=default;
    
    vector<vector<int>> d;
    vector<vector<int>> up_left;
    vector<vector<int>> up_right;
    vector<vector<int>> down_right;
    vector<vector<int>> down_left;
    int n;
    int m;
    
    
    const int INF = 1000*1000*1000;

    void init (int x, int y)
    {
        n = (int)pow(2, 1+trunc(log(x)/log(2)));
        m = (int)pow(2, 1+trunc(log(y)/log(2)));
        
        up_left.resize(m+1);
        up_right.resize(m+1);
        down_right.resize(m+1);
        down_left.resize(m+1);
        d.resize(m+1);
        for (int i=0; i<=m; i++){
            up_left[i].resize(n+1, INF);
            up_right[i].resize(n+1, INF);
            down_right[i].resize(n+1, INF);
            down_left[i].resize(n+1, INF);
            d[i].resize(n+1, INF);
        };
    }

    int getmin (int l1, int r1, int l2, int r2)
    {
        int result = INF;
        int i=l1;
        int j=r1;
        while((i+i&(-i))<l2)
        {
            j=r1;
            while((j+j&(-j))<r2)
            {
                result=min(result,down_right[i][j]);
                i=i+i&(-i);
                j=j+j&(-j);
            }
        }
        result=min(result,d[i][j]);
        i=l1;
        while((i+i&(-i))<l2)
        {
            j=r2;
            while((j-j&(-j))>r1)
            {
                result=min(result,down_left[i][j]);
                i=i+i&(-i);
                j=j-j&(-j);
            }
        }
        result=min(result,d[i][j]);
        i=l2;
        while((i-i&(-i))>l1)
        {
            j=r1;
            while((j+j&(-j))<r2)
            {
                result=min(result,up_left[i][j]);
                i=i-i&(-i);
                j=j+j&(-j);
            }
        }
        result=min(result,d[i][j]);
        i=l2;
        while((i-i&(-i))>l1)
        {
            j=r2;
            while((j-j&(-j))>r1)
            {
                result=min(result,up_right[i][j]);
                i=i-i&(-i);
                j=j-j&(-j);
            }
        }
        result=min(result,d[i][j]);
        return result;
    }
    
    void set (int l, int r, int new_val)
    {
        d[l][r]=new_val;
        int i=l;
        int j=r;
        while(i<n)
        {
            j=r;
            while(j<m)
            {
                down_right[i][j]=min(down_right[i][j],new_val);
                i=i+i&(-i);
                j=j+j&(-j);
            }
        }
        i=l;
        while(i<n)
        {
            j=r;
            while(j>0)
            {
                down_left[i][j]=min(down_left[i][j],new_val);
                i=i+i&(-i);
                j=j-j&(-j);
            }
        }
        i=l;
        while(i>0)
        {
            j=r;
            while(j<m)
            {
                up_right[i][j]=min(up_right[i][j],new_val);
                i=i-i&(-i);
                j=j+j&(-j);
            }
        }

        i=l;
        while(i>0)
        {
            j=r;
            while(j>0)
            {
                up_left[i][j]=min(up_left[i][j],new_val);
                i=i-i&(-i);
                j=j-j&(-j);
            }
        }
    }

    Fenwic (vector<vector<int>> a)
    {
        
        init ((int) a.size(), (int) a[0].size());
        for (unsigned i = 1; i <= a.size(); i++)
            for (unsigned j = 1; j <= a[0].size(); j++)
                set (i, j, a[i-1][j-1]);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a;
    for (unsigned i = 0; i < n; i++)
    {
        vector <int> b;
        for (unsigned j = 0; j < m; j++)
        {
            int k;
            cin >> k;
            b.push_back(k);
        }
        a.push_back(b);
    }
    Fenwic F=Fenwic(a);
    int q;
    cin >> q;
    for (int i=0; i<q; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << F.getmin (x1, y1, x2, y2) << endl;
    }
    return 0;
}
