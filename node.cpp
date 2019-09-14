#include "node.h"

node::node(item value)
{
	this->m_value = value;
}

string node::getContent()
{
	return unboxItem(this->m_value);
}