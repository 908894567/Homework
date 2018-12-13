#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class studentclass;                     //����ѧ���γ���
class Rclass;                           //�������޿���
class Eclass;                           //����ѡ�޿���
int num=0;                              //ѧ������

class classes{                          //�����γ���
public:
    string classname[100];              //�γ�����
    string classroom[100];              //���ҵ�ַ
    string teacher[100];                //��ʦ����
    int start[100];                     //��ʼ��
    int finish[100];                    //������
    int times[100];                     //һ���Ͽδ���
    int ctime[100];                     //���ڼ��Ͽ�
    int ttime[100];                     //�ڼ��ڿ�
    int cnum=0;                         //�γ�����
    void showclass();                   //��ʾ�γ̺���
};

void classes::showclass(){
    for(int i=0;i<cnum;i++){
        cout<<"["<<i+1<<"]"<<classname[i]<<"("<<teacher[i]<<")"<<classroom[i]<<" "<<start[i]<<"--"<<finish[i]<<"��"<<" ����"<<ctime[i]<<"��"<<ttime[i]<<"���"<<endl;
    }
}

class Rclass:public classes{            //���޿��࣬�̳пγ���
public:
    void addclass(studentclass &a);      //��ӱ��޿κ���
    void setclass();                     //¼����޿κ���
    void modifyclass(int k);             //�޸ı��޿κ���
};

void Rclass::setclass(){
    for(int i=cnum;i<100;i++){
    cout<<"������γ�����:"<<endl;
    cin>>classname[i];
    cout<<"*������γ̽�ʦ:"<<endl;
    cin>>teacher[i];
    cout<<"*���������:"<<endl;
    cin>>classroom[i];
    cout<<"*��������ʼ��:"<<endl;
    cin>>start[i];
    if(start[i]>20||start[i]<0)
    {
        cout<<"�������,����������!"<<endl;
        cin>>start[i];
    }
    cout<<"*�����������:"<<endl;
    cin>>finish[i];
    if(finish[i]>20||finish[i]<0)
    {
        cout<<"�������,����������!"<<endl;
        cin>>finish[i];
    }
    cout<<"*������γ�һ�ܵĽ���:"<<endl;
    cin>>times[i];                          //����ͬ�Ŀο�����ݷֱ��������Ͽ�ʱ��
    {
        for(int u=0;u<times[i];u++)
        {
            classname[i+u]=classname[i];
            teacher[i+u]=teacher[i];
            classroom[i+u]=classroom[i];
            start[i+u]=start[i];
            finish[i+u]=finish[i];
            cout<<"*�������"<<u+1<<"�ο������ڼ�"<<endl;
            cin>>ctime[i+u];
            if(ctime[i+u]>7)
            {
                cout<<"�������!  ����������"<<endl;
                cin>>ctime[i+u];
            }
            cout<<"*������γ��ǵڼ���"<<endl;
            cin>>ttime[i+u];
            if(ttime[i+u]>5)
            {
                cout<<"�������!  ����������"<<endl;
                cin>>ttime[i+u];
            }
        }
    cnum=cnum+times[i];
    i=i+times[i]-1;
    }
    cout<<"*�����Ƿ������һ���γ̣�(Y/N)"<<endl;           //�Ƿ��������
            char c;
            cin>>c;
            if(c=='Y'||c=='y') continue;                  //������һ��
            else break;
    }
}

void Rclass::modifyclass(int k){
    cout<<"������γ�����:"<<endl;
    cin>>classname[k-1];
    cout<<"*������γ̽�ʦ:"<<endl;
    cin>>teacher[k-1];
    cout<<"*���������:"<<endl;
    cin>>classroom[k-1];
    cout<<"*��������ʼ��:"<<endl;
    cin>>start[k-1];
    if(start[k-1]>20||start[k-1]<0)
    {
        cout<<"�������,����������!"<<endl;
        cin>>start[k-1];
    }
    cout<<"*�����������:"<<endl;
    cin>>finish[k-1];
    if(finish[k-1]>20||finish[k-1]<0)
    {
        cout<<"�������,����������!"<<endl;
        cin>>finish[k-1];
    }
    cout<<"*���������ڼ��Ͽ�"<<endl;
    cin>>ctime[k-1];
    if(ctime[k-1]>7)
    {
        cout<<"�������!  ����������"<<endl;
        cin>>ctime[k-1];
    }
    cout<<"*������γ��ǵڼ���"<<endl;
    cin>>ttime[k-1];
    if(ttime[k-1]>5)
    {
        cout<<"�������!  ����������"<<endl;
        cin>>ttime[k-1];
    }

}

