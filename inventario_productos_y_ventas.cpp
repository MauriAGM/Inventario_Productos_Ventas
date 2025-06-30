/*Objetivo: Desarrollar un programa que permita registrar, listar, buscar, actualizar y eliminar productos, así como gestionar
las ventas.
Requisitos:
• Define una estructura Producto con los campos: nombre (cadena), precio (flotante).
• Define una estructura Venta con los campos: idVenta (entero), producto (cadena), cantidad (entero), precioTotal (flotante).
• Implementa un menú con las siguientes opciones:
    A: Registrar un nuevo producto.
    B: Listar los productos registrados.
    C: Buscar un producto por nombre.
    D: Actualizar los datos de un producto.
    E: Eliminar un producto.
    F: Registrar una venta.
    G: Listar las ventas realizadas.
    H: Calcular el total de ventas realizadas.
    S: Salir del programa.
• El menú debe estar ciclado y permitir volver al menú principal después de cada opción.*/

#include <iostream>
using namespace std;

const int MAX_P = 200;
const int MAX_V = 100;
struct Producto
{
    string nombre;
    float precio;
};

struct Venta
{
    int IdVenta;
    string producto;
    int cantidad;
    float precioTotal;
};
Producto productos[MAX_P];
Venta ventas[MAX_V];
int totalProductos = 0;
int totalV = 0;
int IdVENTA = 1;

void RegistrarProducto (){
    cout << "Nombre del producto: ";
    getline(cin,productos[totalProductos].nombre);
    cout << "Precio del producto: ";
    cin >> productos[totalProductos].precio;
    totalProductos++;
}

void ListaProducto (){
    for (int i = 0; i < totalProductos; i++){
        cout << productos[i].nombre << " -> " << productos[i].precio << endl;
    }   
}
void BuscarProducto (){
    string nombre;
    cout << "Ingrese el nombre del producto: ";
    getline(cin, nombre);
    
    for (int i = 0; i < totalProductos; i++){
        if (productos[i].nombre == nombre){
            cout << "Producto encontrado: ";
            cout << productos[i].nombre << " -> " << productos[i].precio << endl;
        }
    }
}
void ActualizarProducto (){
    string nombre;
    cout << "Ingrese el nombre del producto: ";
    getline(cin, nombre);

    for (int i = 0; i < totalProductos; i++){
        if (productos[i].nombre == nombre){
            cout << "Nuevo nombre de producto: ";
            getline(cin,productos[i].nombre);
            cout << "Nuevo precio de producto: ";
            cin >> productos[i].precio;
        }
    }

}
void EliminarProducto (){
    string nombre;
    cout << "Ingrese el nombre del producto: ";
    getline(cin, nombre);

    for (int i = 0; i < totalProductos; i++){
        if (productos[i].nombre == nombre){
            for (int j = i; j < totalProductos - 1; j++){
                productos[j] = productos[j+1];
            }
            totalProductos--;
            return;
        }
    }
}
void RegistrarVenta (){
    string nombre;
    cout << "Ingrese el nombre del producto vendido: ";
    getline(cin, nombre);
    int cantidad;
    cout << "Cantidad vendida: ";
    cin >> cantidad;
    for (int i = 0; i < totalProductos; i++){
        if (productos[i].nombre == nombre){
            ventas[totalV].IdVenta = IdVENTA++;
            ventas[totalV].producto = nombre;
            ventas[totalV].cantidad = cantidad;
            ventas[totalV].precioTotal = productos[i].precio * cantidad;
            totalV++;
            return;
        }
    }
}
void ListaVenta (){
    for (int i = 0; i < totalV; i++){
        cout << "Venta ID" << ventas[i].IdVenta;
        cout << "Producto : " << ventas[i].producto;
        cout << "Cantidad : " << ventas[i].cantidad;
        cout << "Total: " << ventas[i].precioTotal << endl;
    }
}
void TotalVenta (){
    float total = 0;
    for (int i = 0; i < totalV; i++){
        total += ventas[i].precioTotal;
    }
    
}
void menu (){
    char opcion;
    do {
        cout << "A: Registrar un nuevo producto. " << endl;
        cout << "B: Listar los productos registrados. " << endl;
        cout << "C: Buscar un producto por nombre. " << endl;
        cout << "D: Actualizar los datos de un producto. " << endl;
        cout << "E: Eliminar un producto. " << endl;
        cout << "F: Registrar una venta. " << endl;
        cout << "G: Listar las ventas realizadas. " << endl;
        cout << "H: Calcular el total de ventas realizadas. " << endl;
        cout << "S: Salir del programa." << endl;
        cin >> opcion;
        switch (opcion){
            case 'A' :
                RegistrarProducto();
                break;
            case 'B' :
                ListaProducto();
                break;
            case 'C' :
                BuscarProducto(); 
                break;
            case 'D': 
                ActualizarProducto();
                break;
            case 'E' :
                EliminarProducto();
                break;
            case 'F' : 
                RegistrarVenta();
                break;
            case 'G':
                ListaVenta();
                break;
            case 'H' :
                TotalVenta();
                break;
            case 'S' :
                cout << "Saliendo del programa......" << endl;
                break;
            default :
                cout << "Opcion Invalida. Intente Nuevamente. " << endl;
        }   
    } while (opcion != 'S');
}

int main(){
    menu();
    return 0;
}