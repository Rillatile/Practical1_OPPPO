#include "node.h"

node::node(item value)
{
	this->m_value.m_value = value;
}

bool operator> (node& n1, node& n2)
{
	if (n1.m_value.getRating() > n2.m_value.getRating())
		return true;
	else
		return false;
}

bool operator< (node& n1, node& n2)
{
	return !(n1 > n2);
}