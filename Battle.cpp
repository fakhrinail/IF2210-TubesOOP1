using namespace std;

void Player::battle() {
    // cek adjacent tiles 
    list<pair<Engimon,point>> wildEngimons = map.wildEngimons // harusnya pake get aja
    list<pair<Engimon,point>>::iterator<pair<Engimon,point>> it;
    Engimon opponent;
    bool isEngimonAdjacent = false;
    for (auto const& engimon : wildEngimons)
    {
        if (playerPosition.isAdjacent(point)) // engimon harusnya punya atribut point sendiri?
        {
            opponent = engimon.getEngimon() // pake operator= harusnya
            opponent.showDetail();
            isEngimonAdjacent = true;
            break;
        }
    }
    
    if (!isEngimonAdjacent)
    {
        cout << "Tidak ada engimon di dekat Anda" << endl;
    }
    else
    {
        // do compare stats
        // if menang
            // ambil engimon lawan kalau cukup
        // else kalah
            // delete activeEngimon
            // tuker engimon
        // while kalah
    }
}