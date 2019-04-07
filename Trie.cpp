#include<bits/stdc++.h>
using namespace std;
struct trienode
{
    bool isleaf;
    trienode* children[26];
};
trienode* root=NULL;
int chartoint(char ch)
{
    int x=ch-'0'-49;
}
trienode* getNode(void)
{
 trienode *temp=NULL;
 temp=(trienode*)malloc(sizeof(struct trienode));
 (*temp).isleaf=false;
 for(int i=0;i<26;i++)
 {
     temp->children[i]=NULL;
 }
 return temp;
}
void insert1(string word,trienode* root)
{
    trienode* current=root;
    for(int i=0;i<word.length();i++)
    {
     int index=chartoint(word[i]);
     if(current->children[index]==NULL)
     {
      trienode* newNode=getNode();
      current->children[index]=newNode;
     }
     current=current->children[index];
    }
    current->isleaf=true;
}
void InsertRecursive(trienode* current,string word ,int index)
{
    if(index==word.length())
    {
        current->isleaf=true;
        return;
    }
    //if its not the last char then check whether it is present in the current's children or not
    int i=chartoint(word[index]);
    if(current->children[i]==NULL){
      trienode* temp=getNode();
      current->children[i]=temp;
    }
    InsertRecursive(current->children[i],word,index+1);
}
bool searchWord(string word,trienode* root)
{
    trienode* current=root;
    for(int i=0;i<word.length();i++)
    {
        int index=chartoint(word[i]);
        if(current->children[index]==NULL)
          return false;
        current=current->children[index];
    }
    return current->isleaf;
}
bool searchRecursive(trienode* current,string word,int index)
{
 if(index==word.length())
 {
     return current->isleaf;
 }
 int i=chartoint(word[index]);
 if(current->children[i]==NULL)
    return false;
 searchRecursive(current->children[i],word,index++);
}
bool DeleteNode(trienode* current,string word,int index)
{
    //we search for the node and change the isleaf to false
    //if the size becomes zero the delete recursively
    if(index==word.length())
    {

        if(current->isleaf==false)
            return false;
        current->isleaf=false;
        int size1=0;
        for(int i=0;i<26;i++)
        {
            if(current->children[i]!=NULL)
                size1++;
        }
        return size1==0;
     }
     int i=chartoint(word[index]);
     if(current->children[i]==NULL)
        return false;
     bool shouldDeleteCurrentNode=DeleteNode(current->children[i],word,index+1);
     if(shouldDeleteCurrentNode)
     {
         current->children[i]=NULL;
         //after we delete the current node we check if the node has any children
         //If not then we return true so that this node can also be deleted
         int s=0;
         for(int i=0;i<26;i++)
         {
             if(current->children[i]!=NULL)
                s++;
         }
         if(s==0)
            return true;
     }
     return false;
}
int main()
{
    root=getNode();
    string st;
    for(int i=0;i<=5;i++)
    {
        printf("Enter a string:");
        getline(cin,st);
        if(i%2==0)
          insert1(st,root);
        else
          InsertRecursive(root,st,0);
    }
    int t=3;
    while(t--){
    printf("Enter a string to be searched:");
    cin>>st;
    bool answer=searchWord(st,root);
    if(answer)
        cout<<"ELEMENT FOUND"<<endl;
    else
        cout<<"NOT FOUND!!"<<endl;
    printf("Enter element to be deleted:");
    cin>>st;
    DeleteNode(root,st,0);
    }
    return 0;
}
