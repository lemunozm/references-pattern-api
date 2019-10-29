#ifndef REFAPI__EXAMPLE__NODE_HPP
#define REFAPI__EXAMPLE__NODE_HPP

#include "NodeImpl.hpp"

#include <refapi/Reference.hpp>

using namespace refapi;

class NodeInfo : public Reference<impl::NodeInfo>
{
public:
    NodeInfo(const std::string& name)
        : Reference(std::make_shared<impl::NodeInfo>(name))
    {}

    const std::string& name() const { return impl()->name(); }

protected:
    NodeInfo(const std::shared_ptr<impl::NodeInfo>& other)
        : Reference(other)
    {}
};


class Node : public NodeInfo
{
public:
    Node(const std::string& name)
        : NodeInfo(std::make_shared<impl::Node>(name))
    {}

    const std::string& name() const { return impl()->name(); }
    const Node parent() const { return impl()->parent(); }

    void attach(Node node)
    {
        impl()->attach(node.impl());
    }

    Node deattach(const std::string& name)
    {
        return impl()->dettach(name);
    }

protected:
    Node(const std::shared_ptr<impl::Node>& other)
        : NodeInfo(other)
    {}

    std::shared_ptr<impl::Node> impl() { return std::static_pointer_cast<impl::Node>(NodeInfo::impl()); }
    const std::shared_ptr<impl::Node> impl() const { return std::static_pointer_cast<impl::Node>(NodeInfo::impl()); }
};


#endif //REFAPI__EXAMPLE__NODE_HPP
