#include "info.h"
 
 
vector<Info> per;
int Info::count = 0;
 
 Info::Info()
{
 
}
  
Info::~Info()
{

}

int Info::GetId()
{
    return id;
}
 
 
void Info::SetName()
{
    //cout << "������"; 
    cin >> name;
}
string Info::GetName() const
{
    string tmp = name;
    return tmp;
}
 
 
void Info::SetTel()
{
    //cout << "�绰��";
    cin >> tel;
}
string Info::GetTel() const
{
    string tmp = tel;
    return tmp;
}
 
void Info::SetAddr()
{
    //cout << "��ַ��";
    cin >> addr;
}
string Info::GetAddr() const
{
    string tmp = addr;
    return tmp;
}

void Info::SetEmail()
{
    //cout << "�ʼ���";
    cin >> email;
}
string Info::GetEmail() const
{
    string tmp = email;
    return tmp;
}
 
void Info::insert()
{
    Info tmp;
    vector<Info>::iterator it;
    tmp.SetName();
    tmp.SetTel();
	tmp.SetEmail();
    tmp.SetAddr();    
    per.push_back(tmp);
}

void Info::search()
{
    vector<Info>::iterator it;
    if(per.empty())
    {
        cout << "ͨѶ¼������ϵ�ˣ�" << endl;
    }
    else
    {
		search_loop:
		string tn; //���ҵ�����
		int flag = 0;//���ҳɹ�����־λ

		cout << "��������ҵ�������";
		cin >> tn;
		for(it = per.begin(); it != per.end(); ++it)
		 {
			if(!((it->GetName()).compare(tn)))
		    {
			 flag = 1;
			 cout << "��Ҫ�ҵ���ϵ��Ϊ��" <<endl;
			  //cout << "ID: " << it->GetId() << endl;
			 cout  << it->GetName() << " ";
			 cout  << it->GetTel()<< " " ;
			 cout << it->GetEmail()<< " ";
			 cout << it->GetAddr()<<endl;
			}
		 }

		if(0 == flag)
		{
		 cout << "���ҵ�����ϵ��" << endl;
		}
		else
		{
		 //cout << "���ҳɹ�"  << endl;
		}
    }  
} 
 

