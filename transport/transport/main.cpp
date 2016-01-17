//
//  main.cpp
//  transport
//
//  Created by Екатерина Вишневская on 17.12.15.
//  Copyright (c) 2015 Екатерина Вишневская. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include "../../graph.h"




double transport(Graph <int, road> g, int s, int t)
{
    const int INF = 1000000000;
    int n=g.GetVertexes().size();
    std::vector<double> d0 (n, INF), d1 (n, INF), p1 (n), p0(n);
    std::vector<bool> pt1(n), pt0(n);
    d0[s] = 0;
    d1[s] = 0;
    //for (auto i: d1){
    //    cout << i<< " ";
    //}
    //cout << endl;
    //for (auto i: d0){
    //    cout << i<< " ";
        
    //}
    //cout << endl;
    std::set < std::pair<double, int> > q0;
    std::set < std::pair<double, int> > q1;
    std::set<int> q=g.GetNextVertexes(s);
    for (auto i: q)
    {
        list<road> l=g.GetMultiEdge(s, i);
        for (auto t: l)
        {
            if (t.type)
            {
                d1[i]=t.w;
                q1.insert(make_pair(d1[i], i));
            }
            else
            {
                d0[i]=t.w;
                q0.insert(make_pair(d0[i], i));
            }
        }
    }
    while (q0.size()+q1.size()>0) {
        //if(q0.size()+q1.size()==0){
        //    cout<<"Why?????????" << endl;;
        //    cout << min(d1[t], d0[t]);
        //    exit (1);
        //}
        int from;
        int dd0;
        int dd1;
        //cout << dd0<<' '<< dd1<< endl;
        if (q0.empty()) dd0=INF+2;
        else dd0 = q0.begin()->first;
        if (q1.empty()) dd1=INF+1;
        else dd1 = q1.begin()->first;
        bool f;
        //cout << dd0 << ' ' << dd1 << endl;

        //cout << q0.size() << endl;
        //cout << q0.size() << endl;
        if (dd0<dd1)
        {
            f=false;
            from=q0.begin()->second;
            q0.erase (q0.begin());
        }
        else
        {
            f=true;
            from=q1.begin()->second;
            q1.erase(q1.begin());
        }
        
        if (f)
        {
            set<int> Next = g.GetNextVertexes(from);

            for (auto to: Next)
            {
                list<road> e=g.GetMultiEdge(from, to);
                for (auto edge: e)
                {
                    double len = edge.w;
                    bool type = edge.type;
                    if (type)
                    {
                        if ((d1[from] + 0.8 * len) < d1[to])
                        {
                            q1.erase (std::make_pair (d1[to], to));
                            d1[to] = d1[from] + 0.8 * len;
                            p1[to] = from;
                            pt1[to]=true;
                            q1.insert (std::make_pair (d1[to], to));
                        }
                    } else
                    {
                        if (d1[from] + len < d0[to])
                        {
                            q0.erase (std::make_pair (d0[to], to));
                            d0[to] = d1[from] + len;
                            p0[to] = from;
                            p0[to] = true;
                            q0.insert (std::make_pair (d0[to], to));
                        }
                    }
                }
            }
        } else
        {
            set<int> Next = g.GetNextVertexes(from);
            for (auto to: Next)
            {
                double len = g.GetEdge(from, to).w;
                bool type = g.GetEdge(from, to).type;
                if (type)
                {
                    if (d0[from] + len < d1[to])
                    {
                        q1.erase (std::make_pair (d1[to], to));
                        d1[to] = d1[from] + len;
                        p1[to] = from;
                        pt1[to] = false;
                        q1.insert (std::make_pair (d1[to], to));
                    }
                } else
                {
                    if (d0[from] + 0.8*len < d0[to])
                    {
                        q0.erase (std::make_pair (d0[to], to));
                        d0[to] = d1[from] + 0.8*len;
                        p0[to] = from;
                        pt0[to] = false;
                        q0.insert (std::make_pair (d0[to], to));
                    }
                }
            }
        }
        
    for (auto i: d1){
        cout << i<< " ";
    }
    cout << endl;
    for (auto i: d0){
        cout << i<< " ";
    }
    cout << endl;
    }

    return min (d0[t], d1[t]);
}

int main() {
    Graph <int, road> G;
    road e;
    e.w = 5;
    e.type = true;
    G.AddEdge(0, 1, e);
    road e1;
    e1.w = 5;
    e1.type = true;
    G.AddEdge(0, 2, e1);
    e.w = 1;
    e.type = false;
    G.AddEdge(1, 2, e);
    e.w = 1;
    e.type = false;
    G.AddEdge(2, 1, e);
    e.w=100;
    e.type=true;
    G.AddEdge(1, 4, e);
    e.w=81;
    e.type=false;
    G.AddEdge(1, 3, e);
    e.w=0;
    G.AddEdge(3, 4, e);
    int s=1, t=4;
    cout << transport(G, s, t);
    
    //set<pair<int, set<pair<int, road>>>> a;
    //set<pair<int, road>> b;
    //b.insert(make_pair(1, road()));
    //set<pair<int, road>> c;
    //a.insert(make_pair(0, b));
    
}

