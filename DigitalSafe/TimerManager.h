class TimerManager {
    public:
        static TimerManager& getInstance() {
            static TimerManager instance;
            return instance;
        }

        template<class T>
        struct Timer {
            time_t duration_ms;
            time_t timeElapsed;
            void (*callback)(T);
        };

        template<class T>
        void addTimer(double duration_ms, void (*callback)(T));
        
        void update();

        TimerManager(TimerManager const&) = delete;
        void operator=(TimerManager const&) = delete;
    private:
        TimerManager() {};
        LinkedList<Timer*> timerList;
        time_t previousTime;
};