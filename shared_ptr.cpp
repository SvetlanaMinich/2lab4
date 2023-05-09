#include "shared_ptr.h"
template<typename T>
shared_ptr<T>::shared_ptr(const shared_ptr& _ptr) {
	this->ptr = _ptr.ptr;
	this->refCount = _ptr.refCount;
	if (_ptr.ptr != nullptr) {
		(*this->refCount)++;
	}
}
template<typename T>
shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr& _ptr) {
	_clean();
	this->ptr = _ptr.ptr;
	this->refCount = _ptr.refCount;
	if (_ptr.ptr != nullptr) {
		(*this->refCount)++;
	}
}
template<typename T>
shared_ptr<T>::shared_ptr(shared_ptr&& _ptr) {
	this->ptr = _ptr.ptr;
	this->refCount = _ptr.refCount;
	_ptr.ptr = _ptr.refCount = nullptr;
}
template<typename T>
shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr&& _ptr) {
	_clean();
	this->ptr = _ptr.ptr;
	this->refCount = _ptr.refCount;
	_ptr.ptr = _ptr.refCount = nullptr;
}
template<typename T>
size_t shared_ptr<T>::getCount() const {
	return *refCount;
}
template<typename T>
T* shared_ptr<T>::get() const {
	return this->ptr;
}
template<typename T>
T* shared_ptr<T>::operator->() const {
	return this->ptr;
}
template<typename T>
T& shared_ptr<T>::operator*() const {
	return *this->ptr;
}
template<typename T>
void shared_ptr<T>::_clean() {
	(*refCount)--;
	if (*refCount == 0) {
		if (ptr != nullptr) {
			delete ptr;
		}
		delete refCount;
	}
}