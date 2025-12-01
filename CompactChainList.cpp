#include "compactChainList.h"


CompactChainList::CompactChainList(){
    CCLsize = 0;
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
                CCL.push_back(pair<Element, int>{e,count});
                e = v[i];
                count = 1;
            }
        }
        CCL.push_back(pair<Element, int>{e,count});
    }
}


CompactChainList::CompactChainList(const CompactChainList &c){
    CCL = c.CCL;
    CCLsize = c.CCLsize;
}


int CompactChainList::size(){
    return CCLsize;
}


int CompactChainList::searchElement(Element e){
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


int CompactChainList::getConsecutiveOcurrences(vector<Element> &v){
    int ans = 0;
    string secuencia;
    string ocurrencia;

    for(int i = 0; i < CCL.size(); i++){
        for(int j = 0; j < CCL[i].second; j++){
            secuencia += CCL[i].first;
        }
    }
    for(int i = 0; i < v.size(); i++){
        ocurrencia += v[i];
    }
    int buscar = secuencia.find(ocurrencia);
    bool flag = true;

    while(buscar < secuencia.length() && flag){
        ans++;
        int posicion = buscar + ocurrencia.length();
        buscar = secuencia.find(ocurrencia, posicion);

        if(buscar > secuencia.length()){
            flag = false;
        }
    }
    return ans;
}


int CompactChainList::getIndexFirstConsecutiveOcurrence(vector<Element> &v){
    int ans = -1;
    string secuencia;
    string ocurrencia;

    for(int i = 0; i < CCL.size(); i++){
        for(int j = 0; j < CCL[i].second; j++){
            secuencia += CCL[i].first;
        }
    }

    for(int i = 0; i < v.size(); i++){
        ocurrencia += v[i];
    }

    int buscar = secuencia.find(ocurrencia);

    if(buscar < secuencia.length()){
        ans = buscar;
    }

    return ans;
}


int CompactChainList::getOcurrences(vector<Element> &v){
    string secuencia;
    string ocurrencia;
    int cnt = 0;

    for(int i = 0; i < CCL.size(); i++){
        for(int j = 0; j < CCL[i].second; j++){
            secuencia += CCL[i].first;
        }
    }
    for(int i = 0; i < v.size(); i++){
        ocurrencia += v[i];
    }
    
    for (int k = 0; k < secuencia.length();k++) {
        int indice = 0;
        int pos = k;

        while (pos < secuencia.length() && indice < ocurrencia.length()) {
            if (secuencia[pos] == ocurrencia[indice]) {
                indice++;
            }
            pos++;
        }

        if (indice == ocurrencia.length()) {
            cnt++;
        }
    }
    return cnt;
}


int CompactChainList::getIndexFirstOcurrence(vector<Element> &v){
    string secuencia;
    string ocurrencia;

    for(int i = 0; i < CCL.size(); i++){
        for(int j = 0; j < CCL[i].second; j++){
            secuencia += CCL[i].first;
        }
    }

    for(int i = 0; i < v.size(); i++){
        ocurrencia += v[i];
    }

    for (int k = 0; k < secuencia.length();k++) {
        int indice = 0;
        int pos = k;

        while (pos < secuencia.length() && indice < ocurrencia.length()) {
            if (secuencia[pos] == ocurrencia[indice]) {
                indice++;
            }
            pos++;
        }

        if (indice == ocurrencia.length()) {
            return k;
        }
    }
    return -1;
}

CompactChainList CompactChainList::getLexicographicFusion(CompactChainList &c){
    return operator+(c);
}


list<Element> CompactChainList::expand() const{
    list<Element> aux;
    for (int i = 0; i < CCL.size(); ++i) {
        for (int j = 0; j < CCL[i].second; j++) {
            aux.push_back(CCL[i].first);
        }
    }    
    return aux;
}


bool CompactChainList::operator<(const CompactChainList &oth) const{
    list <Element> a = expand();
    list <Element> b = oth.expand();

    list <Element>::iterator it1 = a.begin();
    list <Element>::iterator it2 = b.begin();

    while (it1 != a.end() && it2 != b.end()) {
        if (*it1 < *it2) {
            return true;
        }

        if (*it1 > *it2) {
            return false;
        }

        ++it1;
        ++it2;
    }

    return (it1 == a.end() && it2 != b.end());

}


bool CompactChainList::operator==(const CompactChainList &oth) const{
    if (CCLsize != oth.CCLsize) {
        return false;
    }

    if (CCL.size() != oth.CCL.size()) {
        return false;
    }

    for (int i = 0; i < CCL.size();i++) {
        if (CCL[i].first != oth.CCL[i].first || CCL[i].second != oth.CCL[i].second) {
            return false;
        }
    }
    return true;
}



Element CompactChainList::operator[](const int pos) const{
    int indiceBloque = getBlockIndex(pos);
    Element ans;
    
    if(indiceBloque != -1){
        ans = CCL[indiceBloque].first;
    }
    return ans;
}


CompactChainList CompactChainList::operator+(const CompactChainList &oth) const{
    CompactChainList aux;
    if (oth.CCL.empty() && !CCL.empty()) {
        aux.CCL = CCL;
        aux.CCLsize = CCLsize;
        return aux;
    }

    if (!oth.CCL.empty() && CCL.empty()) {
        aux.CCL = oth.CCL;
        aux.CCLsize = oth.CCLsize;
        return aux;
    }

    if (oth.CCL.empty() && CCL.empty()) {
        return aux;
    }
    
    int i = 0, j = 0;

    while (i < CCL.size() && j < oth.CCL.size()) {
        Element e1 = CCL[i].first;
        Element e2 = oth.CCL[j].first;

        if (e1 < e2) {
            aux.CCL.push_back(CCL[i]);
            aux.CCLsize += CCL[i].second;
            i++;
        } else if (e1 > e2) {
            aux.CCL.push_back(oth.CCL[j]);
            aux.CCLsize += oth.CCL[j].second;
            j++;
        } else  {
            int fusion = CCL[i].second + oth.CCL[j].second;
            aux.CCL.push_back(pair<Element, int>{e1, fusion});
            aux.CCLsize += fusion;
            i++;
            j++;  
        }
    }

    while (j < oth.CCL.size()) {
        aux.CCL.push_back(oth.CCL[j]);
        aux.CCLsize += oth.CCL[j].second;
        j++;
    }
    
    while (i < CCL.size()) {
        aux.CCL.push_back(CCL[i]);
        aux.CCLsize += CCL[i].second;
        i++;
    }
    return aux;
}


void CompactChainList::set(int pos, Element e) {
    int indiceBloque = getBlockIndex(pos);
    
    int conteo = 0;
    for(int i = 0; i < indiceBloque; i++){
        conteo += CCL[i].second;
    }
        
    int posEnBloque = pos - conteo;
    int izquierda = posEnBloque;
    int derecha = CCL[indiceBloque].second - posEnBloque - 1;
    Element orig = CCL[indiceBloque].first;
        
    if(orig != e){
        CCL.erase(CCL.begin() + indiceBloque);
        int posInsert = indiceBloque;
            
        if (izquierda > 0) {
            CCL.insert(CCL.begin() + posInsert, pair<Element, int>{orig, izquierda});
            posInsert++;
        }
        
        CCL.insert(CCL.begin() + posInsert, pair<Element, int>{e, 1});
        posInsert++;
        
        if (derecha > 0) {
            CCL.insert(CCL.begin() + posInsert, pair<Element, int>{orig, derecha});
        }
    }
    consecutiveBlock();
}


void CompactChainList::removeFirstOcurrence(Element e){
    bool eliminado = false;
    for (int i = 0; i < CCL.size() && !eliminado; i++){
        if(CCL[i].first == e){

            CCL[i].second -= 1;
            eliminado = true;
            CCLsize -= 1;

            if(CCL[i].second == 0){
                CCL.erase(CCL.begin() + i);
            }
        }
    }
}


void CompactChainList::removeAllOcurrences(Element e){
    int i = 0;
    while (i < CCL.size()){
        if(CCL[i].first == e){
            CCLsize -= CCL[i].second;
            CCL.erase(CCL.begin() + i);
        }
        else{
            i++;
        }
    }
}


void CompactChainList::removeBlockPosition(int pos) {
    int indice = getBlockIndex(pos);

    CCLsize -= CCL[indice].second;
    CCL.erase(CCL.begin() + indice);

    consecutiveBlock();
}


void CompactChainList::insertElement(int pos, Element e){
    bool procesado = false;
    
    if (pos == CCLsize) {
        CCL.push_back(pair<Element, int>{e, 1});
        CCLsize++;
        procesado = true;
    }

    if (!procesado && pos == 0) {
        CCL.insert(CCL.begin(), pair<Element, int>{e, 1});
        CCLsize++;
        procesado = true;
    }

    if (!procesado) {
        int indexCCL = getBlockIndex(pos);

        int cnt = 0;

        for(int i = 0; i < indexCCL; i++){
            cnt += CCL[i].second;
        }

        int posEnBloque = pos - cnt;
        int izquierda = posEnBloque;
        int derecha = CCL[indexCCL].second - posEnBloque;
        Element orig = CCL[indexCCL].first;

        if(orig == e){
            CCL[indexCCL].second++;
            CCLsize++;
        }
        else {
            CCL.erase(CCL.begin() + indexCCL);
            int posInsert = indexCCL;
                
            if (izquierda > 0) {
                CCL.insert(CCL.begin() + posInsert, pair<Element, int>{orig, izquierda});
                posInsert++;
            }
            
            CCL.insert(CCL.begin() + posInsert, pair<Element, int>{e, 1});
            posInsert++;
            
            if (derecha > 0) {
                CCL.insert(CCL.begin() + posInsert, pair<Element, int>{orig, derecha});
            }
            
            CCLsize++;
        }
        
        consecutiveBlock();
    }
}


void CompactChainList::modifyAllOcurrences(Element one, Element two){
    for(int i = 0; i < CCL.size(); i++){
        if(CCL[i].first == one){
            CCL[i].first = two;
        }
    }
    consecutiveBlock();
}


void CompactChainList::push_front(Element e, int num){
    if(CCL.empty()){
        CCL.push_back(pair<Element, int>{e, num});
    }
    else if(CCL[0].first == e){
            CCL[0].second += num;
    }
    else{
        CCL.insert(CCL.begin(), pair<Element, int>{e,num});
    }
    CCLsize += num;
}


void CompactChainList::push_back(Element e, int num){
    if(CCL.empty()){
        CCL.push_back(pair<Element, int>{e, num});
    }
    else if(CCL[CCL.size()-1].first == e){
            CCL[CCL.size()-1].second += num;
    }
    else{
        CCL.push_back({e,num});
    }
    CCLsize += num;
}


void CompactChainList::sortVectorCCL(vector<CompactChainList> &v){
    if(v.size() > 1) {
        vector<CompactChainList> ordenado;
        ordenado.push_back(CompactChainList(v[0]));
        
        for(int i = 1; i < v.size(); i++){
            int posicion = ordenado.size();
            for(int j = 0; j < ordenado.size(); j++){
                if(v[i] < ordenado[j] && posicion == ordenado.size()){
                    posicion = j;
                }
            }
            ordenado.insert(ordenado.begin() + posicion, CompactChainList(v[i]));
        }
        
        v.clear();
        for(int i = 0; i < ordenado.size(); i++){
            v.push_back(CompactChainList(ordenado[i]));
        }
    }
}


void CompactChainList::combineEquals(){
    if (!CCL.empty()) {
        sort (CCL.begin(), CCL.end());
        vector <pair<Element, int>> aux;
        aux.push_back(CCL[0]);

        for (int i = 1; i < CCL.size(); i++) {
            if (CCL[i].first == aux[aux.size() - 1].first) {
                aux[aux.size() - 1].second += CCL[i].second;
            } else {
                aux.push_back(CCL[i]);
            }
        }
        CCL = aux;
    }
}


int CompactChainList::getBlockIndex(const int &pos) const{
    int posBloque = -1, posActual = 0;
    bool encontrado = false;

    for(int i = 0; i < CCL.size() && !encontrado; i++){    
        posActual += CCL[i].second;

        if(pos < posActual){
            encontrado = true;
            posBloque = i;
        }
    }
    return posBloque;
}


void CompactChainList::consecutiveBlock() {
    if(!CCL.empty()){
        vector <pair<Element, int>> aux;
        aux.push_back({CCL[0].first, CCL[0].second});

        for (int i = 1; i < CCL.size(); i++) {
            Element caracter = CCL[i].first;
            int cantidad = CCL[i].second;

            if (caracter == aux[aux.size() - 1].first) {
                aux[aux.size() - 1].second += cantidad;
            } else {
                aux.push_back({caracter, cantidad});
            }
        }
        CCL = aux;
    }

}
void CompactChainList::print() const {
    printf("[");
    for(int i = 0; i < CCL.size(); i++){
        if(i > 0) printf(", ");
        printf("(%d,%d)", CCL[i].first, CCL[i].second);
    }
    printf("]\n");    
}
