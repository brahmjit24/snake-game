#include<iostream>
#include<vector>
#include<fstream>
#define clear() printf("\033[H\033[J")
using namespace std;
struct food{
//public:
int x,y;
char val;
};
struct snake
{
//public:
int x,y;
char val;
};

void print(char board[20][80],int x,int y)
{
for(int i=0;i<x;i++)
{for(int j=0;j<y;j++)
cout<<board[i][j];
cout<<endl;
}
}

void insert(vector <snake> &s,struct snake temp)
{
s[s.size()-1].val='*';
struct snake d;
d.x=temp.x;
d.y=temp.y;
d.val='T';
s.push_back(d);
}

bool iskill(vector <snake> &s)
{
struct snake temp;
temp.x=s[0].x;
temp.y=s[0].y;
temp.val=s[0].val;
for(int i=1;i<s.size();i++)
{
if(s[i].x==temp.x&&s[i].y==temp.y)
{
cout<<"Game Over";
return true;
}
}
return false;


}

bool chkplus(struct food f,vector <snake> &s,struct snake temp)
{
if(f.x==s[0].x&&f.y==s[0].y)
{insert(s,temp);
return true;
}
else
return false;

}




void rndm(struct food &f,vector<snake> &s)
{

f.x=f.x+5;
f.y=f.y+2;
if(f.x>=19)
f.x=1;
else if(f.y>=79)
f.y=4;
for(int i=0;i<s.size();i++)
{
if(s[i].x==f.x&&s[i].y==f.y)
{
rndm(f,s);
}
}

}




//-------------------------------------------------------------------------------
struct snake movedown(vector <snake> &s)
{
struct snake ss;
int i=s.size()-1;
if(s[0].x+1==s[1].x)
{cout<<"move not possible\n";}
else{
//struct snake ss;
ss.x=s[i].x;
ss.y=s[i].y;
ss.val=s[i].val;
while(i!=0)
{
s[i].x=s[i-1].x;
s[i].y=s[i-1].y;
i--;
}
s[0].x=s[0].x+1;



if(s[0].x==19)
s[0].x=1;
}
return ss;
}



//-------------------------------


struct snake moveleft(vector <snake> &s)
{
struct snake ss;
int i=s.size()-1;
if(s[0].y-1==s[1].y)
{cout<<"move not possible\n";}
else{

//struct snake ss;
ss.x=s[i].x;
ss.y=s[i].y;
ss.val=s[i].val;
while(i!=0)
{
s[i].x=s[i-1].x;
s[i].y=s[i-1].y;
i--;
}
s[0].y=s[0].y-1;

if(s[0].y==0)
s[0].y=78;
}
return ss;
}


//------------------------------




struct snake moveup(vector <snake> &s)
{
struct snake ss;
int i=s.size()-1;
if(s[0].x-1==s[1].x)
{cout<<"move not possible\n";}
else{

//struct snake ss;
ss.x=s[i].x;
ss.y=s[i].y;
ss.val=s[i].val;
while(i!=0)
{
s[i].x=s[i-1].x;
s[i].y=s[i-1].y;
i--;
}
s[0].x=s[0].x-1;



if(s[0].x==0)
s[0].x=18;
}
return ss;
}

//------------------------------------------


struct snake moveright(vector <snake> &s)
{

struct snake ss;
int i=s.size()-1;
if(s[0].y+1==s[1].y)
{cout<<"move not possible\n";}
else{


ss.x=s[i].x;
ss.y=s[i].y;
ss.val=s[i].val;
while(i!=0)
{
s[i].x=s[i-1].x;
s[i].y=s[i-1].y;
i--;
}
s[0].y=s[0].y+1;



if(s[0].y==79)
s[0].y=1;
}
return ss;
}

//---------------------------------------------
void insertFood(food f,char board[20][80],int x,int y)
{

board[f.x][f.y]=f.val;

}

void insertSnake(vector<snake> &s ,char board[20][80],int x,int y)
{
for(int i=0;i<s.size();i++)
board[s[i].x][s[i].y]=s[i].val;
}

void cleanboard(char board[20][80])
{
for(int i=1;i<20-1;i++)
for(int j=1;j<80-1;j++)
board[i][j]=' ';

for(int i=0;i<79;i++)
{board[0][i]='.';
 board[19][i]='.';
}

for(int i=0;i<19;i++)
{board[i][0]='.';
 board[i][79]='.';
}
}


int main()
{
char board[20][80];
cleanboard(board);

struct food f;
f.x=10;f.y=30;f.val='F';
insertFood(f,board,20,80);
vector<snake> s;
struct snake d;

d.x=10;
d.y=11;
d.val='H';
s.push_back(d);

d.x=10;
d.y=12;
d.val='*';
s.push_back(d);

d.x=10;
d.y=13;
d.val='T';
s.push_back(d);


insertSnake(s,board,20,80);

print(board,20,80);
char dir;
while(true){
  cin>>dir;
 clear();
struct snake temp;
if(dir=='w'||dir=='W')
{temp=moveup(s);
cleanboard(board);
insertFood(f,board,20,80);
insertSnake(s,board,20,80);
print(board,20,80);
}
else if(dir=='s'||dir=='S')
{temp=movedown(s);
cleanboard(board);
insertFood(f,board,20,80);
insertSnake(s,board,20,80);
print(board,20,80);
}
else if(dir=='d'||dir=='D')
{temp=moveright(s);
cleanboard(board);
insertFood(f,board,20,80);
insertSnake(s,board,20,80);
print(board,20,80);
}
else if(dir=='a'||dir=='A')
{temp=moveleft(s);
cleanboard(board);
insertFood(f,board,20,80);
insertSnake(s,board,20,80);
print(board,20,80);
}
else if(dir=='q'||dir=='Q')
{
cout<<"Game Over";
break;}


else
cout<<"Wrong input";

bool chk;
chk=chkplus(f,s,temp);
if(chk)
{
rndm(f,s);
cleanboard(board);
insertFood(f,board,20,80);
insertSnake(s,board,20,80);
print(board,20,80);
}
if(iskill(s))
break;


}
//-------------------
//-------------------
}

