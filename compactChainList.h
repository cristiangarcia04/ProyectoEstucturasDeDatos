#ifndef COMPACTCHAINLIST_H
#define COMPACTCHAINLIST_H

#include <vector>
#include <list>
#include <utility>
using namespace std;
typedef char Element;

class CompactChainList {
    private:
        vector<pair<Element, int>> CCL;
        int CCLsize = 0;

    public:
        CompactChainList();
        CompactChainList(vector<Element> &v);
        CompactChainList(CompactChainList &c);

        int size();
        int searchElement(Element &e);
        int getConsecutiveOcurrences(vector<Element> &v);
        int getIndexFirstConsecutiveOcurrence(vector<Element> &v);
        int getOcurrences(vector<Element> &v);
        int getIndexFirstOcurrence(vector<Element> &v);
        CompactChainList getLexicographicFusion(CompactChainList &c);
        list<Element> expand();

        bool operator<(const CompactChainList &oth) const;
        bool operator==(const CompactChainList &oth) const;
        bool operator==(const Element &oth) const;
        bool operator==(const int &oth) const;
        Element operator[](const int pos) const;
        Element operator[](const int pos);
        CompactChainList operator+(const CompactChainList &oth) const;

        void set(int &pos, Element &e);
        void removeFirstOcurrence(Element &e);
        void removeAllOcurrences(Element &e);
        void removeBlockPosition(int &pos);
        void insertElement(int &pos, Element &e);
        void modifyAllOcurrences(Element &one, Element &two);
        void push_front(Element &e, int &num);
        void push_back(Element &e, int &num);
        static void sortVectorCCL(vector<CompactChainList> &v);
        void combineEquals();
};

#endif
