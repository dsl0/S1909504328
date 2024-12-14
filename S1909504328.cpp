//Develop a program in C++ to create a database of student’s
//information system containing the following information: Name, Roll
//number, Class, Division, Date of Birth, Blood group, Contact
//address, Telephone number, Driving license no. and other. Construct
//the database with suitable member functions. Make use of
//constructor, default constructor, copy constructor, destructor, static
//member functions, friend class, this pointer, inline code and dynamic
//memory allocation operators-new and delete as well as exception
//handling.
#include <iostream>
using namespace std;
class Patient{
private:
    string name;
    int rollno;
    int Class;
    string Div;
    int DOB;
    string DL;
public:
    Patient(){
        this->name="";
        this->rollno=0;
        this->Class=0;
        this ->Div="";
        this->DOB=0;
        this ->DL="";
        
    }
    void setData(){
        cout<<"Enter your name:"<<endl;
        cin>>name;
        cout<<"Enter your roll no.:"<<endl;
        cin>>rollno;
        cout<<"Enter your class:"<<endl;
        cin>>Class;
        cout<<"Enter your Division:"<<endl;
        cin>>Div;
        cout<<"Enter you Date of Birth:"<<"-"<<endl;
        cin>>DOB;
        cout<<"Enter your DL:"<<endl;
        cin>>DL;
        
    }
    void getData(){
        cout<<"The Patient's name is :"<<name<<endl;
        cout<<"Patients roll number is:"<<rollno<<endl;
        cout<<"Patients is in class :"<<Class<<endl;
        cout<<"Patients division is:"<<Div<<endl;
        cout<<"Patients date of birth is:"<<DOB<<endl;
        cout<<"Patients Driving liscense number is :"<<endl;
        
        
    }
};
int main(){
    Patient p1;
    p1.setData();
    p1.getData();
    return 0;
    
}
------------------------------------------------------------------------------------------------------------------#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Publication{
private:
    string title;
    float prices;
public:
    Publication(){
        title=" ";
        prices=0.0;
    }
    void setData(){
        cout<<"Enter the title:"<<endl;
        cin.ignore();
        getline(cin,title);
        cout<<"Enter the prices:"<<endl;
        cin>>prices;
    }
    void putData(){
        cout<<"================================"<<endl;
        cout<<"Information:"<<endl;
        cout<<"The Title of the book is:"<<title<<endl;
        cout<<"The prices of the book is:"<<prices<<endl;
    }
};
class book:public Publication{
private:
    int pages;
public:
    book(){
        pages=0;
    }
    void setData(){
        Publication::setData();
        cout<<endl;
        cout<<"Enter the page count:"<<endl;
        cin>>pages;
    }
    void putData(){
        Publication::putData();
        try{
            if(pages<0)
            throw pages;
        }
        catch(int f){
            cout<<endl<<"Error: page are not valid:"<<f;
            pages=0;
            
        }
        cout<<"Pages Are:"<<pages;
    }
};
class tape: public Publication{
private:
    int playtime;
public:
    tape(){
        playtime=0;
    }
    void setData(){
        Publication::setData();
        cout<<"Enter the playtime of the tape:"<<endl;
        cin>>playtime;
    }
    void putData(){
        Publication::putData();
        try{
            if(playtime<0)
            throw playtime;
        }
        catch(int r){
            cout<<"Error: Invalid Playtime:"<<playtime<<endl;
            playtime=0;
        }
        cout<<"Playtime is:"<<playtime<<endl;
    }
};
int main(){
    book b[10];
    tape t[10];
    int choice=0,bookCount=0,tapeCount=0;
    cout<<"-----------------------------";
    do{
        cout<<endl<<"1. Add book:";
        cout<<endl<<"2. Add Tape:";
        cout<<endl<<"3. Display book:";
        cout<<endl<<"4. Display Tape:";
        cout<<endl<<"5. Exit";
        cout<<"Enter Choice:"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
            {
                cout<<"-----------------------------"<<endl;
                cout<<"Add book:"<<endl;
                b[bookCount].setData();
                bookCount++;
            }
            case 2:
            {
                cout<<"-----------------------------"<<endl;
                cout<<"Add Tape:"<<endl;
                t[tapeCount].setData();
                tapeCount++;
            }
            case 3:
            {
                cout<<"(books)";
                for(int j=0;j<bookCount;j++){
                    b[j].putData();
                }
                break;
            }
            case 4:
            {
                cout<<("tape");
                for(int j=0;j<tapeCount;j++){
                    b[j].putData();
                }
                break;
            }
            case 5:
            {
                cout<<"****Program exited successfully:****"<<endl;
                exit(0);
            }
            default:
            {
                cout<<endl<<"Invalid";
            }
        }
    }
    while(choice!=5);
    return 0;
}
------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string filename="Example.txt";
    string dataToWrite="Hello, this is a text file";
    string line;
    
    ofstream outFile("Example.txt");
    if(outFile.is_open()){
        outFile<<dataToWrite;
        outFile.close();
        cout<<"Data written in the file successfully"<<endl;   
    }else{
        cerr<<"Error in opening the file"<<endl;
        return 1;
    }
    ifstream inFile("Example.txt");
    if(inFile.is_open()){
        cout<<"Reading from the file."<<endl;
        while(getline(inFile,line)){
            cout<<line<<endl;
        }
        inFile.close();
    }else{
        cerr<<"Unable to open the file"<<endl;
        return 1;
    }
    return 0;
   
}
-------------------------------------------------------------------------------------------------------------------
include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Struct to hold personal records
struct PersonalRecord {
    string name;
    string dob; // Date of Birth
    string phone;

