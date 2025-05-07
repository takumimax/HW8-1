#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    string filename = argv[1];
    ifstream input(filename);
    if (!input) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    map<string, int> score_sum, times;
    int in_times;
    input >> in_times;
    input.ignore(); // ignore the newline

    for (int i = 0; i < in_times; i++) {
        string movie_name;
        int score;

        getline(input, movie_name);
        input >> score;
        input.ignore(); // ignore newline after score

        score_sum[movie_name] += score;
        times[movie_name] += 1;

        cout << movie_name << ": " << score_sum[movie_name] << endl;
    }

    for (const auto& pair : score_sum) {
        string movie = pair.first;
        int total_score = pair.second;
        int count = times[movie];

        cout << movie << ": " << count << " review";
        if (count > 1) cout << "s";
        cout << ", average of " << (double(total_score) / count) << " / 5\n";
    }

    input.close();
    return 0;
}
