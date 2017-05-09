#include<iostream>
#include<iomanip>
using namespace std;
class Set{
	int a[100];
	int s;
	public:
	void input(int n){
		s=n;
		for(int i=0;i<s;i++)
			cin>>a[i];
	}
	void output(){
		cout<<"{";
		for(int i=0;i<s;i++){
			
			cout<<a[i]<<" ,";
		}
		cout<<"}";
	}
	void unio(Set &b){
		for(int i=0;i<b.s;i++){
			a[s++]=b.a[i];
		}
	}
	void intersection(Set &b){
		for(int i=0;i<s;i++){
			for(int j=b.s;j>0;j--){
				if(a[i]==b.a[j]){
					a[j]=b.a[i];
					s--;
				}
			}
		}
	}
	void uni(int s){
		for(int x=1;x<=s;x++)
			a[x]=x;
	}
			
	void difference(Set &b){
		for(int i=0;i<b.s;i++){
			for(int j=0;j<s;j++){
				if(a[j]==b.a[i]){
					int temp=a[j+1];
					a[j+1]=a[j];
					a[j]=temp;
					
				}
			}
		}
		s=s-b.s;
	}
	void cart(Set &b){
		for(int i=0;i<s;i++)
		{
			cout<<"{";	
			for(int j=0;j<b.s;j++)
			{
				cout<<" ( ";
			cout<<a[i]<<" "<<b.a[j]<<" ), ";
			}
			}
			cout<<"}";

	}
	void universalset(int us){
		s=us;
		for(int i=0;i<us;i++){
			a[i]=i+1;
		}
	}
	
		void comp(Set &b){
		for(int i=0;i<s;i++){
			for(int j=0;j<b.s;j++){
				if(a[i]==b.a[j]){
					int temp=b.a[j];
					b.a[j]=b.a[j+1];
					b.a[j+1]=temp;
					
				}
			}
		}
		b.s=b.s-s;
		b.output();
	}
	int issubset(Set&b){
		for(int i=0;i<s;i++){
			for(int j=0;j<b.s;j++){
				while(a[i]=!b.a[j]){
					return 0;
				}
			}
		}
	}
};
int main(){
	Set a,b;
	int s;
	char ans;
	do{
	
		cout<<setw(50) <<"**********MENU**********\n";
		cout<<setw(34) <<"1) Union\n";
		cout<<setw(41) <<"2) Intersection\n";
		cout<<setw(39) <<"3) Difference\n";
		cout<<setw(39) <<"4) Compliment\n";
		cout<<setw(46) <<"5) Cartesian product\n";
		cout<<setw(41) <<"6) Check Subset\n";
		cout<<setw(34) <<"7) Exit \n";
		cout<<setw(50) <<"************************\n";		
		int o;
		cout<<setw(50) <<"\nEnter your choice : ";
		cin>>o;
		switch(o){
			case 1:	cout<<"\nEnter the size of array : ";
					cin>>s;
					cout<<"\nEnter the Elements of Set A : ";
					a.input(s);
					cout<<"\nEnter the size of array : ";
					cin>>s;
					cout<<"\nEnter the Elements of Set b : ";
					b.input(s);
					cout<<"\nUnion of Set A and Set B is :";
					a.unio(b);
					a.output();
					break;
			case 2:	cout<<"\nEnter the size of array : ";
					cin>>s;
					cout<<"\nEnter the Elements of Set A : ";
					a.input(s);
					cout<<"\nEnter the size of array : ";
					cin>>s;
					cout<<"\nEnter the Elements of Set b : ";
					b.input(s);
					cout<<"\nIntersection of Set A and Set B is :";
					a.intersection(b);
					a.output();
					break;
			case 3:	cout<<"\nEnter the size of array : ";
					cin>>s;
					cout<<"\nEnter the Elements of Set A : ";
					a.input(s);
					cout<<"\nEnter the size of array : ";
					cin>>s;
					cout<<"\nEnter the Elements of Set b : ";
					b.input(s);
					cout<<"\nDifference of Set A and Set B is :";
					a.difference(b);
					a.output();	
					break;
			case 4:	cout<<"\nEnter the size of array : ";
					cin>>s;
					cout<<"\nEnter the Elements of Set A : ";
					a.input(s);
					cout<<"\nEnter the size of universal array : ";
					cin>>s;
					b.universalset(s);
					cout<<"\nCompliment of Set A is :";
					a.comp(b);
					break;
			case 5:	cout<<"\nEnter the size of array : ";
					cin>>s;
					cout<<"\nEnter the Elements of Set A : ";
					a.input(s);
					cout<<"\nEnter the size of array : ";
					cin>>s;
					cout<<"\nEnter the Elements of Set b : ";
					b.input(s);
					cout<<"\nDifference of Set A and Set B is :";
					a.cart(b);
					break;
			case 6:	cout<<"\nEnter the size of array : ";
					cin>>s;
					cout<<"\nEnter the Elements of Set A : ";
					a.input(s);
					cout<<"\nEnter the size of array : ";
					cin>>s;
					cout<<"\nEnter the Elements of Set b : ";
					b.input(s);
					if(a.issubset(b)==1)
						cout<<"\nSet A is Subset Set B ";
					else
						cout<<"\nSet A not is Subset Set B ";
				
					break;
			case 7:
					cout<<"\n***********END**********";
					return 0;
			default :
					cout<<"\nYou entered the wrong choice";
					cout<<"\nPlease enter your choice again\n";
					main();

		}
		cout<<"\nDo you want enter again(y/n): ";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
	cout<<"\n***********END**********";
}
