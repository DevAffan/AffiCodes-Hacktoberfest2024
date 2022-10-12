vector<vector<int>> pwset(vector<int> v)
{
    // Write your code here
    vector<vector<int>> ans;
    int n = v.size();

    for (int counter = 0; counter < (1 << n); counter++)
    {
        vector<int> subset;
        for (int i = 0; i < n; i++)
        {
            if (counter & (1 << i))
            {
                subset.push_back(v[i]);
            }
        }
        ans.push_back(subset);
    }
    return ans;
}