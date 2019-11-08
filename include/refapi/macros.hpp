#ifndef REFAPI__MACROS_HPP
#define REFAPI__MACROS_HPP

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


#endif //REFAPI__MACROS_HPP
