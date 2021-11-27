#include "solver.h"

#include <iostream>

int main() {
    Graph G("../data/weibo10000");
    std::mt19937 rng;
    rng.seed(std::random_device()());
    G.generateLogin(rng);
    std::uniform_int_distribution uid(0, G.V - 1);
    int alpha = 10;
    if (0) {
        std::set<int> R;
        while (R.size() < 30) {
            R.insert(uid(rng));
        }
        TIBSolver tib(G, R, alpha);
        tib.solve(rng, 30);
        debug(Phi()(rng, G, R, tib.Z, alpha), Phi()(rng, G, R, {}, alpha));
    }
    
    MultiRoundSolver mul(G), test(G);
    for (int i = 0; i < 25; i += 1) {
        debug(i);
        for (int k = 0; k < 20; k += 1) {
            int u = uid(rng);
            mul.setRumor(u);
            test.setRumor(u);
        }
        mul.solve(rng, 10, alpha);
        test.solve(rng, 0, alpha);
        mul.simulate(rng, alpha);
        test.simulate(rng, alpha);
        debug(mul.count(RUMOR), test.count(RUMOR));
        debug(mul.count(TRUTH), test.count(TRUTH));
        debug("");
    }
}