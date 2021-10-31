/* 
 * your comment header here
 */
 #include "hashtable.h"
int Hashtable::getCount(){
 	return count;
}
int Hashtable::hash(int x){
	return x%SIZE;
}
bool Hashtable::insertEntry(int id, string* inString){
	int hashed = hash(id);
	bool added = false;
	
	if (table[hashed].addNode(id, inString)){
		added = true;
		count++;
	}

	return added;
}
string Hashtable::getData(int x){
	int hashed = hash(x);
 	Data dataT;
 	dataT.data = "";
 	dataT.id = x;
	if(hashed < 15 && hashed >= 0){
		if(table[hashed].getCount()){
	table[hashed].getNode(x, &dataT);
		}
	}
	return dataT.data;
}
void Hashtable::printTable(){
	for(int x = 0; x < SIZE; x++){
		if(table[x].getCount()){
			std::cout << "Index " << x << " Has: ";
			table[x].printList(true);
			std::cout << std::endl;
		}
		else{
			std::cout << "Nothing in index " << x << std::endl;
		}
	}
	
}
bool Hashtable::removeEntry(int id){
	int hashed = hash(id);
	bool deleted = false;
	if(table[hashed].deleteNode(id)){
	count--;
	}
	return deleted;
}
Hashtable::Hashtable(){
	count = 0;
}
Hashtable::~Hashtable(){
	for(int x = 0; x < SIZE; x++){
		if(table[x].getCount()){
			table[x].clearList();
		}
	}
	count = 0;
}
