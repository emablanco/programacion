#include<iostream>
using namespace std;

class FooClass
{
	int x, y, z;
	public:
	FooClass(int, int, int); //Constructor parametrizado 
	FooClass(const FooClass&);  //Constructor de copia
	void printVars();
};

FooClass::FooClass(int a = 1, int b = 2, int c = 3):x(a), y(b), z(c){}

FooClass::FooClass(const FooClass& obj):x(obj.x), y(obj.y), z(obj.z){}

void FooClass::printVars()
{
	cout<<"x: "<<x<<", y: "<<y<<", z: "<<z<<endl;
}

int main()
{
	FooClass fooObj1 = {111,222,333}; //Utilizando el operador de asignación
	fooObj1.printVars();
	FooClass fooObj2 = fooObj1; //Utilizando el operador de asignación
	fooObj2.printVars();
	return 0;
}

