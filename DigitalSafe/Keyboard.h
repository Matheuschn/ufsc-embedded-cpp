class Keyboard {
    private:
        void setRowOutputColumnInput();
        void setRowInputColumnOutput();
    public:
        enum Key {
            NONE,
            ETX = 0x03,
            ZERO = 0X30,
            ONE,
            TWO,
            THREE,
            FOUR,
            FIVE,
            SIX,
            SEVEN,
            EIGHT,
            NINE,
            DEL = 0x7f,
        };

        Keyboard();
        Key readKeys();
};
