class FooClass
{
	int x, y, z;
	public:
	explicit FooClass(int, int, int); //Constructor parametrizado explícito
	explicit FooClass(const FooClass&);  //Constructor de copia explícito
	void printVars();
};

int main()
{
	FooClass fooObj1 = {111,222,333}; // ¡Error, el constructor se declaro explícito!
	FooClass fooObj2(111,222,333); // ¡Bien, así está declarado el constructor!
	FooClass fooObj3 = fooObj2; // ¡Error, el constructor se declaro explícito!
	FooClass fooObj4(fooObj2); // ¡Bien, así está declarado el constructor!
	return 0;
}
