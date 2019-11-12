/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Contributors:
 *     Luis Enrique Muñoz <lemunozm@gmail.com>
 */

#ifndef REFAPI__REFERENCE_HPP
#define REFAPI__REFERENCE_HPP

#define REF_API_CLASS(IMPL_CLASS, API_CLASS, API_BASE_CLASS) \
    protected: \
    std::shared_ptr<IMPL_CLASS> impl() \
    { \
        return std::static_pointer_cast<IMPL_CLASS>(API_BASE_CLASS::impl()); \
    } \
    \
    const std::shared_ptr<IMPL_CLASS> impl() const \
    { \
        return std::static_pointer_cast<IMPL_CLASS>(API_BASE_CLASS::impl()); \
    } \
    \
    public: \
    API_CLASS(const std::shared_ptr<IMPL_CLASS>& other) \
        : API_BASE_CLASS(other) \
    {} \
    \
    IMPL_CLASS* operator ->() \
    { \
        return impl().get(); \
    } \
    \
    const IMPL_CLASS* operator ->() const \
    { \
        return impl().get(); \
    } \
    operator std::shared_ptr<IMPL_CLASS>() \
    { \
        return std::static_pointer_cast<IMPL_CLASS>(impl()); \
    } \
    private:


#include <memory>

namespace refapi {

template<typename IMPL>
class Reference
{
public:
    Reference()
        : impl_(nullptr)
    {}

    Reference(const Reference& reference) = default;

    Reference(const std::shared_ptr<IMPL>& impl)
        : impl_(impl)
    {}

    bool operator ==(const Reference& reference) const
    {
        return impl_ == reference.impl_;
    }

    operator bool() const
    {
        return impl_.get() != nullptr;
    }

protected:
    std::shared_ptr<IMPL>& impl() { return impl_; }
    const std::shared_ptr<IMPL>& impl() const { return impl_; }

    void clear() { impl_.reset(); }

private:
    std::shared_ptr<IMPL> impl_;
};

} //namespace refapi

#endif //REFAPI__REFERENCE_HPP
