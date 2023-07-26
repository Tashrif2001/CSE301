#include<bits/stdc++.h>
using namespace std;

struct node
{
    char c;
    int freq;
    struct node* left;
    struct node* right;
};

void print(struct node* root) {
    if(!root)
    return;
    cout<<root->c<<" "<<root->freq<<" ";
    print(root->left);
    print(root->right);
}

void b_sort(struct node* *arr)
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(arr[i]->freq<arr[j]->freq)
            {
                struct node* temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

struct node* build(char c, int freq)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->c = c;
    newNode->freq = freq;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

int main()
{
    srand(time(NULL));
    int s=4;
    struct node* arr[s];
    for(int i=0; i<s; i++)
    {
        arr[i] = build(i+'a', i+1);
    }
    int i=0;
    b_sort(arr);
    while(s>1)
    {
        struct node* huff1 = arr[i];
        struct node* huff2 = arr[i+1];
        struct node* newHuff = build(-1, huff1->freq+huff2->freq);
        newHuff->left=huff1;
        newHuff->right=huff2;
        s-=2;
        arr[s]=newHuff;

        for (i = s-1; i>0 && arr[i]->freq<arr[i-1]->freq; i--) {
            struct node* temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
        }
    }
    print(arr[0]);
    return 0;
}
