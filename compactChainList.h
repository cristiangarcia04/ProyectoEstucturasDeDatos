#ifndef COMPACTCHAINLIST_H
#define COMPACTCHAINLIST_H

#include <vector>
#include <list>
#include <utility>
#include <string>
using namespace std;
typedef char Element;

class CompactChainList {
    private:
        vector<pair<Element, int>> CCL;
        int CCLsize = 0;

    public:
        CompactChainList();                                                 //DONE
        CompactChainList(vector<Element> &v);                               //DONE
        CompactChainList(CompactChainList &c);                              //DONE

        int size();                                                         //DONE
        int searchElement(Element &e);                                      //DONE
        int getConsecutiveOcurrences(vector<Element> &v);                   //DONE
        int getIndexFirstConsecutiveOcurrence(vector<Element> &v);          //DONE
        int getOcurrences(vector<Element> &v);                              //NOT DONE
        int getIndexFirstOcurrence(vector<Element> &v);                     //NOT DONE
        CompactChainList getLexicographicFusion(CompactChainList &c);       //NOT DONE
        list<Element> expand()const;                                        //DONE

        bool operator<(const CompactChainList &oth) const;                  //DONE
        bool operator==(const CompactChainList &oth) const;                 //DONE
        Element operator[](const int pos) const;                            //DONE
        CompactChainList operator+(const CompactChainList &oth) const;      //DONE

        void set(int &pos, Element &e);                                     //DONE
        void removeFirstOcurrence(Element &e);                              //DONE
        void removeAllOcurrences(Element &e);                               //DONE
        void removeBlockPosition(int &pos);                                 //DONE
        void insertElement(int &pos, Element &e);                           //DONE
        void modifyAllOcurrences(Element &one, Element &two);               //DONE
        void push_front(Element &e, int &num);                              //DONE
        void push_back(Element &e, int &num);                               //DONE
        static void sortVectorCCL(vector<CompactChainList> &v);             //DONE

        void combineEquals();                                               //DONE
        int getBlockIndex(const int &pos) const;                            //DONE
        void consecutiveBlock();                                            //DONE
};

#endif
