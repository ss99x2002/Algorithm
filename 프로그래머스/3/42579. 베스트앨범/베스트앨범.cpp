#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
// 장르별 가장 많이 재생된 노래 2개씩 모아 베스트 앨범 출시 
// 속한 노래가 많이 재생된 장르를 먼저 수록
// 장르 내에서 많이 재생된 노래를 먼저 수록
// 장르 내에서 재생 횟수가 같은 노래 중 교유번호가 낮은 노래를 먼저 수록 

//노래 장르 문자열 generes
//노래별 재생 횟수 plays 
//베스트 앨범에 들어갈 노래의 고유번호를 순서대로 Return
bool comp(pair<int,int> a, pair<int,int> b){
    
    if (a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second; 
}

bool compVec(pair<string,int> a , pair<string,int> b ){
    return a.second > b.second;
}
map <string, vector<pair<int,int>>> songs; //장르, pair{고유번호, 재생횟수};
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for (int i=0; i<genres.size(); i++){
        if (songs.find(genres[i]) == songs.end()){
            vector<pair<int,int>> newSong;
            newSong.push_back({i, plays[i]});
            songs.insert({genres[i], newSong});
        } else {
            songs.find(genres[i])->second.push_back({i, plays[i]});
        }
    }
    vector <pair<string,int>> genresCount;
    for (auto i=songs.begin(); i!=songs.end(); i++){
        sort(i->second.begin(), i->second.end(), comp);
        // 재생목록의ㅣ 합으로 genresCount 매겨야 함 !!! 
        int sum =0;
        for (int j=0; j<i->second.size(); j++){
            sum = sum + i->second[j].second;
        }
        genresCount.push_back({i->first, sum});
    }
    
    sort(genresCount.begin(), genresCount.end(), compVec);
    
    for(int i=0; i<genresCount.size(); i++){
        cout << genresCount[i].first << " " << genresCount[i].second << "\n";
    }
    
    for (int i=0; i<genresCount.size(); i++){
        if (songs.find(genresCount[i].first) != songs.end()){
            answer.push_back(songs.find(genresCount[i].first)->second[0].first);
            if (songs.find(genresCount[i].first)->second.size() >= 2) {
                answer.push_back(songs.find(genresCount[i].first)->second[1].first);
            }
        }
    }
    
    
    return answer;
}