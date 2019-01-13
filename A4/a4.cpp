/*
**  a4.cpp
**  Assignment 4, CMPT-225
**
**  Reads a sequence of integers (in the range of int's) from standard in;
**  It is interpreted as two lists, separated by a single 0
**/
#include <iostream>
#include "heap.h"
using namespace std;

int main(){

    cout << "301347189 mmushtaq Murtaza Mushtaq" << endl;
    int x;
    bool List2 = false; 
    Heap* h1 = new Heap();
    Heap* h2 = new Heap();

    cin >> x;
    while( !cin.eof() ){
        if( x == 0 ){
            List2 = true;       //this flag changes when 0 reached to show that list 2 starting
        }
        if(List2 == false){
            if(h1->size() == h1->capacity()){
                Heap* htest = new Heap();
                htest->insert(x,x);
                h1 = new Heap(*h1, *htest, 10);
                delete htest;
            }
            else{
                h1->insert(x,x);
            }            
        }
        else if(List2 == true && x != 0){
            if(h2->size() == h2->capacity()){
                Heap* htest = new Heap();
                htest->insert(x,x);
                h2 = new Heap(*h2, *htest, 10);
                delete htest;
            }
            else{
                h2->insert(x,x);
            }
        }
        cin >> x;
    }    
    while( !h1->empty()){
        int y = h1->extractMin();
        Heap* htesting = new Heap();
        Heap* hdupli = new Heap(*h2, *htesting, 10);  //copy made of list 2 for searching the max of list 1
        bool flagger = true;
        while( !hdupli->empty()){
            int p = hdupli->extractMin();
            if(y==p){
                flagger=false;
            }
        }
        if(flagger == true){
            cout << y << endl;
            return 0;
        }
    }
    cout << "NONE" << endl;
}
