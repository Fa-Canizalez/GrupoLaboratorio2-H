
#include <iostream>
#include <string>


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
Nodo *fin = nullptr;    // Puntero al ultimo nodo

// Declaracion de funciones
void InsertarInicio(Producto producto);
void BorrarInicio();
Producto SolicitarDatos();
void MostrarLista();


//Somos el grupo que trabajo mal , y hicimos el commit tarde porque no me dejaron subirlo antes 

int main()
{
    Producto producto;

    int opcion;

    do
    {
        std::cout<< "==INVENTARIO==" << std::endl;
        std::cout << "1. Agregar producto" << std::endl;
        std::cout << "2. Eliminar producto" << std::endl;
        std::cout << "3. Mostrar inventario" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout <<"Por favor, ingrese una opcion";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
                SolicitarDatos;
                InsertarInicio(producto);
            break;
        case 2:
                BorrarInicio();
            break;
        case 3:
                MostrarLista();    
            break;
        case 4:
            std::cout << "Saliendo del programa" << std::endl;
            return 0;
            break;
        
        default:

        std::cout << "Opcion invalida, por favor intentelo de nuevo" << std::endl;
            break;
        }


    } while (opcion != 4);
    

    return 0;
}


void InsertarInicio(Producto producto)
{
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->producto = producto;
    nuevo_nodo->siguiente = inicio;
    nuevo_nodo->anterior = nullptr;

   
    if (inicio != nullptr)
    {
        inicio->anterior = nuevo_nodo;
    }
    else
    {
       
        fin = nuevo_nodo;
    }

    
    inicio = nuevo_nodo;
}

// Funcion para borrar el primer nodo
void BorrarInicio()
{
    if (inicio == nullptr)
    {
        std::cout << "Inventario vacio. "
                  << "No se encontraron productos para eliminar.\n";
        return;
    }

    // Guardamos el nodo que vamos a eliminar
    Nodo *actual = inicio;

    // Movemos inicio al siguiente nodo
    inicio = inicio->siguiente;

    // Si quedan elementos
    if (inicio != nullptr)
    {
        inicio->anterior = nullptr;
    }
    else
    {
        // Si la lista quedo vacia,
        // fin tambien debe ser nullptr
        fin = nullptr;
    }

    // Liberamos la memoria
    delete actual;

    std::cout << "Producto eliminado correctamente.\n";
}

// Funcion para solicitar los datos
Producto SolicitarDatos()
{
    Producto nuevo;

    std::cout << "\n--- Registrar producto ---\n\n";

    std::cout << "Nombre del producto: ";
    std::getline(std::cin >> std::ws, nuevo.nombre_producto);

    std::cout << "Precio: ";
    std::cin >> nuevo.precio;

    std::cout << "Codigo del producto: ";
    std::cin >> nuevo.codigo_producto;

    return nuevo;
}

// Funcion para mostrar la lista
void MostrarLista()
{
    if (inicio == nullptr)
    {
        std::cout << "El inventario esta vacio.\n";
        return;
    }

    Nodo *actual = inicio;

    while (actual != nullptr)
    {
        std::cout << "\nCodigo: "
                  << actual->producto.codigo_producto << std::endl;

        std::cout << "Nombre: "
                  << actual->producto.nombre_producto << std::endl;

        std::cout << "Precio: $"
                  << actual->producto.precio << std::endl;

        std::cout << "-------------------------\n";

        actual = actual->siguiente;
    }
}

