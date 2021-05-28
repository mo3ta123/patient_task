#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
struct patient {
	int ID;
	char name[20];
	float W;
};
typedef signed int sint;
typedef unsigned int uint;
sint Get_Patient_Index(struct patient pArr[], uint ArrSize, uint SearchID);
void Print_Patient_Data(struct patient* pArr);
void Get_Patient_Data(struct patient* pArr);

void main(void) {
	int size;
	printf("enter number of patients:");
	scanf("%d", &size);
	struct patient*pArr = (struct patient*)malloc(size*sizeof(struct patient));
	for (int i = 0;i < size;i++) {
		Get_Patient_Data(&pArr[i]);
	}
	printf("enter search id:");
	uint search;
	scanf("%d", &search);
	sint index = Get_Patient_Index(pArr, size, search);
	if (index == -1)printf("didn't find");
	else {
		printf("index:%d\n", index);
		Print_Patient_Data(&pArr[index]);
	}
}

void Get_Patient_Data(struct patient *pArr) {
	int ID;
	float W;
	char name[20];
	printf("enter user ID:");
	scanf("%d", &ID);
	printf("enter name :");
	scanf("%s", name);
	printf("enter weight:");
	scanf("%f", &W);
	pArr->ID = ID;
	pArr->W = W;
	strcpy(pArr->name, name);
}
sint Get_Patient_Index(struct patient pArr[], uint ArrSize,  uint searchID) {
	sint res = -1;
	for (sint i = 0;i < ArrSize;i++) {
		if ((&pArr[i])->ID == searchID) {
			res = i;
			break;
		}
	}
	return res;
}

void Print_Patient_Data(struct patient*pArr) {
	printf("ID:%d\n", pArr->ID);
	printf("name:%s\n", pArr->name);
	printf("weight:%.2f\n", pArr->W);
}