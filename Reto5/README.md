 Datos
Julián Rosas Scull
319661323

Desarrollado en Java.

# Instrucciones para ejecutar y compilar el programa
## Compilación
  ```sh
   $ javac GroupAnagrams.java
   ``` 

## Ejecución

   Una vez compilado el programa, aparecerá ,dados tres test cases que indicaba LeetCode, el agrupamiento de anagramas de palabras en una Lista bidimensional.

   Los test cases fueron:

   * ["eat","tea","tan","ate","nat","bat"]
   * [""]
   * ["a"]

# ¿Cómo resolví el problema? 

Primero me pregunté qué era lo que definía un grupo de palabras, que sean anagramas entre ellas, y me di cuenta que la forma mas óptima de hacerlo es ordenar dichas palabras (en orden alafabético) para así comparar sus ordenamientos. Si son iguales, entonces son anagramas, de otra forma no lo son.

Una vez con dicho razonamiento, el problema se reducía a como agrupar los anagramas en un arreglo bidimensional, lo cual lo resolví con un HashMap.

# Estructuras de datos usadas

Utilicé un HashMap cuya entrada era {Palabra ordenada alfabéticamente, índice de la lista bidimensional donde se encuentran sus anagramas comúnes}. 

Al igual que una lista bidimensional (lo que pedía que regresara la función) y un arreglo de entrada.

# ¿Por qué se me ocurrió resolverlo de esa manera?

Era una de las maneras mas sencillas de hacerlo, si bien la complejidad en tiempo no es llamativa, es la manera más oṕtima de realizar este problema.  

# Lo que se me dificultó

Una vez con la idea de que dos palabras son anagramas si y solo si su ordenamiento alfabético es el mismo, lo único que me causo ruido es como agrupar esas palabras en una lista bidimensional.

