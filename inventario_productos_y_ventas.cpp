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

void RegistrarProducto (){
    
}
void ListaProducto (){
    
}
void BuscarProducto (){
    
}
void ActualizarProducto (){

}
void EliminarProducto (){
    
}
void RegistrarVenta (){
    
}
void ListaVenta (){
    
}
void TotalVenta (){
    
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

}