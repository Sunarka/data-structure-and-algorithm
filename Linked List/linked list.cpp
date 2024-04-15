#include <iostream>
using namespace std;

class Node {
public:
    char id;
    Node* next;

    Node() {
        next = NULL; 
    }
};

class LinkedList { 
public:
    Node* head; 
    Node* tail; 

    LinkedList() { 
		head = tail = NULL; 
	}

    void insertToHead(char data){
    	Node *node = new Node();
    	node->id = data;
    
    	if(head == NULL){
    		head = node;
    		tail = node;
		}else{
			Node *tmp = head;
			head = node;
			head->next = tmp;
		}
	}
	
	void insertToTail(char data){
		Node *node = new Node();
	node->id = data;
		
		if(head == NULL){
			head = node;
			tail = node;
		}else{
			tail->next = node;
			tail = node;
		}
	}
	
	void printAll(){
		Node *tmp = head;
		
		while (tmp != NULL){
			cout << tmp->id << "->";
			tmp = tmp->next;
		}
	}
	
	void insertDataAfter(char data, char after){
		if (head == NULL){
			cout << "Error: empty data";
			
		}else if(tail->id == after){
			insertToTail(data);
			
		}else{
			Node *tmp = head;
			
			while(tmp != NULL && tmp->id != after){
				tmp = tmp->next;
			}
			
			if(tmp == NULL){
				cout << "After data not found" << endl;
			}else{
				Node*newNode = new Node();
				newNode->id = data;
				
		newNode->next = tmp->next;
				tmp->next = newNode;
			}
		}
	}
	
    void DeleteHead(){
        Node *tmp = head;
		
		if(head == NULL){
			cout << "Data kosong!!" << endl;
		
		}else if(head == tail){
			delete tmp;
			head = tail = NULL;
		
		}else{
			head = head->next;
			delete tmp;
			
		}
		cout << "Deleted head" << endl;
	}
	
	void DeleteData(char data){
    	if(head == NULL){
        	cout << "Data kosong " << endl;
        	return;
		}

		Node* current = head;
		Node* prev = NULL;
		Node* prevhead = head;
    
    	if(head->id == data){
        	Node *tmp = head; 
        	head = head->next;
        	
        	if(head == NULL){ 
            	head = tail = NULL; 
        	}
        delete tmp; 
        cout << "Deleted prev Head" << endl;
        return;
		}

    
    	while(current != NULL && current->id != data){
			prev = current;
			current = current->next;
		}
    
    	if(current == NULL){
        	cout << "Data yang mau dihapus tidak ditemukan" << endl;
        	return;
    	}

    	if(prev != NULL){
        	prev->next = current->next; 
   		}

    
    	if(current == tail){
        	tail = prev; 
    	}

    	delete current; 
    	cout << "Data deleted : " << data << endl;
	}

};


int main(int argc, char** argv) { 
    LinkedList *list1 = new LinkedList();

    list1->insertToHead('A');
    list1->insertToTail('B');
    list1->insertDataAfter('C', 'B');
    list1->insertDataAfter('D', 'C');
    list1->insertDataAfter('E', 'D');
    list1->insertDataAfter('F', 'E');

    list1->DeleteHead();
    list1->DeleteData('D');
    cout << "Head : " << list1->head->id <<endl;
    cout << "Tail : " << list1->tail->id <<endl;
    cout << "\n----------------------\n";
    list1->printAll();
    
    return 0; 
}