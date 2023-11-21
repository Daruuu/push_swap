# Push_swap

## Description project
Sort data into a stack, with a limited set of movements

### Notes:
- see documentation of basic algorithms like : 
  - insertion sort
  - merge sort
  - bubble sort
  - 

NOTES:

- objetivo del projecto:
	- ordenar datos
	- input: numeros enteros
	- ordenar numeros enteros recibidos como argumentos del programa 
- datos:
	- tengo 2 stacks  a y b
	- stack a :
		- cantidad aleatoria de numeros positivos/negativos
		- nunca duplicados
	- stack b :
		- esta vacio
	- objetivo: ordenar los numeros del stack en orden ascendente
		- sa swap a: 
			- Intercambia los dos primeros elementos del stack a. 
			- No hace nada si hay uno o menos elementos.
		- sb swap b:
			- Intercambia los dos primeros elementos del stack b.
			- No hace nada si hay uno o menos elementos.
		- ss swap a y swap b a la vez.
		- pa push a:
			- Toma el primer elemento del stack b y lo pone el primero en el stack a. 
			- No hace nada si b está vacío.
		- pb push b:
			- Toma el primer elemento del stack a y lo pone el primero en el stack b. 
			- No hace nada si a está vacío.
		- ra rotate a:
			- Desplaza hacia arriba todos los elementos del stack a una posición,
				de forma que el primer elemento se convierte en el último.
		- rb rotate b:
			- Desplaza hacia arriba todos los elementos del stack b una posición,
				de forma que el primer elemento se convierte en el último.
		- rr ra y rb al mismo tiempo.
		- rra reverse rotate a:
			- Desplaza hacia abajo todos los elementos del stack a una
				posición, de forma que el último elemento se convierte en el primero.
		- rrb reverse rotate b:
			- Desplaza hacia abajo todos los elementos del stack b una posición, 
				de forma que el último elemento se convierte en el primero.
		- rrr rra y rrb al mismo tiempo




