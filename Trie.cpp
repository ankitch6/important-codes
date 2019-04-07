//implementation of TRIE
#include<bits/stdc++.h>

using namespace std;

const int ALPHABET_SIZE=26;

struct trienode{
    struct trienode* children[ALPHABET_SIZE];
    bool endofword;
};

struct trienode* getNode(void)
{
    struct trienode* temp = new trienode;

    temp->endofword=false;

    for(int i=0;i<ALPHABET_SIZE; i++)
    {
        temp->children[i]=NULL;
    }
    return temp;
}


void insert_(struct trienode* root, string word)
{
    struct trienode* current = root;

    for(int i=0;i<word.length();i++)
    {
        int index= (int)word[i]-(int)'a';
        if(current->children[index]==NULL)
            current->children[index]=getNode();
        current=current->children[index];
    }
    current->endofword= true;
}

bool search_(struct trienode* root, string key)
{
    struct trienode *current= root;
    for(int i=0;i<key.length();i++)
    {
        int index=(int)key[i]-(int)'a';
        if(current->children[index]==NULL)
            return false;
        current=current->children[index];
    }
    return current->endofword;
}


bool isNodeEmpty(struct trienode* root)
{
    for(int i=0;i<26;i++)
    {
       if(root->children[i])
            return false;
    }
    return true;
}
trienode* deleteNode(struct trienode* root, string key, int depth)
{
    //if the trie is empty
    if(!root)
        return NULL;
    //if the recursion is at the end of the
    if(depth==key.length())
    {
        if(root->endofword==false)
            return NULL;
        root->endofword=false;

        if(isNodeEmpty(root))
        {
            delete(root);
            root=NULL;
        }
        return root;
    }

    int index= key[depth]-(int)'a';
    if(root->children[index])
    {
        root->children[index]=deleteNode(root->children[index], key, depth+1);
        if(isNodeEmpty(root) && root->endofword == false)
        {
            delete(root);
            root=NULL;
        }
    }
    else
        return NULL;
    return root;
}

int main(void)
{
    int t=10;
    struct trienode *root = getNode();
    while(t--)
    {
        printf("Enter word: ");
        string st;
        cin>>st;
        insert_(root, st);
    }
    printf("Choose Anyone!\n");
    while(true)
    {
        printf("1. Search\n2.Delete\n3.Exit\n");
        int choice;
        scanf("%d", &choice);


    if(choice==1){
        string st;
        printf("Enter key to be searched: ");
        cin>>st;
        bool ans = search_(root, st);
        if(ans)
            cout<<"Element Found!"<<endl;
        else
            cout<<"Element Not Found!"<<endl;
    }
    else if(choice==2){
        string str;
        printf("Enter element to be deleted: ");
        cin>>str;
        root=deleteNode(root, str, 0);
    }
    else if(choice==3)
        exit(0);


    }
    return 0;
}
