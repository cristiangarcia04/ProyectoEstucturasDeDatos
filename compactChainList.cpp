#include "CompactChainList.h"


CompactChainList::CompactChainList(){
}


CompactChainList::CompactChainList(vector<Element> &v){
    CCLsize = v.size();

    if(CCLsize != 0){
        int count;
        Element e;

        for(int i = 0; i < CCLsize; i++){
            if(i == 0){
                e = v[i];
                count = 1;
            }
            else if(v[i] == e){
                count +=1;
            }
            else {
                CCL.push_back(pair{e,count});
                e = v[i];
                count = 1;
            }
        }
        CCL.push_back(pair{e,count});
    }
}


CompactChainList::CompactChainList(CompactChainList &c){
    CCL = c.CCL;
    CCLsize = c.CCLsize;
}


int CompactChainList::size(){
    return CCLsize;
}


int CompactChainList::searchElement(Element &e){
    int pos = 0;
    bool flag = false;

    for(int i = 0; i < CCL.size() && !flag; i++){
        if(CCL[i].first != e){
            pos += CCL[i].second;
        }
        else{
            flag = true;
        }
    }
    if(flag == false){
        pos = -1;
    }
    return pos;
}




void CompactChainList::push_front(Element &e, int &num){
    if(CCL.empty()){
        CCL.push_back(pair{e, num});
    }
    else if(CCL[0].first == e){
            CCL[0].second += num;
    }
    else{
        CCL.insert(CCL.begin(), pair{e,num});
    }
    CCLsize += num;
}


void CompactChainList::push_back(Element &e, int &num){
    if(CCL.empty()){
        CCL.push_back(pair{e, num});
    }
    else if(CCL[CCL.size()-1].first == e){
            CCL[CCL.size()-1].second += num;
    }
    else{
        CCL.push_back({e,num});
    }
    CCLsize += num;
}

list<Element> CompactChainList::expand() {
    list<Element> aux;
    list <pair<Element, int>>:: iterator i;
    for (i = CCL.begin(); i != CCL.end(); ++i) {
        for (int j = 0; j < i->second; j++) {
            aux.push_back(i->first);
        }
    }    
    return aux;
}
