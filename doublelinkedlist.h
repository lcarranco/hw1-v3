//doublelinkedlist.h
struct Node 
{
    int num; //Changed from long long num to int num
	Node* prev; //Node* prev = NULL; ***Why set this to NULL?
	Node* next; //Node* next = NULL; ***Why set this to NULL?
};

class DoubleLinkedList
{
public:
    DoubleLinkedList(); // default construct
	~DoubleLinkedList(); // deconstruct
	DoubleLinkedList(const std::string& num, int digitsPerNode); // user defined construct
    DoubleLinkedList(int digitsPerNode);
	DoubleLinkedList(const DoubleLinkedList& list); // copy construct
	DoubleLinkedList& operator = (const DoubleLinkedList& list); // assignment consturct
    //mandatory
    DoubleLinkedList& operator + (const DoubleLinkedList& list) const;
	DoubleLinkedList& operator * (const DoubleLinkedList& list) const;
	// optional
	DoubleLinkedList& operator - (const DoubleLinkedList& list);
	// 10% extra 
	DoubleLinkedList& operator / (const DoubleLinkedList& list);
	// 20% extra
	DoubleLinkedList Sqrt(const DoubleLinkedList& list) const;
    const Node* GetHead() const;
	const Node* GetTail() const;
	void Append(Node* node);
	void Print() const;
	void DestroyList(); //Function to delete all the nodes from the list
	void InitializeList(); /*Initialize the list to an empty state or if there exists
							a list then delete all the nodes from the list*/
	int LengthOfList() const; //Return the number of nodes in the list
	void InsertFirst(int val);
private: //*************Zero private data members
	void CopyList(const DoubleLinkedList& list);
    Node* head; //Node* head = NULL;. ***Why set head to NULL here and not the default constructor?
    Node* tail; //***Did not set tail to NULL. Why?
    int m_digitsPerNode;
	long long remainder; // for / operator
	float decimal;  // for sqrt()  7 valid digits.
	int counter; //Counter
};