Funciones:
 - Input por consola / archivo --> Ana
    - Contar numero de filas y columnas
    - Recibir mapa y notación (9.ox)
    - Guardar mapa en un array unidimensional (caracteres)

 - Validación input --> Ana
    - Todas las lineas misma longitud
    - Comprobar que hay al menos un obstáculo
    - Salto de linea al final de cada linea
    - Solo puede haber caracteres de la notación (9.ox)
    - Tiene que haber 3 caracteres de notación distintos entre si
    - La notación tambien puede ser un dígito
    - Si no es valido > "map error\n"

 - Conversión del input --> Ana
    - Cambiar todos los valores de notación a nuestros valores.
    - Quitar saltos de línea y leyenda
    - Almacenar en un array unidimensional sin espacios

 - Lógica principal (saca la solucion)
 - Aplicar solución al array
    - Convertir todos los 0 en 2 para la solución
    
 - Dibujar solución
    - Desconvertir la notación para que sea visual
    - No mostrar leyenda




Notación:
 0 -> Vacío
 1 -> Obstáculo
 2 -> Solución