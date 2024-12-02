def is_safe(report):
    return (all(1 <= report[i+1] - report[i] <= 3 for i in range(len(report) - 1)) or
            all(1 <= report[i] - report[i+1] <= 3 for i in range(len(report) - 1)))

def count_safe_reports(file_path):
    with open(file_path) as f:
        return sum(1 for line in f if is_safe(list(map(int, line.split()))))

# Ruta del archivo
file_path = 'D:/Workspace/AdventofCode_2024/Dia_2/dia_2_input_parte1.txt'

# Contamos los informes seguros
safe_reports = count_safe_reports(file_path)
print("Número de informes seguros:", safe_reports)

