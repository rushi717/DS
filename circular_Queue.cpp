#include<iostream>
using namespace std;
int rear=-1,front=-1;
class circular_Q{
	public:
		//int rear=-1,front=-1;
		void enqu(int size,int *ptr,int ele)
		{
			if((rear+1)%size==front)
			{
				cout<<"Overflow"<<endl;
				}	
			else if(front==-1 && rear==-1){
				rear=0;
				front=0;
				ptr[rear]=ele;
				cout<<ele<<" Inserted successfully "<<endl;
			}
			else{
				rear=(rear+1)%size;
				ptr[rear]=ele;
					cout<<ele<<" Inserted successfully "<<endl;
			}
		}
		void deq(int * ptr,int ele,int size)
		{
				if(front==-1 && rear==-1){
					cout<<"Underflow "<<endl;
				}
				else if(rear==front)
				{
					rear=-1;
					front=-1;
				}
				else{
					//	cout<<ele<<" deleted successfully "<<endl;
					ptr[front]=0;
					front=(front+1)%size;
				}
		}
		void display(int size,int *ptr)
		{
		for(int i=front;i<=rear;i++)
		{
			cout<<"\t"<<ptr[i]<<"\t";
			}	
		}
};


int main()
{
	circular_Q q;
		int size,*ptr,choice,ele;
		string s;
		cout<<"Enter the size of the Queue ";
		cin>>size;
		ptr=new int[size];
		for(int i=0;i<size;i++)
		{
			ptr[i]=0;
		}
	do{
		cout<<endl<<"1.Enqueue"<<"\n"<<"2.Dequeue"<<"\n"<<"3.Display"<<"\n"<<"4.Exit"<<endl<<endl;
		cout<<"Enter your choice ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the element you want to Enqueue ";
				cin>>ele;
				q.enqu(size,ptr,ele);
				break;
			case 2:
				cout<<"Are you sure you want to Dequeue ";
				cin>>s;
				if(s[0]=='y'|| s[0]=='Y')
				{
					q.deq(ptr,ele,size);
				}
				else{
					cout<<"OK"<<endl;
				}
				break;
			case 3:
				q.display(size,ptr);
				break;
			case 4:
				break;
		}
		
	}while(choice!=4);
}
