#include "DynArray.hh"
#include <stdlib.h>

//constructors
DynArray::DynArray(void)
{
	m_capacity = DYN_ARRAY_DEFAULT_SIZE;
	m_size = 0;
	m_data = new int[m_capacity];
}

DynArray::DynArray(size_t size)
{
	m_size = 0;
	m_capacity = size;;
	m_data = new int[m_capacity];
}

DynArray::DynArray(size_t size, const int & value)
{
	m_size = size;
	m_capacity = size;;
	m_data = new int[m_capacity];
	fill(begin(), end(), value);
}

DynArray::DynArray(int * arr, size_t size)
{
	m_size = size;
	m_capacity = size;
	m_data = new int[m_capacity];
	for (int i = 0; i < static_cast<int>(m_size); i++) {
		m_data[i] = arr[i];
	}
}

//destructor
DynArray::~DynArray(void)
{
	delete[] m_data;
}

//assignment operators
DynArray & DynArray::operator=(const DynArray & x)
{
	if (this == &x) {
		return *this;
	}
	m_data = x.data();
	m_size = x.size();
	m_capacity = x.capacity();
	return *this;
}

//iterator methods
int * DynArray::begin(void) const
{
	return m_data;
}

int * DynArray::end(void) const
{
	return (m_data + m_size);
}

//capacity methods
bool DynArray::empty(void) const
{
	return m_size==0;
}

size_t DynArray::capacity(void) const
{
	return m_capacity;
}

size_t DynArray::size(void) const
{
	return m_size;
}

//element access methods/operators
int & DynArray::operator[](size_t n) const
{
	return m_data[n];
}

int & DynArray::at(size_t n) const
{
	return m_data[n];
}

int & DynArray::front(void) const
{
	return *begin();
}

int & DynArray::back(void) const
{
	return *end();
}

int * DynArray::data(void) const
{
	return m_data;
}

//modifiers methods
void DynArray::assign(size_t n, const int & val)
{
}

void DynArray::push(const int & val) {
	DynArray new_m_data(m_capacity + 1, 0);
	for (int i = 0; i < m_size; i++) {
		new_m_data.data()[i] = m_data[i];
	}
	new_m_data[m_size] = val;
	delete[] m_data;
	m_data = new_m_data.data();
	m_capacity += 1;
	m_size += 1;
}

//relational operators
bool operator==(const DynArray & lhs, const DynArray & rhs)
{
	bool res = false;
	if (static_cast<int>(lhs.size()) == static_cast<int>(rhs.size()))
	{
		res = true;
		for (int i = 0; i < static_cast<int>(lhs.size()); i++)
		{
			if (lhs[i] != rhs[i]) {
				return false;
			}
		}
	}
	return res;
}

//utils methods
const size_t & DynArray::min(const size_t & lhs, const size_t & rhs)
{
	return (static_cast<int>(lhs) < static_cast<int>(rhs)) ? lhs : rhs;
}

void DynArray::fill(int * first, int * last, int value)
{
	int* p = first;
	while (p < last) {
		*p = value;
		p++;
	}
}