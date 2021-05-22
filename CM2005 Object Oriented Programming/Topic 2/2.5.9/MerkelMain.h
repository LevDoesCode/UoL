

class MerkelMain
{
  public:
    MerkelMain();
  private:
  /* Starts the sim */
    void init();
    void printMenu();
    void printHelp();
    void printMarketStats();
    void enterOffer();
    void enterBid();
    void printWallet();
    void goToNextTimeFrame();
    int getUserOption();
    void processUserOption(int userOption);
};