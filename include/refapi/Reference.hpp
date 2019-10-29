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

protected:
    std::shared_ptr<IMPL>& impl() { return impl_; }
    const std::shared_ptr<IMPL>& impl() const { return impl_; }

    void clear() { impl_.reset(); }

private:
    std::shared_ptr<IMPL> impl_;
};


} //namespace refapi

#endif //REFAPI__REFERENCE_HPP
