def total_distance(left_list, right_list):
    # Ordenamos ambas listas
    left_sorted = sorted(left_list)
    right_sorted = sorted(right_list)
    
    # Calculamos la diferencia absoluta y sumamos
    total_distance = 0
    for left, right in zip(left_sorted, right_sorted):
        total_distance += abs(left - right)
    
    return total_distance

# Leer el archivo y extraer las listas
left_list = []
right_list = []

# Abrimos el archivo
with open('D:/Workspace/AdventofCode_2024/Dia_1/dia_1_imput_parte1.txt') as f:
    for line in f:
        left, right = map(int, line.split())
        left_list.append(left)
        right_list.append(right)

# Calculamos la distancia total
print("La distancia total es:", total_distance(left_list, right_list))
