/* 
 * your comment header here
 */

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */

    // create your hash table object here
    Hashtable hashtable;
    // show it is empty by calling getCount and printTable
    cout << hashtable.getCount() << " Proper elements"<< std::endl;
    hashtable.printTable();
    // try and put ALL the test data into the table and show what happens
    cout << testdatasize << " Is the test data size" << std::endl;
	for(int x = 0; x < testdatasize; x++){
		hashtable.insertEntry(ids[x], &strs[x]);
	}
    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.
	/* Need to test
	bool insertEntry(int, string*);
 	string getData(int);
 	bool removeEntry(int);
 	int getCount();
 	void printTable();
 	Hashtable();
 	~Hashtable();
	*/
	
	//We first test if the insert entry method works, and if it does, if the print table method can express it properly
	hashtable.printTable();
	
	cout << std::endl << "There are " << hashtable.getCount() << " Data Points " << std::endl;
	//lets test getData extensively:
	//First we test the values we know are in the data
	for(int x = 0; x < testdatasize; x++){
		cout << hashtable.getData(ids[x])<<std::endl;
	}
	cout << "Now we test at least some non-ids into getData" << std::endl;
	//Next we test, knowing that statistically there will very likely be a value of x which is not an actual ID
	for(int x = 0; x < testdatasize; x++){
		cout << hashtable.getData(x)<<std::endl;
	}
	//Now we test the extremes
	cout << "getData extremal testing"<<std::endl;
	cout << hashtable.getData(100) <<std::endl;
	cout << hashtable.getData(0) << std::endl;
	cout << "getData extremal testing finished"<<std::endl;
	
	//Time to test removeEntry
	cout << "Testing Remove entry, there are currently data points: " << hashtable.getCount()<<std::endl;
	//remove one entry
	hashtable.removeEntry(ids[1]);
	//check number of entries
	cout << "The current data point number is : "<<hashtable.getCount()<<std::endl;
	//Check remove entry but for extremal cases
	hashtable.removeEntry(1000);
	cout << "Extremal removal one, The current data point number is: " << hashtable.getCount()<<std::endl;
	hashtable.removeEntry(0);
	cout << "Extremal removal two, The current data point number is " << hashtable.getCount() << std::endl;
	cout << "Let's try to remove more elements than there exists" << std::endl;
    for(int x = 0; x< testdatasize + 1; x++){
    	hashtable.removeEntry(ids[x]);
	}
    cout << "The total elements are now: " << hashtable.getCount()<<std::endl;
    
    //Testing mashups now
    cout << "It has been filled up again" << std::endl;
	for(int x = 0; x < testdatasize; x++){
		hashtable.insertEntry(ids[x], &strs[x]);
	}
	//We have filled it up again
   //Testing overflow
   for(int x = 0; x < testdatasize;x++){
   	hashtable.insertEntry(ids[2], &strs[2]);
   	hashtable.removeEntry(ids[2]);
   }
   std::cout << "We should end up with one less than full "<<std::endl;
   std::cout<<hashtable.getCount() << " Is the number of elements"<<std::endl<<std::endl;
    
    //Testing printTable more thoroughly
    for(int x = 0; x < 4; x++){
    	hashtable.printTable();
    	hashtable.removeEntry(ids[x]);
    	cout << std::endl;
    	cout << "Total elements: " << hashtable.getCount()<<std::endl;
	}
	
	
	//Now we test insertEntry exhaustively
	for(int x = 0; x < 4; x++){
		cout << "Testing inserting entry which is a bad id ";
		cout << hashtable.insertEntry(0, &strs[x])<<std::endl;
		string str = "";
		cout << "Testing inserting bad string ";
		cout << hashtable.insertEntry(1,&str)<<std::endl;
		int testint = 1000 + (rand() % 400 + 1);
		cout << "Testing extremal cases ( "<< testint << "):" << hashtable.insertEntry(testint, &strs[x])<<std::endl;
	}

cout << "We now do a completely random test of all the major functions 100 times in completely random fashion, since printing it would be impossible to follow I have left that out" << std::endl;
cout << "As long as the program runs, it would mean we have done this properly and functionally" << std::endl;
	for(int x = 0; x < 100; x++){
	int r = rand() % 3;
	switch(r){
		case 0:
			hashtable.insertEntry(rand() % 400 + 1, &strs[rand() % testdatasize]);
			break;
	
		case 1:
			hashtable.getData(ids[rand() & testdatasize]);
			break;
		case 2:
			hashtable.removeEntry(ids[rand() & testdatasize]);
			break;
	}
		
}
cout << "If you are seeing this, it has worked!"<<std::endl;
	cout << hashtable.getCount() << " Is the total number of data points in hashtable" <<std::endl;
	hashtable.printTable();
	cout << std::endl;
	hashtable.~Hashtable();
	cout << "We have deleted the hashtable, there are currently "<< hashtable.getCount()<< " elements left" << std::endl;
	hashtable.printTable();
    return 0;
}
