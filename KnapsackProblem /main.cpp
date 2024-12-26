#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int POP_SIZE = 100;
const int MAX_GENERATIONS = 1000;
const double MUTATION_RATE = 0.1;
const double CROSSOVER_RATE = 0.7;

struct Item {
    int weight;
    int value;
};

int knapsackCapacity = 50;

int fitness(const vector<Item>& items, const vector<int>& solution) {
    int totalWeight = 0;
    int totalValue = 0;
    
    for (int i = 0; i < items.size(); i++) {
        if (solution[i] == 1) {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
        }
    }

    if (totalWeight > knapsackCapacity) {
        return 0;  
    }

    return totalValue;
}

int selectParent(const vector<vector<int>>& population, const vector<Item>& items) {
    int totalFitness = 0;
    vector<int> fitnesses(population.size());
    for (int i = 0; i < population.size(); i++) {
        fitnesses[i] = fitness(items, population[i]);
        totalFitness += fitnesses[i];
    }

    double randomValue = rand() % totalFitness;
    int cumulativeFitness = 0;
    for (int i = 0; i < population.size(); i++) {
        cumulativeFitness += fitnesses[i];
        if (cumulativeFitness >= randomValue) {
            return i;
        }
    }
    return population.size() - 1;
}

pair<vector<int>, vector<int>> crossover(const vector<int>& parent1, const vector<int>& parent2) {
    int point = rand() % parent1.size();
    vector<int> child1 = parent1;
    vector<int> child2 = parent2;
    
    for (int i = point; i < parent1.size(); i++) {
        swap(child1[i], child2[i]);
    }
    
    return {child1, child2};
}

vector<int> mutate(vector<int> individual) {
    int mutationPoint = rand() % individual.size();
    individual[mutationPoint] = 1 - individual[mutationPoint]; 
    return individual;
}

int main() {
    srand(time(0));

    vector<Item> items = {
        {10, 60}, {20, 100}, {30, 120}
    };

    int numItems = items.size();
    vector<vector<int>> population(POP_SIZE, vector<int>(numItems));

    for (int i = 0; i < POP_SIZE; i++) {
        for (int j = 0; j < numItems; j++) {
            population[i][j] = rand() % 2;
        }
    }

    int generation = 0;
    vector<int> bestSolution;
    int bestFitness = 0;

    while (generation < MAX_GENERATIONS) {
        vector<vector<int>> newPopulation;

        for (int i = 0; i < POP_SIZE / 2; i++) {
            int parent1Index = selectParent(population, items);
            int parent2Index = selectParent(population, items);

            auto [child1, child2] = crossover(population[parent1Index], population[parent2Index]);

            if (rand() / double(RAND_MAX) < MUTATION_RATE) {
                child1 = mutate(child1);
            }
            if (rand() / double(RAND_MAX) < MUTATION_RATE) {
                child2 = mutate(child2);
            }

            newPopulation.push_back(child1);
            newPopulation.push_back(child2);
        }

        population = newPopulation;

        for (int i = 0; i < population.size(); i++) {
            int currentFitness = fitness(items, population[i]);
            if (currentFitness > bestFitness) {
                bestFitness = currentFitness;
                bestSolution = population[i];
            }
        }

        generation++;
    }

    cout << "Best solution: ";
    for (int i = 0; i < bestSolution.size(); i++) {
        cout << bestSolution[i] << " ";
    }
    cout << endl;

    cout << "Best fitness (total value): " << bestFitness << endl;
    return 0;
}