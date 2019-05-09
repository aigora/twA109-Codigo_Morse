class LED
{
  public:
    LED (int);
    void Run (int,int);
    int Update();
  private:
    int pinLED;
    int Estado;
    int inicio;
    int Tiempo_On;
    int Tiempo_Off;
};
