#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct telmtlist *address;

typedef struct telmtlist {
	infotype info;
	address next;
} elemen;

typedef struct {
	address first;
}List;

#define First(L) (L).first
#define Next(P) (P)->next
#define Info(P) (P)->info
#define Nil NULL
#define Infinity 99999

 

bool isEmpty (List L){
	return (First(L)==Nil);
}

void createEmpty (List *L){
	First(*L)=Nil;

}

address alokasi (infotype X){
	address P = address(malloc(sizeof(elemen)));
	if(P==Nil)
		return Nil;

	Info(P) = X;
	Next(P) = Nil;
	return P;	
}

void dealokasi (address *P){
	free(*P);
}

void insertFirst (List *L, infotype X){
	address P = alokasi(X);
	if(P!=Nil){
		Next(P)=First(*L);
		First(*L) = P;
	}
}

void insertAfter (List *L, address P, address Prec){
	Next(P)=Next(Prec);
	Next(Prec)=P;
}

void insertLast (List *L, infotype X){
	address P = alokasi(X);
	if(isEmpty(*L))
		insertFirst(L, X);
	else{
		address last = First(*L);
		while(Next(last)!=Nil) last = Next(last);
		insertAfter(L,P,last);
	}
}

void printInfo (List L){
	cout<<'[';
	if(!isEmpty(L)){
		address P = First(L);
		while(Next(P)!=Nil){
			cout<<Info(P)<<", ";
			P = Next(P);
		}
		cout<<Info(P);
	}
	cout<<']'<<endl;
}


int main(){
	List L;
	createEmpty(&L);

	int n;
	infotype x;
	cin>>n;
	for (int i =0;i<n;i++){
		cin>>x;	
		insertFirst(&L, x);
	
	}
	printInfo(L);
	
}