class Eclass:public classes{                        //ѡ�޿���,�̳пγ���
public:
    Eclass();                                       //���캯������ʼ��ѡ�޿γ�
    void chooseclass(int k,studentclass &a);        //ѡ�κ���
};

Eclass::Eclass(){
    cnum=7;
    classname[0]="Java�������";classname[1]="2D3D��Ϸ���";classname[2]="�Ӿ�������";classname[3]="�鷨����";classname[4]="������ѧ";classname[5]="����ó��";classname[6]="���̹���";
    classroom[0]="C301";classroom[1]="C302";classroom[2]="C303";classroom[3]="C304";classroom[4]="C305";classroom[5]="C306";classroom[6]="C307";
    teacher[0]="��XX";teacher[1]="��XX";teacher[2]="��XX";teacher[3]="��XX";teacher[4]="��XX";teacher[5]="��XX";teacher[6]="��XX";
    ttime[0]=1;ttime[1]=1;ttime[2]=2;ttime[3]=2;ttime[4]=2;ttime[5]=1;ttime[6]=1;
    for(int i=0;i<cnum;i++){
        start[i]=1;
        finish[i]=16;
        times[i]=1;
        ctime[i]=5;
    }
}

class studentclass:public classes{                  //ѧ���γ��࣬�̳пγ���
    friend void chooseclass(int k,studentclass &b); //������Ԫ����ѡ�κ���
    friend void addclass(studentclass &a);          //������Ԫ������ӱ��޿κ���
private:
    string name;
    string id;
public:
    string getname(){return name;}
    string getid(){return id;}
    void setstudent();
    void showstudent(){cout<<"����:"<<name<<"ѧ��:"<<id<<endl;}
    void modify();
    void showSchedule();
};

void studentclass::setstudent(){
    cout<<"*������ѧ������:"<<endl;
    cin>>name;
    cout<<"*������ѧ��ѧ��:"<<endl;
    cin>>id;
    num++;
}

void studentclass::modify(){
    cout<<"*����������:"<<endl;
    cin>>name;
    cout<<"*������ѧ��:"<<endl;
    cin>>id;
}

void studentclass::showSchedule(){
    cout<<"                                   ////////////////////////////////"<<endl;
	cout<<"                                   //��           ��           ��//"<<endl;
	cout<<"                                   ////////////////////////////////"<<endl;
	cout<<"_____________________________________________________________________________________________________"<<endl;
	cout<<"         |     һ     |     ��     |     ��     |     ��     |     ��     |     ��     |     ��     |"<<endl;
   	cout<<"_____________________________________________________________________________________________________"<<endl;
    for(int i=0;i<20;i++)                            //���γ̱�ָ�Ϊ20������,ÿ�ĸ�����Ϊһ��ڿ�
	{
		switch(i)                                    //ÿһ�������Ϊ4�У��ֱ��ӡ�γ����ơ���ʦ���������ҵ�ַ����ʼ�ͽ�����
		{
			case 0:cout<<"һ(1-2)  |";break;
		    case 4:cout<<"��(3-4)  |";break;
		    case 8:cout<<"��(5-6)  |";break;
		    case 12:cout<<"��(7-8)  |";break;
		    case 16:cout<<"��(9-10) |";break;
		}
		if(i%4==0){
            for(int j=0;j<7;j++){
            int l=0;
            for(int n=0;n<100;n++){
                if((ttime[n]-1)*4==i&&ctime[n]-1==j){
                    cout<<setw(12)<<classname[n]<<"|";
                    l=1;
                }
            }
            if(l==0){
               cout<<"            |";
            }
            }
            cout<<endl<<"         |";
		}
		if(i%4==1){
            for(int j=0;j<7;j++){
            int l=0;
            for(int n=0;n<100;n++){
                if((ttime[n]-1)*4+1==i&&ctime[n]-1==j){
                    cout<<setw(12)<<teacher[n]<<"|";
                    l=1;
                }
            }
            if(l==0){
               cout<<"            |";
            }
            }
            cout<<endl<<"         |";
		}
		if(i%4==1){
            for(int j=0;j<7;j++){
            int l=0;
            for(int n=0;n<100;n++){
                if((ttime[n]-1)*4+1==i&&ctime[n]-1==j){
                    cout<<setw(12)<<classroom[n]<<"|";
                    l=1;
                }
            }
            if(l==0){
               cout<<"            |";
            }
            }
            cout<<endl<<"         |";
		}
		if(i%4==3){
            for(int j=0;j<7;j++){
            int l=0;
            for(int n=0;n<100;n++){
                if((ttime[n]-1)*4+3==i&&ctime[n]-1==j){
                    cout<<"  "<<setw(2)<<start[n]<<"----"<<setw(2)<<finish[n]<<"��|";
                    l=1;
                }
            }
            if(l==0){
               cout<<"            |";
            }
            }
            cout<<endl<<"-----------------------------------------------------------------------------------------------------"<<endl;
		}
	}
}

