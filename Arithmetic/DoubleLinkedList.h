#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
struct Node {
	long long num;
	Node* prev;
	Node* next;
	Node() {
		num = 0;
		prev = NULL;
		next = NULL;
	};
};

class DoubleLinkedList {
public:
	DoubleLinkedList();   // default construct
	~DoubleLinkedList();  // deconstruct
	DoubleLinkedList(const std::string& input, int digitsPerNode); // user defined construct
	DoubleLinkedList(const DoubleLinkedList& list);  // copy construct
	DoubleLinkedList& operator = (const DoubleLinkedList& list);  // assignment consturct
	int getCount();
	void copyList(const DoubleLinkedList &list);
	Node* GetHead() const;
	void insertNode(long long value);
	int m_digitsPerNode;
	void destroyList();
	void insertEnd(long long value);
	Node* GetTail() const;
	void Print() const;
	DoubleLinkedList operator * (const DoubleLinkedList& list)const;
	DoubleLinkedList operator + (const DoubleLinkedList& list)const;
	DoubleLinkedList operator - (const DoubleLinkedList& list)const;
	string toString(int digits);
public:
	Node* head;
	Node* tail;
	int count = 0;
};

DoubleLinkedList::DoubleLinkedList()
	: head(NULL)
	, tail(NULL)
	, m_digitsPerNode(1)
	, count(0)
{}

DoubleLinkedList::~DoubleLinkedList() {
	destroyList();
}
int DoubleLinkedList::getCount() {
	return count;
}
DoubleLinkedList::DoubleLinkedList(const std::string& input, int digitsPerNode) : head(NULL)
, tail(NULL), m_digitsPerNode(digitsPerNode) {
	string num = input;
	for (int i = 0; i < input.length(); i++) {
		if (num[0] != '0')
			break;
		num.erase(0, 1);
	}
	if (num == "") {
		num = "0";
	}
	int startIndex = 0;
	int digitsFirstNode = ((num.size() % m_digitsPerNode) == 0) ? m_digitsPerNode : num.size() % m_digitsPerNode;
	string parted; //get the index to append for the first node
	if ((num[0] == '-'|| num[0] == '+') && digitsFirstNode == 1) { //If it is a negative, ignore the negative sign and read in the number
		digitsFirstNode += m_digitsPerNode;
	}
	if (num.size() <= m_digitsPerNode) //if size is less than digitsperNode then just append to the front of the list
		insertNode(stoll(num));
	else {
		parted = num.substr(0, digitsFirstNode); //If it's not negative then just store as normal
		insertNode(stoll(parted));
		startIndex += digitsFirstNode;
		while (startIndex < num.size()) { //append the nodes to the end each until there's nothing left
			parted = num.substr(startIndex, m_digitsPerNode);
			insertEnd(stoll(parted));
			startIndex = startIndex + m_digitsPerNode;
		}
	}
}
DoubleLinkedList& DoubleLinkedList::operator = (const DoubleLinkedList& list) { // assignment consturct

	m_digitsPerNode = list.m_digitsPerNode;
	if (this != &list)
		copyList(list);
	return *this;
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& list)
	: head(NULL), tail(NULL), m_digitsPerNode(list.m_digitsPerNode)
{
	copyList(list);
}
void DoubleLinkedList::copyList(const DoubleLinkedList &list) {
	if (head != NULL)
		destroyList();
	if (list.head == NULL) {
		head = NULL;
		tail = NULL;
		count = 0;
	}
	else {
		m_digitsPerNode = list.m_digitsPerNode;
		count = list.count;
		Node * cur = list.head;
		head = new Node();
		head->num = cur->num;
		head->prev = NULL;
		head->next = NULL;
		tail = head;
		cur = cur->next;
		while (cur != NULL) {
			Node* node = new Node();
			node->num = cur->num;
			node->prev = tail;
			node->next = NULL;
			tail->next = node;
			tail = node;
			cur = cur->next;
		}
	}
}

