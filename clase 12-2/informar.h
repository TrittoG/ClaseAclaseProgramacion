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
int mostrarPantallasNoSuperanPromedio(Pantalla *arrayP, int cantidad_pantalla);

float promedioDias(Contratacion *arrayC, int cantidad_contratacion);
int listarPantallasSuperanDiasContratacion(Pantalla *arrayP, int cantidad_pantalla, Contratacion *arrayC, int cantidad_contratacion);
int mostrarPantallasSiSuperanPromedio(Pantalla *arrayP, int cantidad_pantalla);


int contadorPublicaciones(Contratacion *arrayC, int cantidad_contratacion, int idpantalla);

int mostrarPantallasMasDeUnaPublicacion(Pantalla *arrayP, int cantidad_pantalla, Contratacion *arrayC, int cantidad_contratacion);

int listarPantallasIndicandoFacturacion(Pantalla *arrayP, int cant_pantalla, Contratacion *arrayC, int cant_contratacion);


int informar_pantallaQueMasFactura(Pantalla *ArrayP, int cant_pantalla, Contratacion *ArrayC, int cant_contratacion);



