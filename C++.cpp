#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class studentclass;                     //声明学生课程类
class Rclass;                           //声明必修课类
class Eclass;                           //声明选修课类
int num=0;                              //学生总数

class classes{                          //声明课程类
public:
    string classname[100];              //课程名称
    string classroom[100];              //教室地址
    string teacher[100];                //老师姓名
    int start[100];                     //开始周
    int finish[100];                    //结束周
    int times[100];                     //一周上课次数
    int ctime[100];                     //星期几上课
    int ttime[100];                     //第几节课
    int cnum=0;                         //课程总数
    void showclass();                   //显示课程函数
};

void classes::showclass(){
    for(int i=0;i<cnum;i++){
        cout<<"["<<i+1<<"]"<<classname[i]<<"("<<teacher[i]<<")"<<classroom[i]<<" "<<start[i]<<"--"<<finish[i]<<"周"<<" 星期"<<ctime[i]<<"第"<<ttime[i]<<"大节"<<endl;
    }
}

class Rclass:public classes{            //必修课类，继承课程类
public:
    void addclass(studentclass &a);      //添加必修课函数
    void setclass();                     //录入必修课函数
    void modifyclass(int k);             //修改必修课函数
};

void Rclass::setclass(){
    for(int i=cnum;i<100;i++){
    cout<<"请输入课程名称:"<<endl;
    cin>>classname[i];
    cout<<"*请输入课程教师:"<<endl;
    cin>>teacher[i];
    cout<<"*请输入教室:"<<endl;
    cin>>classroom[i];
    cout<<"*请输入起始周:"<<endl;
    cin>>start[i];
    if(start[i]>20||start[i]<0)
    {
        cout<<"输入错误,请重新输入!"<<endl;
        cin>>start[i];
    }
    cout<<"*请输入结束周:"<<endl;
    cin>>finish[i];
    if(finish[i]>20||finish[i]<0)
    {
        cout<<"输入错误,请重新输入!"<<endl;
        cin>>finish[i];
    }
    cout<<"*请输入课程一周的节数:"<<endl;
    cin>>times[i];                          //将相同的课拷贝多份分别存入具体上课时间
    {
        for(int u=0;u<times[i];u++)
        {
            classname[i+u]=classname[i];
            teacher[i+u]=teacher[i];
            classroom[i+u]=classroom[i];
            start[i+u]=start[i];
            finish[i+u]=finish[i];
            cout<<"*请输入第"<<u+1<<"次课是星期几"<<endl;
            cin>>ctime[i+u];
            if(ctime[i+u]>7)
            {
                cout<<"输入错误!  请重新输入"<<endl;
                cin>>ctime[i+u];
            }
            cout<<"*请输入课程是第几堂"<<endl;
            cin>>ttime[i+u];
            if(ttime[i+u]>5)
            {
                cout<<"输入错误!  请重新输入"<<endl;
                cin>>ttime[i+u];
            }
        }
    cnum=cnum+times[i];
    i=i+times[i]-1;
    }
    cout<<"*请问是否继续下一个课程？(Y/N)"<<endl;           //是否继续输入
            char c;
            cin>>c;
            if(c=='Y'||c=='y') continue;                  //继续下一个
            else break;
    }
}

void Rclass::modifyclass(int k){
    cout<<"请输入课程名称:"<<endl;
    cin>>classname[k-1];
    cout<<"*请输入课程教师:"<<endl;
    cin>>teacher[k-1];
    cout<<"*请输入教室:"<<endl;
    cin>>classroom[k-1];
    cout<<"*请输入起始周:"<<endl;
    cin>>start[k-1];
    if(start[k-1]>20||start[k-1]<0)
    {
        cout<<"输入错误,请重新输入!"<<endl;
        cin>>start[k-1];
    }
    cout<<"*请输入结束周:"<<endl;
    cin>>finish[k-1];
    if(finish[k-1]>20||finish[k-1]<0)
    {
        cout<<"输入错误,请重新输入!"<<endl;
        cin>>finish[k-1];
    }
    cout<<"*请输入星期几上课"<<endl;
    cin>>ctime[k-1];
    if(ctime[k-1]>7)
    {
        cout<<"输入错误!  请重新输入"<<endl;
        cin>>ctime[k-1];
    }
    cout<<"*请输入课程是第几堂"<<endl;
    cin>>ttime[k-1];
    if(ttime[k-1]>5)
    {
        cout<<"输入错误!  请重新输入"<<endl;
        cin>>ttime[k-1];
    }

}

