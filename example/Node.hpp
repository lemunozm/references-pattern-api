#ifndef REFAPI__EXAMPLE__NODE_HPP
#define REFAPI__EXAMPLE__NODE_HPP

#include "NodeImpl.hpp"

#include <refapi/refapi.hpp>

class NodeInfo : public refapi::Reference<impl::NodeInfo>
{
    REF_API_CLASS(impl::NodeInfo, NodeInfo, Reference)
};


class Node : public NodeInfo
{
    REF_API_CLASS(impl::Node, Node, NodeInfo)
public:
    Node(const std::string& name)
        : NodeInfo(std::make_shared<impl::Node>(name))
    {}
};


#endif //REFAPI__EXAMPLE__NODE_HPP
