#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int type;
typedef struct tlist *address;

typedef struct tlist {
	type info;
	address next;
} elemen;

typedef struct {
	address first;
}list;

void createempty(list *L){
	(*L).first = NULL;
}

bool isempty(list L) {
	return ((L).first == NULL) ;
}

address allocation(type x){
	address newelemen;
	newelemen = (elemen*) malloc (sizeof(elemen));
	
	newelemen->info=x;
	newelemen->next=NULL;
	
	return newelemen;
}

void deallocation(address hapus) {
	free(hapus);
}

void insertfirst(list *L, type x) {
	address newelemen;
	newelemen = allocation(x);
	
	if(newelemen !=NULL){
		newelemen->next = (*L).first;
		(*L).first = newelemen;
	}
}

void insertafter(address *prevelemen, type x){
	address newelemen;
	newelemen=allocation(x);
	
	if (newelemen !=NULL){
		newelemen->next = (*prevelemen)->next;
		(*prevelemen)->next = newelemen;
	}
}

void insertlast(list *L, type x){
	if(isempty(*L)) {
		insertfirst(&(*L),x);
	}else {
		address temp;
		temp=(*L).first;
		
		while (temp->next !=NULL){
			temp=temp->next;
		}
		insertafter(&temp,x);
	}
}

void deletefirst(list *L, type *hapus) {
	if(!isempty(*L)) {
		address temp;
		temp=(*L).first;
		*hapus = temp->info;
		(*L).first=(*L).first->next;
		temp->next = NULL;
		deallocation(temp);
	}
}

void deleteafter(address prev, type *hapus){
	if(prev->next !=NULL){
		address temp;
		temp=prev->next;
		*hapus=temp->info;
		prev->next = temp->next;
		temp->next=NULL;
		deallocation(temp);
	}
}

void deletelast(list *L, type *hapus){
	if(!isempty(*L)){
		address temp, prevtemp;
		prevtemp=NULL;
		temp=(*L).first;
		while(temp->next !=NULL){
			prevtemp=temp;
			temp=temp->next;
		}
		
		if (temp==(*L).first){
			deletefirst(&(*L), &(*hapus));
		} else {
			deleteafter(prevtemp, &(*hapus));
		}
	}
}

int main(){
	address awal;
	list data;
	type temphapus;
	bool found=false;
	
	int n;
	int temp;	

			
	createempty(&data);
	cout << "\t\t\tProgram Menggunakan Single Linked List" << endl << endl;
	
	cout << "Masukkan Jumlah data\t= ";
	cin >> n;
	
	cout << "\n";
	for(int i=0;i<n;i++){
		cout << "Data Ke-" << i+1 << "\t= ";
		cin >> temp;
		insertlast(&data,temp);				
	}
	
	cout << endl;
	int key;
	cout << "Data Yang akan dihapus\t= ";
	cin >> key;
	
	cout << endl << endl;
	
	cout << "Data Sebelum Dihapus";
	cout << endl;
	cout << "[";
	awal=data.first;
	while(awal!=NULL){
		cout << awal->info<< " ";
		awal=awal->next;
	}
	cout << "\b]";
	cout << endl << endl;
	
	awal=data.first;
	type indeks=1;
	while(awal!=NULL&&found!=true){
	
		if((awal->info==key)&&(awal==data.first)&&(awal->next==NULL)){
			found=true;
			cout << awal->info <<" merupakan elemen satu-satunya di list";
			deletefirst(&data,&awal->info);
			
		}else if((awal->info==key)&&(awal->next==NULL)){
			found=true;
			cout << awal->info << " ada di akhir list";
			deletelast(&data,&awal->info);
			
		}else if(awal->info==key){
			found=true;
			cout << awal->info << " ada di list elemen ke-" << indeks;
			deleteafter(awal,&awal->info);
		}else if((awal->info==key)&&(awal==data.first)){
			found=true;
			cout << awal->info <<" ada di awal list";
			deletefirst(&data,&awal->info);
			
		}
		indeks ++;
		awal=awal->next;
	}
	
	if(found==false){
		cout << "Data Tidak ada ditemukan";
	}
	
	cout << endl << endl;
	cout << "Data Setelah Dihapus";
	cout << endl;
	cout << "[";
	awal=data.first;
	while(awal!=NULL){
		cout << awal->info<< " ";
		awal=awal->next;
	}
	cout << "]";
}
