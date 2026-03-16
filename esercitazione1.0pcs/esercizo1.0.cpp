#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, const char *argv[]){
    if (argc < 1){
        cout<<"errore nell'apertura del file\n";
    	cout<<"sono nel vero\n";
    }
    else{
        cout<<"inserire nome del file di testo\n";
        string nomefile;
        cin>>nomefile;
        ifstream ifs(nomefile);
        if (ifs.is_open()){
            for(int i = 1; i<4; i++){
                double T1;
                double T2;
                double T3;
                double T4;
                string nomecitta;
                ifs>>nomecitta>>T1>>T2>>T3>>T4;
                double Tmedia;
                Tmedia = (T1+T2+T3+T4)/4;
                cout<<"la temperatura media a "<<nomecitta<<" è "<<Tmedia<<"\n";
            }
        }
    }
   return 0;
}