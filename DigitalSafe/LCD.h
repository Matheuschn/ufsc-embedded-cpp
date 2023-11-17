class LCD {
    private:
        void pulseEnable();
        void send(unsigned char val, bool isCommand);
    public:
        LCD();
        void clearScreen();
        void writeLine(unsigned int line, const char *str);
        void clearLine(unsigned int line);
        void selectLine(unsigned int line);
};
