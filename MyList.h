#ifndef MY_LIST_H_INCLUDED_
#define MY_LIST_H_INCLUDED_

template<typename Type>
class List
{
private:
	struct Node
	{
		Type data;
		Node* pNext;

		Node(Type data = Type(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	Node* head;
	int size;

	List(const List&) = delete;      //не точно
	List& operator=(const List&) = delete;
public:
	List();
	~List();

	int get_size() const { return size; }

	Type& front() { return head->data; }
	const Type& front() const { return head->data; } 
	Type& back();
	const Type& back() const;

	void push_back(const Type& data);
	void push_front(const Type& data);
	void pop_back();
	void pop_front();
	void clear();
	void insert(const Type& data, int index);
	void removeAt(int index);
	Type& operator[](int index);
	const Type& operator[](int index) const;

	//advanced functions:
	void sort();
};

template<typename Type>
List<Type>::List() : head(nullptr), size(0) {}

template<typename Type>
List<Type>::~List()
{
	clear();
}

template<typename Type>
Type& List<Type>::back()
{
	return this->operator[](size - 1);
}

template<typename Type>
const Type& List<Type>::back() const
{
	return this->operator[](size - 1);
}


template<typename Type>
void List<Type>::push_back(const Type& data)
{
	if (head == nullptr)
		head = new Node(data);
	else
	{
		Node* temp = head;
		while (temp->pNext != nullptr)
			temp = temp->pNext;
		temp->pNext = new Node(data);
	}
	size++;
}

template<typename Type>
void List<Type>::push_front(const Type& data)
{
	head = new Node(data, head);
	size++;
}

template<typename Type>
void List<Type>::pop_back()
{
	removeAt(size - 1);
}

template<typename Type>
void List<Type>::pop_front()
{
	if (head == nullptr)
		return;
	Node* temp = head;
	head = head->pNext;
	delete temp;
	size--;
}

template<typename Type>
void List<Type>::clear()
{
	while (size)
		pop_front();
}

template<typename Type>
void List<Type>::insert(const Type& data, int index)
{
	if (index < 0 || index > size) throw std::out_of_range("Invalid index");

	if (!index)
		push_front(data);
	else
	{
		Node* previous = head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;
		previous->pNext = new Node(data, previous->pNext);
		size++;
	}
}

template<typename Type>
void List<Type>::removeAt(int index)
{
	if (index < 0 || index >= size) throw std::out_of_range("Invalid index");

	if (!index)
		pop_front();
	else
	{
		Node* previous = head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;
		Node* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
}

template<typename Type>
Type& List<Type>::operator[](int index)
{
	if (index < 0 || index >= size) throw std::out_of_range("Invalid index");

	Node* temp = head;
	for (int i = 0; i < index; i++)
		temp = temp->pNext;

	return temp->data;
}

template<typename Type>
const Type& List<Type>::operator[](int index) const
{
	if (index < 0 || index >= size) throw std::out_of_range("Invalid index");

	Node* temp = head;
	for (int i = 0; i < index; i++)
		temp = temp->pNext;

	return temp->data;
}

template<typename Type>
void List<Type>::sort()
{
	//Type val;
	//Node* temp = head;
	//for (int i = 0; i < size; i++)
	//{
	//	val = temp->data;
	//	for (int j = i + 1; j < size; j++)
	//	{
	//		if (val < temp->pNext->data)

	//	}
	//}
}

#endif // !MY_LIST_H_INCLUDED_