#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Round {
    public:
    Round(int round_id);
    int getRoundId();

    protected:
    void generateRound();
    void quickStart();
    
    private:
    int round_id;
};

