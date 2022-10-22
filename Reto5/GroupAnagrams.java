import java.util.HashMap;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Arrays;


/**
 * Reto Group Anagrams de LeetCode.
 */
public class GroupAnagrams{
    
    /**
     * Función que dado un arreglo de palabras, agrupa en una lista bidimensional
     * aquellas palabras que forman anagramas entre ellas.
     * 
     * Complejidad en tiempo - O(n*mlogm) donde n es el número de palabras del arreglo
     *                          y m es el tamaño de la palabra más grande.
     * 
     * Complejidad en espacio - O(n) donde n es el número de palabras en el arreglo.
     * 
     * @param strs - Palabras a generar agrupaciones de anagramas
     * @return List<List<String>> -  Lista bidimensional de anagramas agrupados.
     */
    public static List<List<String>> groupAnagrams(String[] strs){
        List<List<String>> anag = new ArrayList<>();

        // Caso especial en el que nada mas hay una palabra a en el arreglo de 
        // palabras.
        if (strs.length == 1) {
            List<String> tmp = new ArrayList<>();
            tmp.add(strs[0]);
            anag.add(tmp);
            return anag;
        }
        
        // HashMap que tendra como entrada <String, Integer>, cuya llave representa
        // la palabra ordenada alfabéticamente (con Arrays.sort), y su valor el índice
        // que va a tomar dichas agrupaciones en la lista bidimensional, para así,
        // poder determinar qué palabra es anagrama de otra. 
        Map<String, Integer> map = new HashMap<>();

        int indiceListaBid = -1;

        // se itera todas las palabras del arreglo.
        for (int i = 0; i < strs.length; i++) {
            
            // sección que dada una palabra la ordena alfabéticamente 
            // (se tiene que transformar en un arreglo de Char, ya que no existe alguna 
            // función que ordene Strings en Java).
            String palabra = strs[i];

            char[] chrArray = palabra.toCharArray();

            Arrays.sort(chrArray);

            palabra = String.valueOf(chrArray);
            
            // se checa si la palabra es anagrama de otra.
            if (map.containsKey(palabra)) {

                // se añade al agrupamiento de anagramas de esa palabra.
                List<String> tmp = anag.get(map.get(palabra));
                tmp.add(strs[i]);
                anag.set(map.get(palabra), tmp);
            } else {
                // se crea un agrupamiento nuevo solo para esa palabra.
                indiceListaBid++;
                map.put(palabra, indiceListaBid);
                List<String> tmp = new ArrayList<>();
                tmp.add(strs[i]);
                anag.add(tmp);
            }
        }

        return anag;
    }
    
    
    public static void main(String[] args) {
        String[] testCase1 = {"eat", "tea", "ate", "nat", "tan", "bat"};
        String[] testCase2 = {""};
        String[] testCase3 = {"a"};


        List<List<String>> anag1 = groupAnagrams(testCase1);
        List<List<String>> anag2 = groupAnagrams(testCase2);
        List<List<String>> anag3 = groupAnagrams(testCase3);

        System.out.println("Anagramas agrupados TestCase 1 ");

        for(List<String> lista : anag1){
            for(String palabra : lista){
                System.out.print(palabra + " ");
            }

            System.out.println();
        }

        System.out.println();

        System.out.println("Anagramas agrupados TestCase 2 ");
        for (List<String> lista : anag2) {
            for (String palabra : lista) {
                System.out.print(palabra + " ");
            }

            System.out.println();
        }
        System.out.println();

        System.out.println("Anagramas agrupados TestCase 3 ");
        for (List<String> lista : anag3) {
            for (String palabra : lista) {
                System.out.print(palabra + " ");
            }

            System.out.println();
        }
    }
}
