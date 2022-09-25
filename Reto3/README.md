# Datos
Julián Rosas Scull
319661323

Desarrollado en GoLang.

# Instrucciones para ejecutar el programa

   ```sh
   $ go run MergeLists.go
   ``` 

   Sin embargo el código no devuelve nada (no supe como crear con la definición de LeetCode las listas simpelemente ligadas)

   Los Test cases que use fueron:

   * [1,2,4] y [1,3,4]
   * [] y []
   * [] y [0]

# ¿Cómo resolví el problema?

Dada la definición de listas simplemente ligadas de LeetCode. 
Estuve experimentando con dicha definición y noté que en realidad no son 
listas de nodos (como habitualmente se usan) sino listas de listas (justo como las del lenguaje de programación Haskell) por lo que decidí iba a haber una lista vacía que represente la memoización de la iteración de una lista iterativa (referencias perdidas por la lista iterativa). Consiguientemente, inicialicé una lista (igualmente vacía) que va a ser la que itere ambas listas (para así mezclarlas) y que sería la lista siguiente de la respuesta (cuyo valor es vacío).

Después, lo que decidí hacer fue iterar ambas listas (comparando el valor de la cabeza de cada una sucesivamente) hasta que alguna de ellas se acabe, para así, la lista que sobre igualarla a la lista que itera. Finalmente retorno la lista siguiente (la que iteró) de la lista de la lista que representa la memoización.

## Estructuras de datos usadas
En este reto no use ninguna estructura de datos auxiliar mas allá de la lista simplemente ligada que define LeetCode, por lo que mi algoritmo tiene complejidad _O(n+m)_ en tiempo donde n es el tamaño de la primera lista y m de la segunda lista, y _O(n)_ en espacio, ya que se genera una lista simplemente ligada con la mezcla ordenada de ambas.

## ¿Por qué se me ocurrió resolverlo de esa manera?

Se me ocurrió resolver de esta manera por que era la manera mas natural y mas eficiente de hacerla, ya que, al tener listas simplemente ligadas, se pudo haber hecho un arreglo de dichas listas u otras estructuras pero se "perdería" el sentido de la pregunta, ya que justamente usar referencias en cuanto a problemas de listas es lo mas eficiente, por lo que el chiste era generar dos listas vacías, una que iterara a ambas listas y otra que sirva como "dummy" la cual solo esta para referenciar como next a la que itera.

## Lo que se me dificultó

Lo que mas se me dificultó fue descubrir como se habían definido las listas simplemente ligadas de leetcode, ya que en realidad es una lista de listas y al pedir el valor de la lista, te regresa el valor de la cabeza de la misma, por lo que era confuso, especialmente por que en cursos anteriores de EDD, las listas representaban nodos y como se tenía una referencia para el anterior nodo (listas doblemente ligadas) entonces no era una lista de listas, sino listas de nodos doblemente ligados.


