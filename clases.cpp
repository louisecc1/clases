#include<iostream>
using namespace std;
class matrix{
  public:
  int c[3][3]={{1,2,3},{3,2,1},{1,2,3}};
};
class calculadora{
  public:
  int imprimir(matrix &a, int m, int n,int h,int r){
    if(r==m){
      return 0;
    }
    cout<<*(a.c[r]+h);
    if ((h+1)%n==0){
      ++r;
    cout<<"\n";
    return imprimir(a,m,n,0,r);
    }
  return imprimir(a,m,n,++h,r);
}
int mayor(matrix &a,matrix &b,matrix &c,int n,int m,int i,int j){
  if(i==n){
    return imprimir(c,n,m,0,0);
  }
  *(c.c[i]+j)=*(a.c[i]+j);
  if(*(a.c[i]+j)<*(b.c[i]+j)){
  *(c.c[i]+j)=*(b.c[i]+j);
  }
  if((j+1)%m==0){
    ++i;
    return mayor(a,b,c,n,m,i,0);
  }
  return mayor(a,b,c,n,m,i,++j);
}
int menor(matrix &a,matrix &b,matrix &c,int n,int m,int i,int j){
  if(i==n){
    return imprimir(c,n,m,0,0);
  }
  *(c.c[i]+j)=*(a.c[i]+j);
  if(*(a.c[i]+j)>*(b.c[i]+j)){
  *(c.c[i]+j)=*(b.c[i]+j);
  }
  if((j+1)%m==0){
    ++i;
    return menor(a,b,c,n,m,i,0);
  }
  return menor(a,b,c,n,m,i,++j);
}
int promedio(matrix &a,matrix &b,matrix &c,int n,int m,int i,int j){
  if(i==n){
    return imprimir(c,n,m,0,0);
  }
  *(c.c[i]+j)=(*(a.c[i]+j)+*(b.c[i]+j))/2;
  if((j+1)%m==0){
    ++i;
    return promedio(a,b,c,n,m,i,0);
  }
  return promedio(a,b,c,n,m,i,++j);
}
int suma(matrix &a,matrix &b,matrix &c,int n,int m,int i,int j){
  if(i==n){
    return imprimir(c,n,m,0,0);
  }
  *(c.c[i]+j)=*(a.c[i]+j)+*(b.c[i]+j);
  if((j+1)%m==0){
    ++i;
    return suma(a,b,c,n,m,i,0);
  }
  return suma(a,b,c,n,m,i,++j);
}
int resta(matrix &a,matrix &b,matrix &c,int n,int m,int i,int j){
  if(i==n){
    return imprimir(c,n,m,0,0);
  }
  *(c.c[i]+j)=*(a.c[i]+j)-*(b.c[i]+j);
  if((j+1)%m==0){
    ++i;
    return resta(a,b,c,n,m,i,0);
  }
  return resta(a,b,c,n,m,i,++j);
}
int multi(matrix a1,matrix b1,int n,int m, int b,int r,int h,int g,int t,int j){
  g=g+(*(a1.c[r]+h))*(*(b1.c[h]+j));
  if(t==n-1){
    return g;
  }
  multi(a1,b1,n,m,b,r,++h,g,++t,j);
}
int multi1(matrix &a1,matrix &b1,matrix &c1,int n,int m, int a, int b,int r,int h){
    if(m!=a){
      cout<<"No se puede realizar la operacion";
      return 0;
    }
    if(r==n){
      return 0;
    }
    *(c1.c[r]+h)=multi(a1,b1,n,m,b,r,0,0,0,h);
    if((h+1)%b==0){
      ++r;
      multi1(a1,b1,c1,n,m,a,b,r,0);
    }
    return multi1(a1,b1,c1,n,m,a,b,r,++h);
}
};
int main(){
  int s;
  matrix a,b,c;
  calculadora h;
  h.resta(a,b,c,3,3,0,0);
  h.suma(a,b,c,3,3,0,0);
  s=h.multi1(a,b,c,3,3,3,3,0,0);
  if (s==0){
    h.imprimir(c,3,3,0,0);
  }
  return 0;
}
