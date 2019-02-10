#ifndef ALGORITHMS_H_INCLUDED
#define ALGORITHMS_H_INCLUDED
#include "sortArray.h"
#include <stdlib.h>

namespace Algorihms{
    void bubbleSort(sortArray &);
    void insertionSort(sortArray &);
    void selectionSort(sortArray &);
    void mergeSort(sortArray &);
    void mergeSort(sortArray &, int, int);
    void merge(sortArray &, int, int, int);
    void shellSort(sortArray &);
    void cocktailSort(sortArray &);
    void heapify(sortArray &, int, int);
    void heapSort(sortArray &);
    int partition(sortArray &, int, int);
    void quickSort(sortArray &, int, int);
    void quickSort(sortArray &);

}


#endif // ALGORITHMS_H_INCLUDED
