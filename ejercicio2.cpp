//ejercicio 2
#include <iostream>
#include <string>
using namespace std;
int hallar_cantidad(int numero, int indice){
	 numero=numero/10;
	 if (numero==0)return indice;
	 indice++;
	 hallar_cantidad(numero,indice);
	 
}
int pot(int a , int b){
	for (int i=0;i>a-1;i++){
		b*=b;
	}	
	return b;	
}
string nivel1(int numero)//0-99
	{
	string resultado=" ";
	string u[21]={"cero","uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve","diez","once","doce",
	"trece","catorce","quince","dieciseis","diesciete","diesciocho","diescinueve","veinte"};
	string d[8]={"veinti","treinta","cuarenta ","cincuenta ","sesenta ","setenta ","ochenta ","noventa "};
	if (numero<=20){
		return u[numero];	
	}
	int det=10;
	resultado+=d[(numero/det)-2];
	if (numero%det>0) resultado=resultado+" y "+u[numero%det];
	return resultado;	
	}
string nivel2(int numero)//'100-999
	{
	if(numero<100)return nivel1(numero);
	if(numero==100) return "cien";
	string resultado=" ";
	string u[9]={"ciento","doscientos","trescientos","cuatrocientos","quinientos","seicientos","setecientos","ochocientos","novecientos"};
	int det=100;
	resultado+=u[((numero/det)-1)];
	if (numero%det>0) resultado+=" "+nivel1(numero%det);
	return resultado;
	}
string nivel3(int numero)//1000-999 999
	{
	if (numero<1000)return nivel2(numero);
	int cantidad=hallar_cantidad(numero,0);
	string resultado=" ";	
	int n1=numero/1000;
	int n2=numero%1000;
	if(cantidad==5){
		resultado=nivel2(n1)+" mil "+nivel2(n2); 
	}else{
		if(n1==1){
			resultado=+" mil "+nivel2(n2);
		}else{
			resultado=nivel1(n1)+" mil "+nivel2(n2);
		}
	}
	return resultado;
	}
string nivel4(int numero)//1 000 000-999 999 999
	{
		int cantidad=hallar_cantidad(numero,0);
		string resultado=" ";	
		int n1=numero/1000000;
		int n2=numero%1000000;
		if(cantidad==8){
			resultado=nivel2(n1)+" millones "+nivel3(n2); 
		}else{
			if(n1==1){
				resultado="un millon "+nivel3(n2);
			}else{
				resultado=nivel1(n1)+" millones "+nivel3(n2);
			}
		}
		return resultado;
	}
int main ()
{
	int n;
	string res;
	cin>>n;
	if (n<0){
		cout<<"no se lee numeros negativos";
	}else if(n<100 and n>0){
		res=nivel1(n);
	}else if(n>=100 and n<1000){
		res=nivel2(n);
	}else if(n>=1000 and n<1000000){
		res=nivel3(n);
	}else if(n>=1000000 and n<1000000000){
		res=nivel4(n);
	}
	cout<<"SE LEE::"<<res<<"\n";
	return 0;
}
