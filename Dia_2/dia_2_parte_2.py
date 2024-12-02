def is_safe(report):
    return (all(1 <= report[i+1] - report[i] <= 3 for i in range(len(report) - 1)) or
            all(1 <= report[i] - report[i+1] <= 3 for i in range(len(report) - 1)))

def is_safe_with_dampener(report):
    if is_safe(report):
        return True
    
    return any(is_safe(report[:i] + report[i+1:]) for i in range(len(report)))

def count_safe_reports_with_dampener(file_path):
    with open(file_path) as f:
        return sum(1 for line in f if is_safe_with_dampener(list(map(int, line.split()))))

# Ruta del archivo
file_path = 'D:/Workspace/AdventofCode_2024/Dia_2/dia_2_input_parte1.txt'

# Contamos los informes seguros con el Problem Dampener
safe_reports = count_safe_reports_with_dampener(file_path)
print("Número de informes seguros (con Dampener):", safe_reports)
