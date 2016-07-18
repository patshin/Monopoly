class Board{
	int NumPlayers;
	bool finish;
	int currentplayer;
	std::string winner; 
	vector <Player*> players;///share ptr??
	vector <Building*> building;//share ptr??
	Textdisplay *td;
public:
	Board();
	~Board();
	void attachplayers(char c);
    void moveplayer(int steps);
    void switchStage();
    void playerStatus();
    void nextplayer();
    void playerBankrupt(int playerindex);
    void printAsset(int playerindex);
    void saveTo(filename);
    void loadFrom(filename);
    bool finish();
    void stayAtTim(playerindex);
    std::string getwinner();
    void clear();
};



#endif
