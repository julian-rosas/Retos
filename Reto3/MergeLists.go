/*
*	Problema Merge two sorted lists de LeetCode en Go
 */

package main

// Definición de singly-linked list de LeetCode.
type ListNode struct {
	Val  int
	Next *ListNode
}

/**
* Función que toma dos listas simplemente ligadas
* y regresa una mezcla de una lista simplemente ligada con
* la mezcla ordenada de ambas listas.
**/
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	nodoEje := new(ListNode)
	nodoIterativo := nodoEje
	nodoEje.Next = nodoIterativo

	// cuando una lista se termine, se rompe el ciclo, ya que no
	// habrá qué comparar
	for list1 != nil && list2 != nil {
		if list1.Val <= list2.Val {
			nodoIterativo.Next = list1
			list1 = list1.Next
		} else {
			nodoIterativo.Next = list2
			list2 = list2.Next
		}

		// el nodoIterativo pierde su referencia pasada, por eso es importante el
		// nodoEje, ya que el mismo guarda la referncia de el nodoIterativo
		nodoIterativo = nodoIterativo.Next
	}

	// depende de que lista se acabe primero, el nodoIterativo asigna como su lista
	// subsecuente a la lista sobrante
	if list1 == nil {
		nodoIterativo.Next = list2
	} else if list2 == nil {
		nodoIterativo.Next = list1
	}

	// se retorna el nodoEje.Next por que es el que ha
	//guardado las referencias pasadas de nodoIterativo
	return nodoEje.Next
}

func main() {
}
