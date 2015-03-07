#include<cstdio>
#include<cstdlib>

void Merge(int data[], int tmp[], int length, int start, int mid, int end){
    int i = start;
    int j = mid+1;
    int k = start;
    while(i<=mid&&j<=end){
        if(data[i]<data[j]){
            tmp[k++] = data[i++];
        } else {
            tmp[k++] = data[j++]; 
        }
    }
    while(i<=mid){
        tmp[k++] = data[i++];
    }
    while(j<=end){
        tmp[k++] = data[j++];
    }
    for(i=start;i<=end;++i){
        data[i] = tmp[i];
    }
}

void MergePass(int data[], int tmp[], int length, int start, int end){
    if(start<end){
        int mid = (start + end)/2;
        MergePass(data,tmp,length,start,mid);
        MergePass(data,tmp,length,mid+1,end);
        Merge(data,tmp,length,start,mid,end);
    }
}

void MergeSort(int data[], int n){
    if(data==NULL){
        return;
    }
    int *tmp = new int[n];
    MergePass(data,tmp,n,0,n-1);
    delete[] tmp;
}

int main(){
    int array[] = {3,2,6,5,9,1,6,3,0};
    int n = 9;
    MergeSort(array, n);
    for(int i=0;i<n;++i){
        printf("%d ",array[i]);
    }
    printf("\n");
}
