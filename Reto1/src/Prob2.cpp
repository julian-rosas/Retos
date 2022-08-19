#include <iostream>
#include <string>
#include <map>

using namespace std;

/**
 * @brief Función que se encarga de retornar el primer caractér sin repetición alguna
 * en una cadena "s", retorna -1 en caso de que para todo caractér "c" en "s", "c" aparece
 * mas de una vez. 
 * 
 * Complejidad en tiempo: O(n)
 * 
 * Complejidad en espacio: O(n)
 * 
 * @param s - cadena a sacar el primer índice sin repetición.
 * @return int - índice.
 */
int buscaPrimerCaracter(string s){
    
    // Se usa un diccionario con la finalidad de mapear cada caractér distinto en "s"
    // con su respectivo número de apariciones. 
    map<char, int> mp;

    // se itera el string "s" y se inserta al diccionario un nuevo caractér mapeado con un entero 1 si 
    // no estaba anteriormente en el diccionario (es una letra nueva en "s" no iterada), y si sí está,
    // solamente se incrementa su valor en 1 a dicha llave (letra) representando así sus apariciones totales.  
    for(int i = 0; i < s.size(); i++){
        if(mp.find(s[i]) != mp.end()){

            map<char,int>::iterator itr;
            itr = mp.find(s[i]);
            itr->second++;
        
        }else{
            mp.insert(pair<char,int>(s[i],1));
        }
    }


    // se itera el string s nuevamente, pero esta vez se busca la primera llave (letra) que tenga como valor 
    // 1, es decir, solamente haya aparecido una vez en todo "s".
    for(int i = 0; i < s.size(); i++){
        map<char, int>::iterator itr;

        itr = mp.find(s[i]);

        if(itr->second == 1)
            return i;
    }

    // se retorna -1 si acaba el ciclo, lo que representa que no existe una letra que solamente esté una vez.
    return -1;
}

/*
void ejemplos(){
    string ej1 = "loveletters";
    string ej2 = "aabb";
    string ej3 = "abcd";

    int indiceEj1 = buscaPrimerCaracter(ej1);
    int indiceEj2 = buscaPrimerCaracter(ej2);
    int indiceEj3 = buscaPrimerCaracter(ej3);


    cout << "Ejemplo 1:" << "\n";
    cout << ej1 << " debe retornar: 1" 
        << " retorna " << indiceEj1 << "\n";

    cout << "Ejemplo 2:" << "\n";
    cout << ej2 << " debe retornar: -1"
         << " retorna " << indiceEj2 << "\n";

    cout << "Ejemplo 3:" << "\n";
    cout << ej3 << " debe retornar: 1"
         << " retorna " << indiceEj3 << "\n";
}
*/

/**
 * @brief Funcion "main" que se encarga de la entrada del programa.
 * 
 * @return int - si se termina o no el programa exitosamente, 0 si es asi.
 */
int main(){

    // cadena a sacar el primer índice sin alguna repetición.
    string s;

    // entrada del programa.
    // Casos Prueba:
    //          - "loveletters"
    //          - "aabb"
    //          - "abcd"
    cin >> s;

    // indice del primer caractér sin repetición en la cadena "s".
    int primer = buscaPrimerCaracter(s);

    cout << primer << "\n\n";

    return 0;
}