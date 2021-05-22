

class MerkelMain
{
  public:
    MerkelMain();
    void printMenu();
    void printHelp();
    void printMarketStats();
    void enterOffer();
    void enterBid();
    void printWallet();
    void goToNextTimeFrame();
    int getUserOption();
    void processUserOption(int userOption);
  private:
    /* Starts the sim */
    void init();
};