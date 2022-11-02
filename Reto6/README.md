 Datos
Julián Rosas Scull
319661323

Desarrollado en Java.

# Instrucciones para ejecutar y compilar el programa

Primeramente, colocarse en la carpeta src con:
  ```sh
   $ cd src
   ``` 

## Compilación
  ```sh
   $ javac RemoveNthNode.java
   ``` 

## Ejecución

   Una vez compilado el programa, aparecerá ,dados tres test cases que indicaba LeetCode, listas con el n-ésimo nodo (de derecha a izquierda) eliminado.

   Los test cases fueron:

   * [1,2,3,4,5], n = 2.
   * [1], n = 1
   * [1,2], n = 1

# ¿Cómo resolví el problema? 
Primero me pregunté cómo se eliminaba un nodo arbitrario de una lista simplemente ligada, ya que al no tener referencia anterior, no aplicaba la lógica de eliminación de las listas simplemente ligadas.

Una vez descubierto el algoritmo para eliminar un nodo arbitrario, el problema se reducía a como "guardar" las referencias anteriores de la lista, las cuales, se guardaban simplemente haciendo referencia a "head" (la lista original) esto porque lo que se modificaba en mi algoritmo era un nodo iterativo (inicilizado como la lista "head") el cual iba a ser modificado por medio de referencias auxiliares para eliminar un nodo.

# Estructuras de datos usadas
Listas **simplemente ligadas** definidas por LeetCode.


# ¿Por qué se me ocurrió resolverlo de esa manera?
Era la manera mas efectiva, ya que toma tiempo y espacio de $O(n)$, ademas de que el problema se reducía a cómo eliminar un nodo de una lista simplemente ligada 

# Lo que se me dificultó
El cómo guardar las referencias anteriores, ya que al avanzar (o iterar) una lista simplemente ligada, ésta va perdiendo las referencias anteriores, por lo que se tiene que modificar una referencia auxiliar a la lista original, de manera que esta referencia auxiliar apunte en memoria a la original, para así, retornar la original con las referencias ya actualizadas (nodo eliminado).

