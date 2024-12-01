from collections import Counter

def similarity_score(left_list, right_list):
    # Contamos la cantidad de veces que aparece cada número en la lista derecha
    right_count = Counter(right_list)
    
    # Calculamos el "similarity score"
    score = 0
    for num in left_list:
        score += num * right_count[num]
    
    return score

# Leer el archivo y extraer las listas
left_list = []
right_list = []

# Abrimos el archivo con la ruta correcta
with open('D:/Workspace/AdventofCode_2024/Dia_1/dia_1_imput_parte1.txt') as f:
    for line in f:
        left, right = map(int, line.split())
        left_list.append(left)
        right_list.append(right)

# Calculamos el similarity score
print("El similarity score es:", similarity_score(left_list, right_list))
