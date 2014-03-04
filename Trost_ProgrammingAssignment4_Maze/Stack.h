#ifndef Stack_H
#define Stack_H
#include <cstddef>
#include <cstdlib>
template<typename T>
class Stack{
public:
	Stack() : top(NULL), count(0)
{
}   
	bool isEmpty(){
		return(count == 0);
	}

	T getTop (void){
		return top->data;
	}

	void push(const T & x){	 
		Node *newOne = new Node;
		newOne->data = x; 
		newOne->next = top;  
		top = newOne;
		count++;
	}   
	T pop(){
		T x;
		Node *temp = top;           
		x = top->data;
		top = top->next; 
		delete temp;  
		count--; 
		return x;
	}		
	void print (void){
		T x;
		Stack <T> S;
		cout << "Contents of Stack: ";
		while (!isEmpty()){
			x = pop();
			cout << x;
			S.push(x);
		}
		cout << '\n';
		while (!S.isEmpty()){
			x = S.pop();
			push(x);
		}
	}
     
    private:
        struct Node{
            T data;
            Node *next;
        };

        Node *top;
        int count;
};

#endif 