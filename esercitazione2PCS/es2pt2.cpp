# include <iostream>
# include <algorithm>
# include <cmath>
using namespace std;
int main()
{
	static const int N = 3;
	double arr[N] = {1.0, 2.0, 3.0};
	double max;
	double min;
	double media;
	double radice;
	double somma_comp;
	double dev_stnd;
	max = arr[0];
	min = arr[0];
	somma_comp = arr[0];
	int i = 1;
	while(i < N){
		somma_comp = somma_comp + arr[i];
		if(arr[i] < min){
			min = arr[i];
		}
		if(arr[i] > max){
			max = arr[i];
		}
		i++;
	}
media = somma_comp/N;
double somma_quadr = 0;
for(int j = 0; j<N; j++){
	somma_quadr = somma_quadr+(arr[j]-media)*(arr[j]-media);
}
dev_stnd = sqrt(somma_quadr/N);
cout<<"minimo: "<<min<<"\n";
cout<<"massimo: "<<max<<"\n";
cout<<"media: "<<media<<"\n";
cout<<"deviazione stnd:"<<dev_stnd<<"\n";
}