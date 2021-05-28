#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
struct patient {
	int ID;
	char name[20];
	float W;
	struct patient*next;
	int index;
};
typedef signed int sint;
typedef unsigned int uint;
sint Get_Patient_Index(struct patient pArr[], uint Size, uint SearchID);
void Print_Patient_Data(struct patient* pArr);
void Get_Patient_Data(struct patient* pArr);

void main() {
	int size;
	printf("enter number of patients:");
	scanf("%d", &size);
	struct patient*Base=NULL;
	struct patient*ptr=NULL;
	struct patient*ptr_new;
	for (int i = 0;i < size;i++) {
		if (i == 0) {
			ptr = (struct patient*)malloc(sizeof(struct patient));
			Base = ptr;
		}
		else {
			ptr_new=(struct patient*)malloc(sizeof(struct patient));	//creates new space for struct
			ptr->next = ptr_new;										//storing the addresse of struct into previes one
			ptr = ptr_new;
		}
		Get_Patient_Data(ptr);
		ptr_new->next=NULL;
		ptr->index = i;
		printf("\n");
	}
	printf("enter id for search:");
	int searchID;
	scanf("%d", &searchID);
	int index=Get_Patient_Index(Base,size,searchID);
	printf("index is %d\n", index);
	
	struct patient*ptr_search = Base;
	for (int i = 0;i < index;i++)
		ptr_search = ptr_search->next;

	Print_Patient_Data(ptr_search);
}


void Get_Patient_Data(struct patient* pArr) {
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
void Print_Patient_Data(struct patient* pArr) {
	printf("ID:%d\n", pArr->ID);
	printf("name:%s\n", pArr->name);
	printf("weight:%.2f\n", pArr->W);
}

sint Get_Patient_Index(struct patient Base[], uint Size, uint SearchID) {
	sint res = -1;
	struct patient*ptr=Base;
	for (sint i = 0;i < Size;i++) {
		if (ptr->ID == SearchID) {
			res = ptr->index;
			break;
		}
		ptr = ptr->next;
	}
	return res;
}