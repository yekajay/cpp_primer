////////////////////////////////////////////////////////////////////
class Mydictionary
{
private:
    string word = "";
    int counter = 0;
public:
    Mydictionary (string w, int c)
    {
        word = w;
        counter = c;
    }
    string get_word() const
    {
        return word;
    }
    int get_counter() const
    {
        return counter;
    }
    void increment_counter()
    {
        ++counter;
    }
};

bool check_valid(string& s)
{
    for (char& c : s)
    {
        c = tolower(c);
    }
    char v[] = {' ', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', ':', '.', ',', '|', '1'}; // expand list
    for (auto i : s)
    {
        for (auto j : v)
        {
            if (i == j)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cout << "***** welcome to the word frequency counter *****" << endl;
    vector<string> raw_words;
    for (string temp; cin >> temp;)
    {
        if (check_valid(temp))
        {
            raw_words.push_back(temp);
        }
    }
    sort(raw_words.begin(), raw_words.end(), [] (string a, string b) {return (a<b);});
    vector<Mydictionary> words;
    unsigned dictionary_counter = 0;
    for (unsigned i = 0; i < raw_words.size(); ++i)
    {
        if (i == 0 || raw_words[i] != raw_words[i-1])
        {
            Mydictionary t(raw_words[i], 1);
            words.push_back(t);
            ++dictionary_counter;
        }
        else
        {
            words[dictionary_counter - 1].increment_counter();
        }
    }
    cout << "\nword:\t\tfrequency:" << endl;
    for (auto i : words)
    {
        cout << i.get_word() << "\t\t" << i.get_counter() << endl;
    }
    return 0;
}


/////////////////////////////////////////////////////////////////////////////////////
int get_mode(vector<int> vi)
{
    int c1 = 1;
    int m2 = -1;
    int c2 = 1;
    if (vi.size() == 1)
    {
        return vi[0];
    }
    for (unsigned i = 1; i < vi.size(); ++i)
    {
        if (vi[i] == vi[i-1])
        {
            ++c1;
            if (c1 == c2)
            {
                m2 = -1;
            }
            if (c1 > c2)
            {
                m2 = vi[i];
                ++c2;
            }
        }
        else
        {
            c1 = 1;
        }
    }
    return m2;
}

int main()
{
    vector<int> v;
    for (int t; cin >> t;)
    {
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    int mode = get_mode(v);
    cout << "\nThe value(s) entered are: " << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << "\n\nThe mode is (-1 means no unique value): " << mode << endl;
    return 0;
}


///////////////////////////////////////////////////////////////////////////////////////
void fib(int num)
{
    if (num < 2)
    {
        cout << "error" << endl;
        return;
    }
    int st = 0;
    int ne = 1;
    int t = 0;
    cout << st << " " << ne << " ";
    for (int i = 3; i <= num; ++i)
    {
        cout << st + ne << " ";
        t = st;
        st = ne;
        ne = t + ne;
    }
    cout << endl;
    return;
}


////////////////////////////////////////////////////////////////////////////////////////
digits.push_back(c_n - '0');


////////////////////////////////////////////////////////////////////////////////////////
cout << 6.7-(3.3*(static_cast<int>(6.7/3.3))) << endl; // or use fmod
