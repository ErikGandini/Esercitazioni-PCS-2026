#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int main(int argc, const char *argv[]){
    
    string namefile=argv[1];
    ifstream ifs(namefile);
    
    if(argc != 2){
	 	cout <<"Non è stato passato correttamente il parametro!\n";   
	 }
    else{
	    
	    if ( ifs.is_open() ){
		    
        	for (int i = 1; i<4 ;i++){
            	string citta;
            	double temp1;
            	double temp2;
            	double temp3;
            	double temp4;
            	ifs>>citta>>temp1>>temp2>>temp3>>temp4;
            	double media_temp;
            	media_temp = (temp1+temp2+temp3+temp4)/4;
            	cout<<citta<<" "<<media_temp<<"\n";
            
        	}
	    }
	    else{
			cout <<"Il file non è stato aperto correttamente!\n";
		}
    
   }     
}