    // Overload < operator for sorting
    bool operator<(const PersonalRecord& other) const {
        return name < other.name;
    }

    // Overload == operator for searching
    bool operator==(const PersonalRecord& other) const {
        return name == other.name;
    }
};

// Function to display records
void displayRecords(const vector<PersonalRecord>& records) {
    for (const auto& record : records) {
        cout << "Name: " << record.name << ", DOB: " << record.dob << ", Phone: " << record.phone << endl;
    }
}

int main() {
    vector<PersonalRecord> records;
    int n;

    cout << "Enter the number of records: ";
    cin >> n;
    cin.ignore(); // Clear input buffer

    // Input records
    for (int i = 0; i < n; ++i) {
        PersonalRecord record;
        cout << "Enter name: ";
        getline(cin, record.name);
        cout << "Enter DOB (YYYY-MM-DD): ";
        getline(cin, record.dob);
        cout << "Enter phone number: ";
        getline(cin, record.phone);
        records.push_back(record);
    }

    // Sort records
    sort(records.begin(), records.end());
    cout << "\nSorted Records:" << endl;
    displayRecords(records);

    // Search for a record
    string searchName;
    cout << "\nEnter the name to search: ";
    getline(cin, searchName);
    
    auto it = find_if(records.begin(), records.end(), [&searchName](const PersonalRecord& record) {
        return record.name == searchName;
    });

    if (it != records.end()) {
        cout << "\nRecord Found:" << endl;
        cout << "Name: " << it->name << ", DOB: " << it->dob << ", Phone: " << it->phone << endl;
    } else {
        cout << "\nRecord not found." << endl;
    }

    return 0;
}
------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <map>
#include <string>

