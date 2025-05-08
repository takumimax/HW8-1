#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(int argc,char* argv[])
{
    string filename=argv[1];
    ifstream input(filename);

    map<string,int> score_sum,times;
    int in_times;
    input>>in_times;
    input.ignore(1024,'\n');

    for(int i=0;i<in_times;i++)
    {
        string movie_name,score_str;
        int score;

        getline(input,movie_name);
        if(!movie_name.empty() && movie_name.back()=='\r')
        {
            movie_name.pop_back(); // 移除 Windows-style 換行的 \r
        }

        getline(input,score_str);
        score=stoi(score_str);

        score_sum[movie_name]+=score;
        times[movie_name]+=1;
    }

    for(auto it1=score_sum.begin();it1!=score_sum.end();it1++)
    {
        string movie_name=it1->first;
        double average=double(it1->second)/times.at(movie_name);

        cout<<movie_name;
        cout<<": "<<times.at(movie_name)<<" review";
        if(times.at(movie_name)>1) cout<<"s";
        cout<<", average of ";

        if(floor(average)==average)
        {
            cout<<static_cast<int>(average)<<" / 5\n";
        }
        else
        {
            cout<<fixed<<setprecision(1)<<average<<" / 5\n";
        }
    }

    input.close();
    return 0;
}
