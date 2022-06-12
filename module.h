#ifndef MODULE_H
#define MODULE_H

#include <iostream>

using namespace std;

template <typename Face, typename Vertex, typename Edge>

class Module{

    protected:
        
        Face fval;
        Vertex vval[6];
        Edge eval[6];

    public:

        Module();

        Module(Face, Vertex, Edge);

        Face get_face();

        Vertex get_vertex(int);

        Edge get_edge(int);

        void set_face(Face);

        void set_vertex(int, Vertex);

        void set_edge(int, Edge);

        void set_verticies(Vertex);

        void set_edges(Edge);

        void print_face();

        void print_vertex(int);

        void print_edge(int);

        void print_verticies();

        void print_edges();

        void print_data();
};
/****************************************
 * Module - default constructor
****************************************/
template <typename Face, typename Vertex, typename Edge>
Module<Face, Vertex, Edge>::Module(){
    set_face(0);
    set_verticies(0);
    set_edges(0);
}
/****************************************
 * Module - parameterized constructor
****************************************/
template <typename Face, typename Vertex, typename Edge>
Module<Face, Vertex, Edge>::Module(Face new_fval, Vertex new_vval, Edge new_eval){
    set_face(new_fval);
    set_verticies(new_vval);
    set_edges(new_eval);
}
/****************************************
 * get_face - face getter
****************************************/
template <typename Face, typename Vertex, typename Edge>
Face Module<Face, Vertex, Edge>::get_face(){
    return fval;
}
/****************************************
 * get_vertex - vertex getter
****************************************/
template <typename Face, typename Vertex, typename Edge>
Vertex Module<Face, Vertex, Edge>::get_vertex(int index){
    return vval[index];
}
/****************************************
 * get_edge - edge getter
****************************************/
template <typename Face, typename Vertex, typename Edge>
Edge Module<Face, Vertex, Edge>::get_edge(int index){
    return eval[index];
}
/****************************************
 * set_face - face setter
****************************************/
template <typename Face, typename Vertex, typename Edge>
void Module<Face, Vertex, Edge>::set_face(Face new_fval){
    fval = new_fval;
}
/****************************************
 * set_vertex - vertex setter
****************************************/
template <typename Face, typename Vertex, typename Edge>
void Module<Face, Vertex, Edge>::set_vertex(int index, Vertex new_vval){
    vval[index] = new_vval;
}
/****************************************
 * set_edge - edge setter
****************************************/
template <typename Face, typename Vertex, typename Edge>
void Module<Face, Vertex, Edge>::set_edge(int index, Edge new_eval){
    eval[index] = new_eval;
}
/****************************************
 * set_verticies - all vertex setter
****************************************/
template <typename Face, typename Vertex, typename Edge>
void Module<Face, Vertex, Edge>::set_verticies(Vertex new_vval){
    for(int i = 0; i < 6; i++)
        set_vertex(i, new_vval);
}
/****************************************
 * set_edges - all edge setter
****************************************/
template <typename Face, typename Vertex, typename Edge>
void Module<Face, Vertex, Edge>::set_edges(Edge new_eval){
    for(int i = 0; i < 6; i++)
        set_edge(i, new_eval);
}
/****************************************
 * print_face - prints a modules face
****************************************/
template <typename Face, typename Vertex, typename Edge>
void Module<Face, Vertex, Edge>::print_face(){
    cout << "\t" << fval << endl;
}
/****************************************
 * print_vertex - prints a modules data
****************************************/
template <typename Face, typename Vertex, typename Edge>
void Module<Face, Vertex, Edge>::print_vertex(int index){
    cout << "\t" << vval[index] << endl;

}
/****************************************
 * print_edge - prints a modules data
****************************************/
template <typename Face, typename Vertex, typename Edge>
void Module<Face, Vertex, Edge>::print_edge(int index){
    cout << "\t" << eval[index] << endl;

}
/****************************************
 * print_verticies - prints a modules 
****************************************/
template <typename Face, typename Vertex, typename Edge>
void Module<Face, Vertex, Edge>::print_verticies(){
    cout << "\t";
    for(int i = 0; i < 6; i++){
        cout << vval[i];
        if(i < 5)
            cout << ", ";
    }
    cout << endl;

}
/****************************************
 * print_edges - prints a modules vertices
****************************************/
template <typename Face, typename Vertex, typename Edge>
void Module<Face, Vertex, Edge>::print_edges(){
    cout << "\t";
    for(int i = 0; i < 6; i++){
        cout << eval[i];
        if(i < 5)
            cout << ", ";
    }
    cout << endl;

}
/****************************************
 * print_data - prints a modules edges
****************************************/
template <typename Face, typename Vertex, typename Edge>
void Module<Face, Vertex, Edge>::print_data(){
    print_face();
    print_verticies();
    print_edges();
}

#endif