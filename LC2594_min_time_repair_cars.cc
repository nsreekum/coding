class Solution {
public:
    struct Comparator {
        bool operator()(vector<long> &m1, vector<long> &m2){
            return (m1[0] > m2[0]);
        }
    };

    long long repairCars(vector<int>& ranks, int cars) {
        unordered_map<int, int> mechanics;
        for(int r : ranks) // O(n)
            mechanics[r]++;

        priority_queue<vector<long>, vector<vector<long>>, Comparator> min_mechanic_time;
        long time, rank, n_cars, n_mechanics;
        for(auto mechanic: mechanics){
            time = mechanic.first;
            rank = mechanic.first;
            n_cars = 1;
            n_mechanics = mechanic.second;
            min_mechanic_time.push({time, rank, n_cars, n_mechanics});
        }

        while(cars > 0) { // O(m)
            auto curr_mechanic = min_mechanic_time.top();
            min_mechanic_time.pop(); // log k
            time = curr_mechanic[0];
            rank = curr_mechanic[1];
            n_cars = curr_mechanic[2];
            n_mechanics = curr_mechanic[3];

            cars -= n_mechanics;
            n_cars += 1;

            min_mechanic_time.push({rank * n_cars * n_cars, rank, n_cars, n_mechanics});
        }

        return time;
    } // O(n + m log k)
};