using namespace std;
int main(){
    map<string,int> statePopulations;
    statePopulations["California"]=123456;
    statePopulations["Ohio"]=234567;
    statePopulations["Texas"]=345678;
    statePopulations["New Jersey"]=456789;
    
    string statename;
    cout<<"Enter the name of the state:"<<endl;
    getline(cin,statename);
    
    auto it=statePopulations.find(statename);
    
    if(it!=statePopulations.end()){
        cout<<"The population of "<< statename <<" is "<<it->second<<"."<<endl;
    }else{
        cout<<"State not found in the records."<<endl;
    }
    return 0;
}
------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;
int n;
template<class T>
void selection(T A[size])
{
    int i,j,min;
    T temp;
    for(i=0;i<=n-2;i++){
        min=i;
        for(j=j+1;j<=n-1;j++){
            if (A[j]<A[min])
            min=j;
        }
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
    cout<<"Sorted list"<<endl;
    for(i=0;i<n;i++)
    cout<<"\t"<<A[i];
}
int main(){
    int i,A[size];
    float B[size];
    cout<<"Selection sort"<<endl;
    cout<<"Integer element"<<endl;
    cout<<"Enter how many elements do you want:"<<endl;
    cin>>n;
    cout<<"Enter the integer element"<<endl;
    for(i=0;i<n;i++)
    cin>>A[i];
    selection(A);
    cout<<"Float elements"<<endl;
    cout<<"Enter how many elements do you want:"<<endl;
    cin>>n;
    cout<<"Enter float elements"<<endl;
    for(i=0;i<n;i++)
    cin>>B[i];
    selection(B);
    return 0;
}
------------------------------------------------------------------------------------------------------------------
#include <graphics.h> 
#include <iostream>


using namespace std;
void floodfill(int x, int y, int o,int n)
{
    if (getpixel(x,y)==o)
    {
        putpixel(x,y,n);
        floodfill(x+1,y,o,n);
        floodfill(x-1,y,o,n);
        floodfill(x,y+1,o,n);
        floodfill(x,y-1,o,n);
    }
}
int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    line(100,100,50,400);
    line(100,100,150,400);
    line(50,400,100,200);
    line(150,400,100,200);
    floodfill(100,150,0,7)
    getch();
    closegraph();
    return 0;
}
------------------------------------------------------------------------------------------------------------------
#include <graphics.h>
#include <iostream>
//SPPU CG Group A:4
//Write C++ program to implement Cohen Southerland line clipping algorithm.
using namespace std;
int main()
{
    int gd = DETECT , gm;
    int X1,Y1,X2,Y2;
    cout<<"Enter the Clipping window Coordinates:"<<endl;
    cin>>X1>>Y1>>X2>>Y2;
    float x1,y1,x2,y2;
    cout<<"Enter the Line Coordinates:"<<endl;
    cin>>x1>>y1>>x2>>y2;
    float op[2][4]; 
    if(x1<X1)
        op[0][3]=1;
    else
        op[0][3]=0;
    if(x1>X2) 
        op[0][2]=1;
    else
        op[0][2]=0;
    if(y1<Y1)
        op[0][0]=1;
    else
        op[0][0]=0;
    if(y1>Y2)
        op[0][1]=1;
    else
        op[0][1]=0;
    if(x2<X1)
        op[1][3]=1;
    else
        op[1][3]=0;
    if(x2>X2) 
        op[1][2]=1;
    else
        op[1][2]=0;
    if(y2<Y1)
        op[1][0]=1;
    else
        op[1][0]=0;
    if(y2>Y2)
        op[1][1]=1;
    else
        op[1][1]=0;
    initgraph(&gd,&gm,NULL);
    outtextxy(100,100,"Before Clipping:");
    rectangle(X1,Y1,X2,Y2);
    line(x1,y1,x2,y2);
    delay(3000);
    cleardevice();
    float m = (y2-y1)/(x2-x1);
    cout<<op[0][0]<<op[0][1]<<op[0][2]<<op[0][3]<<endl;
    cout<<op[1][0]<<op[1][1]<<op[1][2]<<op[1][3]<<endl;
    if(!(op[0][0]==0&&op[0][1]==0&&op[0][2]==0&&op[0][3]==0&&op[1][0]==0&&op[1][1]==0&&op[1][2]==0&&op[1][3]==0))
    {
        if(((op[0][0]&&op[1][0])==0)&&((op[0][1]&&op[1][1])==0)&&((op[0][2]&&op[1][2])==0)&&((op[0][3]&&op[1][3])==0))
        {          
            if(op[0][0]==1)
            {    
                x1 = x1 +(Y1-y1)/m;
                y1=Y1;
            }
            if(op[0][1]==1)
            {
                x1 = x1 +(Y2-y1)/m;
                y1=Y2;
            }
            if(op[0][2]==1)
            {
                y1 = y1 + m*(X2-x1);
                x1=X2;
            }
            if(op[0][3]==1)
            {
                y1 = y1 + m*(X1-x1);
                x1= X1;
            } 
            if(op[1][3]==1)
            {
                y2 = y2 + m*(X1-x2);
                x2= X1;
            }
            if(op[1][2]==1)
            {
                y2 = y2 + m*(X2-x2);
                x2=X2;
            }
            if(op[1][0]==1)
            {
                x2 = x2 +(Y1-y2)/m;
                y2=Y1;
            }
            if(op[1][1]==1)
            {
                x2 = x2 +(Y2-y2)/m;
                y2=Y2;
            }    
        }
        else
        {
            x1=x2=y1=y2=0;
        }
    }
    outtextxy(100,100,"After Clipping:");
    rectangle(X1,Y1,X2,Y2);
    line(x1,y1,x2,y2);
    getch();
    closegraph();
    return 0;
}




