/* 
 * File: linkedlist.cpp
 * Author: Aatmodhee Goswami
 * 
 * Linked List's header file
 */
 
 #ifndef LINKEDLIST_H
 #define LINKEDLIST_H
 #include "data.h"
 #include <iostream>
 class LinkedList
 {
 	private:
 	Node *head;

 		bool addNewHead(int, string*,Node*, Node*);
 		bool addNewTail(int, string*,Node*, Node*);
 		bool connectNodes(int, string*, Node*, Node*);
 		bool deleteSubFunc(Node*);
 	public:
 		LinkedList();
 		bool addNode(int, string*);
 		bool deleteNode(int);
 		bool getNode(int, Data*);
 		void printList(bool=false);
 		int getCount();
 		bool clearList();
		bool exists(int);
		 
 };
 
 #endif
