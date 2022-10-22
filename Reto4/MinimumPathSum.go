/*
* 	Problema Minimum Path Sum de LeetCode.
 */

package main

import (
	"fmt"
)

/*
* Función que permite calcular el mínimo de los dos elementos en tiempo constante
* (se calcula ya que Go no posee una función Min que reciba dos enteros en su biblioteca estandar, solo recibe floats64).
 */
func min(a int, b int) int {
	if a <= b {
		return a
	}

	return b
}

/**
 * Función que dada una matriz de nxm, regresa la suma de los números de la misma
 * desde el índice [0,0] hasta el índice [n-1,m-1] tal que la suma sea mínima.
 */
func minPathSum(grid [][]int) int {
	// dimesión n de la matriz

	n := len(grid)

	// dimensión m de la matriz
	m := len(grid[0])

	// copia de la matriz (inicializada en -1 cada entrada)
	// que va a representar las distancias mínimas de cada entrada respecto a
	// a la entrada origen ([0,0] en este caso).
	minPathsFromOrigin := make([][]int, n)

	for row := range minPathsFromOrigin {
		minPathsFromOrigin[row] = make([]int, m)
	}

	for row := 0; row < n; row++ {
		for column := 0; column < m; column++ {
			minPathsFromOrigin[row][column] = -1
		}
	}

	// se inicializa la posición [0,0] de las distancias mínimas respecto a [0,0] como
	// el valor [0,0] de la matriz original, ya que el valor mínimo de [0,0] a [0,0] es el
	// mismo.
	minPathsFromOrigin[0][0] = grid[0][0]

	// se itera la matriz original linealmente y se va construyendo la matriz de distancias mínimas.
	for row := 0; row < n; row++ {
		for column := 0; column < m; column++ {
			// se salta la primera iteración ya que se asigno anteriormente.
			if row == 0 && column == 0 {
				continue
			}

			// para cualquier columna que se encuentre en el renglón 0 (i.e. [0,y])
			// nada mas existe una manera para la cual se llegó a esa posición, la cual es y-1
			// para cualquier posición [0,y], ya que el problema plantea que solamente se puede recorrer
			// la matriz moviendose hacia la derecha o hacia abajo, en este caso como no hay
			// "arriba", solo se pudo haber accedido desde la "izquierda", finalmente se le suma a dicha posición su respectivo valor en la matriz original.
			if row == 0 {
				minPathsFromOrigin[row][column] = minPathsFromOrigin[row][column-1] + grid[row][column]
			} else if column == 0 {
				// para cualquier renglón que se encuentre en la columna 0 (i.e. [x,0])
				// nada mas existe una manera para la cual se llegó a esa posición, la cual es x-1
				// para cualquier posición [x,0], por lo que como no hay "izquierda", solo se pudo
				// haber accedido desde "arriba", finalmente se le suma a dicha posición su respectivo valor en la matriz original.
				minPathsFromOrigin[row][column] = minPathsFromOrigin[row-1][column] + grid[row][column]
			} else {
				// para cualquier posición [x,y] tal que x != 0 ó y != 0,
				// existen dos posibilidades para haber accedido a dicha posición, [x-1,y] y [x,y-1]
				// (i.e. por la izquierda o por la derecha) por lo que se escoge la distancia mínima (en la matriz de distancias mínimas)
				// de ambas opciones y se le suma su respectivo valor.
				minPathsFromOrigin[row][column] = min(minPathsFromOrigin[row][column-1], minPathsFromOrigin[row-1][column]) + grid[row][column]
			}
		}
	}

	// se retorna el último índice de la matriz de distancias mínimas,
	// la cual representa la suma del camino de sumas mínimas respecto al origen.
	return minPathsFromOrigin[n-1][m-1]
}

func main() {
	// Test Cases

	/**
	 *  -------
	 *  |1|3|1|
	 *  |1|5|1|
	 *  |4|1|1|
	 *  -------
	 */
	grid1 := [][]int{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}

	/**
	 *  -------
	 *  |1|2|3|
	 *  |4|5|6|
	 *  -------
	 */
	grid2 := [][]int{{1, 2, 3}, {4, 5, 6}}

	minPath1 := minPathSum(grid1)

	minPath2 := minPathSum(grid2)

	fmt.Println("El camino minimo para la primera matriz es: ", minPath1)
	fmt.Println("El camino minimo para la segunda matriz es: ", minPath2)
}
