# include <iostream>
# include <vector>

using namespace std;


int main(){
    vector<double> distance;
    double dis;

    for(int i = 0; i < 5; i++ ){
        cin >> dis ;
        distance.push_back(dis);
    }
    cout <<  "\n " << distance.size() ;
    return 0;
}