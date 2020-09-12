#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;

long int N_op = 0;

class Dec{
	
private:
	struct Node{
	int c;
	Node *next;
	Node *prev;
};

typedef Node *PNode;
PNode Head, Tail;
int leght;

PNode CreateNode(int NewInt){
	PNode NewNode = new Node;
	NewNode->c = NewInt;
	NewNode->next = NULL;
	NewNode->prev = NULL;
	return NewNode;
}

public:
	Dec(){
		leght = 0;
		Head = NULL;
		Tail = NULL;
	}
bool empty(){
	if(Head == NULL){
		return 1;
	}
	else{
		return 0;
	}
}
void AddL(int Num){
	PNode NewNode = CreateNode(Num);		
	if(Head == NULL){
		NewNode->next = NULL;			
		NewNode->prev = NULL;			
		Head = NewNode;			
		Tail = NewNode;			
	}
	else{
		NewNode->next = Head;			
		NewNode->prev = NULL;			
		Head->prev = NewNode;			
		Head = NewNode;			
	}
	leght++;			
}

void DelL(){
	if(Head == NULL){
		cout << "List Null" << endl;
		return;
	}
	else{
		Head = Head->next;
		if(Head != NULL){
			Head->prev = NULL;	
		}
		else{
			Tail = NULL;
		}
	leght--;
	}
}

void DelR(){
	if(Tail == NULL){					
		cout << "List Null" << endl;
		return;							
	}
	else{
		Tail = Tail->prev;				
		if(Tail != NULL){
			Tail->next = NULL;		
		}
		else{
			Head = NULL;				
		}
		leght--;					
	}
}

void AddR(int Num){
	PNode NewNode = CreateNode(Num);	
	if(Tail == NULL){					
		NewNode->next = NULL;			
		NewNode->prev = NULL;			
		Head = NewNode;					
		Tail = NewNode;					
	}	
	else{
		NewNode->next = NULL;			
		NewNode->prev = Tail;			
		Tail->next = NewNode;			
		Tail = NewNode;				
	}
	leght++;							
}
void Enter(){
	if(!empty()){
		PNode p = Head;
		while(p != NULL){
			cout << p->c << " ";
			p = p->next;
		}
		cout << endl;
	}
}

int ValueL(){								
	if(!empty()){
		return Head->c;			
	}
}
int ValueR(){					
	if(!empty()){				
		return Tail->c;	
	}
}

void NewDec(){
	leght = 0;
	Head = NULL;
	Tail = NULL;
}
void Sort(){
	N_op++;N_op++;
	for(int i = 1;i < leght;i++){	
	N_op += 23;
	int b = ValueR();DelR();				
		int j;								
		for(j = 0;j<=i;j++){				
			N_op += 6;								
			if(b < ValueL() || j==i){
				N_op += 13;
				AddL(b);
				break;
			}
			else{
				N_op += 21;
				AddR(ValueL());DelL();
			}
		}								
		for(int k = j;k > 0;k--){
			N_op += 21;
			AddL(ValueR());DelR();		
		}
	}
}
};
int EnterNum;

int main(){
	Dec List;
	int n;
	cout << "Enter n:";cin >> n;
	for(int i = 0;i < n;i++){
		List.AddR(i);
	}
	List.Sort();
	cout << "Number of operations: " << N_op<<endl;;
}
