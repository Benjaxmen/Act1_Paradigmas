#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;
class estudiantes{
  public:
    string name;
    float n1,n2,n3,n4,nf;
    estudiantes *next;
    void set_estudiantes(string nombre, float nota1,float nota2, float nota3, float nota4){
      n1=nota1;
      n2=nota2;
      n3=nota3;
      n4=nota4;
      nf=(n1+n2+n3+n4)/4;
      name=" ";
      int l=nombre.length();
      for (int m=0;m<l;m++)
        name=name+nombre[m];
    }
};
int main() {
  string archivo1="archivo1.txt";
  ifstream archivo(archivo1.c_str());
  string linea,nomb,n1,n2,n3,n4;
  int res,lon,i,j=0,k=0;
  char b,l;
  estudiantes arreglo[100];
    while (getline(archivo,linea)) {
        lon = linea.length();
        for (i=0;i<lon;i++){
            l=linea[i];
            b=' ';
            if (l!=b){
                if (j==0){
                  if(i==0){
                    nomb=linea[i];
                    continue;
                  }
                  nomb=nomb+linea[i];
                }
                if (j==1)
                    n1=n1+linea[i];
                if (j==2)
                    n2=n2+linea[i];
                if (j==3)
                    n3=n3+linea[i];
                if (j==4)
                    n4=n4+linea[i];    
            }
            else
                j++;
        }
      
     
      arreglo[k].set_estudiantes(nomb,stof(n1),stof(n2),stof(n3),stof(n4)); 
      k++;
      j=0;
      n1=" ";
      n2=" ";
      n3=" ";
      n4=" ";
      }
  for(int p=0;p<k;p++){
  cout<<arreglo[p].name<<endl;
  cout<<arreglo[p].n1<<" ";
  cout<<arreglo[p].n2<<" ";
  cout<<arreglo[p].n3<<" ";
  cout<<arreglo[p].n4<<endl;
  cout<<"Nota final: "<< arreglo[p].nf<<endl;
    }
  }
