#include "circular_list.h"

CircularList::CircularList() : m_size{ 0 } {}

void CircularList::push_back(item value)
{
	if (!this->m_first)
	{
		this->m_first = make_shared<node>(value);
		this->m_last = this->m_first;
		this->m_first->m_next = this->m_last.lock();
	}
	else
	{
		this->m_last.lock()->m_next = make_shared<node>(value);
		this->m_last = this->m_last.lock()->m_next;
		this->m_last.lock()->m_next = this->m_first;
	}

	this->m_size++;
}

/*void CircularList::print(ofstream& out)
{
	if (!this->m_first)
		return;

	weak_ptr current = this->m_first;
	unsigned int count = 0;

	do
	{
		out << ++count << " - ";
		out << current.lock()->m_value << endl;
		current = current.lock()->m_next;
	} while (current.lock() != this->m_first);

	out << "Total number of items: " << count << endl;
}*/

void CircularList::sort()
{
	if (!this->m_first || this->size() < 2) return;

	for (unsigned int i = 0; i < this->size(); i++)
	{
		weak_ptr<node> n1 = this->m_first;
		weak_ptr<node> n2 = n1.lock()->m_next;
		bool flag = false;

		for (unsigned int j = 0; j < this->size() - i; j++)
		{
			if (*(n2.lock()) > *(n1.lock()))
			{
				n2.lock()->m_value.swap(n1.lock()->m_value);
				flag = true;
			}

			n1 = n2;
			n2 = n1.lock()->m_next;
		}

		if (!flag) break;
	}
}

CLIterator CircularList::begin() const { return CLIterator{ this->m_first }; }

CLIterator CircularList::end() const { return CLIterator{ this->m_last.lock()->m_next }; }

unsigned int CircularList::size() { return this->m_size; }

void CircularList::remove(float minRating)
{
	if (!this->m_first) return;

	weak_ptr<node> current = this->m_first;
	weak_ptr<node> previous = this->m_last;

	do
	{
		if (current.lock()->m_value.getRating() < minRating)
		{
			previous.lock()->m_next = move(current.lock()->m_next);
			current.lock().reset();
			current = previous.lock()->m_next;
			
			if (previous.lock() == this->m_last.lock())
				this->m_first = previous.lock()->m_next;

			if (current.lock() == this->m_first)
				this->m_last = previous;
		}
		else
		{
			previous = current;
			current = current.lock()->m_next;
		}
	} while (current.lock() != this->m_first);
}