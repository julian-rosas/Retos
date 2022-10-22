# Datos
Julián Rosas Scull
319661323

Desarrollado en GoLang.

# Instrucciones para ejecutar el programa

  ```sh
   $ go run MinimumPathSum.go
   ``` 

   Aparecerá ,dados dos test cases que indicaba LeetCode, la suma del camino de suma mínima de ambos test cases.

   Los test cases fueron:

   * [[1,3,1],[1,5,1],[4,2,1]]
   * [[1,2,3],[4,5,6]]

# ¿Cómo resolví el problema? 

Dada la matriz de nxm, estuve experimentando con cómo se realizaban los movimientos (dada las reestricciones de movimiento de LeetCode) dentro de la matriz (i.e. moverse hacia la derecha y hacia abajo), y me di cuenta que todas las casillas de los costados (es decir del renglón 0 y columna 0) nada mas pueden ser accedidos por ya sea la izquierda (en el primer caso) o arriba (en el segundo). Dado dicho razonamiento se me ocurrió hacer una matriz con las mismas dimensiones que la original , la cual mapeara la distancia mínima dada una posición respecto a la posición de origen con el número de la posición original de la matriz original.

Con dicha idea, solamente era ver qué casos eran fijos (los de los costados ya mencionados anteriormente) y en cuales podían haber varias opciones, en esta última solo se comparaban (en la matriz de distancias mínimas respecto al origen) de qué lado era la distancia mínima (haciendo referencia a la suma mínima hasta ese punto), una vez ya realizada dicha comparación, se sumaba con su respectivo valor en la matriz original, y asi se iteraba (linealmente) la matriz original hasta llegar a la posición [n-1,m-1], la cual representaba la suma mínima de los números dentro de la matriz de [0,0] a [n-1,m-1].

# Estructuras de datos usadas

En este reto solamente use un arreglo bidimensional, el cual tenía las mismas dimensiones que la matriz original. Esto permite que la complejidad en espacio sea de _O(n*m)_ y en tiempo sea de _O(n*m)_ donde n y m son las dimensiones de la matriz, e.d. en el caso de que sea cuadrada la matriz, dicha complejidad será cuadrática.


# ¿Por qué se me ocurrió resolverlo de esa manera?

Se me ocurrió resolver de esta manera por que era una de las maneras mas "intuitivas" sobre la resolución del problema, esto por que simplemente era un mapeo de una matriz con su matriz de distancias mínimas, y así al irse acercando a la posición final, se computa en tiempo constante la distancia mínima hasta el momento de las opciones disponibles por cada posición.

# Lo que se me dificultó

Lo que más se me dificultó fue encontrar los base cases del computamiento de distancias mínimas de la matriz respecto a la posición de origen, las cuales eran el los costados de la matriz, ya que sin estos, sentí que todo quedaba en abstracto y que no existía algún caso en que algo fuera "seguro". 




