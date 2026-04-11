/****************************************************
██████╗ ██████╗ ██╗   ██╗████████╗███████╗███╗   ██╗
██╔══██╗██╔══██╗██║   ██║╚══██╔══╝██╔════╝████╗  ██║
██████╔╝██████╔╝██║   ██║   ██║   █████╗  ██╔██╗ ██║
██╔══██╗██╔══██╗██║   ██║   ██║   ██╔══╝  ██║╚██╗██║
██████╔╝██║  ██║╚██████╔╝   ██║   ███████╗██║ ╚████║
╚═════╝ ╚═╝  ╚═╝ ╚═════╝    ╚═╝   ╚══════╝╚═╝  ╚═══╝
***************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("03.out", "w", stdout);

    const int LIMIT = 5000;
    string result;
    result.reserve(LIMIT);

    // Outward spiral: R×1, D×1, L×2, U×2, R×3, D×3, L×4, U×4, ...
    // Directions cycle: R, D, L, U
    // Length increases every 2 turns
    const char dirs[] = {'R', 'D', 'L', 'U'};
    int dir = 0;
    int step = 1;       // current run length
    int turn_count = 0; // how many turns taken at this step length

    while ((int)result.size() < LIMIT)
    {
        int moves_left = LIMIT - (int)result.size();
        int run = min(step, moves_left);
        result.append(run, dirs[dir % 4]);

        dir++;
        turn_count++;
        if (turn_count == 2)
        {
            turn_count = 0;
            step++;
        }
    }

    // Write to all 8 output files
    for (int i = 1; i <= 8; i++)
    {
        char fname[16];
        snprintf(fname, sizeof(fname), "%02d.out", i);
        FILE *f = fopen(fname, "w");
        fprintf(f, "%s\n", result.c_str());
        fclose(f);
    }

    fprintf(stderr, "Generated %zu moves\n", result.size());
    fprintf(stderr, "Spiral covers approx ±%d in each direction\n", step / 2);
    return 0;
}
