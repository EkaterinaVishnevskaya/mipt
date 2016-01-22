//
//  Header.h
//  graph
//
//  Created by Екатерина Вишневская on 11.09.15.
//  Copyright (c) 2015 Екатерина Вишневская. All rights reserved.
//

using namespace std;
#include <list>
#include <vector>
#include <set>
#include <math.h>

template <class V, class E>
class Graph
{
private:
    set <pair <V, set<pair<V, E>>>> edges;
    set<V> vertexes;
public:
    struct edge
    {
        V s;
        V t;
        E data;
   };
    Graph()= default;
    ~Graph () = default;
    
    void AddEdge(V a, V b, E e)
    {
        bool t =true;
        vertexes.insert(a);
        vertexes.insert(b);
        for (typename std::set<pair <V, set<pair<V, E>>>>::iterator i=edges.begin(); i!=edges.end(); ++i)
        {
            if ((*i).first==a)
            {
                t=false;
                cout << typeid((*i).second).name() << endl;
                //cout << (*i).second.size()
                pair <V, set<pair<V, E>>> p = make_pair(a, (*i).second);
                edges.erase(i);
                //typedef typename pair <V, set<pair<V, E>>>::iterator aaa;
                //const_cast<aaa>(i);
                p.second.insert(make_pair(b, e));
                edges.insert(p);
                break;
            }
        }
        if (t)
        {
            set<pair<V, E>> t;
            t.insert(make_pair(b, e));
            //cout << typeid(x.second).name() << endl;
            edges.insert(make_pair(a, t));
        }
    }
    
    E GetEdge(V a, V b)
    {
        for (auto i:edges)
        {
            if (i.first==a)
            {
                for (auto j: i.second)
                    if (j.first==b) return j.second;
            }
        }
        return E();
    }
    
    list<E> GetMultiEdge(V a, V b)
    {
        list<E> res;
        for (auto i:edges)
        {
            if (i.first==a)
            {
                for (auto j: i.second)
                    if (j.first==b) res.push_back(j.second);
            }
        }
        return res;
    }
    
    set<V> GetVertexes()
    {
        return vertexes;
    }
    
    set<V> GetNextVertexes(V v)
    {
        set<V> res;
        for (auto i:edges)
        {
            if (i.first==v)
            {
                for (auto j: i.second)
                {
                    res.insert(j.first);
                }
                break;
            }
        }
        return res;
    }
    
    set<V> GetPrevVertexes(V v)
    {
        set<V> res;
        for (auto i:edges)
        {
            for (auto j: i.second)
            {
                if (j.first==v)
                    res.insert(i.first);
            }
        }
        return res;
    }
    
    set<edge> GetEdgesList()
    {
        set<edge> res;
        for(auto i: edges)
        {
            for(auto j: i.second)
            {
                edge e;
                e.s=j.first;
                e.t=i.first;
                e.data=j.second;
            }
        }
        return res;
    }
};


struct road
{
    bool operator<(const road& r)const
    {
        if(w<r.w)
        {
            return true;
        } else
        {
            if (w==r.w)
            {
                if (!type)
                {
                    return r.type;
                }
                else return false;
            }
            else return false;
        }
    };
    double w;
    bool type;
};

double transport(Graph <int, road> g, int s, int t);

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
        l2++;
        r2++;
        int result = INF;
        int i=l1;
        int j=r1;
        while((i+i&(-i))<=l2)
        {
            j=r1;
            while((j+j&(-j))<=r2)
            {
                result=min(result,down_right[i][j]);
                i=i+i&(-i);
                j=j+j&(-j);
            }
        }
        result=min(result,d[i-1][j-1]);
        i=l1;
        while((i+i&(-i))<=l2)
        {
            j=r2;
            while((j-j&(-j))>r1)
            {
                result=min(result,down_left[i][j]);
                i=i+i&(-i);
                j=j-j&(-j);
            }
        }
        result=min(result,d[i-1][j-1]);
        i=l2;
        while((i-i&(-i))>l1)
        {
            j=r1;
            while((j+j&(-j))<=r2)
            {
                result=min(result,up_left[i][j]);
                i=i-i&(-i);
                j=j+j&(-j);
            }
        }
        result=min(result,d[i-1][j-1]);
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
        result=min(result,d[i-1][j-1]);
        return result;
    }
    
    void set (int l, int r, int new_val)
    {
        d[l-1][r-1]=new_val;
        int i=l;
        int j=r;
        while(i<=n)
        {
            j=r;
            while(j<=m)
            {
                down_right[i][j]=min(down_right[i][j],new_val);
                i=i+i&(-i);
                j=j+j&(-j);
            }
        }
        i=l;
        while(i<=n)
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
            while(j<=m)
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
        for (unsigned i = 0; i < a.size(); i++)
            for (unsigned j = 0; j < a[0].size(); j++)
                set (i+1, j+1, a[i][j]);
    }
};





