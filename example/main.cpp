#include "Node.hpp"

#include <iostream>

int main()
{
    Node node("parent");
    node.attach(Node("child_1"));
    node.attach(Node("child_2"));

    std::cout << node.name() << std::endl;
    std::cout << node.size() << std::endl;

    return 0;
}
