#include <iostream>

namespace lib
{
template <typename T>
class node
{
public:
	T element;
	node *next;
	node *prev;
	node(T elemval, node *nextval = nullptr, node *prevval = nullptr) : element(elemval), next(nextval), prev(prevval) {}
	node(node *nextval = nullptr, node *prevval = nullptr) : next(nextval), prev(prevval) {}
};

template <typename T>
class list
{
private:
	node<T> *head;
	node<T> *fence;
	node<T> *tail;

	void init()
	{
		head = fence = tail = new node<T>(nullptr);
	}

public:
	int flag = 1;
	list() { init(); }
	bool append(T it)
	{
		tail->next = new node<T>(it, nullptr);
		tail->next->prev = tail;

		if (flag == 1)
		{
			head = tail->next;
			flag++;
			fence = head;
		}
		tail = tail->next;
		return true;
	}

	bool append(const std::initializer_list<T> arr)
	{
		if (head == nullptr)
		{
			for (auto it = arr.begin(); it < arr.end(); it++)
			{
				if (flag == 1)
				{
					head = new node<T>(*it, nullptr);
					tail = head;
					fence = head;
					flag++;
				}
				else
				{
					append(*it);
				}
			}
			return 1;
		}
		else
		{
			for (auto it = arr.begin(); it < arr.end(); it++)
			{
				append(*it);
			}
		}
	}

	bool print()
	{
		fence = head;
		while (fence != nullptr)
		{
			std::cout << fence->element << " ";
			fence = fence->next;
		}
		fence = head;
		std::cout << std::endl;
		return true;
	}

	node<T> *find(T element)
	{
		fence = head;
		while (fence != nullptr)
		{
			if (fence->element == element)
				return fence;
			fence = fence->next;
		}
		return nullptr;
	}

	bool remove(T element)
	{
		fence = this->find(element);
		if (fence != nullptr)
		{
			if (flag == 1)
			{
				fence = tail = head = nullptr;
			}
			else if (fence == head)
			{
				head->next->prev = nullptr;
				head = head->next;
			}
			else if (fence == tail)
			{
				tail->prev->next =nullptr;
				tail = tail->prev;
				fence=nullptr;
			}
			else
			{
				fence->next->prev = fence->prev;
				fence->prev->next = fence->next;
			}
			flag--;
			return true;
		}
		else
		{
			return false;
		}
	}

	list(const std::initializer_list<T> arr)
	{
		for (auto it = arr.begin(); it < arr.end(); it++)
		{
			if (flag == 1)
			{
				head = new node<T>(*it, nullptr);
				tail = head;
				fence = head;
				flag++;
			}
			else
			{
				append(*it);
			}
		}
	}

	node<T> *begin()
	{
		fence = head;
		return fence;
	}

	node<T> *end()
	{
		fence = tail;
		return fence;
	}
};
} // namespace lib
