#include<stdio.h>

#define ARRAY_SIZE 1000000
#define SMALL_ARRAY_SIZE 70

void generateRandomArray(int* array,int size) {
	srand(time(0));
	for (int i = 0; i < size; i++)
		array[i] = rand();
}

void swap(int*a,int*b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void quickSort(int* array,int startPos,int endPos) {
	int length = endPos - startPos;
	if (length < 1)
		return;
	//如果陣列大小小於70就做bubble sort
	if (length < SMALL_ARRAY_SIZE) {
		for(int i= 0;i<= endPos - startPos;i++)
			for (int j = startPos; j <= endPos - i; j++) 
				if (array[i] > array[j])
					swap(&array[i],&array[j]);
		return;
	}
	//pivit設定為最後一個
	int pivit = array[endPos];
	int pivitPos = startPos;
	//比pivit小的放左邊 剩下放右邊
	for (int i = startPos; i <= endPos; i++) 
		if (array[i] <= pivit) {
			swap(&array[i], &array[pivitPos]);
			pivitPos++;
		}
	//pivitPos的位置實際上在pivit的右邊一格
	quickSort(array, startPos, pivitPos - 2);
	quickSort(array, pivitPos, endPos);
}

int main() {
	static int array[ARRAY_SIZE];
	generateRandomArray(array,ARRAY_SIZE);
	time_t t1, t2;
	t1 = clock();
	quickSort(array,0, ARRAY_SIZE - 1);
	t2 = clock();
	printf("time = %d us",t2-t1);
}