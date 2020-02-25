#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct tElmnlist *address;

typedef struct tElmnlist {
    infotype info;
    address next;
} elemen;

typedef struct {
    address first;
}list;

void createEmpty(list *L){
    (*L).first = NULL;
}

bool isEmpty(list L) {
    return ((L).first == NULL) ;
}

address alokasi(infotype x){
    address newElmn;
    newElmn = (elemen*) malloc (sizeof(elemen));
    
    newElmn->info=x;
    newElmn->next=NULL;
    
    return newElmn;
}

void dealokasi(address hapus) {
    free(hapus);
}

void insertfirst(list *L, infotype x) {
    address newElmn;
    newElmn = alokasi(x);
    
    if(newElmn !=NULL){
        newElmn->next = (*L).first;
        (*L).first = newElmn;
    }
}

void insertafter(address *prevelemen, infotype x){
    address newElmn;
    newElmn=alokasi(x);
    
    if (newElmn !=NULL){
        newElmn->next = (*prevelemen)->next;
        (*prevelemen)->next = newElmn;
    }
}

void insertlast(list *L, infotype x){
    if(isEmpty(*L)) {
        insertfirst(&(*L),x);
    }else {
        address P;
        P=(*L).first;
        
        while (P->next !=NULL){
            P=P->next;
        }
        insertafter(&P,x);
    }
}

void deletefirst(list *L, infotype *hapus) {
    if(!isEmpty(*L)) {
        address P;
        P=(*L).first;
        *hapus = P->info;
        (*L).first=(*L).first->next;
        P->next = NULL;
        dealokasi(P);
    }
}

void deleteafter(address prev, infotype *hapus){
    if(prev->next !=NULL){
        address P;
        P=prev->next;
        *hapus=P->info;
        prev->next = P->next;
        P->next=NULL;
        dealokasi(P);
    }
}

void deletelast(list *L, infotype *hapus){
    if(!isEmpty(*L)){
        address P, prevtemp;
        prevtemp=NULL;
        P=(*L).first;
        while(P->next !=NULL){
            prevtemp=P;
            P=P->next;
        }
        
        if (P==(*L).first){
            deletefirst(&(*L), &(*hapus));
        } else {
            deleteafter(prevtemp, &(*hapus));
        }
    }
}

void printInfo(list nilai){
        cout<< "[";
    if(!isEmpty(nilai)){
        address awal = nilai.first;
        while(awal->next!=NULL){
            cout<<awal->info<<", ";
            awal = awal->next;
        }
        cout << awal->info;
    }
    cout<< "]";
    
}
void hapus(list *nilai){
        address awal;
        infotype x;
    awal=(*nilai).first;
    
        while(awal!=NULL){
            x=awal->info;
            if(x%2==0){
                deletefirst(&(*nilai),&(*nilai).first->info);
            }else if(x%3==0){
                deletelast(&(*nilai),&(*nilai).first->info);
            }
            awal=awal->next;
        }
}

int main(){
    list nilai;
    int n;
    int X;    
            
    createEmpty(&nilai);
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> X;
        insertlast(&nilai,X);                
    }
    
    hapus(&nilai);    
    
    printInfo(nilai);

}
