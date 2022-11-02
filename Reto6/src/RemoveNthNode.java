

/**
 * Clase que resuelve el problema Remove Nth Node From End Od List de 
 * LeetCode.
 */
public class RemoveNthNode{

    /**
     * Definition for singly-linked list.
     */
    public static class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }



    /**
     * Función que se encarga de quitar el n-ésimo nodo (de derecha a izquierda) de
     * una lista simplemente ligada.
     * 
     * Complejidad en tiempo - O(n) donde n es el número de elementos.
     * Complejidad en espacio - O(n) ya que se esta creando una lista simplemente ligada auxiliar para
     *                          actualizar referencias.
     * 
     * @param head - lista simplemente ligada
     * @param n - n-ésimo nodo a quitar de derecha a izquierda
     * @return Lista sin el n-ésimo nodo
     */
    public static ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode iterativeList = head;

        // memoizamos el tamaño de la lista.
        int size = 0;

        while (iterativeList != null) {
            iterativeList = iterativeList.next;
            size++;
        }

        iterativeList = head;

        // sacamos el n-ésimo nodo equivalente de izquierda a derecha. 
        int diff = (size - 1) - (n - 1);

        // si el nodo es le primero de la lista
        if (diff == 0) {
            return head.next;
        }

        // iteramos hasta que lleguemos al nodo anterior que el que queremos eliminar.
        for(int index = 0; index < diff - 1; index++){
            iterativeList = iterativeList.next;
        }

        // actualizamos referencias de tal manera que el nodo auxiliar sea el que 
        // se quiere eliminar y que el siguiente de la lista iterativa sea el siguiente
        // del nodo auxiliar, para así, eliminar con referencias el nodo.
        ListNode auxList = iterativeList.next;
        iterativeList.next = auxList.next;

        // retornamos la referencia completa de head actualizada.
        return head;
    
    }


    public static void main(String[] args) {
        ListNode test1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        ListNode test2 = new ListNode(1);
        ListNode test3 = new ListNode(1, new ListNode(2));


        ListNode result1 = removeNthFromEnd(test1,2);
        ListNode result2 = removeNthFromEnd(test2, 1);
        ListNode result3 = removeNthFromEnd(test3, 1);


        System.out.println("Primer test case de leetcode: [1,2,3,4,5] con n = 2");
        System.out.println("Resultado: ");
        
        while(result1 != null){
            System.out.print(result1.val + " ");
            result1 = result1.next;
        }

        System.out.println("Segundo test case de leetocde: [1] con n = 1");
        System.out.println("Resultado: " + result2);
        System.out.println("Tercer test case de leetcode: [1,2] con n = 1");
        System.out.println("Resultado: ");

        while (result3 != null) {
            System.out.print(result3.val + " ");
            result3 = result3.next;
        }

    }

}