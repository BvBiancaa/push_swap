# 42 push_swap

<h3> Italiano 🇮🇹</h3>
Il progetto consiste nella scrittura di un algoritmo di ordinamento utilizzando il linguaggio C. L'obiettivo principale è ordinare uno stack di dimensioni variabili con il minor numero di mosse possibili, utilizzando solo delle mosse predefinite:


 <table style="width:100%">
  <tr>
    <th>Mossa</th>
    <th>Compoortamento</th>
  </tr>
  <tr>
    <td>sa (swap a)</td>
    <td style="text-align:right">Scambia i primi due elementi dello stack a. Non fa nulla se ci sono uno o nessun elemento</td>
  </tr>
  <tr>
    <td>sb (swap b)</td>
    <td style="text-align:right">Scambia i primi due elementi dello stack b. Non fa nulla se ci sono uno o nessun elemento</td>
  </tr>
  <tr>
    <td>ss</td>
    <td style="text-align:right">Esegue sa e sb contemporaneamente</td>
  </tr>
   <td>pa (push a)</td>
    <td style="text-align:right">Prende il primo elemento dello stack b e lo sposta in cima allo stack a. Non fa nulla se lo stack b è vuoto</td>
  </tr>
  <tr>
    <td>pb (push b)</td>
    <td style="text-align:right">Prende il primo elemento dello stack a e lo sposta in cima allo stack b. Non fa nulla se lo stack a è vuoto</td>
  </tr>
  <tr>
    <td>ra (rotate a)</td>
    <td style="text-align:right">Sposta tutti gli elementi dello stack a verso l'alto di una posizione. Il primo elemento diventa l'ultimo</td>
  </tr>
  <tr>
    <td>rb (rotate b)</td>
    <td style="text-align:right">Sposta tutti gli elementi dello stack b verso l'alto di una posizione. Il primo elemento diventa l'ultimo</td>
  </tr>
  <tr>
    <td>rr</td>
    <td style="text-align:right">Esegue ra e rb contemporaneamente</td>
  </tr>
   <td>rra (reverse rotate a)</td>
    <td style="text-align:right">Sposta tutti gli elementi dello stack a verso il basso di una posizione. L'ultimo elemento diventa il primo</td>
  </tr>
  <tr>
    <td>rrb (reverse rotate b)</td>
    <td style="text-align:right">Sposta tutti gli elementi dello stack b verso il basso di una posizione. L'ultimo elemento diventa il primo</td>
  </tr>
   <tr>
    <td>rrr</td>
    <td style="text-align:right">Esegue rra e rrb contemporaneamente</td>
  </tr>
</table>

Ho scelto di svolgere il progetto usando gli array perché, nonostante siano più lenti delle liste nell'aggiungere e togliere elementi (azione frequente nel programma), occupano meno ram, la velocità di accesso casuale è la migliore e permettono l'accesso tramite indice.
 
Il programma copia tutti i numeri nello stack a, successivamente trova la Longest Increasing Subsequence (LIS) che rappresenta la sequenza di numeri in a ordinata in modo crescente e di lunghezza massima.

Tutti gli altri numeri vengono spostati da a in b, utilizzando le operazioni push b e ra/rra. La scelta tra la rotazione a sinistra (ra) o a destra (rra) dipende dalla posizione del numero nel primo stack e da quale operazione richiede meno mosse per farlo arrivare in cima.

Vengono costruiti due array di supporto:
- Considerando numero per numero presente in b, calcola il numero di mosse necessarie per spostarlo in cima a b.
- Per ogni numero preso in considerazione di b, calcola il numero di mosse necessarie per far accettare quel numero da a.
Le mosse "reverse", cioe' rra e rrb hanno segno negativo, ra e rb hanno segno positivo.

Viene poi calcolato il miglior numero da spostare da b ad a:
Il programma considera ogni numero in b. Per ognuno, utilizza gli array di supporto per calcolare un punteggio che tiene conto delle mosse per accettare il numero in a e delle mosse per farlo arrivare in cima a b.
Viene selezionato il numero con il punteggio più basso come il miglior numero da spostare, tenendo conto che, se le mosse sono dello stesso segno, le azioni si possono ottimizzare usando rrr o rr.

-------------------

<h3> English 🇬🇧</h3>
The project involves writing a sorting algorithm using the C language. The main objective is to sort a variable-sized stack with the fewest possible moves, using only predefined operations:

<table style="width:100%">
  <tr>
    <th>Move</th>
    <th>Behavior</th>
  </tr>
  <tr>
    <td>sa (swap a)</td>
    <td style="text-align:right">Swap the top two elements of stack a. Does nothing if there is one or no elements</td>
  </tr>
  <tr>
    <td>sb (swap b)</td>
    <td style="text-align:right">Swap the top two elements of stack b. Does nothing if there is one or no elements</td>
  </tr>
  <tr>
    <td>ss</td>
    <td style="text-align:right">Perform sa and sb simultaneously</td>
  </tr>
   <td>pa (push a)</td>
    <td style="text-align:right">Take the top element of stack b and move it to the top of stack a. Does nothing if stack b is empty</td>
  </tr>
  <tr>
    <td>pb (push b)</td>
    <td style="text-align:right">Take the top element of stack a and move it to the top of stack b. Does nothing if stack a is empty</td>
  </tr>
  <tr>
    <td>ra (rotate a)</td>
    <td style="text-align:right">Rotate all elements of stack a upward by one position. The first element becomes the last</td>
  </tr>
  <tr>
    <td>rb (rotate b)</td>
    <td style="text-align:right">Rotate all elements of stack b upward by one position. The first element becomes the last</td>
  </tr>
  <tr>
    <td>rr</td>
    <td style="text-align:right">Perform ra and rb simultaneously</td>
  </tr>
   <td>rra (reverse rotate a)</td>
    <td style="text-align:right">Rotate all elements of stack a downward by one position. The last element becomes the first</td>
  </tr>
  <tr>
    <td>rrb (reverse rotate b)</td>
    <td style="text-align:right">Rotate all elements of stack b downward by one position. The last element becomes the first</td>
  </tr>
   <tr>
    <td>rrr</td>
    <td style="text-align:right">Perform rra and rrb simultaneously</td>
  </tr>
</table>

I chose to implement the project using arrays because, despite being slower than lists for adding and removing elements (frequent actions in the program), arrays occupy less memory, have the best random access speed, and allow access by index.

The program copies all the numbers into stack a. Then, it finds the Longest Increasing Subsequence (LIS), which represents the sequence of numbers in a sorted in ascending order with the maximum length.

All the other numbers are moved from a to b using the push b and ra/rra operations. The choice between left rotation (ra) or right rotation (rra) depends on the position of the number in the first stack and which operation requires fewer moves to bring it to the top.

Two support arrays are built:

- For each number in b, calculate the number of moves needed to bring it to the top of b.
- For each considered number in b, calculate the number of moves needed for a to accept that number.

The "reverse" moves, rra and rrb, have a negative sign, while ra and rb have a positive sign.

Next, the program calculates the best number to move from b to a:
It considers each number in b. For each number, it uses the support arrays to calculate a score that takes into account the moves to accept the number in a and the moves to bring it to the top of b.
The number with the lowest score is selected as the best number to move, taking into account that if the moves have the same sign, actions can be optimized using rrr or rr.
