/**
Dato importante: Cuando no se declara un constructor por defecto para una clase y en cambio sí se han declarado otros constructores (o por lo menos otro), entonces el compilador de C++ NO declarará de manera implícita ningún constructor por defecto.



 **/

class FooClass
{
	int x, y, z;
	public:
	FooClass(int, int, int); //Declaración constructor parametrizado 	
};

int main()
{
	FooClass fooObj1(111,222,333); // ¡Bien!
	FooClass fooObj2 = {111,222,333}; // ¡También está bien en este caso!
	FooClass fooObj3 ; // ¡Error, C++ ya no declara un constructor por defecto implícito!
	FooClass fooObj4(fooObj2); // ¡Bien, C++ si declara un constructor de copia implícito!
	FooClass fooObj5 = fooObj4; // ¡Está bien en este caso (C++ si declara un constructor de copia implícito)!
	return 0;
}
