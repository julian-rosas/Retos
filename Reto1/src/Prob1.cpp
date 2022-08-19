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
        for(int palabra = 0; palabra < palabras.size(); palabra++){

            // caso en el cual el prefijo es mas grande que la palabra a sacar el prefijo común.
            if(prefijo.size() > palabras[palabra].size()){
                prefijo.erase(prefijo.begin() + palabras[palabra].size(), prefijo.end());
            }

            // se itera la palabra y se compara con el prefijo cada caractér, así para cada palabra en el vector.
            for(int chrtr = 0; chrtr < palabras[palabra].size(); chrtr++){
                if(prefijo[chrtr] != palabras[palabra][chrtr]){
                    prefijo.erase(prefijo.begin() + chrtr, prefijo.end());
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
        // Casos prueba:
        //      - ["flower", "flight", "flown"]
        //      - ["dog", "race", "car"]
        //      - ["hola", "hay", "hora"]
        //      - ["a", "b", "c"]
        //      - ["hola"]
        for(int i = 0; i < tam; i++){
            string palabra;
            cin >> palabra;
            palabras.push_back(palabra);
        }

        prefijo = commonPrefix(palabras);

        cout << prefijo << "\n";


        return 0;
}