#include<iostream>
#include<string>
using namespace std;
class  student;
student* arr;
int size;
class student
{
public:
	int id;
	string name;

	int  Hash(string s)
	{
		int hv=0;
		int c=0;
		int i=0;
		while (s[i]=='\0')
		{
			c++;
			i++;
		}
		hv=c*10;
		hv=hv/size;
		return hv;
	}
	void input()
	{
		cout<<"Enter Id "<<endl;
		cin>>id;
		cout<<"Enter Name "<<endl;
		cin.ignore();
		getline(cin,name);
		int index;
		index=Hash(name);
		int indexdup=index;
		int size1=size;
		int i = index;
		for (; i < size1;)
		{
			if (arr[i].id==-1)
			{
				arr[i].id=id;
				arr[i].name=name;

				break;
			}
			else
			{
				i+=2;
				if (index==size)
				{
					i=0;
					size1=indexdup;
				}
			}
			index=i;
		}
		if (index==size1)
		{
			cout<<"Full"<<endl;
		}
	}
	void search()
	{
		string se;
		cout<<"Enter Name for Search "<<endl;
		cin.ignore();
		getline(cin,se);
		int index;
		index=Hash(se);
		int size1=size;
		int indexdup=index;
		int i = index;
		bool chk=true;
		for (; i < size1;)
		{
			if (arr[i].name==se)
			{
				cout<<"Found "<<endl;
				cout<<"Name is "<<arr[i].name<<endl;
				chk=false;
				break;
			}
			else
			{
				i+=2;
				if (index==size)
				{
					i=0;
					size1=indexdup;
				}
			}
		}
		if (chk)
		{
			cout<<"Not Found "<<endl;
		}
	}
};
void main()
{
	int in;
	cout<<"Enter Size "<<endl;
	cin>>size;
	arr=new student[size];
	for (int i = 0; i < size; i++)
	{
		arr[i].id=-1;
	}
	student call;
	do
	{
		cout<<"Enter 1 for Input\n2 for Search\n3 for Exit"<<endl;
		cin>>in;
			switch (in)
			{
			case 1:
				call.input();
				break;
			case 2:
				call.search();
				break;
			case 3:
				cout<<"The End "<<endl;
				break;
			}
	} while (in!=3);




	system("pause");
}