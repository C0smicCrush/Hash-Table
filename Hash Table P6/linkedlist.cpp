/* 
 * File: linkedlist.cpp
 * Author: Aatmodhee Goswami
 * 
 * The brains of the Linked List!
 */
 #include "linkedlist.h"
 
 LinkedList::LinkedList(){
	head = NULL;
 }
bool LinkedList::addNode(int idIn, string* inString){
	bool added = false;
	Node* position = head;
	if((idIn > 0) &&  !(inString->empty())){
		int check  = 0;
		Node* nodePtr = new Node;
		nodePtr->data.data = *inString;
		nodePtr->data.id = idIn;
		if(!head  || head->data.id > idIn){
			added = addNewHead(idIn, inString, position, nodePtr);
			check++;
		}
		position = head;
		while(position->data.id < idIn &&(position->next)){
			position = position->next;
		}	
		if(position->data.id == idIn && check == 0){
			delete nodePtr;
			}
		if((position->data.id > idIn) || (position->data.id < idIn)){
			added = connectNodes(idIn,inString,position, nodePtr);
		}
	}
	 return added;
}

 
 bool LinkedList::addNewTail(int idIn, string* inString, Node* position, Node* inNode)
 {
	position->next = inNode;
	inNode->next = NULL;
	inNode->prev = position;
	return true;
 }
 bool LinkedList::connectNodes(int idIn, string* inString, Node* position, Node* inNode){
 	if(position->data.id > idIn){
	
 	inNode->prev = position->prev;
 	inNode->next = position;
 	position->prev->next = inNode;
 	position->prev = inNode;
 	}
 	else{
 		bool added = addNewTail(idIn, inString, position, inNode);
	 }
 	return true;
 	
 }
 
 bool LinkedList::addNewHead(int idIn, string* inString, Node*position, Node* inNode){
 	
	if(!head){
	head = inNode;
	head->next = NULL;
	head->prev = NULL;
}

	else{
	inNode->next = head;
	inNode->prev = NULL;
	head->prev = inNode;
	head = inNode;
	}
 
 return true;
 }
 
 bool LinkedList::getNode(int id, Data* inData){
 	bool added = true;
 	if(id > 0){
 		Node* ptr = head;
 		while(ptr->next && ptr->data.id < id){
 			ptr = ptr->next;
		 }
		if(ptr->data.id == id){
			added = true;
			inData->id = id;
			inData->data = ptr->data.data;
		} 
		else{
			inData->id = -1;
			inData->data = "";
		}
	 }
	 else{
	 	inData->id = -1;
	 	inData->data = "";
	 	
	 }
	 return added;
 }
 
 bool LinkedList::clearList(){
 	if(head){
 		Node* ptr = head;
 		
 		while(ptr->next){
 			ptr = ptr->next;
 			delete ptr->prev;
		 }
		 delete ptr;
	 }
	 head = NULL;
 	return true;
 }
 bool LinkedList::deleteNode(int idIn){
 	bool exists = false;
 	Node* ptr = head;
 	if(idIn > 0 && head){
	while(ptr->data.id < idIn && ptr->next){
			ptr = ptr->next;
	}
	if(ptr->data.id == idIn){
		exists = deleteSubFunc(ptr);
	}
}
	 return exists;

 }
 bool LinkedList::deleteSubFunc(Node* nodeIt){
 	if(!nodeIt->next){
 		if(!nodeIt->prev){
 			delete nodeIt;
			head = NULL;	
		 }
		 else{
		 	nodeIt->prev->next = NULL;
		 	delete nodeIt;
		 }
	 }
	 else if(!nodeIt->prev){
	 	head = nodeIt->next;
	 	nodeIt->next->prev = NULL;
	 	delete nodeIt;
	 }
	 else{
	 	nodeIt->prev->next = nodeIt->next;
	 	nodeIt->next->prev = nodeIt->prev;
	 	delete nodeIt;
	 }
 	return true;
 }
 bool LinkedList::exists(int idIn){
 	bool exists = false;
 	if(idIn > 0){
 		Node* ptr = head;
 		while(ptr->next && ptr->data.id < idIn){
 			ptr = ptr->next;
		 }
		if(ptr->data.id == idIn){
			exists = true;
		} 
	
	 }
	 return exists;
 }
 int LinkedList::getCount(){
 	Node* position;
 	int count = 0;
 	position = head;
	 
 	while(position != NULL){
 		position = position->next;
 		count++;
	 }
	 return count;
 }
 void LinkedList::printList(bool x){
 	if(x){
 		Node* position;
 		position = head;
 		while(position->next){
 			position = position->next;
		 }
		while(position){
			std::cout << position->data.id<< "-->";
			position = position->prev;
		}
	 }
	else{
	
 	Node* position;
 	position = head;
 	while (position != NULL){
 		std::cout << position->data.id << position->data.data<<std::endl;
 		position = position->next;
	 }
	}
 }
 
