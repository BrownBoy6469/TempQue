#include <iostream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

int main() {
    LinkedList ll1 = LinkedList();
    // Node item1 = Node("411048",2015,1,9.58);
    // Node item2 = Node("411048",2015,3,14.82);
    // Node item3 = Node("411048",2016,4,20.51);
    // Node item4 = Node("411048",2016,1,10.99);
    // Node item5 = Node("411000",1973,1,0.54);
    // Node item6 = Node("411048",2016,3,18.40);
    // Node item7 = Node("411048",2016,5,-99.99);
    ll1.insert("411048",2015,1,9.58);
    cout << endl;
    ll1.insert("411048",2015,3,14.82);
    cout << endl;
    ll1.insert("411048",2016,4,20.51);
    cout << endl;
    ll1.insert("411048",2016,1,10.99);
    cout << endl;
    ll1.insert("411000",1973,1,0.54);
    cout << endl;
    ll1.insert("411048",2016,3,18.40);
    cout << endl;
    ll1.insert("411048",2016,5,-99.99);
    cout << endl;

    cout << ll1;
    cout << endl;



    LinkedList ll2 = ll1;
    cout << ll2;
    cout << endl;
    
    
    cout << "done" << endl;
    return 0;
}