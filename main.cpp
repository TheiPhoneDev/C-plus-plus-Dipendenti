#include <iostream>
#include <fstream>

using namespace std;

const int dimensioneMax=100;
const int perc=2;

struct dipendente {
    string nome;
    float stipendio;
    int livello;
};

//prototipi
void caricaFile(fstream &file, dipendente v[], int &n);
void stampaDaFile(fstream &file);
void ordinaDipendenti(fstream &file, dipendente v[], int &n);
void aumentaStipendio(fstream &file, dipendente v[], int &n);
int Menu();



int main() {
    
    int scelta;
    int n;
    fstream file;
    dipendente dipendenti[dimensioneMax];
    

    do {
        scelta=Menu();
        switch(scelta) {
            case 1:
                caricaFile(file,dipendenti,n);
            break;
            case 2:
                ordinaDipendenti(file,dipendenti,n);
                stampaDaFile(file);
            break;
            case 3:
                aumentaStipendio(file,dipendenti,n);
                stampaDaFile(file);
            break;
            case 4:
                stampaDaFile(file);
            break;
            case 0:
                cout<<"Esci"<<endl;
            break;
            default:
                cout<<"Attenzione, scelta sbagliata!"<<endl;
            break;
        }
    }while(scelta!=0);

    return 0;
}


int Menu () {
  int scegli;
  cout<<"-------MENU'-------"<<endl;
  cout<<"1-Carica file dipendenti"<<endl;
  cout<<"2-Ordina dipendenti in ordine alfabetico"<<endl;
  cout<<"3-Aumenta lo stipendio per i dipendenti di livello 4"<<endl;
  cout<<"4-Visualizza i dati"<<endl;

  cout<<"0-Fine"<<endl;

  cout<<"Scegli un operazione: "<<endl;
  cin>>scegli;

  return scegli;
}

void caricaFile(fstream &file, dipendente v[], int &n) {
    
    file.open("dipendenti.txt",ios::out);

    cout<<"Inserisci il numero di dipendenti da registrare: ";
    cin>>n;
    

    for(int i=0; i<n; i++) {
        cout<<endl;
        cout<<"Inserisci il nome del dipendente: ";
        cin>>v[i].nome;
        cout<<"Inserisci lo stipendio del dipendente: ";
        cin>>v[i].stipendio;
        cout<<"Inserisci il livello del dipendente: ";
        cin>>v[i].livello;
        file<<v[i].nome<<" "<<v[i].stipendio<<" "<<v[i].livello;
        if(i<n-1) {
            file<<endl;
        }
        cout<<endl;
    }
    
    
    file.close();
    
    file.open("variabile.txt",ios::out);
    file<<n;
    file.close();

}

void stampaDaFile(fstream &file) {
    
    string nome;
    float stipendio;
    int livello;
    
    file.open("dipendenti.txt",ios::in);
    
    while(!file.eof()) {
        file>>nome>>stipendio>>livello;
        cout<<"Nome: "<<nome<<" "<<"Stipendio: "<<stipendio<<" "<<"Livello: "<<livello<<endl;
    }
    
    file.close();

    
}

void ordinaDipendenti(fstream &file, dipendente v[], int &n) {
    
    dipendente temp;
    string nome;
    float stipendio;
    int livello;
    

    file.open("variabile.txt",ios::in);
    file>>n;
    file.close();

    file.open("dipendenti.txt",ios::in);

    for(int i=0; i<n; i++) {
        file>>nome>>stipendio>>livello;
        v[i].nome=nome;
        v[i].stipendio=stipendio;
        v[i].livello=livello;

    }
    file.close();


    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(v[i].nome>v[j].nome) {
                temp=v[i];
                v[i]=v[j];
                v[j]=temp;
            }
        }
    }
    
    file.open("dipendenti.txt",ios::out);
    
    for(int i=0; i<n; i++) {
        file<<v[i].nome<<" "<<v[i].stipendio<<" "<<v[i].livello;
        if(i<n-1) {
            file<<endl;
        }
    }
    
    file.close();



}

void aumentaStipendio(fstream &file, dipendente v[], int n) {
   
    string nome;
    float stipendio, perc=0.00;
    int livello;

    file.open("variabile.txt",ios::in);
    file>>n;
    file.close();

    file.open("dipendenti.txt",ios::in);

    for(int i=0; i<n; i++) {
        file>>nome>>stipendio>>livello;
        v[i].nome=nome;
        v[i].stipendio=stipendio;
        v[i].livello=livello;

    }
    file.close();
   
    
    file.open("dipendenti2.txt",ios::out);
    
    for(int i=0; i<n; i++) {
        if(v[i].livello==4) {
            perc=v[i].stipendio*2/100;
            v[i].stipendio=v[i].stipendio+perc;
            file<<v[i].nome<<" "<<v[i].stipendio<<" "<<v[i].livello;
            if(i<n-1) {
                file<<endl;
            }
        }
    }
    
    file.close();
   
    
}