class Eclass:public classes{                        //选修课类,继承课程类
public:
    Eclass();                                       //构造函数，初始化选修课程
    void chooseclass(int k,studentclass &a);        //选课函数
};

Eclass::Eclass(){
    cnum=7;
    classname[0]="Java程序设计";classname[1]="2D3D游戏设计";classname[2]="视觉与艺术";classname[3]="书法鉴赏";classname[4]="西方哲学";classname[5]="国际贸易";classname[6]="工商管理";
    classroom[0]="C301";classroom[1]="C302";classroom[2]="C303";classroom[3]="C304";classroom[4]="C305";classroom[5]="C306";classroom[6]="C307";
    teacher[0]="李XX";teacher[1]="陈XX";teacher[2]="张XX";teacher[3]="赵XX";teacher[4]="李XX";teacher[5]="王XX";teacher[6]="宋XX";
    ttime[0]=1;ttime[1]=1;ttime[2]=2;ttime[3]=2;ttime[4]=2;ttime[5]=1;ttime[6]=1;
    for(int i=0;i<cnum;i++){
        start[i]=1;
        finish[i]=16;
        times[i]=1;
        ctime[i]=5;
    }
}

class studentclass:public classes{                  //学生课程类，继承课程类
    friend void chooseclass(int k,studentclass &b); //声明友元函数选课函数
    friend void addclass(studentclass &a);          //声明友元函数添加必修课函数
private:
    string name;
    string id;
public:
    string getname(){return name;}
    string getid(){return id;}
    void setstudent();
    void showstudent(){cout<<"姓名:"<<name<<"学号:"<<id<<endl;}
    void modify();
    void showSchedule();
};

void studentclass::setstudent(){
    cout<<"*请输入学生姓名:"<<endl;
    cin>>name;
    cout<<"*请输入学生学号:"<<endl;
    cin>>id;
    num++;
}

void studentclass::modify(){
    cout<<"*输入新名字:"<<endl;
    cin>>name;
    cout<<"*输入新学号:"<<endl;
    cin>>id;
}

