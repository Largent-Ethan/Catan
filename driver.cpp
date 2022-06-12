#include "./hexarray.h"
#include "./module.h"

#include <iostream>

using namespace std;

int main(){

    Hexarray<int, int, int> board;

    board.print_faces();

    cout << endl;

    Hexarray<int, int, int> board2(5);

    board2.print_faces();
    
    cout << endl;

    Hexarray<int, int, int> board3(4, 3, 2, 1);
    
    board3.print_faces();

    cout << endl;

    board3.get_mod(1, 1).print_data();

    board3.set_vertex(1, 1, 4, 9);

    board3.get_mod(1, 1).print_data();

    return 0;
};