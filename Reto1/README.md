Julián Rosas Scull - 319661323
==============================

Se usó el lenguaje de programación C++. 

# Compilación

Para poder compilar el código use:
   
   ```sh
   g++ [archivo.cpp] -o [nombre_del_archivo_de_ejecucion]
   ``` 

En donde:

[archivo.cpp] - puede ser Prob1.cpp ó Prob2.cpp.

# Ejecución 

Tras la compilación, el formato de ejecución es el siguiente:

   ```sh
   ./[nombre_del_archivo_de_ejecucion]
   ``` 

Para ejecutar _Prob1.cpp_:

1. Ingrese (que esté dentro de los parámetros de un _entero de 32 bits_) el total de palabras que se quiere sacar el prefijo (número de palabras en el arreglo).

2. Ingrese las palabras línea por línea ,o bien, separadas por espacios.

3. Al terminar, se reflejará un vacío ("") en caso de que no haya prefijo común entre todas las palabras, o su respectivo prefijo en caso de haberlo.

Para ejecutar _Prob2.cpp_:

1. Ingrese la cadena a la cual quiere analizar cual es la primera letra sin repetición.

2. Al terminar, se retornará -1 en caso de que todas las letras de la cadena introducida, estén al menos dos veces, de otra manera, retornará el índice respectivo de la primera letra no repetida.


## Ejemplos usados
Ejemplos de prueba usados en **Prob1.cpp**:

*  ["flower", "flight", "flown"]
*  ["dog", "race", "car"]
*  ["hola", "hay", "hora"]
*  ["a", "b", "c"]
*  [" "]


Ejemplos de prueba usados en **Prob2.cpp**:

*  "loveletters"
*  "aabb"
*  "abcd"







