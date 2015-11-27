#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<exception>

int RandomInRange(int start, int end){
    srand(time(NULL));
    return start+rand()%(end-start+1);
}

void Swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int Partition(int data[], int length, int start, int end){
    if(data==NULL||length<=0||start<0||end>=length){
        //throw new std::exception("Invalid Parameters.");
        throw new std::exception();
    }
    int index = RandomInRange(start,end);
    Swap(&data[index],&data[end]);
    int small = start - 1;
    for(index=start;index<end;++index){
        if(data[index]<data[end]){
            ++small;
            if(index!=small){
                Swap(&data[index],&data[small]);
            }
        }
    }
    ++small;
    Swap(&data[small],&data[end]);
    return small;
}

void QuickSort(int data[], int length, int start, int end){
    if(start==end){
        return;
    }
    int index = Partition(data, length, start, end);
    if(index>start){
        QuickSort(data, length, start, index - 1);
    }
    if(index<end){
        QuickSort(data, length, index + 1, end);
    }
}

int main(){
    int array[] = {3,2,6,5,9,1,6,3,0};
    int n = 9;
    QuickSort(array, n, 0, n-1);
    for(int i=0;i<n;++i){
        printf("%d ",array[i]);
    }
    printf("\n");
}
