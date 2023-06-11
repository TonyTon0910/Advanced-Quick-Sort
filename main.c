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
	//�p�G�}�C�j�p�p��70�N��bubble sort
	if (length < SMALL_ARRAY_SIZE) {
		for(int i= 0;i<= endPos - startPos;i++)
			for (int j = startPos; j <= endPos - i; j++) 
				if (array[i] > array[j])
					swap(&array[i],&array[j]);
		return;
	}
	//pivit�]�w���̫�@��
	int pivit = array[endPos];
	int pivitPos = startPos;
	//��pivit�p������ �ѤU��k��
	for (int i = startPos; i <= endPos; i++) 
		if (array[i] <= pivit) {
			swap(&array[i], &array[pivitPos]);
			pivitPos++;
		}
	//pivitPos����m��ڤW�bpivit���k��@��
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