void DoubleLinkedList::destroyList() {
	Node * temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		delete temp;
	}
	tail = NULL;
	count = 0;
}
Node* DoubleLinkedList::GetHead()const {
	return head;
}
Node* DoubleLinkedList::GetTail() const {
	return tail;
}
void DoubleLinkedList::insertNode(long long value) {
	Node* node = new Node;
	if (head == NULL) {
		head = node;
		tail = node;
		node->num = value;
		node->next = NULL;
		node->prev = NULL;
	}
	else {
		node->num = value;
		node->prev = NULL;
		node->next = head;
		head->prev = node;
		head = node;
	}
	count++;
}
void DoubleLinkedList::insertEnd(long long value) {
	Node * node = new Node;
	if (tail == NULL) {
		head = node;
		tail = node;
		node->num = value;
	}
	else {
		node->num = value;
		tail->next = node;
		node->prev = tail;
		node->next = NULL;
		tail = node;
	}
	count++;
}
void DoubleLinkedList::Print() const {
	Node *current;
	current = head;
	while (current->num == 0 && current->next != NULL) {
		current = current->next;
	}
	cout << current->num;
	current = current->next;
	while (current != NULL) {
		cout << setfill('0') << setw(m_digitsPerNode) << current->num; //add 0 infront of numbers until it have the digitspernode size
		current = current->next;
	}
	cout << endl;
}
DoubleLinkedList DoubleLinkedList::operator + (const DoubleLinkedList& list)const {
	int carryover = 0;
	long long a;
	Node* cur1 = tail;
	Node* cur2 = list.tail;
	DoubleLinkedList aresult;
	int power = pow(10, m_digitsPerNode);
	if ((head == NULL || head->num >= 0) && list.head->num >= 0) {
		while ((cur1 != NULL) || (cur2 != NULL)) {
			if (cur2 == NULL) {
				a = cur1->num + carryover;
				carryover = a / power;
				a = a % power;
				aresult.insertNode(a);
				cur1 = cur1->prev;
			}
			else if (cur1 == NULL) {
				a = cur2->num + carryover;
				carryover = a / power;
				a = a % power;
				aresult.insertNode(a);
				cur2 = cur2->prev;
			}
			else {
				a = cur1->num + cur2->num + carryover;
				carryover = a / power;
				a = a % power;
				aresult.insertNode(a);
				cur1 = cur1->prev;
				cur2 = cur2->prev;
			}
		}
		if (carryover > 0) {
			aresult.insertNode(carryover);
		}
		return aresult;
	}
	else if ((head->num <= 0) && list.head->num >= 0) {
		head->num *= -1;
		aresult = list - *this;
		return aresult;
	}
	else if ((head->num >= 0) && list.head->num <= 0) {
		list.head->num *= -1;
		aresult = *this - list;
		return aresult;
	}
	else {
		head->num *= -1;
		list.head->num *= -1;
		while ((cur1 != NULL) || (cur2 != NULL)) {
			if (cur2 == NULL) {
				a = cur1->num + carryover;
				carryover = a / power;
				a = a % power;
				aresult.insertNode(a);
				cur1 = cur1->prev;
			}
			else if (cur1 == NULL) {
				a = cur2->num + carryover;
				carryover = a / power;
				a = a % power;
				aresult.insertNode(a);
				cur2 = cur2->prev;
			}
			else {
				a = cur1->num + cur2->num + carryover;
				carryover = a / power;
				a = a % power;
				aresult.insertNode(a);
				cur1 = cur1->prev;
				cur2 = cur2->prev;
			}
		}
		if (carryover > 0) {
			aresult.insertNode(carryover);
		}
		aresult.head->num *= -1;
		return aresult;
	}
	aresult.m_digitsPerNode = m_digitsPerNode;
}
DoubleLinkedList DoubleLinkedList::operator - (const DoubleLinkedList& list)const {
	int carryover = 0;
	int a;
	Node* cur1 = tail;
	Node* cur2 = list.tail;
	DoubleLinkedList aresult;
	int power = pow(10, m_digitsPerNode);
	long long num;
		if (count < list.count) {
			if (head->num >= 0 && list.head->num >= 0) {
				cur1 = list.tail;
				cur2 = tail;
				while ((cur1 != NULL) || (cur2 != NULL)) {
					if (cur1 == NULL) {
						a = cur2->num - carryover;
						if (cur2 == list.head) {
							if (a == 0)
								break;
						}
						if (a < 0) {
							a = power + a;
							carryover = 1;
						}
						else
							carryover = 0;
						aresult.insertNode(a);
						if (cur2 != NULL)
							cur2 = cur2->prev;
					}
					else if (cur2 == NULL) {
						a = cur1->num - carryover;
						if (cur1 == head) {
							if (a == 0)
								break;
						}
						if (a < 0) {
							a = power + a;
							carryover = 1;
						}
						else
							carryover = 0;
						aresult.insertNode(a);
						if (cur1 != NULL)
							cur1 = cur1->prev;
					}
					else {
						a = cur1->num - cur2->num - carryover;
						if (cur1 == head && cur2 == list.head) {
							if (a == 0)
								break;
						}
						if (a < 0) {
							a = power + a;
							carryover = 1;
						}
						else {
							carryover = 0;
						}
						aresult.insertNode(a);
						if (cur1 != NULL)
							cur1 = cur1->prev;
						if (cur2 != NULL)
							cur2 = cur2->prev;
					}
				}
				aresult.head->num *= -1;
			}
			else if (head->num <= 0 && list.head->num >= 0) {
				cur1 = list.tail;;
				cur2 = tail;
				head->num = head->num *-1;
				aresult = *this + list;
				aresult.head->num *= -1;
			}
			else if (head->num >= 0 && list.head->num <= 0) {
				cur1 = list.tail;
				cur2 = tail;
				list.head->num *= -1;
				aresult = *this + list;
			}
			else {
				cur1 = list.tail;
				cur2 = tail;
				list.head->num *= -1;
				head->num *= -1;
				while ((cur1 != NULL) || (cur2 != NULL)) {
					if (cur1 == NULL) {
						a = cur2->num - carryover;
						if (cur2 == list.head) {
							if (a == 0)
								break;
						}
						if (a < 0) {
							a = power + a;
							carryover = 1;
						}
						else
							carryover = 0;
						aresult.insertNode(a);
						if (cur2 != NULL)
							cur2 = cur2->prev;
					}
					else if (cur2 == NULL) {
						a = cur1->num - carryover;
						if (cur1 == head) {
							if (a == 0)
								break;
						}
						if (a < 0) {
							a = power + a;
							carryover = 1;
						}
						else
							carryover = 0;
						aresult.insertNode(a);
						if (cur1 != NULL)
							cur1 = cur1->prev;
					}
					else {
						a = cur1->num - cur2->num - carryover;
						if (cur1 == head && cur2 == list.head) {
							if (a == 0)
								break;
						}
						if (a < 0) {
							a = power + a;
							carryover = 1;
						}
						else {
							carryover = 0;
						}
						aresult.insertNode(a);
						if (cur1 != NULL)
							cur1 = cur1->prev;
						if (cur2 != NULL)
							cur2 = cur2->prev;
					}
				}
			}
		}
		else if (count > list.count) {
			if (head->num >= 0 && list.head->num >= 0) {
				while ((cur1 != NULL) || (cur2 != NULL)) {
					if (cur1 == NULL) {
						a = cur2->num - carryover;
						if (cur2 == list.head) {
							if (a == 0)
								break;
						}
						if (a < 0) {
							a = power + a;
							carryover = 1;
						}
						else
							carryover = 0;
						aresult.insertNode(a);
						if (cur2 != NULL)
							cur2 = cur2->prev;
					}
					else if (cur2 == NULL) {
						a = cur1->num - carryover;
						if (cur1 == head) {
							if (a == 0)
								break;
						}
						if (a < 0) {
							a = power + a;
							carryover = 1;
						}
						else
							carryover = 0;
						aresult.insertNode(a);
						if (cur1 != NULL)
							cur1 = cur1->prev;
					}
					else {
						a = cur1->num - cur2->num - carryover;
						if (cur1 == head && cur2 == list.head) {
							if (a == 0)
								break;
						}
						if (a < 0) {
							a = power + a;
							carryover = 1;
						}
						else {
							carryover = 0;
						}
						aresult.insertNode(a);
						if (cur1 != NULL)
							cur1 = cur1->prev;
						if (cur2 != NULL)
							cur2 = cur2->prev;
					}
				}
			}
		else if (head->num <= 0 && list.head->num <= 0) {
			head->num = head->num * -1;
			list.head->num = list.head->num * -1;
			while ((cur1 != NULL) || (cur2 != NULL)) {
				if (cur1 == NULL) {
					a = cur2->num - carryover;
					if (cur2 == list.head) {
						if (a == 0)
							break;
					}
					if (a < 0) {
						a = power + a;
						carryover = 1;
					}
					else
						carryover = 0;
					aresult.insertNode(a);
					if (cur2 != NULL)
						cur2 = cur2->prev;
				}
				else if (cur2 == NULL) {
					a = cur1->num - carryover;
					if (cur1 == head) {
						if (a == 0)
							break;
					}
					if (a < 0) {
						a = power + a;
						carryover = 1;
					}
					else
						carryover = 0;
					aresult.insertNode(a);
					if (cur1 != NULL)
						cur1 = cur1->prev;
				}
				else {
					a = cur1->num - cur2->num - carryover;
					if (cur1 == head && cur2 == list.head) {
						if (a == 0)
							break;
					}
					if (a < 0) {
						a = power + a;
						carryover = 1;
					}
					else {
						carryover = 0;
					}
					aresult.insertNode(a);
					if (cur1 != NULL)
						cur1 = cur1->prev;
					if (cur2 != NULL)
						cur2 = cur2->prev;
				}
			}
			aresult.head->num = aresult.head->num * -1;
			}
			else if (head->num <= 0 && list.head->num >= 0) {
				head->num = head->num * -1;
				aresult = *this + list;
				aresult.head->num *= -1;
			}
			else {
				list.head->num = list.head->num *-1;
				aresult = *this + list;
			}
		}
		else {
			if (head->num >= 0 && list.head->num >= 0) {
				if (head->num < list.head->num) {
					cur1 = list.tail;
					cur2 = tail;
					while ((cur1 != NULL) || (cur2 != NULL)) {
						if (cur1 == NULL) {
							a = cur2->num - carryover;
							if (cur2 == list.head) {
								if (a == 0)
									break;
							}
							if (a < 0) {
								a = power + a;
								carryover = 1;
							}
							else
								carryover = 0;
							aresult.insertNode(a);
							if (cur2 != NULL)
								cur2 = cur2->prev;
						}
						else if (cur2 == NULL) {
							a = cur1->num - carryover;
							if (cur1 == head) {
								if (a == 0)
									break;
							}
							if (a < 0) {
								a = power + a;
								carryover = 1;
							}
							else
								carryover = 0;
							aresult.insertNode(a);
							if (cur1 != NULL)
								cur1 = cur1->prev;
						}
						else {
							a = cur1->num - cur2->num - carryover;
							if (cur1 == head && cur2 == list.head) {
								if (a == 0)
									break;
							}
							if (a < 0) {
								a = power + a;
								carryover = 1;
							}
							else {
								carryover = 0;
							}
							aresult.insertNode(a);
							if (cur1 != NULL)
								cur1 = cur1->prev;
							if (cur2 != NULL)
								cur2 = cur2->prev;
						}
					}
					aresult.head->num *= -1;
				}
				else {
					cur1 = tail;
					cur2 = list.tail;
					while ((cur1 != NULL) || (cur2 != NULL)) {
						if (cur1 == NULL) {
							a = cur2->num - carryover;
							if (cur2 == list.head) {
								if (a == 0)
									break;
							}
							if (a < 0) {
								a = power + a;
								carryover = 1;
							}
							else
								carryover = 0;
							aresult.insertNode(a);
							if (cur2 != NULL)
								cur2 = cur2->prev;
						}
						else if (cur2 == NULL) {
							a = cur1->num - carryover;
							if (cur1 == head) {
								if (a == 0)
									break;
							}
							if (a < 0) {
								a = power + a;
								carryover = 1;
							}
							else
								carryover = 0;
							aresult.insertNode(a);
							if (cur1 != NULL)
								cur1 = cur1->prev;
						}
						else {
							a = cur1->num - cur2->num - carryover;
							if (cur1 == head && cur2 == list.head) {
								if (a == 0)
									break;
							}
							if (a < 0) {
								a = power + a;
								carryover = 1;
							}
							else {
								carryover = 0;
							}
							aresult.insertNode(a);
							cur1 = cur1->prev;
							cur2 = cur2->prev;
						}
					}
				}
			}
			else if (head->num <= 0 && list.head->num >= 0) {
				head->num *= -1;
				aresult = *this + list;
				aresult.head->num *= -1;
			}
			else if (head->num <= 0 && list.head->num <= 0) {
				list.head->num *= -1;
				aresult = *this + list;
			}
			else {
				if (head->num > list.head->num) {
					list.head->num *= -1;
					cur1 = list.tail;
					cur2 = tail;
					while ((cur1 != NULL) || (cur2 != NULL)) {
						if (cur1 == NULL) {
							a = cur2->num - carryover;
							if (cur2 == list.head) {
								if (a == 0)
									break;
							}
							if (a < 0) {
								a = power + a;
								carryover = 1;
							}
							else
								carryover = 0;
							aresult.insertNode(a);
							if (cur2 != NULL)
								cur2 = cur2->prev;
						}
						else if (cur2 == NULL) {
							a = cur1->num - carryover;
							if (cur1 == head) {
								if (a == 0)
									break;
							}
							if (a < 0) {
								a = power + a;
								carryover = 1;
							}
							else
								carryover = 0;
							aresult.insertNode(a);
							if (cur1 != NULL)
								cur1 = cur1->prev;
						}
						else {
							a = cur1->num - cur2->num - carryover;
							if (cur1 == head && cur2 == list.head) {
								if (a == 0)
									break;
							}
							if (a < 0) {
								a = power + a;
								carryover = 1;
							}
							else {
								carryover = 0;
							}
							aresult.insertNode(a);
							if (cur1 != NULL)
								cur1 = cur1->prev;
							if (cur2 != NULL)
								cur2 = cur2->prev;
						}
					}
				}
				else {
					head->num *= -1;
					list.head->num *= -1;
					cur1 = tail;
					cur2 = list.tail;
					while ((cur1 != NULL) || (cur2 != NULL)) {
						if (cur1 == NULL) {
							a = cur2->num - carryover;
							if (cur2 == list.head) {
								if (a == 0)
									break;
							}
							if (a < 0) {
								a = power + a;
								carryover = 1;
							}
							else
								carryover = 0;
							aresult.insertNode(a);
							if (cur2 != NULL)
								cur2 = cur2->prev;
						}
						else if (cur2 == NULL) {
							a = cur1->num - carryover;
							if (cur1 == head) {
								if (a == 0)
									break;
							}
							if (a < 0) {
								a = power + a;
								carryover = 1;
							}
							else
								carryover = 0;
							aresult.insertNode(a);
							if (cur1 != NULL)
								cur1 = cur1->prev;
						}
						else {
							a = cur1->num - cur2->num - carryover;
							if (cur1 == head && cur2 == list.head) {
								if (a == 0)
									break;
							}
							if (a < 0) {
								a = power + a;
								carryover = 1;
							}
							else {
								carryover = 0;
							}
							aresult.insertNode(a);
							if (cur1 != NULL)
								cur1 = cur1->prev;
							if (cur2 != NULL)
								cur2 = cur2->prev;
						}
					}
					aresult.head->num *= -1;
				}
			}
		}
	aresult.m_digitsPerNode = m_digitsPerNode;
	return aresult;
}
DoubleLinkedList DoubleLinkedList::operator * (const DoubleLinkedList& list)const {
	int a;
	Node* cur2 = list.tail;
	Node* cur1 = tail;
	DoubleLinkedList result;
	DoubleLinkedList result1;
	int count = 0;
	int carryover = 0;
	result.m_digitsPerNode = m_digitsPerNode;
	int power = pow(10, m_digitsPerNode);
	if (head->num >= 0 && list.head->num >= 0) {
		while (cur2 != NULL) {
			carryover = 0;
			cur1 = tail;
			result1.m_digitsPerNode = m_digitsPerNode;
			result1.destroyList();
			while (cur1 != NULL) {
				a = cur1->num * cur2->num + carryover;
				carryover = a / power;
				a = a % power;
				result1.insertNode(a);
				cur1 = cur1->prev;
			}
			if (carryover > 0) {
				result1.insertNode(carryover);
			}
			for (int x = 0; x < count; x++) {
				result1.insertEnd(0);
			}
			cur2 = cur2->prev;
			result = result + result1;
			count++;
		}
	}
	else if(head-> num >=0 && list.head->num <= 0){
		list.head->num *= -1;
		while (cur2 != NULL) {
			carryover = 0;
			cur1 = tail;
			result1.m_digitsPerNode = m_digitsPerNode;
			result1.destroyList();
			while (cur1 != NULL) {
				a = cur1->num * cur2->num + carryover;
				carryover = a / power;
				a = a % power;
				result1.insertNode(a);
				cur1 = cur1->prev;
			}
			if (carryover > 0) {
				result1.insertNode(carryover);
			}
			for (int x = 0; x < count; x++) {
				result1.insertEnd(0);
			}
			cur2 = cur2->prev;
			result = result + result1;
			count++;
		}
		result.head->num *= -1;
	}
	else if (head->num <= 0 && list.head->num >= 0) {
		head->num *= -1;
		while (cur2 != NULL) {
			carryover = 0;
			cur1 = tail;
			result1.m_digitsPerNode = m_digitsPerNode;
			result1.destroyList();
			while (cur1 != NULL) {
				a = cur1->num * cur2->num + carryover;
				carryover = a / power;
				a = a % power;
				result1.insertNode(a);
				cur1 = cur1->prev;
			}
			if (carryover > 0) {
				result1.insertNode(carryover);
			}
			for (int x = 0; x < count; x++) {
				result1.insertEnd(0);
			}
			cur2 = cur2->prev;
			result = result + result1;
			count++;
		}
		result.head->num *= -1;
	}
	else {
		head->num *= -1;
		list.head->num *= -1;
		while (cur2 != NULL) {
			carryover = 0;
			cur1 = tail;
			result1.m_digitsPerNode = m_digitsPerNode;
			result1.destroyList();
			while (cur1 != NULL) {
				a = cur1->num * cur2->num + carryover;
				carryover = a / power;
				a = a % power;
				result1.insertNode(a);
				cur1 = cur1->prev;
			}
			if (carryover > 0) {
				result1.insertNode(carryover);
			}
			for (int x = 0; x < count; x++) {
				result1.insertEnd(0);
			}
			cur2 = cur2->prev;
			result = result + result1;
			count++;
		}
	}
	
	return result;
}
string DoubleLinkedList::toString(int digits) {
	string result = "";
	Node * current = head;
	stringstream ss;
	while (current != NULL)
	{
		if (current == head) {
			ss << current->num;
		}
		else {
			ss  <<  std::setfill('0') << setw(digits) << current->num;
		}
		current = current->next;
	}
	result = ss.str();
	return result;
}

#endif
