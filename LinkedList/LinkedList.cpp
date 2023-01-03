#include <iostream>
using namespace std;
template<typename T>
class List
{
public:
	List();
	~List();
	int getSize() { return size; }
	void push_back(T data);
	void push_front(T data);
	void insert(T data, const int index);
	void pop_front();
	void pop_back();
	void removeAt(const int index);
	void clear();
	T& operator[](const int index);
private:
	template<typename T>
	class Node
	{
	public:
		T data;
		Node* pNext;
		Node(T data, Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;
	Node<T>* head;
};

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}
template<typename T>

List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	size--;
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	size++;
}
template<typename T>
void List<T>::clear()
{
	while (size) {
		pop_front();
	}
}
template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (index == 0)
			return current->data;
		if (counter == index)
			return current->data;
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	if (head == nullptr)
		head = new Node<T>(data);
	else
		head = new Node<T>(data, head);
	size++;
}

template<typename T>
void List<T>::insert(T data, const int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
		size++;
	}
}
template<typename T>
void List<T>::removeAt(const int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
}

template<typename T>
void List<T>::pop_back() 
{
	removeAt(size - 1);
}

int main()
{


	List<int> lst;
	lst.push_front(5);
	lst.push_front(2);
	lst.push_back(4);
	lst.removeAt(1);
	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << " ";
	}
	List<float> lstF;
	lstF.push_back(23.5);
	cout << lstF[0];
	lstF.pop_back();
	lstF.push_back(23);

	return 0;
}