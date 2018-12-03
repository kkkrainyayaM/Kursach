#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <algorithm>
using namespace std;
template<typename X>
class List
{
private:
	struct Node;
public:
	class Iterator {
	public:
		Iterator(Node* node) : val(node) {}
		bool operator==(const Iterator& other) const {
			if (this == &other) {
				return true;
			}
			return m_node == other.m_node;
		}
		bool operator!=(const Iterator& other) const {
			return !operator==(other);
		}

		// Переход к следующему узлу
		void operator++() {
			if (val) {
				val = val->m_next;
			} // Иначе достигнут конец списка. Уместно возбудить исключение
		}

	}
	List() {}
	List() {
		ph = 0;//указатель на головной узел списка
	};
	void push_front(X const& val)
	{
		Node* ptmp = ph;
		ph = new Node(val);
		ph->next = ptmp;
		cout << "Элемент " << val << " добавлен в начало списка.\n";
	}
	void push_back(X const& val)
	{
		if (!ph)
			ph = new Node(val);
		else
		{
			Node* ptmp = ph;
			while (ptmp->next)
				ptmp = ptmp->next;
			ptmp->next = new Node(val);
		}
		cout << "Элемент " << val << " добавлен в конец списка.\n";
	}
	void erase(X const& val)
	{
		while (ph && ph->data == val)
		{
			Node* ptmp = ph;
			ph = ph->next;
			delete ptmp;
			ptmp = 0;
		}

		Node* ptmp = ph;
		while (ptmp && ptmp->next)
		{
			while (ptmp->next && ptmp->next->data == val)
			{
				Node* ptmp1 = ptmp->next;
				ptmp->next = ptmp->next->next;
				delete ptmp1;
				ptmp1 = 0;
			}
			ptmp = ptmp->next;
		}
		cout << "Элемент " << val << " удален из списка.\n";
	}
	size_t count(X const& val)const
	{
		node* ptmp = ph;
		size_t cntr = 0;
		while (ptmp)
		{
			if (ptmp->data == val)
				++cntr;
			ptmp = ptmp->next;
		}
		return cntr;
	}
	bool empty()const
	{
		return !static_cast<bool>(ph);
	}
	void print()const
	{
		//cout << "Элементы списка:\n";
		Node* ptmp = ph;
		while (ptmp)
		{
			cout << ptmp->data << endl;
			ptmp = ptmp->next;
		}
	}
	~List()
	{
		Node* ptmp = 0;
		while (ph)
		{
			ptmp = ph;
			ph = ph->next;
			delete ptmp;
		}
	}
private:
	struct Node
	{
		Node() {
			next = NULL;
		}
		Node(const X& val) {
			next = NULL;
			data = val;
		}
		X data;
		Node* next;
	};
	Node* ph;
	List(List const&);
};

class WorkFile {
private:
	List<Seller>selL;
	List<Participant>partL;
	List<User>userL;
	List<Lot>lotL;
	WorkFile* Instance;
	WorkFile() {}
	WorkFile(const WorkFile&);
public:
	static WorkFile& getInstance() {
		static WorkFile Instance;
		return Instance;
	}
};