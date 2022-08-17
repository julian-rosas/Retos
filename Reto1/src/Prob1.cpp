#include <iostream>
#include <string>
#include <vector>

using namespace std;



/**
 * @brief Funcion que se encarga de retornar el prefijo común de un vector de 
 * palabras. En caso de que no exista el prefijo o el vector de palabras es de 
 * tamaño 0, entonces se retorna un string vacío ("").
 * 
 * Complejidad en tiempo: O(n*m) donde n es el tamaño del arreglo de strings y 
 * m es la longitud del string mas grande en dicho arreglo.
 * 
 * Complejidad en espacio: O(1).
 * 
 * @param palabras - vector de palabras a analizar.
 * @return string - prefijo común entre las palabras.
 */
string commonPrefix(vector<string> palabras){
    // caso particular en el que no hay palabras en el vector.
    if(palabras.size() == 0)
        return "";

    // prefijo a retornar, se inicializa como la primera palabra del vector
    // para asi ir borrando en caso de que alguna palabra no comparta
    // carcactéres.
    string prefijo = palabras[0];

    // iteración de el vector de palabras.
    for(int i = 0; i < palabras.size(); i++){

        // caso en el cual el prefijo es mas grande que la palabra a sacar el prefijo común.
        if(prefijo.size() > palabras[i].size()){
            prefijo.erase(prefijo.begin() + palabras[i].size(), prefijo.end());
        }

        // se itera la palabra y se compara con el prefijo cada caractér, así para cada palabra en el vector.
        for(int j = 0; j < palabras[i].size(); j++){
            if(prefijo[j] != palabras[i][j]){
                prefijo.erase(prefijo.begin() + j, prefijo.end());
                break;
            }
        }
    }
    
    return prefijo;
}


/**
 * @brief Funcion "main" que se encarga de la entrada del programa.
 * 
 * @return int - si se termina o no el programa exitosamente, 0 si es asi.
 */
int main(){
    // tamaño que va a tener el vector
    int tam;
    
    
    // vector de palabras con tamaño "tam".
    vector<string> palabras;

    // prefijo restante de las palabras.
    string prefijo;

    // entrada del tamaño del vector.
    cin >> tam;

    // entrada de las palabras en el vector.
    for(int i = 0; i < tam; i++){
        string a;
        cin >> a;
        palabras.push_back(a);
    }

    prefijo = commonPrefix(palabras);

    cout << prefijo << "\n";


    return 0;
}