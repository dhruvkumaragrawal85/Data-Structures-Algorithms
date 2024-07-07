const ll mod = 5381;                                          //take a prime number mod, larger fewer collisions
const ll alphabetSize = 26;                                   //alphabet size
vector<int> search(string pattern, string text)
{
    int m = pattern.size();
    int n = text.size();
    ll patternHash = 0, initialHash = 0;
    ll multiplier = 1;
    for (int i = 0; i < m; i++)                                /*baa=>(2*(26^2)+1*(26^1)+1*(26^0))*/
    {
        patternHash = (patternHash * alphabetSize) % mod;
        patternHash = (patternHash + pattern[i] - 'a' + 1) % mod;
        initialHash = (initialHash * alphabetSize) % mod;
        initialHash = (initialHash + text[i] - 'a' + 1) % mod;
        if (i > 0)                                             //Prepare a multiplier, used when removing left character
            multiplier = (multiplier * alphabetSize) % mod;
    }
    vector<int> res;
    if (patternHash == initialHash && pattern.compare(text.substr(0, m)) == 0)
        res.push_back(1);                                      //Check first window
    for (int i = m; i < n; i++)                                //Shift and check other windows
    {
        initialHash = (initialHash - (multiplier * (text[i - m] - 'a' + 1)) % mod + mod) % mod;
        initialHash = ((initialHash * alphabetSize) % mod + (text[i] - 'a' + 1)) % mod;
        if (patternHash == initialHash && pattern.compare(text.substr(i - m + 1, m)) == 0)
            res.push_back((i - m + 1) + 1);
    }
    return res;                                                //Returns positions matched (1-indexed)
}
