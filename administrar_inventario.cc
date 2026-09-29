#include <iostream>

//Struct para administrar el inventario
struct Producto
{
    int codigo_producto;
    std::string nombre_producto;
    float precio;
};

struct Nodo
{
    Producto producto;
    Nodo *siguiente;
    Nodo *anterior;
};

// Variables globales

Nodo *inicio = nullptr; // Puntero al primer nodo
Nodo *fin = nullptr;    // Puntero al último nodo

//Declaracion de funciones
void BorrarInicio(Producto producto);
Producto SolicitarDatos();

int main ()
{

    return 0;
}


void BorrarInicio(Producto producto)
{
    if (inicio == nullptr)
    {
        std::cout << "Inventario vacio. No se encontraron productos para eliminar.\n";
        return;
    }

    Nodo *actual = inicio;
    inicio = (inicio)->siguiente;

    if (inicio != nullptr)
    {
        (inicio)->anterior = nullptr;
    }

    delete actual;
}

Producto SolicitarDatos()
{
    Producto nuevo;

    std::cout << "\n\n ---Registrar producto--- \n\n";
    std::cout << "Nombre del producto: ";
    std::cin >> nuevo.nombre_producto;
    std::cout << "\nPrecio: ";
    std::cin >> nuevo.precio;
    std::cout << "\nCodigo del producto: ";
    std::cin >> nuevo.codigo_producto;
}

