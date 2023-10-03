#include <vector>

class StateMachine {
    public:
        enum States {
            S000 = 0,
            S025,
            S050,
            S075,
            S100,
            S125,
            S150
        };

        enum Inputs {
            NONE = 0,
            M025,
            M050,
            M100,
            DEV,
            MEET,
            ETIRPS
        };

        enum Outputs {
            D025 = 0,
            D050,
            D100,
            LMEET,
            LETIRPS
        };

        StateMachine() {};
        std::vector<Outputs> changeState(Inputs input);
    
    private:
        States currentState = States::S000;
};