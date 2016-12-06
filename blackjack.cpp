#include<iostream>
#include<limits.h>
#include<vector>
#include<fstream>
#include <stdio.h>  
#include <stdlib.h> 

using namespace std;

int a [] = {4,5,6,7,8, 9,10,11,12,13, 14,15,16,17,18, 19,20, 12,13,14,15,16, 17,18,19,20,21, 22};
bool soft[35];
double p;

double q[28][28];

int gh(int x,bool y){

if(x==21){return 26;}
if(x==22){return 27;}

if(y){return x+5;}
else{return x-4;}
}


int newhand(int x,bool y,int new1)
{
int x1  = x+new1;bool y1 = y;
if(new1==1){y1=true;x1= x+11;}

if(x1>21 && y1){x1-=10;
if(y && new1==1){}else {y1=false;}
}
if(x1>21){x1=22;y1 = false;}

return gh(x1,y1);
}



void calculate(){


for(int i = 0;i<28 ;++i){

if((a[i]>=17 && a[i]<=21 && (!soft[i])) || (a[i]>=17 && a[i]<=21 && soft[i]) || (a[i]==22))
{
for(int j=0;j<28;++j){q[i][j] = 0;}

q[i][i] = 1;continue;
}

for(int j=0;j<28;++j){q[i][j] = 0;}

for(int k = 1;k<=10;++k){
int t = newhand(a[i],soft[i],k);

if(k==10){q[i][t] = q[i][t] + p;}
else{q[i][t] = q[i][t] + ((1.0-p)/9.0);}

}


}







double q1[28][28];
double q2[28][28];
int x5 = 25;
for(int i = 0;i<28;++i){

for(int k = 0;k<28;++k){
q2[i][k] = q[i][k];
}}


while(x5>0 ){



for(int i = 0;i<28;++i){

for(int k = 0;k<28;++k){
q1[i][k] = 0;
}}

for(int i = 0;i<28;++i){

for(int k = 0;k<28;++k){
for(int j = 0;j<28;++j){
q1[i][k]+=q2[i][j]*q[j][k];
}

}

}




for(int i = 0;i<28;++i){

for(int k = 0;k<28;++k){
q2[i][k] = q1[i][k];

}}




--x5;
}



for(int i = 0;i<28;++i){

for(int k = 0;k<28;++k){
q[i][k] = q1[i][k];

}}








}







void dealer(double* init,double* final1){






//cout << "a1";

for(int i = 0;i<28;++i){


for(int j = 0;j<28;++j){
final1[i]+=init[j]*q[j][i];
}



}





}

void dealermain(int up,double *b)
{
double* x= new double[28];
for(int i = 0;i<28;++i){
x[i] = 0;
}



for(int i = 1;i<=10;++i){
int t= 0;double p1 = p;if(i!=10){p1 = (1.0-p)/9;}
if(up==1){t = gh(i+11,true);}
else{t = newhand(up,false,i);}

x[t] = x[t]+p1;
//if(a[t]==21){x[t] = 0;}

}



dealer(x,b);




//delete(x);


}


double lose(int c ,int k,bool bj = false){

if(a[c]==22){return 1.0;}
double ans = 0.0;
double *b = new double[28];
for(int i = 0;i<28;++i){b[i]  = 0;}
dealermain(k,b);

for(int i = 0;i<28;++i){
if(a[i]>a[c] && a[i]!=22){
ans+=b[i];

}




}

if(a[c]==21 && !bj){
if(k==1){ans+=p;}
else if(k==10){ans+=(1.0-p)/9;}


}



return ans;
}


double win(int c ,int k,bool bj = false){

if(a[c]==22){return 0.0;}

double ans = 0.0;
double *b = new double[28];
for(int i = 0;i<28;++i){b[i]  = 0;}
dealermain(k,b);

for(int i = 0;i<28;++i){
if(a[i]<a[c] || a[i]==22){ans+=b[i];}

}

if(bj){
ans = 1.500;
if(k==1){
ans = ans-=(1.5*p);

}

if(k==10){
ans = ans-=(1.5*((1.0-p)/9.0));

}



}

return ans;
}




