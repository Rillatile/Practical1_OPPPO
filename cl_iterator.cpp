#include "cl_iterator.h"

CLIterator::CLIterator(shared_ptr<node> ptr) : m_ptr{ ptr } {}

ItemStruct CLIterator::operator*() const
{
	return this->m_ptr.lock()->m_value;
}

CLIterator& CLIterator::operator++()
{
	this->m_ptr = this->m_ptr.lock()->m_next;

	return *this;
}

bool CLIterator::operator!=(const CLIterator& other) const
{
	return this->m_ptr.lock() != other.m_ptr.lock();
}
