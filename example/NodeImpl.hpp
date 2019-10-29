#ifndef REFAPI__EXAMPLE__NODEIMPL_HPP
#define REFAPI__EXAMPLE__NODEIMPL_HPP

#include <memory>
#include <string>
#include <map>

namespace impl {

class NodeInfo
{
public:
    NodeInfo(const std::string& name)
        : name_(name)
    {}

    const std::string& name() const { return name_; }

private:
    std::string name_;
};


class Node : public NodeInfo
{
public:
    Node(const std::string& name)
        : NodeInfo(name)
        , parent_(nullptr)
    {}

    const std::shared_ptr<Node> parent() const { return parent_; }

    void attach(std::shared_ptr<Node> node)
    {
        parent_ = node;
        children_.emplace(node->name(), node);
    }

    std::shared_ptr<Node> dettach(const std::string& name)
    {
        auto it = children_.find(name);
        if(it == children_.end())
        {
            return nullptr;
        }
        it->second->parent_ = nullptr;
        return it->second;
    }

    std::shared_ptr<Node> operator [](const std::string& name)
    {
        return children_.at(name);
    }

private:
    std::shared_ptr<Node> parent_;
    std::map<std::string, std::shared_ptr<Node>> children_;
};

}



#endif //REFAPI__EXAMPLE__NODEIMPL_HPP
