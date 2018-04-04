#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <ncurses.h>

class AEntity
{
    protected:
        std::string     _shape;
        size_t          _posX;
        size_t          _posY;
        size_t          _sizeX;
        size_t          _sizeY;
        std::string     _symbole;
        std::string     _type;
        
        AEntity(void);
        AEntity(AEntity const &src);
        virtual ~AEntity(void);
        AEntity(size_t posX, size_t posY, size_t sizeX, size_t sizeY, std::string symbole, std::string type);
        
        AEntity         &operator=(AEntity const &rhs);
        
    public:
        void            printEntity(void) const;
        void            displayShape(std::string c);

        virtual void    move(size_t key);

        std::string     getShape(void) const;
        size_t          getPosX(void) const;
        size_t          getPosY(void) const;
        size_t          getSizeX(void) const;
        size_t          getSizeY(void) const;
        std::string     getSymbole(void) const;
        std::string     getType(void) const;
        clock_t         getLastTime(void) const;

        void            setPos(int x , int y);
        void            setSize(int x , int y);
        void            setSymbole(std::string symbole);
        void            setType(std::string type);
        void            setLastTime(clock_t time);
};

#endif