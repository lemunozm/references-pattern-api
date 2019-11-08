#ifndef REFAPI__REFERENCE_HPP
#define REFAPI__REFERENCE_HPP

#include <memory>

namespace refapi {

template<typename IMPL>
class Reference
{
public:
    Reference(std::nullptr_t null)
        : impl_(nullptr)
    {}

    Reference(const Reference& reference) = default;

    Reference(const std::shared_ptr<IMPL>& impl)
        : impl_(impl)
    {}

    bool operator == (const Reference& reference)
    {
        return impl_ == reference.impl_;
    }

protected:
    std::shared_ptr<IMPL>& impl() { return impl_; }
    const std::shared_ptr<IMPL>& impl() const { return impl_; }

    void clear() { impl_.reset(); }

private:
    std::shared_ptr<IMPL> impl_;
};


#define REF_API_CLASS_BASE(API_CLASS, IMPL_CLASS) \
    protected: \
    API_CLASS(const std::shared_ptr<IMPL_CLASS>& other) \
        : Reference(other) \
    {}

#define REF_API_CLASS_INHERITANCE(API_CLASS, API_BASE_CLASS, IMPL_CLASS) \
    protected: \
    API_CLASS(const std::shared_ptr<IMPL_CLASS>& other) \
        : API_BASE_CLASS(other) \
    {} \
    \
    std::shared_ptr<IMPL_CLASS> impl() \
    { \
        return std::static_pointer_cast<IMPL_CLASS>(API_BASE_CLASS::impl()); \
    } \
    const std::shared_ptr<IMPL_CLASS> impl() const \
    { \
        return std::static_pointer_cast<IMPL_CLASS>(API_BASE_CLASS::impl()); \
    }

} //namespace refapi

#endif //REFAPI__REFERENCE_HPP
