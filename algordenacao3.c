#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define RANGE 10000
#define tamanho_bucket 1000
#define numero_bucket 1000
#define max 1000


void countingSort(int arr[])
{
	
	int output[sizeof(arr)/sizeof(arr[0])];
	
	int count[RANGE + 1], i;
	memset(count, 0, sizeof(count));

	for(i = 0; arr[i]; ++i)
		++count[arr[i]];

	for (i = 1; i <= RANGE; ++i)
		count[i] += count[i-1];

	for (i = 0; arr[i]; ++i)
	{
		output[count[arr[i]]-1] = arr[i];
		--count[arr[i]];
	}

	for (i = 0; arr[i]; ++i)
		arr[i] = output[i];
}

void radixSort(int vector[], int size) {
    int i;
    int *b;
    int maior = vector[0];
    int exp = 1;

    b = (int *)calloc(size, sizeof(int));

    for (i = 0; i < size; i++) {
        if (vector[i] > maior)
    	    maior = vector[i];
    }
 
    while (maior/exp > 0) {
        int bucket[RANGE] = { 0 };
    	for (i = 0; i < size; i++)
    	    bucket[(vector[i] / exp) % 10]++; 
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = size - 1; i >= 0; i--)
    	    b[--bucket[(vector[i] / exp) % 10]] = vector[i];
    	for (i = 0; i < size; i++)
    	    vector[i] = b[i];
    	exp *= 10;
    }

    free(b);
}

 typedef struct {
         int topo;
         int balde[tamanho_bucket];
 }bucket;
 
 void bucketSort(int v[],int tamanho);                   
 void bubble(int v[],int tamanho);                                                 
                                                                  
 void bucketSort(int v[],int tamanho){                                     
         bucket b[numero_bucket];                                      
         int i,j,k;                                                 
 /* 1 */ for(i=0;i<numero_bucket;i++)                    
                 b[i].topo=0;
         
 /* 2 */ for(i=0;i<tamanho;i++){                          
                 j=(numero_bucket)-1;
                 while(1){
                         if(j<0)
                                 break;
                         if(v[i]>=j*10){
                                 b[j].balde[b[j].topo]=v[i];
                                 (b[j].topo)++;
                                 break;
                         }
                         j--;
                 }
         }
         
 /* 3 */ for(i=0;i<numero_bucket;i++)                     
                 if(b[i].topo)
                         bubble(b[i].balde,b[i].topo);
         
         i=0;
 /* 4 */ for(j=0;j<numero_bucket;j++){                   
                 for(k=0;k<b[j].topo;k++){
                         v[i]=b[j].balde[k];
                         i++;
                 }
         }
 }
 
 void bubble(int v[],int tamanho){
         int i,j,temp,flag;
         if(tamanho)
                 for(j=0;j<tamanho-1;j++){
                         flag=0;
                         for(i=0;i<tamanho-1;i++){
                                 if(v[i+1]<v[i]){
                                         temp=v[i];
                                         v[i]=v[i+1];
                                         v[i+1]=temp;
                                         flag=1;
                                 }
                         }
                         if(!flag)
                                 break;
                 }
 }

int main(int argc, char** argv){
	int size, i;
	scanf("%d", &size);
	int * num = (int*) malloc(sizeof(int)*size);
	for(i = 0; i < size; i++)
		scanf("%d", (num + i));

        switch(*argv[1])
    {
        case '1':
            countingSort(num);
            break;
       case '2':
            radixSort(num, size);
            break;
       case '3':
           bucketSort(num, size);
            break;
       //case '4':
         //  quick_sort(num, 0,size-1);
           // break;
       //case '5':
         //    heapsort(num, size);
           // break;
    }


	//FILE* file = fopen(argv[1], "w");
	for(i = 0; i<size; i++){
		//printf("%d%s", num[i],i != size-1 ? ", ":"\n") ;
		printf( "%d\n", num[i]);
	}

}