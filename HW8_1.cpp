#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
    string filename=argv[1];
    ifstream input(filename);

    map<string , int> score_sum,times;
    int in_times;
    input>>in_times;
    //input.ignore(numeric_limits<streamsize>::max(), '\n');
    input.ignore();


    for(int i=0;i<in_times;i++)
    {
        string movie_name;
        int score;

        getline(input,movie_name);
        //input.get();
        input>>score;
        input.ignore();
        //input.ignore(numeric_limits<streamsize>::max(), '\n');

        //cout<<movie_name<<endl;


        score_sum[movie_name]+=score;
        times[movie_name]+=1;

        //cout<<movie_name<<": "<<score_sum[movie_name]<<endl;
    }

    //cout<<score_sum.begin()->first<<endl;

    for(auto it1=score_sum.begin();it1!=score_sum.end();it1++)
    {       
        string movie_name= it1->first;
        double average=double(it1->second)/times.at(movie_name);

        cout<<movie_name;
        cout<<": "<<times.at(movie_name)<<" review";
        if(times.at(movie_name)>1) cout<<"s";
        cout<<", average of ";
        cout<<fixed<<setprecision(1)<<average<<" / 5\n";
        //fixed<<setprecision(1)
    }
    // for (auto it1 = score_sum.begin(); it1 != score_sum.end(); ++it1) {
    //     const string& movie = it1->first;
    //     int total_score = it1->second;
    
    //     // 使用 .at() 可以保證 key 存在
    //     int review_count = times.at(movie);
    //     double average = static_cast<double>(total_score) / review_count;
    
    //     cout << movie << ": " << review_count << " review";
    //     if (review_count > 1) cout << "s";
    //     cout << ", average of " << average << " / 5\n";
    // }
    

    
    // for(auto it1=score_sum.begin();it1!=score_sum.end();it1++)
    // {
       
    //     cout<<it1->first<<endl;

    // }

    input.close();
    return 0;
}