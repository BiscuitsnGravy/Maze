#ifndef QUEUE_H
#define QUEUE_H
#include <cstddef>
#include <cstdlib>
template<typename T>
class Queue{
public:
	Queue() : frontPtr(NULL), backPtr(NULL), count(0)
{
}   
	bool isEmpty(){
		return(count == 0);
	}
	void enqueue(const T & x){	 
		Node *newOne = new Node;
		newOne->data = x; 
		newOne->next = NULL;  
		if(isEmpty()){ 
			frontPtr = newOne;  
		}       
		else           
			backPtr->next = newOne;       
		backPtr = newOne;        
		count++;
	}   
	T dequeue(){
		T x;
		Node *temp = frontPtr;   

		if(frontPtr == backPtr){               
			frontPtr = NULL;            
			backPtr = NULL;          
		}          
		else{
			frontPtr = frontPtr->next;  
		}
		x = temp->data;
		delete temp;  
		count--; 
		return x;
	}		

	void print (void)	{
		T x;
		cout << "Contents of Queue: ";
		if (!isEmpty()){
			for (int i=0;i<count;i++){
				x = dequeue();
				cout << x;
				enqueue (x);
			}
			cout << '\n';
		}
	} 
    private:
        struct Node{
            T data;
            Node *next;
        };

        Node *frontPtr;
        Node *backPtr;
        int count;
};

#endif // QUEUE_H 