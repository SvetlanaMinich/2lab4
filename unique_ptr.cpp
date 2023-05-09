#include "unique_ptr.h"
template<typename T, typename Deleter>
unique_ptr<T, Deleter>::unique_ptr(unique_ptr&& _ptr) noexcept : ptr(_ptr){
	_ptr = nullptr;
}
template<typename T, typename Deleter>
unique_ptr<T, Deleter>& unique_ptr<T, Deleter>::operator=(unique_ptr&& _ptr) noexcept {
	ptr = _ptr;
	_ptr = nullptr;
	return *this;
}
template<typename T, typename Deleter>
T& unique_ptr<T, Deleter>::operator*() {
	return *ptr;
}
template<typename T, typename Deleter>
T* unique_ptr<T, Deleter>::get() const {
	return ptr;
}
template<typename T, typename Deleter>
T* unique_ptr<T, Deleter>::operator->() {
	return ptr;
}
template<typename T, typename Deleter>
unique_ptr<T, Deleter>::~unique_ptr() {
	Deleter()(ptr);
}
