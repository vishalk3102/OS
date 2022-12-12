// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int rf[15], rfs, pf = 0, nf;
    printf("Enter the size of reference string :");
    cin >> rfs;
    printf("\nEnter the reference string :");
    for (int i = 0; i < rfs; i++)
    {
        cin >> rf[i];
    }
    printf("\nEnter the number of frame: ");
    cin >> nf;
    vector<int> v;
    int count = 0;
    for (int i = 0; i < rfs; i++)
    {
        auto it = find(v.begin(), v.end(), rf[i]);
        if (it == v.end())
        {
            if (v.size() == nf)
            {
                v.erase(v.begin());
            }
            v.push_back(rf[i]);
            count++;
        }
        else
        {
            v.erase(it);
            v.push_back(rf[i]);
        }
    }
    cout << "Number of page faults are :" << count << endl;
}