void Eclass::chooseclass(int k,studentclass &a){
    a.classname[a.cnum]=classname[k-1];
    a.classroom[a.cnum]=classroom[k-1];
    a.teacher[a.cnum]=teacher[k-1];
    a.start[a.cnum]=start[k-1];
    a.finish[a.cnum]=finish[k-1];
    a.ctime[a.cnum]=ctime[k-1];
    a.ttime[a.cnum]=ttime[k-1];
    a.cnum++;
}

void Rclass::addclass(studentclass &a){
    cout<<"Ϊѧ����ӱ��޿�...."<<endl;
    for(int i=0;i<cnum;i++){
        a.classname[a.cnum]=classname[i];
        a.classroom[a.cnum]=classroom[i];
        a.teacher[a.cnum]=teacher[i];
        a.start[a.cnum]=start[i];
        a.finish[a.cnum]=finish[i];
        a.ctime[a.cnum]=ctime[i];
        a.ttime[a.cnum]=ttime[i];
        a.cnum++;
    }
}

int main(){
    int x,y,k;
    char c;
    string s;
    studentclass b[100];
    Rclass  r;
    Eclass e;
    while(1)
    {
    cout<<"***************|��ӭʹ�ÿγ̱���ϵͳ|***************"<<endl<<endl;   //ϵͳ����
	cout<<" ***************| ��������ؿγ���Ϣ |***************"<<endl<<endl;
	cout<<"   ----------------------------------------------"<<endl;
	cout<<"   |                 1.��Ϣ¼��                 |"<<endl;
	cout<<"   |                 2.��Ϣ�޸�                 |"<<endl;
	cout<<"   |                 3.��Ϣ��ѯ                 |"<<endl;
	cout<<"   |                 4.��Ϣ��ʾ                 |"<<endl;
	cout<<"   |                   0.�˳�                   |"<<endl;
	cout<<"   ----------------------------------------------"<<endl;
	cout<<"   |��ѡ��(0-4)                                 |"<<endl;
    cin>>x;
    switch(x)
    {
    case 1:
        {   int z=0;
            cout<<"   ----------------------------------------------"<<endl;
            cout<<"   |                 1.ѧ����Ϣ¼��             |"<<endl;
            cout<<"   |                 2.���޿γ�¼��             |"<<endl;
            cout<<"   |                 3.ѡ��ѡ�޿�               |"<<endl;
            cout<<"   |                 4.�������˵�               |"<<endl;
            cout<<"   ----------------------------------------------"<<endl;
            cout<<"   |��ѡ��(1-4)                                 |"<<endl;
            cin>>y;
            if(y==1){
                for(int i=num;i<100;i++)
                {
                    b[i].setstudent();
                    r.addclass(b[i]);
                    cout<<"*�����Ƿ������һ��ѧ����(Y/N)"<<endl;
                    cin>>c;
                    if(c=='Y'||c=='y') continue;
                    else break;
                }
            }
            if(y==2){
                    r.setclass();
                for(int i=0;i<num;i++){
                    r.addclass(b[i]);
                }
                    break;
                }
            if(y==3){
                cout<<"*������ѡ��ѧ����������ѧ��:"<<endl;
                cin>>s;
                for(int i=0;i<num;i++){
                    if(s==b[i].getname()||s==b[i].getid()){
                    z=1;
                    cout<<"----------------------------------------------"<<endl;
                    e.showclass();

                    cout<<"*����������ѡ���ѡ�޿εĿγ���ţ�"<<endl;
                    cin>>k;
                    e.chooseclass(k,b[i]);
                    cout<<"ѡ�γɹ�"<<endl;
                    break;
                }
                }
                if(z==0){
                    cout<<"δ�ҵ���ѧ��"<<endl;
                    break;
                }
                z=0;
            }
            if(y==4){break;}
            break;
        }
    case 2:
        {   int z=0;
            cout<<"   ----------------------------------------------"<<endl;
            cout<<"   |                 1.ѧ����Ϣ�޸�             |"<<endl;
            cout<<"   |                 2.���޿γ���Ϣ�޸�         |"<<endl;
            cout<<"   |                 3.�������˵�               |"<<endl;
            cout<<"   ----------------------------------------------"<<endl;
            cout<<"   |��ѡ��(1-3)                                 |"<<endl;
            cin>>y;
            if(y==1){
                cout<<"*������ѧ����������ѧ��:"<<endl;
                cin>>s;
                for(int i=0;i<num;i++){
                if(s==b[i].getname()||s==b[i].getid())
                {
                    b[i].modify();
                    z=1;
                    break;
                }
            }
                if(z==0){
                    cout<<"δ�ҵ���ѧ��"<<endl;
                    break;
                }
                z=0;
            }
            if(y==2){
                    r.showclass();
                    if(r.cnum==0){cout<<"δ¼��γ�"<<endl;break;}
                    cout<<"*��������Ҫ�޸ĵĿγ����:"<<endl;
                    cin>>k;
                    r.modifyclass(k);
                    break;
                }
            if(y==3){break;}
            break;
        }
    case 3:
        {   int z=0;
            cout<<"   ----------------------------------------------"<<endl;
            cout<<"   |                 1.ѧ����Ϣ��ѯ             |"<<endl;
            cout<<"   |                 2.ѧ���γ���Ϣ��ѯ         |"<<endl;
            cout<<"   |                 3.�������˵�               |"<<endl;
            cout<<"   ----------------------------------------------"<<endl;
            cout<<"   |��ѡ��(1-3)                                 |"<<endl;
            cin>>y;
            if(y==1){
                cout<<"*������ѧ��������ѧ��:"<<endl;
                cin>>s;
                for(int i=0;i<num;i++){
                if(s==b[i].getname()||s==b[i].getid()){
                    cout<<"����:"<<b[i].getname()<<"  ѧ��:"<<b[i].getid()<<endl;
                    z=1;
                    break;
                }
            }
                if(z==0){
                    cout<<"δ�ҵ���ѧ��"<<endl;
                    break;
                }
                z=0;
            }
            if(y==2){
                cout<<"*������ѧ��������ѧ��:"<<endl;
                cin>>s;
                for(int i=0;i<num;i++){
                if(s==b[i].getname()||s==b[i].getid()){
                    b[i].showclass();
                    if(b[i].cnum==0)
                        cout<<"��ѧ��δ¼��γ�"<<endl;
                    z=1;
                    break;
                }
            }
                if(z==0){
                    cout<<"δ�ҵ���ѧ��"<<endl;
                    break;
                }
                z=0;
            }
            if(y==3){break;}
            break;
        }
    case 4:
        {   int z=0;
            cout<<"   ----------------------------------------------"<<endl;
            cout<<"   |                 1.ѧ����Ϣ��ʾ             |"<<endl;
            cout<<"   |                 2.��ӡѧ���γ̱�           |"<<endl;
            cout<<"   |                 3.�������˵�               |"<<endl;
            cout<<"   ----------------------------------------------"<<endl;
            cout<<"   |��ѡ��(1-3)                                 |"<<endl;
            cin>>y;
            if(y==1){
                for(int i=0;i<num;i++){
                    cout<<i+1<<".";
                    b[i].showstudent();
                    b[i].showclass();
                }
                break;
            }
            if(y==2){
                cout<<"*������ѧ����������ѧ��:"<<endl;
                cin>>s;
                for(int i=0;i<num;i++){
                if(s==b[i].getname()||s==b[i].getid()){
                    z=1;
                    if(b[i].cnum==0)
                    {cout<<"��ѧ��δ¼��γ�"<<endl;break;}
                    b[i].showSchedule();
                    break;
                }
                }
                if(z==0){
                    cout<<"δ�ҵ���ѧ��"<<endl;
                    break;
                }
                z=0;
            }
            if(y==3){break;}
            break;
        }
    case 0:
        {exit(1);}
    }
    cout<<"���س�������.............";
    getchar();
    getchar();
    system("CLS");
    }
}