------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;


class dda
{
	private:
		float x1,x2,y1,y2,dx,dy,xi,yi,xn,yn,length;
	public:
		void initialValues(float a,float b,float c,float d)
		{
			x1=a,y1=b,x2=c,y2=d;
			dx=x2-x1;
			dy=y2-y1;
			if(abs(dx)>=abs(dy))
				length=abs(dx);
			else
				length=abs(dy);
			xi=dx/length;
			yi=dy/length;
			xn=x1;
			yn=y1;
		}
		void drawLine()
		{
			for(int i=1; i<=length; i++)
			{
				putpixel(floor(xn),floor(yn),CYAN);
				xn = xn+xi;
				yn = yn+yi;
				delay(100);
			}
		}
};


class bressenham
{
	private:
		int xc,yc,r,xi,yi,pi;
	public:
		void initialValues(int a, int b, int c)
		{
			xc=a,yc=b,r=c;
			xi=0;
			yi=r;
			pi=3-(2*r);
		}
		void drawCircle()
		{
			while(xi<=yi)
			{
				putpixel(xc+xi,yc+yi, WHITE);
				putpixel(xc-xi,yc+yi, CYAN);
				putpixel(xc+xi,yc-yi, WHITE);
				putpixel(xc-xi,yc-yi, CYAN);
				putpixel(xc+yi,yc+xi, WHITE);
				putpixel(xc-yi,yc+xi, CYAN);
				putpixel(xc+yi,yc-xi, WHITE);
				putpixel(xc-yi,yc-xi, CYAN);
				xi++;
				if(pi<0)
				pi=pi+(4*xi)+6;
				else
				{
					yi--;
					pi=pi+(4*(xi-yi))+10;
				}
				delay(100);
			}
		}
};


