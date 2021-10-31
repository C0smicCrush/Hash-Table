/* 
 * your comment header here
 */
 #ifndef Hashtable_H
 #define Hashtable_H
 #define SIZE 15
 #include "linkedlist.h"
 class Hashtable{
 	public:
 	bool insertEntry(int, string*);
 	string getData(int);
 	bool removeEntry(int);
 	int getCount();
 	void printTable();
 	Hashtable();
 	~Hashtable();

 	private:
 	int hash(int);
 	int count;
 	LinkedList table[SIZE];
 };
 #endif
