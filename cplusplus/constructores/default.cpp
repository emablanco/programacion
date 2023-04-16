#include<iostream>
using namespace std;

class FooClass
{
	int x = 1, y = 2, z = 3; //Valores asignados a las variables en la declaración
	public:
	FooClass() = default; //Obligando al constructor a tomar los valores de la declaración de las variables
	FooClass(const FooClass&) = default;  //Se va a utilizar el constructor por copia que implementa el compilador
	void printVars();
};

// ¡No hay definición del constructor!

void FooClass::printVars()
{
	cout<<"x: "<<x<<", y: "<<y<<", z: "<<z<<endl;
}

int main()
{
	FooClass fooObj1;
	fooObj1.printVars();
	return 0;
}
