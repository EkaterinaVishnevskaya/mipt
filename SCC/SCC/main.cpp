//
//  main.cpp
//  graph
//
//  Created by Екатерина Вишневская on 6.09.15.
//  Copyright (c) 2015 Екатерина Вишневская. All rights reserved.
//

#include <iostream>
#include "../../graph.h"


/*void dfs1 (Graph<int, bool> Gr, int v, vector<short> &visited, list<int> &sorted) {
    visited[v] = 1;
    
    for (int i=0; i<Gr.GetNextVertexes(v).size(); ++i)
        if (visited[Gr.GetNextVertexes(v)[i]]==0)
            dfs1 (Gr, Gr.GetNextVertexes(v)[i], visited, sorted);
    
    sorted.push_back (v);
}

void dfs2 (Graph Gr, int v, vector<short> &visited, vector<int> &comp)
{
    visited[v] = 1;
    comp.push_back (v);
    for (int i=0; i<Gr.GetPrevVertexes(v).size(); ++i)
        if (visited[Gr.GetPrevVertexes(v)[i]]==0)
            dfs2 (Gr, Gr.GetPrevVertexes(v)[i], visited, comp);
}

int scc() {
    int n, m;
    cin >>n;
    cin >>m;
    Graph Graf(2*n+1);
    for (int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        Graf.AddEdge(a+n, -b+n);
        Graf.AddEdge(b+n, -a+n);
    }
    vector<short> used (2*n+1, 0);
    vector<int> component;
    list<int> order;
    for (int i=0; i<2*n+1; ++i)
    {    if (!used[i])
        dfs1 (Graf, i, used, order);
    }
    used.clear();
    used.resize(2*n+1, 0);
    int count=0;
    order.reverse();
    
    vector<int> compsnumbers (2*n+1, 0);
    
    for (auto i: order)
    {
        if (used[i]==0)
        {
            count++;
            dfs2 (Graf, i, used,  component);
            for (auto v: component)
            {
                compsnumbers[v]=count;
            }
            component.clear();
        }
    }
    for (auto v: compsnumbers)
    {
        std::cout << v <<' ';
    }
    for (int i=0; i<n;i++)
    {
        if (compsnumbers[i]==compsnumbers[i+1+n])
        {
            cout << "No solution";
            return 0;
        }
    }
    return 0;
}*/