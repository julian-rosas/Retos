/*
*	Problema Number of Islands de leetcode.
 */

package main

import "fmt"

/*
*	Función que dada un grid de strings (arreglo bidimensional) de
*	nxm, regresa el número de "islas" (siguiendo el criterio del problema, '0' si es agua, '1' si es isla)
 */
func numIslands(matrix [][]string) int {
	numIslas := 0

	numRenglones := len(matrix)
	numColumnas := len(matrix[0])

	// se itera la matriz de nxm y donde se encuentre un "1" (pedazo de isla)
	// se hace dfs sobre los alrededores del 1 cambiándolos a 0 (pedazo de agua), se aumenta el
	// contador de islas, y se sigue recorriendo la matriz con todo ese pedazo de isla
	// ya convertido a agua (a ceros).
	for renglon := 0; renglon < numRenglones; renglon++ {
		for columna := 0; columna < numColumnas; columna++ {
			// si se encuentra un pedazo de isla
			if matrix[renglon][columna] == "1" {
				// se aumenta el contador de islas.
				numIslas++
				dfs(renglon, columna, matrix)
			}
		}
	}

	return numIslas
}

/*
*	Función que dada una matriz de nxm y una posición dada por i y j (dentro de la matriz o no)
*	hace recorrido dfs en la matriz cambiando los "1" por "0", i.e. pedazo de
*	tierra por agua.
 */
func dfs(renglon int, columna int, matrix [][]string) {

	// caso base donde si el índice i o j son inválidos dentro de la matriz,
	// o bien, la posición dada representa un pedazo de agua, se rompe la recursión.
	if renglon < 0 || renglon >= len(matrix) || columna < 0 || columna >= len(matrix[0]) || matrix[renglon][columna] == "0" {
		return
	}

	// la posición dada es válida dentro de la matriz y es un pedazo de isla.
	matrix[renglon][columna] = "0"

	// se revisa las fronteras (arriba, abajo, derecha e izquierda) de la posición de la matriz
	// sean válidas o no.

	//arriba
	dfs(renglon+1, columna, matrix)

	// abajo
	dfs(renglon-1, columna, matrix)

	// derecha
	dfs(renglon, columna+1, matrix)

	// izquierda
	dfs(renglon, columna-1, matrix)

}

func main() {

	grid1 := [][]string{
		{"1", "1", "1", "1", "0"},
		{"1", "1", "0", "1", "0"},
		{"1", "1", "0", "0", "0"},
		{"0", "0", "0", "0", "0"}}

	grid2 := [][]string{
		{"1", "1", "0", "0", "0"},
		{"1", "1", "0", "0", "0"},
		{"0", "0", "1", "0", "0"},
		{"0", "0", "0", "1", "1"}}

	fmt.Println("Para el primer Test case\n", grid1)

	numOfIslands1 := numIslands(grid1)

	fmt.Println("Respuesta:", numOfIslands1)

	fmt.Println()

	fmt.Println("Para el segundo Test case\n", grid2)

	numOfIslands2 := numIslands(grid2)

	fmt.Println("Respuesta:", numOfIslands2)

}
