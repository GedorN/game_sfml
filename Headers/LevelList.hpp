#include"./Element.hpp"
#include"./Level.hpp"

class LevelList
{
    protected:
    unsigned int n;
    Element<Level> *first;
    Element<Level> *current;

    public:
    LevelList();
    ~LevelList();

    void add(Level *info);
    void free();

    void executar(unsigned int frames);

    Level* getCurrentLevel(unsigned int x);




};