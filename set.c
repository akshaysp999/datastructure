#include<stdio.h>
#include<stdlib.h>

int U[30],nU=0,
A[30],nA=0,
B[30],nB=0,
bitA[30],bitB[30],bitUnion[30],bitIntersection[30],bitDiffer[30];
void ReadSet();
void printSet(int a[],int asize);
void CreatePrintBitString();
void BitStringConversion(int a[],int asize,int bitArr[]);
int search(int a[],int asize,int item);
void setUnion(int a1[],int a2[]);
void setIntersection(int a1[],int a2[]);
void setDifference(int a1[],int a2[]);
void printBitAsSet(int a[]);
int main()
{    
    int ch=0;
printf("\n============================\n");
    printf("1.Read all sets(universal,set A,set B)\n");
   printf("2.Creation and Printing of Bitstrings\n");
   printf("3.Performing Union\n");
   printf("4.Performing Intersection\n");
   printf("5.Performing Difference\n");
   printf("6.Exit\n");
        printf("============================\n");
        while(ch!=6)
        {
   printf("Enter Choice:");
   scanf("%d",&ch);
   switch(ch)
    {
        case 1:
            ReadSet();
            break;
        case 2:
          printf("Generating bit strings\n");
          CreatePrintBitString();
          break;
        case 3:
            printf("Set union\n");
            setUnion(bitA,bitB);
            printBitAsSet(bitUnion);
             break;
        case 4:
            printf("Set Intersection\n");
            setIntersection(bitA,bitB);
            printBitAsSet(bitIntersection);
             break;
        case 5:
            printf("Set Difference\n");
            setDifference(bitA,bitB);
             printBitAsSet(bitDiffer);
             break;
        case 6:
           exit(0);
             break;
             default:
         printf("Please enter valid option");
    }
}
}
void ReadSet()
{
	int i;
	printf("Enter the size of universal set:");
	scanf("%d",&nU);
	printf("Enter the set elements:\n");
	for(i=0;i<nU;i++)
	    {
		scanf("%d",&U[i]);
		}
		printf("Enter the size of Set A:");
	scanf("%d",&nA);
	printf("Enter the set elements:\n");
	for(i=0;i<nA;i++)
	    {
		scanf("%d",&A[i]);
		}
		printf("Enter the size Set B:");
	scanf("%d",&nB);
	printf("Enter the set elements:\n");
	for(i=0;i<nB;i++)
	    {
		scanf("%d",&B[i]);
		}
	}


void printBitAsSet(int a[])
{
    int i,Flag=0;
    printf("{");
    for(i=0;i<nU;i++){
        if(a[i]==1){
            if(i!=0 && Flag==1){
                printf(",");
            }
            printf("%d",U[i]);
            Flag=1;
        }       
    }
    printf("}");
}
void setUnion(int a1[],int a2[])
{
    int i=0;
    printf("Set A\n");
    printSet(A,nA);
    printf("Set B\n");
    printSet(B,nB);
    for( i=0;i<nU;i++){        
        bitUnion[i]=a1[i]|a2[i];
    }
    printSet(bitUnion,nU);
}
void setIntersection(int a1[],int a2[])
{
    int i=0;
    printf("Set A\n");
    printSet(A,nA);
    printf("Set B\n");
    printSet(B,nB);
    for( i=0;i<nU;i++){        
        bitIntersection[i]=a1[i]&a2[i];
    }
    printSet(bitIntersection,nU);
}
void setDifference(int a1[],int a2[])
{
    int i=0;
    printf("Set A\n");
    printSet(A,nA);
    printf("Set B\n");
    printSet(B,nB);
    for( i=0;i<nU;i++)
    {   
         printf("%d\n",!a2[i]);
        bitDiffer[i]=a1[i]&(!a2[i]);
    }
    printSet(bitDiffer,nU);
}
void printSet(int a[],int asize)
{
    int i=0;
    printf("{");
    for( i=0;i<asize;i++){
        printf("%d",a[i]);
        if(i!=asize-1){
            printf(",");
        }
    }
    printf("}\n");
}

void CreatePrintBitString()
{
int i=0;
    for(i=0;i<nU;i++)
    {
        bitA[i]=0;
        bitB[i]=0;
        bitUnion[i]=0;
        bitIntersection[i]=0;
        bitDiffer[i]=0;
    }
     BitStringConversion(A,nA,bitA);
   printf("\nSet A representation in Bit String\n");
    printSet(bitA,nU);
    BitStringConversion(B,nB,bitB);
    printf("\nSet B representation in Bit String\n");
    printSet(bitB,nU);
    }

void BitStringConversion(int a[],int asize,int bitArr[]){
int i=0,pos;
    for( i=0;i<asize;i++)
    {
        pos=search(U,nU,a[i]);
        if(pos>=0){
            bitArr[pos]=1;
        }       
    }
}
int search(int a[],int asize,int item){
int i=0;
    for( i=0;i<asize;i++)
    {
        if(a[i]==item)
            return i;
    }
    return -1;
}
