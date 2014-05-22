#ifndef MAESTRO_H
#define MAESTRO_H

#include "Piece.h"

using namespace std;

class Maestro
{
    private:
        Piece** tabPiece;
        int numberOfPieces;

    public:
        Maestro();
        Maestro(Piece** _tabPiece, int _numberOfPieces);
        void biasedWheel();
        void addPiece(Piece* _piece);
        Piece* getPiece(int i);
        void setPiece(int i, Piece* _piece);
        void setNumberOfPieces(int i);
        int getNumberOfPieces();
}

#endif //MAESTRO_H
