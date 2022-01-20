//Comb Search by siraj

// Appx Time Consuming is 7-9 ms

#include <stdio.h>
#include <time.h>

#define shrink 1.3

int update_gap(int gap){
    
    gap=gap/shrink;                            //shrink factor --> 1.3
    if(gap<1){  return 1;   }
    return gap;
}

void comb_sort(int *a,int n){
    
    int swap=1,gap=n,temp;
    
    while(gap!=1 || swap==1){
        
        gap=update_gap(gap);
        swap=0;
        
        for(int i=0;i<(n-gap);i++){
            if(a[i]>a[i+gap]){
                temp=a[i];
                a[i]=a[i+gap];
                a[i+gap]=temp;
				swap=1;
            }
        }
    }
}


void main(){
    
    int a[]={10,8,6,2,656,1,65,36,43,646461,16,41,6,4,13,3,54,61,543,16464,646,46,12,1,11,65,16,3,16,6323,3131,165,36143,164131,16232,156413,31641,19466,
     13,531515,64654,1656154,65465165,615654,654654,656164,6465464,1654564,64651654,651561654,16549846,564646,64651646,16164616,61655465,615616,6165946,645646,
     4651,6161,16451,6164,65461215,1216145,615461,616132,161515,-164,-48,-1,-1,1564};
	 
    int n=sizeof(a)/sizeof(int);
    
    clock_t begin=clock();
    
   comb_sort(a,n);
    
    clock_t end=clock();
    
    printf("\n\nAfter sort the element\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    
    printf("\nTime Consuming is %f ms",(((double)(end-begin)*1000000)/CLOCKS_PER_SEC));

}