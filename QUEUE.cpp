#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct TElmtQueue *address;
typedef struct TElmtQueue{
    infotype Info;
    address Next;
} ElmtQueue;

typedef struct { 
	address Head;  //penghapusan
	address Tail;  //penambahan
} Queue;

#define Nil NULL
#define Head(Q) (Q).Head
#define Tail(Q) (Q).Tail
#define InfoHead(Q) (Q).Head->Info
#define InfoTail(Q) (Q).Tail->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info

address Allocation(infotype X) {
    address NewElmt;
    NewElmt = (ElmtQueue*) malloc (sizeof(ElmtQueue));

    Info(NewElmt) = X;
    Next(NewElmt) = Nil;    

    return NewElmt;
}

void Deallocation(address P) {
    free(P);
}

bool IsEmpty(Queue Q) {
    return ((Head(Q)==Nil) && (Tail(Q)==Nil));
}

int NbElmt(Queue Q){
	if (IsEmpty(Q)) {
		return 0;
	} else {
		return (Tail(Q)-Head(Q)+1);	
	}
}

void CreateEmpty (Queue *Q){
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}

void Add (Queue *Q, infotype X)
{
   address P =  Allocation(X);
   if (P!=Nil) {
      if (IsEmpty(*Q)) {
          Head(*Q) = P;
		  Tail(*Q) = P;
      } else {
          Next(Tail(*Q)) = P;
          Tail(*Q) = P;
      }
   }
}

void Del(Queue *Q, infotype *X){
   address P;
   *X = InfoHead(*Q);
   P = Head(*Q);
   Head(*Q) = Next(Head(*Q));
   if (Head(*Q)==Nil) {
      Tail(*Q) = Nil;
   }
   Deallocation(P);
}

int main() {
    Queue data;
    infotype tempHapus;

    CreateEmpty(&data);
    Add(&data, 7);
    Add(&data, 6);
    
    Del(&data, &tempHapus); cout << tempHapus << "  Data Telah dihapus" << endl;
    Del(&data, &tempHapus); cout << tempHapus <<"  Data Telah dihapus" << endl;
    Add(&data, 7);
 
 	while (!IsEmpty(data)) {
        Del(&data, &tempHapus);
		cout << tempHapus << endl;
    }
    
    return 0;
} 
