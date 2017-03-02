#include "DynArray.hh"
#include <stdlib.h>

DynArray::DynArray(void)
{
	m_capacity = DYN_ARRAY_DEFAULT_SIZE;
	m_size = 0;
	m_data = new int[m_capacity];
}

DynArray::DynArray(size_t size, const int & value)
{
	m_size = size;
	m_capacity = size;;
	m_data = new int[m_capacity];
	for (int i = 0; i < static_cast<int>(size); i++) {
		m_data[i] = value;
	}
}

DynArray::~DynArray(void)
{
	delete[] m_data;
}

int * DynArray::begin(void) const
{
	return m_data;
}

int * DynArray::end(void) const
{
	return (m_data + m_capacity);
}

void DynArray::fill(int * first, int * last, int value)
{
	int* p = first;
	while (p < last) {
		*p = value;
		p++;
	}
}

bool operator==(const DynArray & lhs, const DynArray & rhs)
{
	bool res = false;
	if (lhs.m_size == rhs.m_size) 
	{
		res = true;
		for (int i = 0; i < static_cast<int>(lhs.m_size); i++)
		{
			if (lhs[i] != rhs[i]) {
				return false;
			}
		}
	}
	return res;
}

int & DynArray::operator[](size_t n) const
{
	return m_data[n];
}
