#ifndef COMPACTCHAINLIST_H
#define COMPACTCHAINLIST_H

#include <vector>
#include <list>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

typedef int Element;

class CompactChainList {
    private:
        vector<pair<Element, int>> CCL;
        int CCLsize = 0;

    public:
        CompactChainList();
        CompactChainList(vector<Element> &v);
        CompactChainList(const CompactChainList &c);

        int size();
        int searchElement(Element e);
        int getConsecutiveOcurrences(vector<Element> &v);
        int getIndexFirstConsecutiveOcurrence(vector<Element> &v);
        int getOcurrences(vector<Element> &v);
        int getIndexFirstOcurrence(vector<Element> &v);
        CompactChainList getLexicographicFusion(CompactChainList &c);
        list<Element> expand() const;

        bool operator<(const CompactChainList &oth) const;
        bool operator==(const CompactChainList &oth) const;
        Element operator[](const int pos) const;
        CompactChainList operator+(const CompactChainList &oth) const;

        void set(int pos, Element e);
        void removeFirstOcurrence(Element e);
        void removeAllOcurrences(Element e);
        void removeBlockPosition(int pos);
        void insertElement(int pos, Element e);
        void modifyAllOcurrences(Element one, Element two);
        void push_front(Element e, int num);
        void push_back(Element e, int num);
        static void sortVectorCCL(vector<CompactChainList> &v);

        void combineEquals();
        int getBlockIndex(const int &pos) const;
        void consecutiveBlock();
        void print() const;
};

#endif
