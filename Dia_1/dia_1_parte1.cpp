#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cmath>

class DistanceCalculator {
public:
    DistanceCalculator(const std::string& file_path) {
        read_data(file_path);
    }

    int calculate_total_distance() {
        sort_lists();
        return compute_distance();
    }

    double measure_execution_time() {
        auto start = std::chrono::high_resolution_clock::now();
        int distance = calculate_total_distance();
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed = end - start;
        double elapsed_time = elapsed.count();

        std::cout << "La distancia total es: " << distance << "\n";
        return elapsed_time;
    }

private:
    std::vector<int> left_list;
    std::vector<int> right_list;

    void read_data(const std::string& file_path) {
        std::ifstream file(file_path);
        if (!file.is_open()) {
            throw std::runtime_error("No se puede abrir el archivo");
        }

        int left, right;
        while (file >> left >> right) {
            left_list.push_back(left);
            right_list.push_back(right);
        }
    }

    void sort_lists() {
        std::ranges::sort(left_list);
        std::ranges::sort(right_list);
    }

    int compute_distance() const {
        int total_distance = 0;
        for (size_t i = 0; i < left_list.size(); ++i) {
            total_distance += std::abs(left_list[i] - right_list[i]);
        }
        return total_distance;
    }
};

int main() {
    try {
        DistanceCalculator calculator("D:/Workspace/AdventofCode_2024/Dia_1/dia_1_imput_parte1.txt");
        double elapsed_time = calculator.measure_execution_time();
        std::cout << "El tiempo de ejecucion fue de " << elapsed_time << " segundos\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}
