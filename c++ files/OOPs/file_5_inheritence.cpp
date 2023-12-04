#include<iostream>
using namespace std;

class parent{
    public : 
    int x;
    protected :
    int y;
    private : 
    int z;
};

class child1: public parent{
    // X will be public here also
    // y will be protected here also
    // z will not be accesible here
};

class child2: private parent{
    // x will become private 
    // y will become private
    // z will not be accesible here
};

class child3: protected parent{
    // x will become protected
    // y will remain protected
    // z will not be accesible here
};


int main(){

    return 0;
}