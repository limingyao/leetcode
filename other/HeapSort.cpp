#include<cstdio>
#include<cstdlib>

void Swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 大根堆
void adjust(int data[], int n, int root){
    int i = 2*root;
    while(i<n){
        if(data[i]<data[i+1]){
            ++i;
        }
        if(data[root]>=data[i]){
            break;
        }
        Swap(&data[i],&data[root]);
        root = i;
        i*=2;
    }
}

void HeapSort(int data[], int n){
    if(data==NULL||n==0){
        return ;
    }
    for(int i=n/2;i>0;--i){
        adjust(data, n, i);
    }
    for(int i=n;i>0;--i){
        Swap(&data[i],&data[1]);
        adjust(data, i-1, 1);
    }
}

int main(){
    // 第一个元素不参加排序
    int array[] = {0,3,2,6,5,9,1,6,3,0};
    int n = 9;
    HeapSort(array, n);
    for(int i=1;i<=n;++i){
        printf("%d ",array[i]);
    }
    printf("\n");
}
