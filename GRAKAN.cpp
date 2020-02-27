//bikin spasi
//bikin tabel

//| Afdi Fauzul Bahar                 NIM     14117149 |
//| Arimbi Ayuningtyas                NIM     14117140 |
//| Pungki Resti Prabandari           NIM     14117154 |


#include<iostream>
#include<fstream>
#include<conio.h>
#include<ctime>
#include<string.h>
using namespace std;

//Struct
/*-----------------------------------------------------------------------------------------------------------------*/
struct schedule{
	string matkul,hari,ruang;
	int Y,M,T,D,h[2],m[2],s[2];
	
};
struct assigment{
	string matkul,tugas;
	int deadline,Y,M,T,D,h,m,s;
};
/*-----------------------------------------------------------------------------------------------------------------*/

int deadline(int x,int N,int Now){
	int A[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int sum=0;
	for(int i=0;i<N-1;i++){
		sum=sum+A[i];
	}
	sum=sum+x-Now-1;
	return sum;
	
}

int bulan(string x){
	int N;
	for(int i=0;x[i];i++){
		N=N+1;
		x[i]=toupper(x[i]);
	}
	if(x=="JANUARI"){
		return 1;
	}else if(x=="FEBRUARI"){
		return 2;
	}else if(x=="MARET"){
		return 3;
	}else if(x=="APRIL"){
		return 4;
	}else if(x=="MEI"){
		return 5;
	}else if(x=="JUNI"){
		return 6;
	}else if(x=="JULI"){
		return 7;
	}else if(x=="AGUSTUS"){
		return 8;
	}else if(x=="SEPTEMBER"){
		return 9;
	}else if(x=="OKTOBER"){
		return 10;
	}else if(x=="NOVEMBER"){
		return 11;
	}else if(x=="DESEMBER"){
		return 12;
	}else{
		return 0;
	}
}

int hari2(string x){
	int N;
	for(int i=0;x[i];i++){
		N=N+1;
		x[i]=toupper(x[i]);
	}
	if(x=="SENIN"){
		return 1;
	}else if(x=="SELASA"){
		return 2;
	}else if(x=="RABU"){
		return 3;
	}else if(x=="KAMIS"){
		return 4;
	}else if(x=="JUMAT"){
		return 5;
	}else if(x=="SABTU"){
		return 6;
	}else{
		return 7;
	}
}


string hari(int x){
	if(x==1){
		return "SENIN";
	}else if(x==2){
		return "SELASA";
	}else if(x==3){
		return "RABU";
	}else if(x==4){
		return "KAMIS";
	}else if(x==5){
		return "JUMAT";
	}else if(x==6){
		return "SABTU";
	}else{
		return "MINGGU";
	}
}

void mainmenu(){
	cout<<"\n\t |-----------------=[ Main Menu ]=--------------------|";
	cout<<"\n\t |                  (S)chedule                        |";
	cout<<"\n\t |                  (A)ssigment                       |";
	cout<<"\n\t |                  (O)pen File                       |";
	cout<<"\n\t |                  (Q)uit                            |";
	cout<<"\n\t |----------------------------------------------------|\n";
	
	cout<<"Your Choice : ";
}
void schedulemenu(){
		cout<<"\n\t |------------------[ Schedule Menu ]-----------------|";
		cout<<"\n\t |                  (I)nput Jadwal                    |";
		cout<<"\n\t |                  (C)heck Jadwal                    |";
		cout<<"\n\t |                  (G)anti Jadwal                    |";
		cout<<"\n\t |                  (S)impan Jadwal                   |";
		cout<<"\n\t |                  (B)ack to Main Menu               |";
		cout<<"\n\t |----------------------------------------------------|\n";
		cout<<"Your Choice : ";
}
void assigmentmenu(){
		cout<<"\n\t |----------------[ Assigment Menu ]----------------|";
		cout<<"\n\t |                  (I)nput Tugas                   |";
		cout<<"\n\t |                  (C)heck Tugas                   |";
		cout<<"\n\t |                  (G)anti Tugas                   |";
		cout<<"\n\t |                  (S)impan Task                   |";
		cout<<"\n\t |                  (B)ack to Main Menu             |";
		cout<<"\n\t |--------------------------------------------------|\n";
		cout<<"Your Choice : ";
}
void inputschedule(string *a,string *hari,int *c, int *d,string *ruang){		
		cout<<"Mata kuliah : ";
		cin>>*a;
		cout<<"Hari : ";
		cin>>*hari;
		cout<<"Mulai Pukul(24) : ";
		cin>>*c;
		cout<<"Sampai Pukul(24) : ";
		cin>>*d;
		cout<<"Ruang : ";
		cin>>*ruang;
}
void inputassigment(string *a,string *b,int *c,int *d){
		string tmps;
		inputA:
		cout<<"Mata kuliah : ";
		cin>>*a;
		cout<<"Tugas : ";
		cin>>*b;
		cout<<"Bulan pengumpulan : ";
		cin>>tmps;
		*c=bulan(tmps);
		if(*c==0){
			cout<<"Anda salah memasukkan bulan. yang benar(januari,februari,maret, april,mei, juni, juli, agustus, september, oktober, november, desember)";
			getch();
			system("cls");
			goto inputA;
		}
		cout<<"Tanggal pengumpulan : ";
		cin>>*d;
}
		
int main(){
	//Kamus & Inisialisasi
	ifstream openFile;
	ofstream saveFile;
	schedule scd[100];
	assigment asg[100];
	schedule tmp;
	assigment tmpa;
	int i=0,N=0;
	int k=0,M=0;
	int j=0;
	char choice;
	string tmps;
	int tmpi;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int YearN=1900+ltm->tm_year;
	int MonN=1+ltm->tm_mon;
	int DateN=ltm->tm_mday;
	int yDateN=ltm->tm_yday;
	int DayN=ltm->tm_wday;
	int hourN=ltm->tm_hour;
	int minN=ltm->tm_min;
	int secN=ltm->tm_sec;
	
	goto open;
	awal:
	system("cls");
	cout<<"Apakah anda ingin melihat jadwal hari ini?(Y/N) : ";
	cin>>choice;
	if(choice=='Y'||choice=='y'){
		goto checkNS;
	}else if(choice=='N'||choice=='n'){
		cout<<"Menuju menu utama...(Press key)";
		getch();
		goto menuutama;
	}else{
		cout<<"Keypoint is wrong...";
		getch();
		goto awal;
	}
		
	//Menu Utama
/*-----------------------------------------------------------------------------------------------------------------*/
	menuutama:
	system("CLS");
	mainmenu();
	cin>>choice;
	if(choice=='S' || choice=='s'){
		goto schedule;
	}else if(choice=='A' || choice=='a'){
		goto assigment;
	}else if(choice=='Q' || choice=='q'){
		cout<<"Exiting the Program...";
		goto exit;
	}else if(choice=='O' || choice=='o'){
		goto open;
	}else{
		cout<<"Keypoint yang anda masukkan salah...(press enter)";
		getch();
		goto menuutama;
	}
/*-----------------------------------------------------------------------------------------------------------------*/

//Sub Menu
/*-----------------------------------------------------------------------------------------------------------------*/
	schedule:
		system("CLS"); 
		schedulemenu();
		cin>>choice;
		if(choice=='I' || choice=='i'){
			goto inputS;
		}else if(choice=='C' || choice=='c'){
			goto checkS;
		}else if(choice=='G' || choice=='g'){
			goto gantiS;
		}else if(choice=='S' || choice=='s'){
			goto simpan;
		}else if(choice=='B' || choice=='b'){
			goto menuutama;
		}else{
			cout<<"Keypoint yang anda masukkan salah...(press enter)";
			getch();
			goto schedule;
		}
	assigment:
		system("CLS"); 	
		assigmentmenu();
		cin>>choice;
		if(choice=='I' || choice=='i'){
			goto inputA;
		}else if(choice=='C' || choice=='c'){
			goto checkA;
		}else if(choice=='G' || choice=='g'){
			goto gantiA;
		}else if(choice=='S' || choice=='s'){
			goto simpan;
		}else if(choice=='B' || choice=='b'){
			goto menuutama;
		}else{
			cout<<"Keypoint yang anda masukkan salah...(press enter)";
			getch();
			goto assigment;
		}
	open:
		i=0,k=0;
		openFile.open ("example.txt");
  		while(!openFile.eof()){
  		openFile >> scd[i].matkul;
  		openFile >> scd[i].hari;
		openFile >> scd[i].h[0];
		openFile >> scd[i].h[1];
		openFile >> scd[i].ruang;
		i++;
		}
		openFile.close();
		N=i;
		
		openFile.open ("example2.txt");
		while(!openFile.eof()){
		openFile >> asg[k].matkul;
		openFile >> asg[k].tugas;
		openFile >> asg[k].M;
		openFile >> asg[k].T;
		openFile >> asg[k].deadline;
		k++;
		}
  		openFile.close();
		M=k;
		
		goto awal;
/*-----------------------------------------------------------------------------------------------------------------*/

	inputS:
		i=N;
		inputschedule(&scd[i].matkul,&scd[i].hari,&scd[i].h[0],&scd[i].h[1],&scd[i].ruang);
		i++;
		N=i;
		cout<<endl;
		salah1:
		cout<<"Input lagi?(Y/N) : ";
		cin>>choice;
		if(choice=='Y' || choice=='y'){
			goto inputS;
		}else if(choice=='N' || choice=='n'){
			cout<<"Menuju schedule menu...(Press key)";
			getch();
			goto schedule;
		}else{
			cout<<"Keypoint is wrong...";
			getch();
			system("CLS");
			goto salah1;
		}		
	checkNS:
		tmps=hari(DayN);
		if(tmps=="SENIN"){
			for(int l=0;l<N;l++){
				for(int j=0;scd[l].hari[j];j++){
					scd[l].hari[j]=toupper(scd[l].hari[j]);
				}
				if(scd[l].hari==tmps){
					cout<<l+1<<". ";
					cout<<scd[l].matkul;
					cout<<" ";
					cout<<scd[l].hari;
					cout<<" ";
					cout<<scd[l].h[0];
					cout<<" ";
					cout<<scd[l].h[1];
					cout<<" ";
					cout<<scd[l].ruang;
					cout<<endl;
				}
			}
		}else if(tmps=="SELASA"){
			for(int l=0;l<N;l++){
				for(int j=0;scd[l].hari[j];j++){
					scd[l].hari[j]=toupper(scd[l].hari[j]);
				}
				if(scd[l].hari==tmps){
					cout<<l+1<<". ";
					cout<<scd[l].matkul;
					cout<<" ";
					cout<<scd[l].hari;
					cout<<" ";
					cout<<scd[l].h[0];
					cout<<" ";
					cout<<scd[l].h[1];
					cout<<" ";
					cout<<scd[l].ruang;
					cout<<endl;
				}
			}
		}else if(tmps=="RABU"){
			for(int l=0;l<N;l++){
				for(int j=0;scd[l].hari[j];j++){
					scd[l].hari[j]=toupper(scd[l].hari[j]);
				}
				if(scd[l].hari==tmps){
					cout<<l+1<<". ";
					cout<<scd[l].matkul;
					cout<<" ";
					cout<<scd[l].hari;
					cout<<" ";
					cout<<scd[l].h[0];
					cout<<" ";
					cout<<scd[l].h[1];
					cout<<" ";
					cout<<scd[l].ruang;
					cout<<endl;
				}
			}
		}else if(tmps=="KAMIS"){
			for(int l=0;l<N;l++){
				for(int j=0;scd[l].hari[j];j++){
					scd[l].hari[j]=toupper(scd[l].hari[j]);
				}
				if(scd[l].hari==tmps){
					cout<<l+1<<". ";
					cout<<scd[l].matkul;
					cout<<" ";
					cout<<scd[l].hari;
					cout<<" ";
					cout<<scd[l].h[0];
					cout<<" ";
					cout<<scd[l].h[1];
					cout<<" ";
					cout<<scd[l].ruang;
					cout<<endl;
				}
			}
		}else if(tmps=="JUMAT"){
			for(int l=0;l<N;l++){
				for(int j=0;scd[l].hari[j];j++){
					scd[l].hari[j]=toupper(scd[l].hari[j]);
				}
				if(scd[l].hari==tmps){
					cout<<l+1<<". ";
					cout<<scd[l].matkul;
					cout<<" ";
					cout<<scd[l].hari;
					cout<<" ";
					cout<<scd[l].h[0];
					cout<<" ";
					cout<<scd[l].h[1];
					cout<<" ";
					cout<<scd[l].ruang;
					cout<<endl;
				}
			}
		}else if(tmps=="SABTU"){
			for(int l=0;l<N;l++){
				for(int j=0;scd[l].hari[j];j++){
					scd[l].hari[j]=toupper(scd[l].hari[j]);
				}
				if(scd[l].hari==tmps){
					cout<<l+1<<". ";
					cout<<scd[l].matkul;
					cout<<" ";
					cout<<scd[l].hari;
					cout<<" ";
					cout<<scd[l].h[0];
					cout<<" ";
					cout<<scd[l].h[1];
					cout<<" ";
					cout<<scd[l].ruang;
					cout<<endl;
				}
			}
		}else{
			for(int l=0;l<N;l++){
				for(int j=0;scd[l].hari[j];j++){
					scd[l].hari[j]=toupper(scd[l].hari[j]);
				}
				if(scd[l].hari==tmps){
					cout<<l+1<<". ";
					cout<<scd[l].matkul;
					cout<<" ";
					cout<<scd[l].hari;
					cout<<" ";
					cout<<scd[l].h[0];
					cout<<" ";
					cout<<scd[l].h[1];
					cout<<" ";
					cout<<scd[l].ruang;
					cout<<endl;
				}
			}
		}
		cout<<endl<<"press key...";
		getch();
		goto awal;
	checkS:
		if(N==0){
			cout<<"Data belum terinput"<<endl;
			cout<<"Menuju schedule menu...(Press key)";
			getch();
			goto schedule;
		}else{
			for(int a=0;a<N;a++){
				scd[a].D=hari2(scd[a].hari);
			}
			for(int a=N-1;a>=0;a--){
				for(int b=0;b<a;b++){
					if(scd[b].D>scd[b+1].D){
						tmp=scd[b];
						scd[b]=scd[b+1];
						scd[b+1]=tmp;
					}
				}
			}
			for(i=0;i<N;i++){
				j=0;
			cout<<i+1<<". ";
			cout<<scd[i].matkul;
			cout<<" ";
			cout<<scd[i].hari;
			cout<<" ";
			cout<<scd[i].h[j];
			cout<<" ";
			j++;
			cout<<scd[i].h[j];
			cout<<" ";
			cout<<scd[i].ruang;
			cout<<endl;
			}
			salah2:
		cout<<endl<<"Ganti Jadwal?(Y/N) : ";
		cin>>choice;
		if(choice=='Y' || choice=='y'){
			goto gantiS;
		}else if(choice=='N' || choice=='n'){
			cout<<"Menuju schedule menu...(Press key)";
			getch();
			goto schedule;
		}else{
			cout<<"Keypoint is wrong...";
			getch();
			system("CLS");
			goto salah2;
		}
		}
		
	gantiS:
		cout<<"Baris ke- : ";
		cin>>i;
		i--;
		inputschedule(&scd[i].matkul,&scd[i].hari,&scd[i].h[0],&scd[i].h[1],&scd[i].ruang);
		cout<<endl<<"ganti jadwal berhasil!!! (Press Key)";
		getch();
		goto schedule;
	inputA:
		k=M;		
		inputassigment(&asg[k].matkul,&asg[k].tugas,&asg[k].M,&asg[k].T);
		k++;
		M=k;
		cout<<endl<<"Succes input tugas ke-"<<k;
		salah3:
		cout<<endl<<"Input lagi?(Y/N) : ";
		cin>>choice;
		cout<<endl;
		if(choice=='Y' || choice=='y'){
			goto inputA;
		}else if(choice=='N' || choice=='n'){
			cout<<"Menuju assigment menu...(Press key)";
			getch();
			goto assigment;
		}else{
			cout<<"Keypoint is wrong...";
			getch();
			system("CLS");
			goto salah3;
		}		
		
	checkA:
		if(M==0){
			cout<<"Data belum terinput"<<endl;
			cout<<"Menuju assigment menu...(Press key)";
			getch();
			goto assigment;
		}else{
//			for(int a=0;a<N;a++){
//				scd[a].D=hari2(scd[a].hari);
//			}
			for(int a=M-1;a>=0;a--){
				for(int b=0;b<a;b++){
					if(asg[b].deadline>asg[b+1].deadline){
						tmpa=asg[b];
						asg[b]=asg[b+1];
						asg[b+1]=tmpa;
					}
				}
			}
			for(k=0;k<M;k++){
			cout<<k+1<<". ";
			cout<<asg[k].matkul;
			cout<<" ";
			cout<<asg[k].tugas;
			cout<<" ";
			asg[k].deadline=deadline(asg[k].T,asg[k].M,yDateN);
			if(asg[k].deadline==0){
				cout<<"Hari ini bakalan kadaluarsa";
			}else if(asg[k].deadline>0){
				cout<<asg[k].deadline<<" Hari lagi";
			}else{
				cout<<"Kadaluarsa";
			}
			cout<<endl;
			}
			salah4:
		cout<<endl<<"Ganti Tugas?(Y/N) : ";
		cin>>choice;
		if(choice=='Y' || choice=='y'){
			goto gantiA;
		}else if(choice=='N' || choice=='n'){
			cout<<"Menuju assigment menu...(Press key)";
			getch();
			goto assigment;
		}else{
			cout<<"Keypoint is wrong...";
			getch();
			system("CLS");
			goto salah4;
		}
		}
		
	gantiA:
		cout<<endl<<"Baris ke- : ";
		cin>>k;
		j=0;
		k--;
		cout<<"Ganti menjadi"<<endl<<endl;
		inputassigment(&asg[k].matkul,&asg[k].tugas,&asg[k].M,&asg[k].T);
		cout<<endl<<"ganti tugas berhasil!!! (Press Key)"<<endl;
		getch();
		system("cls");
		goto assigment;
	simpan:
  		saveFile.open ("example.txt");
  		for(i=0;i<N;i++){
  		saveFile << scd[i].matkul<<endl;
  		saveFile << scd[i].hari<<endl;
		saveFile << scd[i].h[0]<<endl;
		saveFile << scd[i].h[1]<<endl;
		saveFile << scd[i].ruang<<endl;
		}
		saveFile.close();
		
		saveFile.open ("example2.txt");
		for(k=0;k<M;k++){
		saveFile << asg[k].matkul<<endl;
		saveFile << asg[k].tugas<<endl;
		saveFile << asg[k].M<<endl;
		saveFile << asg[k].T<<endl;
		saveFile << asg[k].deadline<<endl;
		}
  		saveFile.close();
  		goto menuutama;
	exit:
	cout<<"\n\n\t |-------------=[ Program Created By ]=---------------|";
	cout<<"\n\t | Afdi Fauzul Bahar                 NIM     14117149 |";
	cout<<"\n\t | Arimbi Ayuningtyas                NIM     14117140 |";
	cout<<"\n\t | Pungki Resti Prabandari           NIM     14117154 |";
	cout<<"\n\t |----------------------------------------------------|\n";
	;
}
