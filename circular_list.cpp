#include "circular_list.h"

void CircularList::push_back(item value)
{
	if (!this->m_first)
	{
		this->m_first = make_shared<node>(value);
		this->m_first->m_next = this->m_first;
		this->m_last = this->m_first;
	}
	else
	{
		this->m_last.lock()->m_next = make_shared<node>(value);
		this->m_last = this->m_last.lock()->m_next;
		this->m_last.lock()->m_next = this->m_first;
	}
}

void CircularList::print(ofstream& out)
{
	if (!this->m_first)
		return;

	weak_ptr current = this->m_first;
	unsigned int count = 0;

	do
	{
		out << ++count << " - " << current.lock()->getContent() << endl;
		current = current.lock()->m_next;
	} while (current.lock() != this->m_first);

	out << "Total number of items: " << count << endl;
}