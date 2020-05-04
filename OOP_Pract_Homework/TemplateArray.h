#ifndef TEMPLATE_ARRAY_H
#define TEMPLATE_ARRAY_H

/* User-Defined Custom Template Array */
template<class T>
class TemplateArray
{
public:
	TemplateArray();
	TemplateArray(const TemplateArray& other);
	TemplateArray<T>& operator=(const TemplateArray& other);
	T& operator[](unsigned int index) const;

	~TemplateArray();

	TemplateArray<T>& add(T element);
	TemplateArray<T>& clear();
	unsigned int size() const;
	unsigned int cap() const;
	bool isEmpty() const;

private:
	T* elements = nullptr;

	unsigned int _size = 0;
	unsigned int _cap = 0;

	void resize();
};

#endif // TEMPLATE_ARRAY_H

template<class T>
inline TemplateArray<T>::TemplateArray() :_size(0), _cap(1)
{
	elements = new T[_cap];
}

template<class T>
inline TemplateArray<T>::TemplateArray(const TemplateArray& other) :_size(other._size), _cap(other._cap)
{
	elements = new T[_cap];
	for (unsigned int i = 0; i < _size; ++i)
	{
		elements[i] = other.elements[i];
	}
}

template<class T>
inline TemplateArray<T>& TemplateArray<T>::operator=(const TemplateArray& other)
{
	if (this != &other)
	{
		_size = other._size;
		_cap = other._cap;
		delete[] elements;
		elements = new T[_cap];
		for (unsigned int i = 0; i < _size; ++i)
		{
			elements[i] = other.elements[i];
		}
	}
	return *this;
}

template<class T>
inline T& TemplateArray<T>::operator[](unsigned int index) const
{
	return elements[index];
}

template<class T>
inline TemplateArray<T>::~TemplateArray()
{
	clear();
}

template<class T>
inline TemplateArray<T>& TemplateArray<T>::add(T element)
{
	if (_size == _cap)
		resize();
	elements[_size] = element;
	++_size;
	return *this;
}

template<class T>
inline TemplateArray<T>& TemplateArray<T>::clear()
{
	if (elements != nullptr)
	{
		delete[] elements;
		elements = nullptr;
		_size = _cap = 0;
	}
	return *this;
}

template<class T>
inline unsigned int TemplateArray<T>::size() const
{
	return _size;
}

template<class T>
inline unsigned int TemplateArray<T>::cap() const
{
	return _cap;
}

template<class T>
inline bool TemplateArray<T>::isEmpty() const
{
	return (_size == 0);
}

template<class T>
inline void TemplateArray<T>::resize()
{
	_cap *= 2;
	T* temp = new T[_cap];
	for (unsigned int i = 0; i < _size; ++i)
	{
		temp[i] = elements[i];
	}
	delete[] elements;
	elements = temp;
}
