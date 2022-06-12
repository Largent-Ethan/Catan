#ifndef HEXARRAY_H
#define HEXARRAY_H

#include "./module.h"

#include <iostream>

using namespace std;

template <typename Face, typename Vertex, typename Edge>
class Hexarray : public Module<Face, Vertex, Edge>{

    private:

        Module<Face, Vertex, Edge>** harr;
        int size = 3;

    public:

        Hexarray();

        Hexarray(int);

        Hexarray(int, Face, Vertex, Edge);

        ~Hexarray();

        Module<Face, Vertex, Edge> get_mod(int, int);

        void set_mod(int, int, Face, Vertex, Edge);

        void set_mods(Face, Vertex, Edge);

        void set_face(int, int, Face);

        void set_vertex(int, int, int, Vertex);

        void set_edge(int, int, int, Edge);

        void print_faces();
};
/****************************************
 * Hexarray - default constructor
****************************************/
template <typename Face, typename Vertex, typename Edge>
Hexarray<Face, Vertex, Edge>::Hexarray(){
    bool limit_reached = false;
    int row_size = size;
    harr = new Module<Face, Vertex, Edge>*[size * 2 - 1];
    for(int i = 0; i < size * 2 - 1; i++){
        if(i == size - 1)
            limit_reached = true;
        harr[i] = new Module<Face, Vertex, Edge>[row_size];
        if(limit_reached == false)
            row_size = row_size + 1;
        else
            row_size = row_size - 1;
    }
}
/****************************************
 * Hexarray - sized sontructor
****************************************/
template <typename Face, typename Vertex, typename Edge>
Hexarray<Face, Vertex, Edge>::Hexarray(int new_size){
    size = new_size;
    bool limit_reached = false;
    int row_size = size;
    harr = new Module<Face, Vertex, Edge>*[size * 2 - 1];
    for(int i = 0; i < size * 2 - 1; i++){
        if(i == size - 1)
            limit_reached = true;
        harr[i] = new Module<Face, Vertex, Edge>[row_size];
        if(limit_reached == false)
            row_size = row_size + 1;
        else
            row_size = row_size - 1;
    }
}
/****************************************
 * Hexarray - parameterized constructor
****************************************/
template <typename Face, typename Vertex, typename Edge>
Hexarray<Face, Vertex, Edge>::Hexarray(int new_size, Face starting_fval, Vertex starting_vval, Edge starting_eval){
    size = new_size;
    bool limit_reached = false;
    int row_size = size;
    harr = new Module<Face, Vertex, Edge>*[size * 2 - 1];
    for(int i = 0; i < size * 2 - 1; i++){
        if(i == size - 1)
            limit_reached = true;
        harr[i] = new Module<Face, Vertex, Edge>[row_size];
        for(int j = 0; j < row_size; j++){
            harr[i][j].set_face(starting_fval);
            harr[i][j].set_verticies(starting_vval);
            harr[i][j].set_edges(starting_eval);
        }
        if(limit_reached == false)
            row_size = row_size + 1;
        else
            row_size = row_size - 1;
    }
}
/****************************************
 * ~Hexarray - destructor
****************************************/
template <typename Face, typename Vertex, typename Edge>
Hexarray<Face, Vertex, Edge>::~Hexarray(){
    for(int i = 0; i < size * 2 - 1; i++)
        delete[] harr[i];
    delete harr;
}
/****************************************
 * get_mod - module getter
****************************************/
template <typename Face, typename Vertex, typename Edge>
Module<Face, Vertex, Edge> Hexarray<Face, Vertex, Edge>::get_mod(int x, int y){
    return harr[x][y];
}
/****************************************
 * set_mod - module setter
****************************************/
template <typename Face, typename Vertex, typename Edge>
void Hexarray<Face, Vertex, Edge>::set_mod(int x, int y, Face new_fval, Vertex new_vval, Edge new_eval){
    harr[x][y].set_face(new_fval);
    harr[x][y].set_verticies(new_vval);
    harr[x][y].set_edges(new_eval);
}
/****************************************
 * set_mods - all module setter
****************************************/
template <typename Face, typename Vertex, typename Edge>
void Hexarray<Face, Vertex, Edge>::set_mods(Face new_fval, Vertex new_vval, Edge new_eval){
    bool limit_reached = false;
    int row_size = size;
    for(int i = 0; i < size * 2 - 1; i++){
        if(i == size - 1)
            limit_reached = true;
        for(int j = 0; j < row_size; j++){
            harr[i][j].set_face(new_fval);
            harr[i][j].set_verticies(new_vval);
            harr[i][j].set_edges(new_eval);
        }
        if(limit_reached == false)
            row_size = row_size + 1;
        else
            row_size = row_size - 1;
    }
}
/****************************************
 * set_face - set face of involved hexes
****************************************/
template <typename Face, typename Vertex, typename Edge>
void Hexarray<Face, Vertex, Edge>::set_face(int x, int y, Face new_fval){
    harr[x][y].set_face(new_fval);
}
/****************************************
 * set_vertex - set vertex of involved hexes
****************************************/
template <typename Face, typename Vertex, typename Edge>
void Hexarray<Face, Vertex, Edge>::set_vertex(int x, int y, int index, Vertex new_vval){
    harr[x][y].set_vertex(new_vval);
    harr[x][y].set_vertex(new_vval);//!!!!! make it set adjacent vertex !!!!!
    harr[x][y].set_vertex(new_vval);//!!!!! make it set adjacent vertex !!!!!
}
/****************************************
 * set_edge - set edge of involved hexes
****************************************/
template <typename Face, typename Vertex, typename Edge>
void Hexarray<Face, Vertex, Edge>::set_edge(int x, int y, int index, Edge new_eval){
    harr[x][y].set_edge(new_eval);
    harr[x][y].set_edge(new_eval);//!!!!! make it set adjacent edge !!!!!
}
/****************************************
 * print_faces - prints all faces
****************************************/
template <typename Face, typename Vertex, typename Edge>
void Hexarray<Face, Vertex, Edge>::print_faces(){
    bool limit_reached = false;
    int row_size = size;
    for(int i = 0; i < size * 2 - 1; i++){
        cout << "\t";
        if(i == size - 1)
            limit_reached = true;
        for(int j = 0; j < row_size; j++)
            cout << harr[i][j].get_face();
        if(limit_reached == false)
            row_size = row_size + 1;
        else
            row_size = row_size - 1;
        cout << endl;
    }
}

#endif
