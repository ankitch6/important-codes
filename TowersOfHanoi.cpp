//towers of hanoi recursive solution
#include<iostream>
using namespace std;

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod)
{
   if(n==1)
   {
       cout<< "Move Disk 1 from "<<from_rod<<" to "<<to_rod<<endl;
       return;
   }
   tower_of_hanoi(n-1, from_rod, aux_rod, to_rod);
   cout<<"Move Disk "<<n<<" from "<<from_rod<<" to "<<to_rod<<endl;
   tower_of_hanoi(n-1, aux_rod, to_rod, from_rod);
}

int main(void)
{
    int n;
    cout<<"Enter the number of disks: ";
    cin>>n;
    tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}
