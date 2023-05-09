#include<memory>
template<typename T, typename Deleter = std::default_delete<T>>
class unique_ptr
{
private:
	T* ptr;
public:
	unique_ptr() : ptr(nullptr) {};
	explicit unique_ptr(T* _ptr) : ptr(_ptr) {};
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr(unique_ptr&& _ptr) noexcept;
	unique_ptr& operator=(unique_ptr&& _ptr) noexcept;
	T& operator*();
	T* get() const;
	T* operator->();
	~unique_ptr();
};

