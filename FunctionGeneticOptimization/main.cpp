#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int POP_SIZE = 100;
const int GEN_SIZE = 10;
const double MUTATION_RATE = 0.1;
const double CROSSOVER_RATE = 0.7;
const int MAX_GENERATIONS = 1000;

// Function to maximize: f(x) = x^2
double fitness(int x) {
    return x * x;
}

// Selection: Roulette wheel selection
int selectParent(const vector<int>& population) {
    int totalFitness = 0;
    for (int x : population) {
        totalFitness += fitness(x);
    }

    double randomValue = rand() % totalFitness;
    int cumulativeFitness = 0;
    for (int i = 0; i < population.size(); i++) {
        cumulativeFitness += fitness(population[i]);
        if (cumulativeFitness >= randomValue) {
            return population[i];
        }
    }
    return population.back(); // Fallback
}

// Crossover: Single point crossover
pair<int, int> crossover(int parent1, int parent2) {
    int mask = 1 << (rand() % GEN_SIZE);  // Random bitmask for crossover
    int child1 = (parent1 & mask) | (parent2 & ~mask);
    int child2 = (parent2 & mask) | (parent1 & ~mask);
    return {child1, child2};
}

// Mutation: Random bit flip
int mutate(int individual) {
    int mutationPoint = rand() % GEN_SIZE;
    individual ^= (1 << mutationPoint);  // Flip a random bit
    return individual;
}

int main() {
    srand(time(0));

    vector<int> population(POP_SIZE);
    for (int i = 0; i < POP_SIZE; i++) {
        population[i] = rand() % (1 << GEN_SIZE);  // Random 10-bit individual
    }

    int generation = 0;
    int bestIndividual = population[0];

    while (generation < MAX_GENERATIONS) {
        vector<int> newPopulation;

        // Selection, Crossover, Mutation
        for (int i = 0; i < POP_SIZE / 2; i++) {
            int parent1 = selectParent(population);
            int parent2 = selectParent(population);

            pair<int, int> children;
            if (rand() / double(RAND_MAX) < CROSSOVER_RATE) {
                children = crossover(parent1, parent2);
            } else {
                children = {parent1, parent2};
            }

            if (rand() / double(RAND_MAX) < MUTATION_RATE) {
                children.first = mutate(children.first);
            }
            if (rand() / double(RAND_MAX) < MUTATION_RATE) {
                children.second = mutate(children.second);
            }

            newPopulation.push_back(children.first);
            newPopulation.push_back(children.second);
        }

        population = newPopulation;

        for (int individual : population) {
            if (fitness(individual) > fitness(bestIndividual)) {
                bestIndividual = individual;
            }
        }

        generation++;
    }

    cout << "Best individual: " << bestIndividual << endl;
    cout << "Fitness of best individual: " << fitness(bestIndividual) << endl;

    return 0;
}