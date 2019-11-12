#ifndef REFAPI__EXAMPLE__ORIGINAL_API_HPP
#define REFAPI__EXAMPLE__ORIGINAL_API_HPP

#include <memory>
#include <string>
#include <map>

namespace original_api {

class NodeInfo
{
public:
    NodeInfo(const std::string& name)
        : name_(name)
    {}

    const std::string& name() const { return name_; }
    virtual size_t size() const = 0;

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

    virtual size_t size() const
    {
        return sizeof(Node);
    }

    const std::shared_ptr<Node>& parent() const { return parent_; }

    void attach(const std::shared_ptr<Node>& node)
    {
        //node.parent_ = this;
        children_.emplace(node->name(), node);
    }

    const std::shared_ptr<Node>& dettach(const std::string& name)
    {
        auto it = children_.find(name);
        if(it == children_.end())
        {
            static std::shared_ptr<Node> null;
            return null;
        }
        it->second->parent_ = nullptr;
        return it->second;
    }

    const std::shared_ptr<Node>& operator [](const std::string& name)
    {
        return children_.at(name);
    }

private:
    std::shared_ptr<Node> parent_;
    std::map<std::string, std::shared_ptr<Node>> children_;
};

} //namespace original_api

#endif //REFAPI__EXAMPLE__ORIGINAL_API_HPP
