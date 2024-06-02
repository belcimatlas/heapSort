#include<stdio.h>
#include<stdlib.h>
void maxHeapOlustur(int *dizi, int N);
void maxHeapify(int *dizi, int parent, int N);
void swap(int *dizi, int parent, int enBuyuk);
void heapSort(int *dizi, int N);
void printDizi(int *dizi,int N);

void maxHeapOlustur(int *dizi, int N){
	int i;
	for(i=N/2-1;i>=0;i--){                     //leaf node'lar haric tum elemanlari gezerek maxHeapify fonksiyonu cagirilir ve satirda bulunan queue max heap haline getirilir.
		maxHeapify(dizi, i, N);
	}
}
void maxHeapify(int *dizi, int parent, int N){
	int sol=2*parent+1;                                        //sol cocugun index'i parent'in indexinin iki katindan bir fazladir.
	int sag=2*parent+2;                                        //sag cocugun index'i parent'in indexinin iki katindan iki fazladir.
	int enBuyuk;                                               //parent ve cocuklar arasindaki en buyuk elemanini indexi enBuyuk degiskeninde tutulur. 
	if(sol<N && dizi[sol]>dizi[parent]){    //sol cocuk varsa parent ile karsilastirilir ve hangisi buyukse enBuyuk degiskeni onun indexine esitlenir.
		enBuyuk=sol;
	}
	else{
		enBuyuk=parent;
	}
	if(sag<N && dizi[sag]>dizi[enBuyuk]){   //sag cocuk varsa enBuyuk ile karsilastirilir ve hangisi buyukse enBuyuk degiskeni onun indexine esitlenir.
		enBuyuk=sag;
	}
	if(enBuyuk!=parent){                                       //eger enBuyuk parent degilse max heap ozelliginin saglanmasi icin en buyuk elemanin parent ile yer degistirmesi gerekir.
		swap(dizi, parent, enBuyuk);                  //parent ve enBuyuk yer degistirir.
		maxHeapify(dizi, enBuyuk, N);                 //yer degisimi yasandigi icin tekrar heapify yapilmasi gerekir.
	}
}
void swap(int *dizi, int parent, int enBuyuk){
	int tmp;
	tmp=dizi[parent];
	dizi[parent]=dizi[enBuyuk];
	dizi[enBuyuk]=tmp;
}
void heapSort(int *dizi, int N){
	int i;
	maxHeapOlustur(dizi, N);
	for(i=N-1; i>0; i--){
		printf("%d\t",dizi[0]);
		swap(dizi, 0, i);
	//	maxHeapOlustur(dizi, i);
		maxHeapify(dizi, 0, i); // Kökü yeniden düzenle
		//Silinecek elemanin bulundugu konumdan (0) heapify yapariz.
	}
	printf("%d\n",dizi[0]);
}
void printDizi(int *dizi,int N){
	int i;
	for(i=0;i<N;i++){
		printf("%d\t",dizi[i]);
	}
}
int main(){
	int *dizi, N=6;
	
	dizi = (int *)malloc(N * sizeof(int));             //kullanilan diziler ve matris icin dinamik yer ayirma
	if(dizi == NULL) {
        printf("Bellek ayrilamadi.");
        exit(1);
    }
    dizi[0] = 9;
    dizi[1] = 6;
    dizi[2] = 2;
    dizi[3] = 8;
    dizi[4] = 7;
    dizi[5] = 5;
    printDizi(dizi,N);
    printf("\nheapsort:\n");
    heapSort(dizi,N);
    
    //printDizi(dizi,N);
    free(dizi);
    return 0;
}

