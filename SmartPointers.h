#pragma once

#include <memory>

template <class T>
using SharedPtr = std::shared_ptr<T>;

template <class T>
using WeakPtr = std::weak_ptr<T>;

template <class T>
using UniquePtr = std::unique_ptr<T>;

template<class T>
using SharedPtrFromThis = std::enable_shared_from_this<T>;

template<class T>
bool empty(const std::shared_ptr<T>& ptr)
{
	return ptr.use_count() == 0;
}

template <class T>
SharedPtr<T> refNew()
{
	return std::make_shared<T>();
}

template <class T, class... Args>
SharedPtr<T> refNew(Args&&... args) {
	return std::make_shared<T>(std::forward<Args>(args)...);
}

template <class T, class U>
SharedPtr<T> refCast(const std::shared_ptr<U>& ptr)
{
	return std::static_pointer_cast<T>( ptr );
}