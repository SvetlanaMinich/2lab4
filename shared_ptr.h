template<typename T>
class shared_ptr
{
private:
	T* ptr;
	size_t* refCount;
	void _clean();
public:
	shared_ptr() :ptr(nullptr), refCount(new size_t(0)) {};
	shared_ptr(T* _ptr) :ptr(_ptr), refCount(new size_t(1)) {};
	shared_ptr(const shared_ptr& _ptr);
	shared_ptr& operator=(const shared_ptr& _ptr);
	shared_ptr(shared_ptr&& _ptr);
	shared_ptr& operator=(shared_ptr&& _ptr);
	size_t getCount() const;
	T* get() const;
	T* operator->() const;
	T& operator*() const;
	~shared_ptr() { _clean(); };
};

