#include "Maestro.h"
#include <cstdlib>

Maestro::Maestro()
{
    numberOfPieces = 0;
    tabPiece = (Piece**)malloc(sizeof(int)*numberOfPieces);
}

Maestro::Maestro(Piece** _tabPiece, int _numberOfPieces)
{
    tabPiece = (Piece**)malloc(sizeof(int)*_numberOfPieces);
    for(int i=0;i<_numberOfPieces;++i)
    {
        tabPiece[i] = _tabPiece[i];
    }
    numberOfPieces = _numberOfPieces;

}

void Maestro::biasedWheel()
{
    int i=0;
    int j=0;
    Piece** tabTemp = (Piece**)malloc(sizeof(int)*numberOfPieces/2);
    while(j<(numberOfPieces/2))
    {
        i = rand() % (numberOfPieces-1);
        if((rand()%100) < tabPiece[i]->getMark())
        {
            tabTemp[j] = tabPiece[i];
            tabPiece[i]->setMark(0);
            ++j;
        }
    }

    numberOfPieces = numberOfPieces/2;

    for(i=0;i<numberOfPieces;++i)
    {
        tabPiece[i] = tabTemp[i];
    }
    tabPiece = (Piece**)realloc(tabPiece, sizeof(int)*numberOfPieces);

}

void Maestro::addPiece(Piece* _piece)
{
    tabPiece = (Piece**)realloc(tabPiece, sizeof(int)*(numberOfPieces+1));
    tabPiece[numberOfPieces] = _piece;
}

Piece* Maestro::getPiece(int i)
{
    return tabPiece[i];
}

void Maestro::setPiece(int i, Piece* _piece)
{
    tabPiece[i] = _piece;
}

void Maestro::setNumberOfPieces(int i)
{
    numberOfPieces = i;
}

int Maestro::getNumberOfPieces()
{
    return numberOfPieces;
}
