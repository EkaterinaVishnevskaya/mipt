#include <vector>
#include "jsoncpp/include/json/json.h"
//#include "agraph/agraph.h"
#include "graph.h"

#include "catch.hpp"

#include <fstream>
#include <iostream>

#include <unistd.h>

using std::cout;
using std::endl;

/*SCENARIO("scenario1"){
    std::ifstream ifs;
    Json::Value root;
    Json::Reader reader;

    char buf[1024];
    getcwd(buf, 1024);
    cout << "current dir: " << buf << endl;
    
    bool res = reader.parse(ifs, root);
    REQUIRE( res != false );

    cout << "pairs:" << endl;

    Json::Value g = root["2sat"];
    for(unsigned int i = 0; i < g.size(); ++i){
        cout << g[i][0].asString() << " : " << g[i][1].asString() << endl;
    }

}

/*SCENARIO("scenario2"){
    std::ifstream ifs;
    Json::Value root;
    Json::Reader reader;

    ifs.open("../mipt/graph.json", std::ifstream::in);
    bool res = reader.parse(ifs, root);
    REQUIRE( res != false );

   std::unique_ptr<GraphConcept> g(GraphFactory::makeGraph(root));
    g->algorithm();

   Json::Value r = root["graphs"][0]["graph"];
    cout << "nodes:" << endl;
    for (auto& n : r["nodes"]) {
        cout << n["id"].asString() << " : " << n["label"].asString() << endl;
    }

    cout << "edges:" << endl;
    for (auto& e : r["edges"]) {
        cout << e["source"].asString() << " -> " << e["target"].asString() << endl;
    }
}*/

/*SCENARIO("scenario3", "[tag1][tag2]"){
    GIVEN("vector"){
        std::vector<int> v( 5 );

        WHEN( "the size is increased" ) {
            v.resize( 10 );
            THEN( "the size and capacity change" ) {
                REQUIRE( v.size() == 10 );
                REQUIRE( v.capacity() >= 10 );
            }
        }
        WHEN( "nothing happened" ) {
            REQUIRE( v.size() != 5 ); //неправильная проверка
        }
    }
}*/

SCENARIO("transport"){
    Graph <int, road> G;
    road e;
    e.w = 8;
    e.type = true;
    G.AddEdge(0, 1, e);
    e.w = 10;
    e.type = false;
    G.AddEdge(0, 1, e);
    e.w = 15;
    e.type = true;
    G.AddEdge(1, 2, e);
    e.w = 5;
    e.type = false;
    G.AddEdge(1, 2, e);
    int s=0, t=2;
    REQUIRE( transport(G, s, t)==11.0);
}

SCENARIO("waterway"){
    GIVEN("up_left")
    {
        vector<vector<int>> a = {{1, 2}, {3, 4}, {5, 6}};
        Fenwic F = Fenwic(a);
        REQUIRE(F.getmin(1, 2, 2, 3)==3);
        REQUIRE(F.getmin(1, 1, 2, 3)==1);
    }
    GIVEN("down_right")
    {
        vector<vector<int>> a = {{5, 6}, {3, 4}, {1, 2}};
        Fenwic F = Fenwic(a);
        REQUIRE(F.getmin(1, 2, 2, 3)==1);
        REQUIRE(F.getmin(1, 1, 2, 2)==3);
    }
    
}

