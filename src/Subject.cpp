//
// Created by Jordy on 2/21/16.
//

#define MUTATION_RATE 1 //talvez 3% seja alto de mais


#include "Subject.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <ctime>

#include <chrono>
#include <random>
#include <fstream>
#include <string.h>

using namespace std;

//MatrixGenerator::MatrixGenerator(int id, char* path, char *name)  {
//
//    printf("ok");
//
//    this->path = path;
//    this-> name = name;
//    this->id = id;
//
//    printf("ok");
//
//    simulateFitness(); //apenas para fins de teste, o algoritmo não irá convergir.
//
//    double value;
//    srand( (unsigned)time(0) );
//    for (int i = 0; i < LINE; ++i) {
//        for (int j = 0; j < COLUMN; ++j) {
//            value = (1 + ( rand() % 1000 )); //gerate values between 1 and 100;
//            matriz[i][j] = value;
//        }
//    }
//
//    fileName = new char[100];fileName = new char[100];
//
//    merge();
//    createFile();
//}

Subject::Subject(const char *fileName, const char *path, bool randomInitialization) {

    this->name =  fileName;
    this->path = path;


    if(randomInitialization)
    {
        double value;

        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //criação da random seed
        std::default_random_engine generator(seed); //aplicando a seed ao gerador de números randomicos
        std::uniform_int_distribution<int> distribution(0,1000);


        for (int i = 0; i < LINE; ++i) {
            for (int j = 0; j < COLUMN; ++j) {
                value = distribution(generator);
                matriz[i][j] = value;
                //this->simulateFitness();
            }
        }
    }
    else {

        this->fileName = fileName;

        for (int i = 0; i < LINE; ++i) {
            for (int j = 0; j < COLUMN; ++j) {
                matriz[i][j] = 0;
                //this->simulateFitness();
            }
        }
    }
}

Subject::Subject() {

    fileName = new char[100];

    for (int i = 0; i < LINE; ++i) {
        for (int j = 0; j < COLUMN; ++j) {
            matriz[i][j] = 0;
        }
    }

    //simulateFitness(); //apenas para fins de teste, o algoritmo não irá convergir.

}


//void MatrixGenerator::createFile() {
//
//printf("entrei");
//    merge(); //cria o nome do arquivo
//
//    if(!fileName)
//        exit(1); //createFile utilizado antes da inicialização da matriz.
//
//
//
//    fmatrix.open(fileName,ios_base::out);
//
//
//
//    if (!fmatrix) // Se nào conseguiu criar
//    {
//        printf("Problemas em abrir o arquivo\n");
//        exit(2); //problemas ao abrir o arquivo
//    }
//
//
//    for (int i = 0; i < LINE; ++i) {
//        for (int j = 0; j < COLUMN; ++j) {
//            fmatrix <<" "<<matriz[i][j];
//        }
//        fmatrix<<endl;
//    }
//    fmatrix.close();
//}

void Subject::mutate() {

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //criação da random seed
    std::default_random_engine generator(seed); //aplicando a seed ao gerador de números randomicos
    std::uniform_int_distribution<int> distribution(0, 100);
    std::uniform_int_distribution<int> mutation(0, 1000);


    for(uint l =  0; l < LINE; l++)
        for(uint c = 0; c < COLUMN; c++)
            if(distribution(generator) <= MUTATION_RATE)
                matriz[l][c] = mutation(generator);
}

Subject::~Subject() {

    delete(fileName);
//    delete(path);

}

void Subject::createFile(const char *_fileName) {

    if(!_fileName)
        exit(1); //createFile utilizado antes da inicialização da matriz.

    fmatrix.flush();
    fmatrix.open(_fileName,ios_base::out);


    if (!fmatrix) // Se nào conseguiu criar
    {
        printf("Problemas em abrir o arquivo\n");
        exit(5); //problemas ao abrir o arquivo
    }


    for (int i = 0; i < LINE; ++i) {
        for (int j = 0; j < COLUMN; ++j) {
            fmatrix << matriz[i][j]<<" ";
        }
        fmatrix << endl;
    }
    fmatrix.close();
}

void Subject::simulateFitness() {

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //criação da random seed
    std::default_random_engine generator(seed); //aplicando a seed ao gerador de números randomicos
    std::uniform_int_distribution<int> distribution(0, 200);

    fitness = distribution(generator);

}

//void MatrixGenerator::merge() {
//
//    printf(" n%s p%s",name,path);
//
//
//    if(!path || !name)
//        exit(4); //path ou name não inicializados
//
//    char aux[100];  //vai escapar do escopo
//
//    sprintf(aux,"%s%si%d.chr",path,name,id); //estrutura de nomeação basica
//
//    fileName = aux;
//
//}

bool Subject::alreadyCrossed(int id) {

    if(crosserList.empty())
        return false;

    for(uint i = 0; i < crosserList.size(); i++)
        if(crosserList.at(i) == id)
            return true;

    return false;

}
