#include <iostream>
#include <string>

using namespace std;

int main() {
    string start, end;
    cin >> start;
    cin >> end;
    int startt = stoi(start.substr(0, 2)) * 60 * 60 + 
                 stoi(start.substr(3, 2)) * 60 + 
                 stoi(start.substr(6, 2));
    int endt = stoi(end.substr(0, 2)) * 60 * 60 +
               stoi(end.substr(3, 2)) * 60 + 
               stoi(end.substr(6, 2));
    if (endt <= startt)
        endt += 24 * 60 * 60;
    int diff = endt - startt;
    int hr = diff / (60 * 60), mi = (diff % (60 * 60)) / (60), sec = diff % 60;
    string hrs = to_string(hr);
    if (hrs.size() < 2)
        hrs = "0" + hrs;
    string mis = to_string(mi);
    if (mis.size() < 2)
        mis = "0" + mis;
    string secs = to_string(sec);
    if (secs.size() < 2)
        secs = "0" + secs;
    cout << hrs << ":" << mis << ":" << secs << endl;
    return 0;
}
