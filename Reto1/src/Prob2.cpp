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
int searchFirstCharacter(string s){
    
        // Se usa un diccionario con la finalidad de mapear cada caractér distinto en "s"
        // con su respectivo número de apariciones. 
        map<char, int> mp;

        // se itera el string "s" y se inserta al diccionario un nuevo caractér mapeado con un entero 1 si 
        // no estaba anteriormente en el diccionario (es una letra nueva en "s" no iterada), y si sí está,
        // solamente se incrementa su valor en 1 a dicha llave (letra) representando así sus apariciones totales.  
        for(int chrtr = 0; chrtr < s.size(); chrtr++){
            if(mp.find(s[chrtr]) != mp.end()){

                map<char,int>::iterator itr;
                itr = mp.find(s[chrtr]);
                itr->second++;
            
            }else{
                mp.insert(pair<char,int>(s[chrtr],1));
            }
        }


        // se itera el string s nuevamente, pero esta vez se busca la primera llave (letra) que tenga como valor 
        // 1, es decir, solamente haya aparecido una vez en todo "s".
        for(int chrtr = 0; chrtr < s.size(); chrtr++){
            map<char, int>::iterator itr;

            itr = mp.find(s[chrtr]);

            if(itr->second == 1)
                return chrtr;
        }

        // se retorna -1 si acaba el ciclo, lo que representa que no existe una letra que solamente esté una vez.
        return -1;
}


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
        //      - "loveletters"
        //      - "aabb"
        //      - "abcd"
        cin >> s;

        // indice del primer caractér sin repetición en la cadena "s".
        int primer = searchFirstCharacter(s);

        cout << primer << "\n\n";

        return 0;
}