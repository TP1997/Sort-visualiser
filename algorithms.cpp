#include "algorithms.h"

void Algorihms::bubbleSort(sortArray &array){
    array.delayTime=0;
    bool switched;
    int m=0;
    do{
        switched=false;
        for(int n=0; n<array.size()-m-1; n++){
            if(array[n]>array[n+1]){
                array.swap(n, n+1);
                switched=true;
            }
            array.draw(2, n, n+1);
        }
        m++;
    }
    while(switched);
}

void Algorihms::insertionSort(sortArray &array){
    array.delayTime=10;
    //std::vector<int> shifts;
    for(int n=1; n<array.size(); n++){
        int temp=array[n];
        int newpos=n;
        while(newpos>0 && temp<array[newpos-1]){
            array[newpos]=array[newpos-1];
            //shifts.push_back(newpos);
            array.draw(2, newpos, newpos-1);
            newpos--;
        }
        array[newpos]=temp;
        array.draw(1, newpos);
    }
}

void Algorihms::selectionSort(sortArray &array){
    array.delayTime=50;
    for(int n=0; n<array.size()-1; n++){
        int minindex=n;
        for(int m=n+1; m<array.size(); m++){
            if(array[m]<array[minindex])
                minindex=m;
        }
        array.swap(minindex, n);
        array.draw(2, minindex, n);
    }
}

void Algorihms::mergeSort(sortArray &array){
    array.delayTime=10;
    mergeSort(array, 0, array.size()-1);
}
void Algorihms::mergeSort(sortArray &array, int startInd, int endInd){
    if(startInd<endInd){
        int mid=(startInd+endInd)/2;
        mergeSort(array, startInd, mid);
        mergeSort(array, mid+1, endInd);
        merge(array, startInd, mid, endInd);
    }
}
void Algorihms::merge(sortArray &array, int ls, int le, int re){
    std::vector<int> sorted;
    int rs=le+1;
    int start=ls;
    while(ls<=le && rs<=re){
        if(array[ls]<array[rs])
            sorted.push_back(array[ls++]);
        else
            sorted.push_back(array[rs++]);
    }
    while(ls<=le){
        sorted.push_back(array[ls++]);
    }
    while(rs<=re){
        sorted.push_back(array[rs++]);
    }
    for(unsigned int n=0; n<sorted.size(); n++, start++){
        array[start]=sorted[n];
        array.draw(1, start);
    }
}

void Algorihms::shellSort(sortArray &array){
    array.delayTime=20;
    std::vector<int> shifts;
    for(int gap=array.size()/2; gap>0; gap/=2){
        for(int n=gap; n<array.size(); n++){
            int temp=array[n];
            int newpos=n;
            while(newpos>=gap && temp<array[newpos-gap]){
                array[newpos]=array[newpos-gap];
                //shifts.push_back(newpos);
                array.draw(2, newpos, newpos-1);
                newpos-=gap;
            }
            array[newpos]=temp;
            //array.draw(1, newpos);
            //array.draw(shifts);
            //shifts.clear();
        }
    }
}

void Algorihms::cocktailSort(sortArray &array){
    array.delayTime=5;
    int start=0;
    int end=array.size()-1;
    bool swapped=true;

    while(swapped){
        swapped=false;
        for(int n=start; n<end; n++){
            if(array[n]>array[n+1]){
                array.swap(n, n+1);
                swapped=true;
                array.draw(2, n, n+1);
            }
        }
        //array.draw(0);
        if(!swapped)
            break;
        swapped=false;
        end--;
        for(int n=end; n>start; n--){
            if(array[n]<array[n-1]){
                array.swap(n, n-1);
                swapped=true;
                array.draw(2, n, n-1);
            }
        }
        //array.draw(0);
        start++;
    }
}

void Algorihms::heapify(sortArray &array, int i, int last){
    //help indecies
    int largest=i;
    int leftChildIdx=i*2+1;
    int rightChildIdx=i*2+2;
    if(leftChildIdx<=last && array[leftChildIdx]>array[largest])
        largest=leftChildIdx;
    if(rightChildIdx<=last && array[rightChildIdx]>array[largest])
        largest=rightChildIdx;

    if(largest!=i){
        array.swap(largest, i);
        array.draw(2, largest, i);
        heapify(array, largest, last);
    }
}

void Algorihms::heapSort(sortArray &array){
    array.delayTime=20;
    int firstP=(array.size()-1)/2-1;
    for(int n=firstP; n>=0; n--){
        heapify(array, n, array.size()-1);
    }
    for(int n=array.size()-1; n>0; n--){
        array.swap(0, n);
        array.draw(2, 0, n);
        heapify(array, 0, n-1);
    }
}

int Algorihms::partition(sortArray &array, int l, int r){
    int pivot=(rand()%(r-l+1))+l;
    int left=l;
    int right=r;
    int temp=array[pivot];
    array.swap(pivot, right);
    right--;
    do{
        array.swap(left, right);
        array.draw(2, left, right);
        while(temp<array[right])right--;
        while(temp>array[left])left++;
    }
    while(left<right);
    array.swap(left, r);
    array.draw(2, left, r);
    return left;
}

void Algorihms::quickSort(sortArray &array, int l, int r){
    array.draw(0);
    if(l<r){
        int pivot=partition(array, l, r);
        quickSort(array, l, pivot-1);
        //array.draw(0);
        quickSort(array, pivot+1, r);
    }
}

void Algorihms::quickSort(sortArray &array){
    array.delayTime=20;
    quickSort(array, 0, array.size()-1);
}


