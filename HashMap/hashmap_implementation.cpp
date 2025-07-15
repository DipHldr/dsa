#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int>m;
    //insertion
    //1
    pair<string,int>p=make_pair("babbar",3);
    m.insert(p);
    //2
    pair<string,int>pair2("love",2);
    m.insert(pair2);

    //3
    m["mera"]=1;

    //search
    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;
    cout<<m["unknownkey"]<<endl;
    cout<<m.at("unknownkey")<<endl;
    /*
    cout<<m.at("unknownkey")<<endl;
     cout<<m["unknownkey"]<<endl;*/
//size
cout<<"size of map :"<<m.size()<<endl;

//check presence
cout<<m.count("bro")<<endl;//if absent then returns 0 else 1
cout<<m.count("babbar")<<endl;
//erase
m.erase("love");
cout<<"new size: "<<m.size()<<endl;

//accessing all elements in a map
  for(auto i:m){
    cout<<i.first<<" "<<i.second<<endl;
  }
  cout<<endl<<endl;
  //iterator
  unordered_map<string,int>::iterator it=m.begin();
  while(it!=m.end()){
    cout<<it->first<<" "<<it->second<<endl;
    it++;
  }

}