void studentclass::showSchedule(){
    cout<<"                                   ////////////////////////////////"<<endl;
	cout<<"                                   //课           程           表//"<<endl;
	cout<<"                                   ////////////////////////////////"<<endl;
	cout<<"_____________________________________________________________________________________________________"<<endl;
	cout<<"         |     一     |     二     |     三     |     四     |     五     |     六     |     日     |"<<endl;
   	cout<<"_____________________________________________________________________________________________________"<<endl;
    for(int i=0;i<20;i++)                            //将课程表分割为20个区域,每四个区域为一大节课
	{
		switch(i)                                    //每一个区域分为4行，分别打印课程名称、老师姓名、教室地址、起始和结束周
		{
			case 0:cout<<"一(1-2)  |";break;
		    case 4:cout<<"二(3-4)  |";break;
		    case 8:cout<<"三(5-6)  |";break;
		    case 12:cout<<"四(7-8)  |";break;
		    case 16:cout<<"五(9-10) |";break;
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
                    cout<<"  "<<setw(2)<<start[n]<<"----"<<setw(2)<<finish[n]<<"周|";
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
    cout<<"为学生添加必修课...."<<endl;
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
    cout<<"***************|欢迎使用课程表建立系统|***************"<<endl<<endl;   //系统进入
	cout<<" ***************| 请输入相关课程信息 |***************"<<endl<<endl;
	cout<<"   ----------------------------------------------"<<endl;
	cout<<"   |                 1.信息录入                 |"<<endl;
	cout<<"   |                 2.信息修改                 |"<<endl;
	cout<<"   |                 3.信息查询                 |"<<endl;
	cout<<"   |                 4.信息显示                 |"<<endl;
	cout<<"   |                   0.退出                   |"<<endl;
	cout<<"   ----------------------------------------------"<<endl;
	cout<<"   |请选择(0-4)                                 |"<<endl;
    cin>>x;
    switch(x)
    {
    case 1:
        {   int z=0;
            cout<<"   ----------------------------------------------"<<endl;
            cout<<"   |                 1.学生信息录入             |"<<endl;
            cout<<"   |                 2.必修课程录入             |"<<endl;
            cout<<"   |                 3.选择选修课               |"<<endl;
            cout<<"   |                 4.返回主菜单               |"<<endl;
            cout<<"   ----------------------------------------------"<<endl;
            cout<<"   |请选择(1-4)                                 |"<<endl;
            cin>>y;
            if(y==1){
                for(int i=num;i<100;i++)
                {
                    b[i].setstudent();
                    r.addclass(b[i]);
                    cout<<"*请问是否继续下一个学生？(Y/N)"<<endl;
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
                cout<<"*请输入选课学生的姓名或学号:"<<endl;
                cin>>s;
                for(int i=0;i<num;i++){
                    if(s==b[i].getname()||s==b[i].getid()){
                    z=1;
                    cout<<"----------------------------------------------"<<endl;
                    e.showclass();

                    cout<<"*请输入你想选择的选修课的课程序号："<<endl;
                    cin>>k;
                    e.chooseclass(k,b[i]);
                    cout<<"选课成功"<<endl;
                    break;
                }
                }
                if(z==0){
                    cout<<"未找到此学生"<<endl;
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
            cout<<"   |                 1.学生信息修改             |"<<endl;
            cout<<"   |                 2.必修课程信息修改         |"<<endl;
            cout<<"   |                 3.返回主菜单               |"<<endl;
            cout<<"   ----------------------------------------------"<<endl;
            cout<<"   |请选择(1-3)                                 |"<<endl;
            cin>>y;
            if(y==1){
                cout<<"*请输入学生的姓名或学号:"<<endl;
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
                    cout<<"未找到此学生"<<endl;
                    break;
                }
                z=0;
            }
            if(y==2){
                    r.showclass();
                    if(r.cnum==0){cout<<"未录入课程"<<endl;break;}
                    cout<<"*请输入你要修改的课程序号:"<<endl;
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
            cout<<"   |                 1.学生信息查询             |"<<endl;
            cout<<"   |                 2.学生课程信息查询         |"<<endl;
            cout<<"   |                 3.返回主菜单               |"<<endl;
            cout<<"   ----------------------------------------------"<<endl;
            cout<<"   |请选择(1-3)                                 |"<<endl;
            cin>>y;
            if(y==1){
                cout<<"*请输入学生姓名或学号:"<<endl;
                cin>>s;
                for(int i=0;i<num;i++){
                if(s==b[i].getname()||s==b[i].getid()){
                    cout<<"姓名:"<<b[i].getname()<<"  学号:"<<b[i].getid()<<endl;
                    z=1;
                    break;
                }
            }
                if(z==0){
                    cout<<"未找到此学生"<<endl;
                    break;
                }
                z=0;
            }
            if(y==2){
                cout<<"*请输入学生姓名或学号:"<<endl;
                cin>>s;
                for(int i=0;i<num;i++){
                if(s==b[i].getname()||s==b[i].getid()){
                    b[i].showclass();
                    if(b[i].cnum==0)
                        cout<<"此学生未录入课程"<<endl;
                    z=1;
                    break;
                }
            }
                if(z==0){
                    cout<<"未找到此学生"<<endl;
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
            cout<<"   |                 1.学生信息显示             |"<<endl;
            cout<<"   |                 2.打印学生课程表           |"<<endl;
            cout<<"   |                 3.返回主菜单               |"<<endl;
            cout<<"   ----------------------------------------------"<<endl;
            cout<<"   |请选择(1-3)                                 |"<<endl;
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
                cout<<"*请输入学生的姓名或学号:"<<endl;
                cin>>s;
                for(int i=0;i<num;i++){
                if(s==b[i].getname()||s==b[i].getid()){
                    z=1;
                    if(b[i].cnum==0)
                    {cout<<"此学生未录入课程"<<endl;break;}
                    b[i].showSchedule();
                    break;
                }
                }
                if(z==0){
                    cout<<"未找到此学生"<<endl;
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
    cout<<"按回车键继续.............";
    getchar();
    getchar();
    system("CLS");
    }
}