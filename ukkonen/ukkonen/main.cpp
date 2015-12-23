//
//  main.cpp
//  ukkonen
//
//  Created by Екатерина Вишневская on 17.12.15.
//  Copyright (c) 2015 Екатерина Вишневская. All rights reserved.
//

#include <iostream>

const int N=1000000,INF=1000000000;
std::string a;
int suff_tree[N][26],left[N],right[N],parent[N],suff_link[N],tv,pos,vcount,currc;

void ukkadd (char s) {
    int c=s-'a';
    if (right[tv]<pos)
    {
        if (suff_tree[tv][c]==-1)
        {
            suff_tree[tv][c]=vcount;
            left[vcount]=currc;
            parent[vcount++]=tv;
            tv=suff_link[tv];
            pos=right[tv]+1;
            ukkadd (s);
            return;
        }
        tv=suff_tree[tv][c];
        pos=left[tv];
    }
    if (pos==-1 || c==a[pos]-'a')
        pos++;
    else {
        left[vcount+1]=currc;
        parent[vcount+1]=vcount;
        left[vcount]=left[tv];
        right[vcount]=pos-1;
        parent[vcount]=parent[tv];
        suff_tree[vcount][c]=vcount+1;
        suff_tree[vcount][a[pos]-'a']=tv;
        left[tv]=pos;
        parent[tv]=vcount;
        suff_tree[parent[vcount]][a[left[vcount]]-'a']=vcount;
        vcount+=2;
        tv=suff_link[parent[vcount-2]];
        pos=left[vcount-2];
        while (pos<=right[vcount-2])
        {
            tv=suff_tree[tv][a[pos]-'a'];
            pos+=right[tv]-left[tv]+1;
        }
        if (pos==right[vcount-2]+1)
            suff_link[vcount-2]=tv;
        else suff_link[vcount-2]=vcount;
        pos=right[tv]-(pos-right[vcount-2])+2;
        ukkadd (s);
        return;
    }
}

void build() {
    vcount=2;
    tv=0;
    pos=0;
    std::fill(right,right+N,(int)a.size()-1);
    suff_link[0]=1;
    left[0]=-1;
    right[0]=-1;
    left[1]=-1;
    right[1]=-1;
    memset (suff_tree, -1, sizeof suff_tree);
    std::fill(suff_tree[1],suff_tree[1]+26,0);
    for (currc=0; currc<(int)a.size(); ++currc)
        ukkadd (a[currc]);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
