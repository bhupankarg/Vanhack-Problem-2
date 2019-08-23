#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'optimalPoint' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY magic
 *  2. INTEGER_ARRAY dist
 */

int optimalPoint(vector<int> magic, vector<int> dist)
{
    int startPoint = -1;
    int totalMagic = accumulate(magic.begin(), magic.end(), 0);
    int totalDist = accumulate(dist.begin(), dist.end(), 0);
    if(totalMagic >= totalDist)
    {
        int magicInStock = 0;
        for(int i = 0; i < dist.size(); i++)
        {
            if(magic[i] < dist[i])
            {
                if(magicInStock != 0)
                {
                    if((magic[i] + magicInStock) < dist[i])
                    {
                        startPoint = -1;
                        magicInStock = 0;
                    }
                    else if((magic[i] + magicInStock) > dist[i])
                    {
                        magicInStock = (magic[i] + magicInStock) - dist[i];
                    }
                }
            }
            else
            {
                if(startPoint == -1)
                    startPoint = i;
                if(magic[i] > dist[i])
                    magicInStock = magicInStock + (magic[i] - dist[i]);
            }
        }
    }
    return startPoint;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string magic_count_temp;
    getline(cin, magic_count_temp);

    int magic_count = stoi(ltrim(rtrim(magic_count_temp)));

    vector<int> magic(magic_count);

    for (int i = 0; i < magic_count; i++) {
        string magic_item_temp;
        getline(cin, magic_item_temp);

        int magic_item = stoi(ltrim(rtrim(magic_item_temp)));

        magic[i] = magic_item;
    }

    string dist_count_temp;
    getline(cin, dist_count_temp);

    int dist_count = stoi(ltrim(rtrim(dist_count_temp)));

    vector<int> dist(dist_count);

    for (int i = 0; i < dist_count; i++) {
        string dist_item_temp;
        getline(cin, dist_item_temp);

        int dist_item = stoi(ltrim(rtrim(dist_item_temp)));

        dist[i] = dist_item;
    }

    int result = optimalPoint(magic, dist);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
