#include <iostream>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int* p,int length);
void mergeSort(int* p, int length);
void merges(int* p, int first, int last);
void merge(int* &p,int first, int mid, int last);

int main(int size){
	size = 10;
	int* p = new int[size];
	std::cout << "First List \n";
	for (int i = 0; i<size; i++){
		p[i] = rand() % 100 + 1;
		std::cout << p[i] << '\n';
	}
	std::cout << "\n Running BubbleSort...\n";
	clock_t t = clock();
	bubbleSort(p,size);
	t = clock() - t;
	std::cout << "\n Sorted List: \n";
	for (int i = 0; i<size; i++){
		std::cout << p[i] << '\n';
	}
	std::cout << "BubbleSort took:" << ((double)t)<< "\n";
	std::cout << "\n Second List: \n";
	for (int i = 0; i<size; i++){
		p[i] = rand() % 10000 + 1;
		std::cout << p[i] << '\n';
	}
	std::cout << "\n Running MergeSort... \n";
	t = clock();
	mergeSort(p,size);
	t = clock() - t;
	std::cout << "\n Sorted List: \n";
	for(int i=0;i<size;i++){
		std::cout << p[i] << '\n';
	}
}



void bubbleSort(int* p, int length){
	
	for(int i=0;i<length;i++){
		for(int j=0;j<length-1;j++){
			if (p[j]>p[j+1]){
				int temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
}

void mergeSort(int* p, int length){
	clock_t t = clock();
	merges(p,0,length-1);
	t = clock() - t;
}

void merges(int* p, int first, int last){
    if (first < last){
        int mid = first + (last-first)/2;
        merges(p,first,mid);
        merges(p,mid+1,last);
        merge(p,first,mid+1,last);
    }
    return;
}
void merge(int* &p,int first, int mid, int last){
	int length = last-first+1;
    int *a = new int[length];
    int i = 0;
    int j = 0;
    while(i+j <= length){
        if(i>=mid-first){
            a[i+j]=p[mid+j];
            j++;
        } else if(j>=length-mid+first){
            a[i+j]=p[first+i];
            i++;
        } else if(p[first+i]<p[mid+j]){
            a[i+j]=p[first+i];
            i++;
        } else{
            a[i+j]=p[mid+j];
            j++;
        }
    }
    for(int i = 0;i<length;i++){
        p[first+i]=a[i];
    }

}