int main()
{
	int gd=DETECT,gm;
	int xc,yc,r;
	cout<<"Enter center the x coordinate of circle's centre : ";
	cin>>xc;
	cout<<"Enter center the y coordinate of circle's centre : ";
	cin>>yc;
	cout<<"Enter the radius of the circle : ";
	cin>>r;
	bressenham b1,b2;
	dda line1,line2,line3;
	initgraph(&gd,&gm,NULL);
	b1.initialValues(xc,yc,r);
	b1.drawCircle();
	b2.initialValues(xc,yc,r/2);
	b2.drawCircle();
	line1.initialValues(xc,yc-r,xc+(r/1.154),yc+(r/2));
	line2.initialValues(xc,yc-r,xc-(r/1.154),yc+(r/2));
	line3.initialValues(xc+(r/1.154),yc+(r/2),xc-(r/1.154),yc+(r/2));
	line1.drawLine();
	line2.drawLine();
	line3.drawLine();
	getch();
	closegraph();
	return 0;
}
-----------------------------------------------------------------------------------------------------------------------
include <graphics.h>
#include <math.h>
#include <iostream>
//SPPU CG Group B:(7)
//Write  C++  program  to  draw  2-D  object  and 
//perform following basic transformations, Scaling b) 
//Translation c) Rotation. Apply the concept of 
//operator overloading. OR (b) Write C++ program to 
//implement translation, rotation and scaling 
//transformations on equilateral triangle and rhombus. 
//Apply the concept of operator overloading. 
using namespace std;
void display(int x1,int y1,int x2,int y2,int x3,int y3)
{
    int xmid = getmaxx()/2;
    int ymid = getmaxx()/2;
    line(xmid,0,xmid,getmaxy());
    line(0,ymid,getmaxx(),ymid);
    line(x1+xmid,y1+ymid,x2+xmid,y2+ymid);
    line(x2+xmid,y2+ymid,x3+xmid,y3+ymid);
    line(x1+xmid,y1+ymid,x3+xmid,y3+ymid);
}
void translate(int x1,int y1,int x2,int y2,int x3,int y3,int tx,int ty)
{
    outtextxy(100,100,"Before Translation:");
    display(x1,y1,x2,y2,x3,y3);
    delay(3000);
    cleardevice();
    outtextxy(100,100,"After Translation:");
    display(x1+tx,y1+ty,x2+tx,y2+ty,x3+tx,y3+ty);
}
void scale(int x1,int y1,int x2,int y2,int x3,int y3,float tx,float ty)
{
    outtextxy(100,100,"Before Scaling:");
    display(x1,y1,x2,y2,x3,y3);
    delay(3000);
    cleardevice();
    outtextxy(100,100,"After Scaling:");
    display(x1*tx,y1*ty,x2*tx,y2*ty,x3*tx,y3*ty);
}
void arotate(int x1,int y1,int x2,int y2,int x3,int y3,float a)
{
    a = a*(3.1415/180);
    float c = cos(a);
    float s = sin(a);
    outtextxy(100,100,"Before Rotation:");
    display(x1,y1,x2,y2,x3,y3);
    delay(3000);
    cleardevice();
    outtextxy(100,100,"After Rotation:");
    display((x1*c-y1*s),(x1*s+y1*c),(x2*c-y2*s),(x2*s+y2*c),(x3*c-y3*s),(x3*s+y3*c));
}
void crotate(int x1,int y1,int x2,int y2,int x3,int y3,float a)
{
    a = a*(3.1415/180);
    float c = cos(a);
    float s = sin(a);
    outtextxy(100,100,"Before Rotation:");
    display(x1,y1,x2,y2,x3,y3);
    delay(3000);
    cleardevice();
    outtextxy(100,100,"After Rotation:");
    display((x1*c+y1*s),(-x1*s+y1*c),(x2*c+y2*s),(-x2*s+y2*c),(x3*c+y3*s),(-x3*s+y3*c));


}
int main()
{
    int x1,y1,x2,y2,x3,y3;
    int gd = DETECT , gm;
    cout<<"Enter the coordinates of the Triangle : x1,y1,x2,y2,x3,y3:"<<endl;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    while(1)
    {
        int ch;
        cout<<"Enter|1-Translation|2-Scaling|3-AnticlockwiseR|4-ClockwiseR|0-EXIT:"<<endl;
        cin>>ch;
        if(ch==1)
        {
            int tx,ty;
            cout<<"Enter Tx and Ty:"<<endl;
            cin>>tx>>ty;
            initgraph(&gd,&gm,NULL);
            translate(x1,y1,x2,y2,x3,y3,tx,ty);
            getch();
            closegraph();
        }
        else if(ch==2)
        {
            float sx,sy;
            cout<<"Enter Sx and Sy:"<<endl;
            cin>>sx>>sy;
            initgraph(&gd,&gm,NULL);
            scale(x1,y1,x2,y2,x3,y3,sx,sy);
            getch();
            closegraph();
        }
        else if(ch==3)
        {
            float a;
            cout<<"Enter Angle:"<<endl;
            cin>>a;
            initgraph(&gd,&gm,NULL);
            arotate(x1,y1,x2,y2,x3,y3,a);
            getch();
            closegraph();
        }
        else if(ch==4)
        {
            float a;
            cout<<"Enter Angle:"<<endl;
            cin>>a;
            initgraph(&gd,&gm,NULL);
            crotate(x1,y1,x2,y2,x3,y3,a);
            getch();
            closegraph();
        }
        else if(ch==0)
        {
            cout<<"EXITED"<<endl;
            break;
        }
    }
    return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

using namespace std;

void move(int j,int h,int &x,int &y)
{
if(j==1)
y-=h;
else if(j==2)
x+=h;
else if(j==3)
y+=h;
else if(j==4)
x-=h;
lineto(x,y);
}

void hilbert(int r,int d,int l,int u,int i,int h,int &x,int &y)
{
if(i>0)
{
i--;
hilbert(d,r,u,l,i,h,x,y);
move(r,h,x,y);
hilbert(r,d,l,u,i,h,x,y);
move(d,h,x,y);
hilbert(r,d,l,u,i,h,x,y);
move(l,h,x,y);
hilbert(u,l,d,r,i,h,x,y);
}
}

int main()
{
int n,x1,y1;
int x0=50,y0=150,x,y,h=10,r=2,d=3,l=4,u=1;

cout<<"\nGive the value of n: ";
cin>>n;
x=x0;y=y0;
int gm,gd=DETECT;
initgraph(&gd,&gm,NULL);
moveto(x,y);
hilbert(r,d,l,u,n,h,x,y);
delay(10000);

closegraph();

return 0;
}
---------------------------------------------------------------------------
#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;
typedef float Matrix4 [4][4];
Matrix4 theMatrix;
static GLfloat input[8][3]=
{
 {40,40,-50},{90,40,-50},{90,90,-50},{40,90,-50},
 {30,30,0},{80,30,0},{80,80,0},{30,80,0}
};
float output[8][3];
float tx,ty,tz;
float sx,sy,sz;
float angle;
int choice,choiceRot;
void setIdentityM(Matrix4 m)
{
for(int i=0;i<4;i++)
 for(int j=0;j<4;j++)
 m[i][j]=(i==j);
}
void translate(int tx,int ty,int tz)
{
for(int i=0;i<8;i++)
{
output[i][0]=input[i][0]+tx;
output[i][1]=input[i][1]+ty;
output[i][2]=input[i][2]+tz;
}
}
void scale(int sx,int sy,int sz)
{
 theMatrix[0][0]=sx;
 theMatrix[1][1]=sy;
 theMatrix[2][2]=sz;
}
void RotateX(float angle) //Parallel to x
{
angle = angle*3.142/180;
 theMatrix[1][1] = cos(angle);
theMatrix[1][2] = -sin(angle);
theMatrix[2][1] = sin(angle);
theMatrix[2][2] = cos(angle);
}
void RotateY(float angle) //parallel to y
{
angle = angle*3.14/180;
theMatrix[0][0] = cos(angle);
theMatrix[0][2] = -sin(angle);
theMatrix[2][0] = sin(angle);
theMatrix[2][2] = cos(angle);
}
void RotateZ(float angle) //parallel to z
{
angle = angle*3.14/180;
theMatrix[0][0] = cos(angle);
theMatrix[0][1] = sin(angle);
theMatrix[1][0] = -sin(angle);
theMatrix[1][1] = cos(angle);
}
void multiplyM()
{
//We Don't require 4th row and column in scaling and rotation
//[8][3]=[8][3]*[3][3] //4th not used
for(int i=0;i<8;i++)
{
 for(int j=0;j<3;j++)
 {
 output[i][j]=0;
 for(int k=0;k<3;k++)
 {
 output[i][j]=output[i][j]+input[i][k]*theMatrix[k][j];
 }
 }
}
}
void Axes(void)
{
glColor3f (0.0, 0.0, 0.0); // Set the color to BLACK
glBegin(GL_LINES); // Plotting X-Axis
glVertex2s(-1000 ,0);
glVertex2s( 1000 ,0);
glEnd();
glBegin(GL_LINES); // Plotting Y-Axis
glVertex2s(0 ,-1000);
glVertex2s(0 , 1000);
glEnd();
}
void draw(float a[8][3])
{
 glBegin(GL_QUADS);
 glColor3f(0.7,0.4,0.5); //behind
 glVertex3fv(a[0]);
 glVertex3fv(a[1]);
 glVertex3fv(a[2]);
 glVertex3fv(a[3]);
 glColor3f(0.8,0.2,0.4); //bottom
 glVertex3fv(a[0]);
 glVertex3fv(a[1]);
 glVertex3fv(a[5]);
 glVertex3fv(a[4]);
 glColor3f(0.3,0.6,0.7); //left
 glVertex3fv(a[0]);
 glVertex3fv(a[4]);
 glVertex3fv(a[7]);
 glVertex3fv(a[3]);
 glColor3f(0.2,0.8,0.2); //right
glVertex3fv(a[1]);
glVertex3fv(a[2]);
glVertex3fv(a[6]);
glVertex3fv(a[5]);
glColor3f(0.7,0.7,0.2); //up
glVertex3fv(a[2]);
glVertex3fv(a[3]);
glVertex3fv(a[7]);
glVertex3fv(a[6]);
glColor3f(1.0,0.1,0.1);
glVertex3fv(a[4]);
glVertex3fv(a[5]);
glVertex3fv(a[6]);
glVertex3fv(a[7]);
glEnd();
}
void init()
{
 glClearColor(1.0,1.0,1.0,1.0); //set backgrond color to white
 glOrtho(-454.0,454.0,-250.0,250.0,-250.0,250.0);
 // Set the no. of Co-ordinates along X & Y axes and their gappings
 glEnable(GL_DEPTH_TEST);
 // To Render the surfaces Properly according to their depths
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
Axes();
glColor3f(1.0,0.0,0.0);
draw(input);
setIdentityM(theMatrix);
switch(choice)
{
case 1:
 translate(tx,ty,tz);
 break;
case 2:
 scale(sx,sy,sz);
multiplyM();
 break;
case 3:
 switch (choiceRot) {
 case 1:
 RotateX(angle);
 break;
 case 2: RotateY(angle);
 break;
 case 3:
 RotateZ(angle);
 break;
 default:
 break;
 }
multiplyM();
 break;
}
--------------------------------------------------------------------------------------------------------------------------------
#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
using namespace std;
class walkingman
{
int rhx,rhy;
public:
void draw(int,int);
void draw(int);
};
void walkingman::draw(int i)
{
line(20,380,580,380);
if(i%2)
{
line(25+i,380,35+i,340);
line(45+i,380,35+i,340);
line(35+i,310,25+i,330);
delay(20);
}
else
{
line(35+i,340,35+i,310);
line(35+i,310,40+i,330);
delay(20);
}
line(35+i,340,35+i,310);
circle(35+i,300,10);
line(35+i,310,50+i,330);
line(50+i,330,50+i,280);
line(15+i,280,85+i,280);
arc(50+i,280,0,180,35);
arc(55+i,330,180,360,5);
}
void walkingman::draw(int x,int y)
{
int j;
rhx=x;
rhy=y;
for
(j=0;j<100;j++)
{
outtextxy(rand()%rhx,rand()%(rhy-50),"|");
setcolor(WHITE);
}
}
int main()
{
int gd=DETECT,gm;
int rhx,rhy,j,i;
walkingman obj;
initgraph(&gd,&gm,"");
for(i=0;i<500;i++)
{
obj.draw(i);
rhx=getmaxx();
rhy=getmaxy();
obj.draw(rhx,rhy);
delay(150);
cleardevice();
}
getch();
}
---------------------------------------------------------------------------------------------------------------------
#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Default Constructor
    Complex() : real(0), imag(0) {}

    // Parameterized Constructor
    Complex(double r, double i) : real(r), imag(i) {}

    // Overload operator+ to add two complex numbers
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload operator* to multiply two complex numbers
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // Overload operator<< to print a complex number
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
        return os;
    }

    // Overload operator>> to read a complex number
    friend std::istream& operator>>(std::istream& is, Complex& c) {
        std::cout << "Enter real part: ";
        is >> c.real;
        std::cout << "Enter imaginary part: ";
        is >> c.imag;
        return is;
    }
};

int main() {
    Complex c1, c2;

    std::cout << "Enter first complex number:\n";
    std::cin >> c1;

    std::cout << "Enter second complex number:\n";
    std::cin >> c2;

    Complex sum = c1 + c2;
    Complex product = c1 * c2;

    std::cout << "Sum: " << sum << "\n";
    std::cout << "Product: " << product << "\n";

    return 0;
}