int main(int argc, char *argv[]){



p  = atof(argv[1]);


for(int i =0;i<28;++i){

if(i<17){soft[i] = false;}
else{soft[i] = true;}
}
soft[26] = soft[27]  = false;



for(int i =0;i<28;++i){

for(int j =0;j<28;++j){
q[i][j] = 0.0;

}}

calculate();



/*for(int k  =1;k<11;++k){
double *b = new double[28];

for(int i = 0;i<28;++i){b[i]  = 0;}

dealermain(k,b);

cout << k << " ";
for(int i =0;i< 28 ;++i){
cout << b[i] << " ";
}
cout << endl;
delete(b);
}
*/



/*cout << endl;
for(int i  =0 ;i< 28;++i){
cout << i << " --  ";

for(int k = 1;k<=10;++k){
int t =  newhand(a[i],soft[i],k);
cout << t << " ";

}

cout << "\n";
}



*/
//return 0;
double trans[28][28];

int order[] = {27,26,16,15,14,13,12,11,10,9,8,7,6,25,24,23,22,21,20,19,18,17,5,4,3,2,1,0};

double s_win[29][10];
double s_lose[29][10];
double c_win[29][10];
double c_lose[29][10];

int strat[29][10];


for(int i = 0;i<28;++i){for(int j = 0;j<28;++j){trans[i][j] = 0;}}
for(int i = 0;i<29;++i){for(int j = 0;j<10;++j){s_win[i][j] = s_lose[i][j] = 0;c_win[i][j] = 0;c_lose[i][j] = 0;strat[i][j] = 0;}}


for(int i  =0 ;i< 28;++i){

for(int k = 1;k<=10;++k){

s_win[i][k-1] = win(i,k);
s_lose[i][k-1] = lose(i,k);



}


}


for(int k = 1;k<=10;++k){

c_win[28][k-1] = s_win[28][k-1] = win(21,k,true);
c_lose[28][k-1] = s_lose[28][k-1] = lose(21,k,true);



}




for(int k = 1;k<=10;++k){c_win[27][k-1] = 0;c_lose[27][k-1] = 1;}
int check[28];for(int f  =0 ;f< 28;++f){check[f]=0;}
check[27] = 1;



for(int f  =1 ;f< 28;++f){
int i = order[f];
for(int k = 1;k<=10;++k){


for(int j = 1;j<=10;++j){
double p1 = p;
if(j!=10){p1 = (1.0-p)/9;}

c_win[i][k-1]+=p1*c_win[newhand(a[i],soft[i],j)][k-1];
c_lose[i][k-1]+=p1*c_lose[newhand(a[i],soft[i],j)][k-1];
}

if((c_win[i][k-1]-c_lose[i][k-1]) < (s_win[i][k-1]-s_lose[i][k-1])){
c_win[i][k-1] = s_win[i][k-1];
c_lose[i][k-1] = s_lose[i][k-1];
}
else{
strat[i][k-1]  =1;

}
check[i] = 1;
}


}

//}

//cout << "a1";


for(int i = 0;i<28;++i){
if(a[i]==22){trans[i][i]  =1;}
else
{

for(int k = 1;k<=10;++k){
double p1 = p;if(k!=10){p1  = (1.0-p)/9;}
int t =newhand(a[i],soft[i],k);


trans[i][t] += p1;

}

	

}}










/*
for(int i = 0;i<28;++i){



for(int k = 1;k<=10;++k){

double hit_adv  = 0.0;
for(int j = 0;j<28;++j){
hit_adv+=trans[i][j]*(c_win[j][k-1]-c_lose[j][k-1]);

}


if((s_win[i][k-1]-s_lose[i][k-1]) > hit_adv)
{strat[i][k-1]  =0;}
else{strat[i][k-1]  =1;}


}



}
*/








for(int i = 0;i<28;++i){


for(int j = 1;j<=10;++j){
double x1 = 0;
double x2 = 0;
for(int k = 1;k<=10;++k){
double p1 = p;if(k!=10){p1 = (1.0-p)/9.0;}
x1+= p1*(s_win[newhand(a[i],soft[i],k)][j-1]);
x2+=p1*(s_lose[newhand(a[i],soft[i],k)][j-1]);
}
	
x1*=2;x2*=2;
if(x1-x2 >= (c_win[i][j-1]-c_lose[i][j-1])){strat[i][j-1] = 2;c_win[i][j-1] = x1;c_lose[i][j-1] = x2;}



}


}

double p_win[10][10];
double p_lose[10][10];
int stpair[10][10];
for(int i = 1;i<=10;++i){
for(int j = 1;j<=10;++j){
p_win[i][j] = p_lose[i][j] = 0;stpair[i][j]=0;
}
}



for(int i = 2;i<=10;++i){

int t= gh(2*i,false);
for(int j = 1;j<=10;++j){
double x1 = 0;
double x2 = 0;



for(int k = 1;k<=10;++k){

if(k==i){continue;}
double p1 = p;if(k!=10){p1 = (1.0-p)/9.0;}

if(k==1 && i == 10){
x1+= p1*(c_win[28][j-1]);
x2+=p1*(c_lose[28][j-1]);

continue;
}


x1+= p1*(c_win[newhand(i,false,k)][j-1]);
x2+=p1*(c_lose[newhand(i,false,k)][j-1]);



}
	
x1*=2;x2*=2;
double p1 = p;if(i!=10){p1 = (1.0-p)/9.0;}

if((x1-x2)/(1.0-2*p1) >= (c_win[t][j-1]-c_lose[t][j-1])){stpair[i][j-1] = 1;}






}


}




for(int i = 1;i<=1;++i)
{
int t= gh(12,true);
for(int j = 1;j<=10;++j){
double x1 = 0;
double x2 = 0;



for(int k = 1;k<=10;++k){
double p1 = p;if(k!=10){p1 = (1.0-p)/9.0;}


if(k==1){

x1+=p1*(s_win[t][j-1]);
x2+=p1*(s_lose[t][j-1]);
continue;
}

if(k==10){
x1+=p1*(s_win[28][j-1]);
x2+=p1*(s_lose[28][j-1]);
continue;
}




x1+=p1*(s_win[newhand(11,true,k)][j-1]);
x2+=p1*(s_lose[newhand(11,true,k)][j-1]);



}
	
x1*=2;x2*=2;


double p1 = p;if(i!=10){p1 = (1.0-p)/9.0;}



if((x1-x2)/1 > (c_win[t][j-1]-c_lose[t][j-1])){stpair[i][j-1] = 1;}








}


}







for(int i = 1;i<28;++i){

if(i==16){continue;}
if(i==17){continue;}
if(i==26){continue;}
if(i==27){continue;}




if(soft[i]){cout << "A" << a[i]-11;}
else{cout << a[i];}

cout << "\t";
for(int k = 2;k<=10;++k){

if(strat[i][k-1]==0){cout << "S ";}
if(strat[i][k-1]==1){cout << "H ";}
if(strat[i][k-1]==2){cout << "D ";}

}

for(int k = 1;k<=1;++k){

if(strat[i][k-1]==0){cout << "S";}
if(strat[i][k-1]==1){cout << "H";}
if(strat[i][k-1]==2){cout << "D";}

}


cout << endl;

}



for(int i = 2;i<=10;++i){

cout << i<<i;

cout << "\t";
for(int k = 2;k<=10;++k){

if(stpair[i][k-1]==0){int t =gh(2*i,false);
if(strat[t][k-1]==0){cout << "S ";}
if(strat[t][k-1]==1){cout << "H ";}
if(strat[t][k-1]==2){cout << "D ";}

}
else{cout << "P ";}

}


for(int k = 1;k<=1;++k){

if(stpair[i][k-1]==0){int t =gh(2*i,false);
if(strat[t][k-1]==0){cout << "S";}
if(strat[t][k-1]==1){cout << "H";}
if(strat[t][k-1]==2){cout << "D";}

}
else{cout << "P";}

}

cout << endl;

}


for(int i = 1;i<=1;++i){

cout << "A"<<"A";

cout << "\t";
for(int k = 2;k<=10;++k){

if(stpair[i][k-1]==0){int t =gh(12,true);
if(strat[t][k-1]==0){cout << "S ";}
if(strat[t][k-1]==1){cout << "H ";}
if(strat[t][k-1]==2){cout << "D ";}

}
else{cout << "P ";}

}


for(int k = 1;k<=1;++k){

if(stpair[i][k-1]==0){int t =gh(12,true);
if(strat[t][k-1]==0){cout << "S";}
if(strat[t][k-1]==1){cout << "H";}
if(strat[t][k-1]==2){cout << "D";}

}
else{cout << "P";}

}


}


return 0;

}

