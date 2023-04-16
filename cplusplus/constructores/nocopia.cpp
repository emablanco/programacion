 class FooClass
{
	int x, y, z; 
	public:
	FooClass() = delete; //Se prohibe la utilización del constructor por defecto
	FooClass(int, int, int); //Único constructor que se puede utilizar
	FooClass(const FooClass&) = delete;  //Se prohibe la utilización del constructor por copia
	void printVars();
};

int main()
{
	FooClass obj1; // ¡Error, constructor por defecto deshabilitado!
	FooClass obj2(1,2,3); // ¡Bien, sin problema!
	FooClass obj3(obj2); // ¡Error, constructor de copia deshabilitado!
}
