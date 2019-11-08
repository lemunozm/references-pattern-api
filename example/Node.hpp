#ifndef REFAPI__EXAMPLE__NODE_HPP
#define REFAPI__EXAMPLE__NODE_HPP

#include "NodeImpl.hpp"

#include <refapi/macros.hpp>
#include <refapi/Reference.hpp>

using namespace refapi;

class NodeInfo : public Reference<impl::NodeInfo>
{
    REF_API_CLASS_BASE(NodeInfo, impl::NodeInfo)
public:
    const std::string name() const { return impl()->name(); }
    size_t size() const { return impl()->size(); }
};


class Node : public NodeInfo
{
    REF_API_CLASS_INHERITANCE(Node, NodeInfo, impl::Node)
public:
    Node(const std::string& name)
        : NodeInfo(std::make_shared<impl::Node>(name))
    {}
    const Node parent() const { return impl()->parent(); }
    void attach(Node node) { impl()->attach(node.impl()); }
    Node deattach(const std::string& name) { return impl()->dettach(name); }
};


#endif //REFAPI__EXAMPLE__NODE_HPP
