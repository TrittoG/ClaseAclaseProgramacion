int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit);
int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);




int importeGastado(Contratacion* arrayC,int limite, Pantalla* arrayP, int limitePantallas, int importe, char *cuit);
int informar_ClientesGastadoContrataciones(Contratacion* arrayC,int cantidad_cont ,Pantalla* ArrayP, int cantidad_de_elementos);
int ListarPantallasInferiorAMil(Pantalla *ArrayP, int cantidad_pantalla);
int informar_ListadoPantallas(Pantalla* ArrayP, int cantPantalla);
float PromedioPrecios(Pantalla *arrayP, int cantidad_pantalla);



