#include "Node.hpp"

#include <iostream>

int main()
{
    Node node1("parent");
    node1.attach(Node("child_1"));
    node1.attach(Node("child_2"));

    std::cout << node1.name() << std::endl;
    std::cout << node1.size() << std::endl;

    Node node2("other");
    node2 = node1;

    std::cout << node2.name() << std::endl;
    std::cout << (node2 == node1) << std::endl;

    return 0;
}
