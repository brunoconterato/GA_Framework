//
// Created by Jordy on 2/21/16.
//

#ifndef NOVOPROJETO_MATRIXGENERATOR_H
#define NOVOPROJETO_MATRIXGENERATOR_H

#define LINE 8
#define COLUMN 12

#include "AgConfig.h"

#include <chrono>
#include <random>
#include <fstream>
#include <string.h>

using namespace std;

class Subject {
private:

    vector<int> crosserList;
    typedef unsigned int uint;
    double fitness; // fitness of the matrix
    double matriz[LINE][COLUMN];
    const char* path; // path of the file
    int id; // identificador dentre a geração
    const char* name; // nome da geração a qual ele pertence
    fstream fmatrix; //arquivo que guarda as informações da matriz




    void merge();
public:
    const char *fileName; // name of the file

    Subject();
    ~Subject();
    Subject(const char *, const char *, bool);
    void createFile();
//    MatrixGenerator(int,char*,char*); // Generate a matrix[n][m] with random values
    void createFile(const char* _fileName);
    void mutate(); // random change in some value with some probability
    bool alreadyCrossed(int id);

    //retorna dois filhos
    // TODO: static MatrixGenerator* crossOver(MatrixGenerator,MatrixGenerator);
    //char* readFile();//read a file with the matriz;

    void simulateFitness();

    //void updateFitness(); // edit the fitness

    void addCrosser(int id){
        crosserList.push_back(id);
    }


    void setId(int id)
        {this->id = id;}

    int getId()
        { return this->id;}

    void  setPath(const char *path)
        {this->path = (char*)path;}

    const char* getPath() const
        {return path;}

    void setName(char *name)
        {this->name = name;}

    const char* getName() const
        {return name;}

    void setFileName(char *fileName)
        {this->fileName = fileName;}

    const  char* getFileName() const
        { return fileName;}

    void setValueAt(double value,int i , int j)
        { this-> matriz[i][j] = value; }

    double  getValueAt(int i, int j) const
        {return matriz[i][j];}

    double getFitness() const
        { return fitness; }

    void setFitness(double fitness) {
        Subject::fitness = fitness;
    }
};


#endif //NOVOPROJETO_MATRIXGENERATOR_H