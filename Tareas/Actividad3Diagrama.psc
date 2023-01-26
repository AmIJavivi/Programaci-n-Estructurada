Algoritmo sin_titulo
	Repetir
		contador = 0
		Escribir "Dame un numero"
		Leer Valor1
		Si valor1 > 0 & valor1 <= 500 Entonces
			Escribir "Sumarle 5 en 5, 100 veces"
			Mientras contador <> 100 Hacer
				valor1 = valor1 + 5
				contador = contador + 1
				Escribir contador " - " valor1
			FinMientras
		SiNo
			Si valor1 > 500 & valor1 <= 1000 Entonces
				Escribir "Sumarle 10 en 10, 50 veces"
				Mientras contador <> 50 Hacer
					valor1 = valor1 + 10
					contador = contador + 1
					Escribir contador " - " valor1
				FinMientras
			SiNo
				Si valor1 > 1000 Entonces
					Escribir "No se puede calcular el valor"
				FinSi
			FinSi
		FinSi
		Escribir "Deseas terminar con el programa [Si] [No]"
		Leer Salida
	Hasta Que salida == "si"
FinAlgoritmo
