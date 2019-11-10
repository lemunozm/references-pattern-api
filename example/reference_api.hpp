#ifndef REFAPI__EXAMPLE__REFERENCE_API_HPP
#define REFAPI__EXAMPLE__REFERENCE_API_HPP

#include "original_api.hpp"

#include <refapi/refapi.hpp>

namespace reference_api {

class NodeInfo : public refapi::Reference<original_api::NodeInfo>
{
    REF_API_CLASS(original_api::NodeInfo, NodeInfo, Reference)
};

class Node : public NodeInfo
{
    REF_API_CLASS(original_api::Node, Node, NodeInfo)
public:
    Node(const std::string& name)
        : NodeInfo(std::make_shared<original_api::Node>(name))
    {}
};

} //reference_api


#endif //REFAPI__EXAMPLE__REFERENCE_API_HPP
