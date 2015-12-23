#include "agraph.h"
#include <string>
#include <iostream>

/* ваша реализация графа, таких реализаций может быть несколько, подходящих для разных случаев */
template<typename V, typename E>
class Graph {
public:
    
    bool do_algorithm() {
        std::cout << "do algorithm for " << typeid(V).name() << "," << typeid(E).name() << std::endl;
		return true;
    }
    ~Graph() {}
};

/* ваша реализация фабричного метода */
GraphConcept* GraphFactory::makeGraph(Json::Value &Input){
    /* определяем подходящий тип графа для данного алгоритма */
	/* сюда же нужно добавить инициализацию */

        return new GraphModel<Graph<int, double>>(Graph<int, double> ());
    
}
